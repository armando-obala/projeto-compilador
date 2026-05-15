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
#include <FlexLexer.h>

extern int yyparse();

yyFlexLexer* lexer;

int yylex() { return lexer->yylex(); }
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

void modoArquivo(const std::string &caminho) {
  std::ifstream arquivo(caminho);
  if (!arquivo.is_open()) {
    std::cerr << "Erro: nao foi possivel abrir '" << caminho << "'\n";
    return;
  }

  std::cout << "\n  Arquivo: " << caminho << "\n";

  lexer = new yyFlexLexer(&arquivo, nullptr);
  rodarAnalise();
  delete lexer;
}

void modoInterativo() {
  std::cout << "\n";
  std::cout << "  +------------------------------------------+\n";
  std::cout << "  |   COMPILADOR DIDATICO - Modo Interativo  |\n";
  std::cout << "  |   Fase 5: Analise Sintatica e Semantica  |\n";
  std::cout << "  +------------------------------------------+\n";
  std::cout << "\n";
  std::cout << "  Digite seu codigo e pressione Enter.\n";
  std::cout << "  Para sair: Ctrl+Z + Enter (Windows)\n";
  std::cout << "             Ctrl+D        (Linux/Mac)\n";
  std::cout << "\n";

  lexer = new yyFlexLexer(&std::cin, nullptr);
  rodarAnalise();
  delete lexer;

  std::cout << "  Sessao encerrada.\n\n";
}

int main(int argc, char *argv[]) {
  if (argc >= 2) {
    modoArquivo(argv[1]);
  } else {
    modoInterativo();
  }

  return 0;
}