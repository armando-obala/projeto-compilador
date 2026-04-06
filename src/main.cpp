/* ╔══════════════════════════════════════════════════════════════╗
   ║  main.cpp  —  Ponto de entrada do Compilador Didático        ║
   ║                                                              ║
   ║  DOIS MODOS DE USO:                                          ║
   ║    ./compilador programa.src  → modo arquivo                 ║
   ║    ./compilador               → modo interativo (teclado)    ║
   ╚══════════════════════════════════════════════════════════════╝ */

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include "tokens.h"

/* ── FlexLexer.h ────────────────────────────────────────────────
   Gerado pelo Flex quando usamos %option c++.
   Declara a classe yyFlexLexer com o método yylex().           */
#include <FlexLexer.h>


/*
   tokenTypeName — converte TokenType → std::string legível

   !!!Se você adicionar um novo token em tokens.h e em lexico.l, adicione também um case aqui!!!
*/
std::string tokenTypeName(TokenType t) {
    switch(t) {
        case TokenType::END_OF_FILE:    return "EOF";

        /* keywords */
        case TokenType::KW_INT:         return "KW_INT";
        case TokenType::KW_FLOAT:       return "KW_FLOAT";
        case TokenType::KW_BOOL:        return "KW_BOOL";
        case TokenType::KW_STRING:      return "KW_STRING";
        case TokenType::KW_IF:          return "KW_IF";
        case TokenType::KW_ELSE:        return "KW_ELSE";
        case TokenType::KW_WHILE:       return "KW_WHILE";
        case TokenType::KW_ENDDO:       return "KW_ENDDO";
        case TokenType::KW_PRINT:       return "KW_PRINT";
        case TokenType::KW_RETURN:      return "KW_RETURN";

        /* literais */
        case TokenType::LIT_INT:        return "LIT_INT";
        case TokenType::LIT_FLOAT:      return "LIT_FLOAT";
        case TokenType::LIT_STRING:     return "LIT_STRING";
        case TokenType::LIT_TRUE:       return "LIT_TRUE";
        case TokenType::LIT_FALSE:      return "LIT_FALSE";

        /* ── Tokens especiais ─────────────────────────────────── */
        case TokenType::LIT_CPF:        return "LIT_CPF";
        case TokenType::LIT_CNPJ:       return "LIT_CNPJ";
        case TokenType::LIT_EMAIL:      return "LIT_EMAIL";
        case TokenType::LIT_DATA:       return "LIT_DATA";
        case TokenType::LIT_HORA:       return "LIT_HORA";
        case TokenType::LIT_TEL:        return "LIT_TEL";
        case TokenType::LIT_CEP:        return "LIT_CEP";
        case TokenType::LIT_HEX:        return "LIT_HEX";

        /* identificador */
        case TokenType::IDENTIFICADOR:  return "IDENTIFICADOR";

        /* operadores aritméticos */
        case TokenType::OP_MAIS:        return "OP_MAIS";
        case TokenType::OP_MENOS:       return "OP_MENOS";
        case TokenType::OP_MULTI:       return "OP_MULTI";
        case TokenType::OP_DIVID:       return "OP_DIVID";
        case TokenType::OP_PORCENT:     return "OP_PORCENT";

        /* operadores relacionais */
        case TokenType::OP_EQ:          return "OP_EQ";
        case TokenType::OP_NEQ:         return "OP_NEQ";
        case TokenType::OP_LT:          return "OP_LT";
        case TokenType::OP_GT:          return "OP_GT";
        case TokenType::OP_LE:          return "OP_LE";
        case TokenType::OP_GE:          return "OP_GE";

        /* operadores lógicos */
        case TokenType::OP_AND:         return "OP_AND";
        case TokenType::OP_OR:          return "OP_OR";
        case TokenType::OP_NOT:         return "OP_NOT";

        /* atribuição */
        case TokenType::OP_ASSIGN:      return "OP_ASSIGN";

        /* delimitadores */
        case TokenType::LPAREN:         return "LPAREN";
        case TokenType::RPAREN:         return "RPAREN";
        case TokenType::LBRACE:         return "LBRACE";
        case TokenType::RBRACE:         return "RBRACE";
        case TokenType::SEMICOLON:      return "SEMICOLON";
        case TokenType::COMMA:          return "COMMA";

        /* erro */
        case TokenType::UNKNOWN:        return "UNKNOWN";

        default:                        return "???";
    }
}


/* 
   printCabecalho — cabeçalho da tabela de tokens

   std::setw(N) define a largura mínima da coluna.
   std::left    alinha o texto à esquerda.
*/
void printCabecalho() {
    std::cout << "\n";
    std::cout << "  "
              << std::left << std::setw(5)  << "#"
              << std::setw(16) << "TIPO"
              << std::setw(26) << "LEXEMA"
              << "LINHA\n";
    std::cout << "  "
              << std::string(60, '-') << "\n";
}


/*
   printToken — imprime uma linha da tabela para um token
*/
void printToken(int numero, TokenType tipo,
                const std::string& lexema, int linha) {
    std::cout << "  "
              << std::left << std::setw(5)  << numero
              << std::setw(16) << tokenTypeName(tipo)
              << std::setw(26) << lexema
              << linha << "\n";
}


/*
   rodarLexer — loop principal que consome tokens

   Recebe um yyFlexLexer já configurado (apontando para arquivo ou stdin) e imprime todos os tokens.
 */
void rodarLexer(yyFlexLexer& lexer) {
    printCabecalho();

    int token;
    int count = 0;
    int erros = 0;

    /* - Loop principal 
       lexer.yylex() é o método da classe gerada pelo Flex.
       Cada chamada lê e retorna o próximo token (como int).
       Quando o input acaba, retorna 0.                         */
    while ((token = lexer.yylex()) != 0) {
        TokenType tipo = (TokenType)token;

        if (tipo == TokenType::UNKNOWN) erros++;

        /* lexer.YYText() retorna o texto do token atual */
        printToken(++count, tipo, lexer.YYText(), lexer.lineno());
    }

    std::cout << "  " << std::string(60, '-') << "\n";
    std::cout << "  Total: " << count << " token(s)";
    if (erros > 0)
        std::cout << "  |  Erros lexicos: " << erros;
    else
        std::cout << "  |  Sem erros lexicos";
    std::cout << "\n\n";
}


/* 
   modoArquivo — lê um arquivo .src e tokeniza
*/
void modoArquivo(const std::string& caminho) {
/*
   std::ifstream abre o arquivo para leitura.       
*/
    std::ifstream arquivo(caminho);
    if (!arquivo.is_open()) {
        std::cerr << "Erro: nao foi possivel abrir '"
                  << caminho << "'\n";
        return;
    }

    std::cout << "\n  Arquivo: " << caminho << "\n";

/* 
   Cria o lexer apontando para o arquivo
   O construtor de yyFlexLexer aceita um istream*     
*/
    yyFlexLexer lexer(&arquivo, nullptr);
    rodarLexer(lexer);
}


/* ══════════════════════════════════════════════════════════════
   modoInterativo — lê do teclado (std::cin)

   std::cin é o equivalente C++ do stdin em C.
   O yyFlexLexer aceita qualquer istream, então passamos
   &std::cin para ler do teclado.
   ══════════════════════════════════════════════════════════════ */
void modoInterativo() {
    std::cout << "\n";
    std::cout << "  ╔══════════════════════════════════════════╗\n";
    std::cout << "  ║   COMPILADOR DIDÁTICO — Modo Interativo  ║\n";
    std::cout << "  ║   Fase 1: Analise Lexica (Flex + C++)    ║\n";
    std::cout << "  ╚══════════════════════════════════════════╝\n";
    std::cout << "\n";
    std::cout << "  Digite seu codigo e pressione Enter.\n";
    std::cout << "  Cada linha e analisada na hora.\n";
    std::cout << "  Para sair: Ctrl+Z + Enter (Windows)\n";
    std::cout << "             Ctrl+D        (Linux/Mac)\n";
    std::cout << "\n";
    std::cout << "  Exemplos para testar:\n";
    std::cout << "    int x = 10;\n";
    std::cout << "    123.456.789-09        (CPF)\n";
    std::cout << "    joao@email.com        (Email)\n";
    std::cout << "    15/03/2025            (Data)\n";
    std::cout << "    0xFF                  (Hexadecimal)\n";
    std::cout << "\n";

    /* Cria o lexer apontando para o teclado (std::cin) */
    yyFlexLexer lexer(&std::cin, nullptr);
    rodarLexer(lexer);

    std::cout << "  Sessao encerrada.\n\n";
}


/* ══════════════════════════════════════════════════════════════
   main — decide qual modo usar baseado nos argumentos

   argc → quantidade de argumentos da linha de comando
   argv → array de strings com os argumentos
     argv[0] = nome do executável
     argv[1] = arquivo .src (se fornecido)
   ══════════════════════════════════════════════════════════════ */
int main(int argc, char* argv[]) {

    if (argc >= 2) {
        /* Modo arquivo: ./compilador tests/programa.src */
        modoArquivo(argv[1]);
    } else {
        /* Modo interativo: ./compilador */
        modoInterativo();
    }

    return 0;
}