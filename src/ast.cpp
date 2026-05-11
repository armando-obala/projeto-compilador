#include "ast.h"
#include <iostream>

ProgramNode* rootProgram = nullptr;

// Utilitário para reportar erro semântico
void reportSemanticError(int line, const std::string& msg) {
    std::cerr << "  ERRO SEMANTICO [Linha " << line << "]: " << msg << "\n";
    // Podermos usar exit(1) mas por enquanto apenas imprime
}

// ---- Implementação das Expressões ----

DataType IdentifierExpr::evalType() {
    if (!symTable.exists(name)) {
        reportSemanticError(line, "Variavel '" + name + "' nao foi declarada.");
        return type = DataType::UNKNOWN;
    }
    return type = symTable.lookup(name);
}

DataType BinaryExpr::evalType() {
    DataType t1 = left->evalType();
    DataType t2 = right->evalType();

    if (t1 == DataType::UNKNOWN || t2 == DataType::UNKNOWN) {
        return type = DataType::UNKNOWN; // Erro em sub-expressão propaga
    }

    // Operadores relacionais e lógicos retornam BOOL
    if (op == Operator::EQ || op == Operator::NEQ || op == Operator::LT || 
        op == Operator::GT || op == Operator::LE || op == Operator::GE ||
        op == Operator::AND || op == Operator::OR) {
        
        // Regras restritas: não se compara booleano com int, etc
        if (t1 != t2) {
             reportSemanticError(line, "Comparacao invalida entre tipos incompativeis: " + typeToString(t1) + " e " + typeToString(t2) + ".");
        }
        return type = DataType::BOOL;
    }

    // Operadores aritméticos
    if (t1 == DataType::STRING || t2 == DataType::STRING || t1 == DataType::BOOL || t2 == DataType::BOOL) {
        reportSemanticError(line, "Operacao aritmetica invalida com tipo string ou bool.");
        return type = DataType::UNKNOWN;
    }

    // Promoção de tipo (se um é float, o resultado é float)
    if (t1 == DataType::FLOAT || t2 == DataType::FLOAT) {
        return type = DataType::FLOAT;
    }
    
    return type = DataType::INT;
}

DataType UnaryExpr::evalType() {
    DataType t1 = right->evalType();
    if (op == Operator::NOT) {
        if (t1 != DataType::BOOL && t1 != DataType::UNKNOWN) {
            reportSemanticError(line, "Operador '!' requer uma expressao booleana.");
        }
        return type = DataType::BOOL;
    }
    return type = t1; // Operator::SUB (-) etc
}

// ---- Implementação dos Comandos ----

void VarDeclStmt::checkSemantic() {
    // 1. Tentar adicionar na tabela de símbolos
    if (!symTable.declare(name, varType)) {
        reportSemanticError(line, "Redeclaracao da variavel '" + name + "'.");
        return;
    }

    // 2. Se houver inicialização, verificar compatibilidade de tipo
    if (expr) {
        DataType exprType = expr->evalType();
        if (exprType != DataType::UNKNOWN) {
            if (exprType != varType) {
                // Permitimos conversão de INT para FLOAT implicitamente, mas avisamos nos outros casos
                if (varType == DataType::FLOAT && exprType == DataType::INT) {
                    // OK
                } else {
                    reportSemanticError(line, "Atribuicao invalida. Tentando atribuir '" + typeToString(exprType) + "' a variavel '" + name + "' do tipo '" + typeToString(varType) + "'.");
                }
            }
        }
    }
}

void AssignStmt::checkSemantic() {
    if (!symTable.exists(name)) {
        reportSemanticError(line, "Atribuicao a variavel nao declarada '" + name + "'.");
        return;
    }

    DataType varType = symTable.lookup(name);
    DataType exprType = expr->evalType();

    if (exprType != DataType::UNKNOWN) {
        if (exprType != varType) {
            if (varType == DataType::FLOAT && exprType == DataType::INT) {
                // OK
            } else {
                reportSemanticError(line, "Atribuicao invalida. Tentando atribuir '" + typeToString(exprType) + "' a variavel '" + name + "' do tipo '" + typeToString(varType) + "'.");
            }
        }
    }
}

void IfStmt::checkSemantic() {
    DataType condType = condition->evalType();
    if (condType != DataType::BOOL && condType != DataType::UNKNOWN) {
        reportSemanticError(line, "A condicao do 'if' deve ser uma expressao booleana.");
    }
    thenBlock->checkSemantic();
    if (elseBlock) {
        elseBlock->checkSemantic();
    }
}

void WhileStmt::checkSemantic() {
    DataType condType = condition->evalType();
    if (condType != DataType::BOOL && condType != DataType::UNKNOWN) {
        reportSemanticError(line, "A condicao do 'while' deve ser uma expressao booleana.");
    }
    block->checkSemantic();
}

void PrintStmt::checkSemantic() {
    expr->evalType(); // Print aceita qualquer coisa
}

void ReturnStmt::checkSemantic() {
    expr->evalType(); 
}

void BlockStmt::checkSemantic() {
    for (auto stmt : statements) {
        stmt->checkSemantic();
    }
}

void ProgramNode::checkSemantic() {
    for (auto stmt : statements) {
        stmt->checkSemantic();
    }
}
