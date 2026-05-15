#pragma once
#include <string>
#include <vector>
#include <iostream>
#include "symtable.h"

enum class Operator {
    ADD, SUB, MUL, DIV, MOD,
    EQ, NEQ, LT, GT, LE, GE,
    AND, OR, NOT
};

class ASTNode {
public:
    int line;
    ASTNode(int line) : line(line) {}
    virtual ~ASTNode() = default;
    virtual void checkSemantic() = 0;
};

class Stmt : public ASTNode {
public:
    Stmt(int line) : ASTNode(line) {}
};

class Expr : public ASTNode {
public:
    DataType type = DataType::UNKNOWN;
    Expr(int line) : ASTNode(line) {}

    virtual DataType evalType() = 0;

    void checkSemantic() override {
        evalType();
    }
};

class LiteralIntExpr : public Expr {
public:
    int value;
    LiteralIntExpr(int line, int v) : Expr(line), value(v) {}
    DataType evalType() override { return type = DataType::INT; }
};

class LiteralFloatExpr : public Expr {
public:
    float value;
    LiteralFloatExpr(int line, float v) : Expr(line), value(v) {}
    DataType evalType() override { return type = DataType::FLOAT; }
};

class LiteralBoolExpr : public Expr {
public:
    bool value;
    LiteralBoolExpr(int line, bool v) : Expr(line), value(v) {}
    DataType evalType() override { return type = DataType::BOOL; }
};

class LiteralStringExpr : public Expr {
public:
    std::string value;
    LiteralStringExpr(int line, const std::string& v) : Expr(line), value(v) {}
    DataType evalType() override { return type = DataType::STRING; }
};

class IdentifierExpr : public Expr {
public:
    std::string name;
    IdentifierExpr(int line, const std::string& n) : Expr(line), name(n) {}
    DataType evalType() override;
};

class BinaryExpr : public Expr {
public:
    Expr* left;
    Operator op;
    Expr* right;

    BinaryExpr(int line, Expr* l, Operator o, Expr* r)
        : Expr(line), left(l), op(o), right(r) {}
    ~BinaryExpr() { delete left; delete right; }
    DataType evalType() override;
};

class UnaryExpr : public Expr {
public:
    Operator op;
    Expr* right;

    UnaryExpr(int line, Operator o, Expr* r)
        : Expr(line), op(o), right(r) {}
    ~UnaryExpr() { delete right; }
    DataType evalType() override;
};

class VarDeclStmt : public Stmt {
public:
    DataType varType;
    std::string name;
    Expr* expr;

    VarDeclStmt(int line, DataType type, const std::string& n, Expr* e)
        : Stmt(line), varType(type), name(n), expr(e) {}
    ~VarDeclStmt() { if (expr) delete expr; }
    void checkSemantic() override;
};

class AssignStmt : public Stmt {
public:
    std::string name;
    Expr* expr;

    AssignStmt(int line, const std::string& n, Expr* e)
        : Stmt(line), name(n), expr(e) {}
    ~AssignStmt() { delete expr; }
    void checkSemantic() override;
};

class IfStmt : public Stmt {
public:
    Expr* condition;
    Stmt* thenBlock;
    Stmt* elseBlock;

    IfStmt(int line, Expr* cond, Stmt* tb, Stmt* eb)
        : Stmt(line), condition(cond), thenBlock(tb), elseBlock(eb) {}
    ~IfStmt() { delete condition; delete thenBlock; if (elseBlock) delete elseBlock; }
    void checkSemantic() override;
};

class WhileStmt : public Stmt {
public:
    Expr* condition;
    Stmt* block;

    WhileStmt(int line, Expr* cond, Stmt* b)
        : Stmt(line), condition(cond), block(b) {}
    ~WhileStmt() { delete condition; delete block; }
    void checkSemantic() override;
};

class PrintStmt : public Stmt {
public:
    Expr* expr;
    PrintStmt(int line, Expr* e) : Stmt(line), expr(e) {}
    ~PrintStmt() { delete expr; }
    void checkSemantic() override;
};

class ReturnStmt : public Stmt {
public:
    Expr* expr;
    ReturnStmt(int line, Expr* e) : Stmt(line), expr(e) {}
    ~ReturnStmt() { delete expr; }
    void checkSemantic() override;
};

class BlockStmt : public Stmt {
public:
    std::vector<Stmt*> statements;
    BlockStmt(int line) : Stmt(line) {}
    ~BlockStmt() { for (auto s : statements) delete s; }
    void addStatement(Stmt* s) { if (s) statements.push_back(s); }
    void checkSemantic() override;
};

class ProgramNode : public ASTNode {
public:
    std::vector<Stmt*> statements;
    ProgramNode(int line) : ASTNode(line) {}
    ~ProgramNode() { for (auto s : statements) delete s; }
    void addStatement(Stmt* s) { if (s) statements.push_back(s); }
    void checkSemantic() override;
};

extern ProgramNode* rootProgram;