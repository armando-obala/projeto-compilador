%code requires {
    #include "ast.h"
}

%{
#include <iostream>
#include <string>

int yylex();
void yyerror(const char* s);
extern int get_linha();
%}

%union {
    int iValue;
    float fValue;
    char* sValue;
    bool bValue;
    class Expr* expr;
    class Stmt* stmt;
    DataType dataType;
    Operator opType;
}

/* Palavras-chave */
%token KW_INT KW_FLOAT KW_BOOL KW_STRING
%token KW_IF KW_ELSE KW_WHILE KW_ENDDO KW_PRINT KW_RETURN

/* Literais */
%token <iValue> LIT_INT
%token <fValue> LIT_FLOAT
%token <sValue> LIT_STRING
%token LIT_TRUE LIT_FALSE

/* Tokens especiais */
%token <sValue> LIT_CPF LIT_CNPJ LIT_EMAIL LIT_DATA LIT_HORA LIT_TEL LIT_CEP LIT_HEX LIT_RG LIT_MOEDA LIT_URL LIT_IP LIT_PERCENT

/* Identificador */
%token <sValue> IDENTIFICADOR

/* Operadores */
%token OP_MAIS OP_MENOS OP_MULTI OP_DIVID OP_PORCENT
%token OP_EQ OP_NEQ OP_LT OP_GT OP_LE OP_GE
%token OP_AND OP_OR OP_NOT
%token OP_ASSIGN
%token LPAREN RPAREN LBRACE RBRACE SEMICOLON COMMA
%token UNKNOWN

/* Tipos dos Não-Terminais */
%type <stmt> declaracao comando declaracao_variavel comando_if comando_while comando_atribuicao comando_print comando_return bloco token_especial_isolado
%type <expr> expressao literal
%type <dataType> tipo

/* ── Precedência e Associatividade ───────────────────────────────────── */
%left OP_OR
%left OP_AND
%left OP_EQ OP_NEQ
%left OP_LT OP_GT OP_LE OP_GE
%left OP_MAIS OP_MENOS
%left OP_MULTI OP_DIVID OP_PORCENT
%right OP_NOT

%start programa

%%

programa:
    lista_declaracoes
    | /* vazio */
    ;

lista_declaracoes:
    declaracao { if ($1) rootProgram->addStatement($1); }
    | lista_declaracoes declaracao { if ($2) rootProgram->addStatement($2); }
    ;

declaracao:
    declaracao_variavel { $$ = $1; }
    | comando { $$ = $1; }
    | token_especial_isolado { $$ = $1; }
    ;

declaracao_variavel:
    tipo IDENTIFICADOR OP_ASSIGN expressao SEMICOLON { $$ = new VarDeclStmt(get_linha(), $1, std::string($2), $4); free($2); }
    | tipo IDENTIFICADOR SEMICOLON { $$ = new VarDeclStmt(get_linha(), $1, std::string($2), nullptr); free($2); }
    ;

tipo:
    KW_INT { $$ = DataType::INT; }
    | KW_FLOAT { $$ = DataType::FLOAT; }
    | KW_BOOL { $$ = DataType::BOOL; }
    | KW_STRING { $$ = DataType::STRING; }
    ;

comando:
    comando_if { $$ = $1; }
    | comando_while { $$ = $1; }
    | comando_atribuicao { $$ = $1; }
    | comando_print { $$ = $1; }
    | comando_return { $$ = $1; }
    ;

comando_if:
    KW_IF LPAREN expressao RPAREN bloco { $$ = new IfStmt(get_linha(), $3, $5, nullptr); }
    | KW_IF LPAREN expressao RPAREN bloco KW_ELSE bloco { $$ = new IfStmt(get_linha(), $3, $5, $7); }
    ;

comando_while:
    KW_WHILE LPAREN expressao RPAREN bloco { $$ = new WhileStmt(get_linha(), $3, $5); }
    ;

comando_atribuicao:
    IDENTIFICADOR OP_ASSIGN expressao SEMICOLON { $$ = new AssignStmt(get_linha(), std::string($1), $3); free($1); }
    ;

comando_print:
    KW_PRINT LPAREN expressao RPAREN SEMICOLON { $$ = new PrintStmt(get_linha(), $3); }
    ;

comando_return:
    KW_RETURN expressao SEMICOLON { $$ = new ReturnStmt(get_linha(), $2); }
    ;

bloco:
    LBRACE { $<stmt>$ = new BlockStmt(get_linha()); } lista_declaracoes_bloco RBRACE { $$ = $<stmt>2; }
    | LBRACE RBRACE { $$ = new BlockStmt(get_linha()); }
    ;

lista_declaracoes_bloco:
    declaracao { if ($1) ((BlockStmt*)$<stmt>0)->addStatement($1); }
    | lista_declaracoes_bloco declaracao { if ($2) ((BlockStmt*)$<stmt>0)->addStatement($2); }
    ;

token_especial_isolado:
    LIT_CPF { $$ = nullptr; }
    | LIT_CNPJ { $$ = nullptr; }
    | LIT_EMAIL { $$ = nullptr; }
    | LIT_DATA { $$ = nullptr; }
    | LIT_HORA { $$ = nullptr; }
    | LIT_TEL { $$ = nullptr; }
    | LIT_CEP { $$ = nullptr; }
    | LIT_HEX { $$ = nullptr; }
    | LIT_RG { $$ = nullptr; }
    | LIT_MOEDA { $$ = nullptr; }
    | LIT_URL { $$ = nullptr; }
    | LIT_IP { $$ = nullptr; }
    | LIT_PERCENT { $$ = nullptr; }
    ;

expressao:
    expressao OP_MAIS expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::ADD, $3); }
    | expressao OP_MENOS expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::SUB, $3); }
    | expressao OP_MULTI expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::MUL, $3); }
    | expressao OP_DIVID expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::DIV, $3); }
    | expressao OP_PORCENT expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::MOD, $3); }
    | expressao OP_EQ expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::EQ, $3); }
    | expressao OP_NEQ expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::NEQ, $3); }
    | expressao OP_LT expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::LT, $3); }
    | expressao OP_GT expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::GT, $3); }
    | expressao OP_LE expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::LE, $3); }
    | expressao OP_GE expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::GE, $3); }
    | expressao OP_AND expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::AND, $3); }
    | expressao OP_OR expressao { $$ = new BinaryExpr(get_linha(), $1, Operator::OR, $3); }
    | OP_NOT expressao { $$ = new UnaryExpr(get_linha(), Operator::NOT, $2); }
    | LPAREN expressao RPAREN { $$ = $2; }
    | IDENTIFICADOR { $$ = new IdentifierExpr(get_linha(), std::string($1)); free($1); }
    | literal { $$ = $1; }
    ;

literal:
    LIT_INT { $$ = new LiteralIntExpr(get_linha(), $1); }
    | LIT_FLOAT { $$ = new LiteralFloatExpr(get_linha(), $1); }
    | LIT_STRING { $$ = new LiteralStringExpr(get_linha(), std::string($1)); free($1); }
    | LIT_TRUE { $$ = new LiteralBoolExpr(get_linha(), true); }
    | LIT_FALSE { $$ = new LiteralBoolExpr(get_linha(), false); }
    ;

%%

void yyerror(const char* s) {
    std::cerr << "  ERRO SINTATICO: " << s << " na linha " << get_linha() << "\n";
}
