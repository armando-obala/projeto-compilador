/* ╔══════════════════════════════════════════════════════════════╗
   ║  main.cpp  —  Ponto de entrada do Compilador Didático        ║
   ║                                                              ║
   ║  DOIS MODOS DE USO:                                          ║
   ║    ./compilador programa.src  → modo arquivo                 ║
   ║    ./compilador               → modo interativo (teclado)    ║
   ╚══════════════════════════════════════════════════════════════╝ */

#include "ast.h"
#include <fstream>
#include <iomanip>
#include <iostream>
#include <string>

/* ── FlexLexer.h ────────────────────────────────────────────────
   Gerado pelo Flex quando usamos %option c++.
   Declara a classe yyFlexLexer com o método yylex().           */
#include <FlexLexer.h>

/* ── Conexão com Bison ───────────────────────────────────────── */
extern int yyparse();

/* Variável global que o Bison usará para acessar o lexer do Flex */
yyFlexLexer *lexer;

/* Função intermediária obrigatória chamada pelo yyparse() */
int yylex() { return lexer->yylex(); }

/* Função para o parser obter a linha atual */
int get_linha() { return lexer->lineno(); }

void rodarAnalise() {
  std::cout << "\n  Iniciando Analise Sintatica...\n";
  symTable.clear();
  rootProgram = new ProgramNode(0);
  int resultado = yyparse();

  std::cout << "  " << std::string(60, '-') << "\n";
  if (resultado == 0) {
    std::cout << "  Resultado: Sucesso! Sintaxe Correta.\n\n";
    std::cout << "  Iniciando Analise Semantica...\n";
    rootProgram->checkSemantic();
    std::cout << "  Resultado: Analise Semantica concluida.\n\n";
  } else {
    std::cout << "  Resultado: Falha. Encontrados erros sintaticos.\n\n";
  }

  delete rootProgram;
  rootProgram = nullptr;
}

/*
   modoArquivo — lê um arquivo .src e tokeniza
*/
void modoArquivo(const std::string &caminho) {
  /*
     std::ifstream abre o arquivo para leitura.
  */
  std::ifstream arquivo(caminho);
  if (!arquivo.is_open()) {
    std::cerr << "Erro: nao foi possivel abrir '" << caminho << "'\n";
    return;
  }

  std::cout << "\n  Arquivo: " << caminho << "\n";

  /*
     Cria o lexer apontando para o arquivo
     O construtor de yyFlexLexer aceita um istream*
  */
  lexer = new yyFlexLexer(&arquivo, nullptr);
  rodarAnalise();
  delete lexer;
}

/* ══════════════════════════════════════════════════════════════
   modoInterativo — lê do teclado (std::cin)

   std::cin é o equivalente C++ do stdin em C.
   O yyFlexLexer aceita qualquer istream, então passamos
   &std::cin para ler do teclado.
   ══════════════════════════════════════════════════════════════ */
void modoInterativo() {
  std::cout << "\n";
  std::cout << "  +------------------------------------------+\n";
  std::cout << "  |   COMPILADOR DIDATICO — Modo Interativo  |\n";
  std::cout << "  |   Fase 5: Analise Sintatica e Semantica  |\n";
  std::cout << "  +------------------------------------------+\n";
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
  lexer = new yyFlexLexer(&std::cin, nullptr);
  rodarAnalise();
  delete lexer;

  std::cout << "  Sessao encerrada.\n\n";
}

/* ══════════════════════════════════════════════════════════════
   main — decide qual modo usar baseado nos argumentos

   argc → quantidade de argumentos da linha de comando
   argv → array de strings com os argumentos
     argv[0] = nome do executável
     argv[1] = arquivo .src (se fornecido)
   ══════════════════════════════════════════════════════════════ */
int main(int argc, char *argv[]) {

  if (argc >= 2) {
    /* Modo arquivo: ./compilador tests/programa.src */
    modoArquivo(argv[1]);
  } else {
    /* Modo interativo: ./compilador */
    modoInterativo();
  }

  return 0;
}