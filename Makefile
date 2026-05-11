# ╔══════════════════════════════════════════════════════════════╗
# ║  Makefile — Compilador Didático (Flex + C++)                 ║
# ║                                                              ║
# ║  DIFERENÇA do Makefile C:                                   ║
# ║    - Usa g++ em vez de gcc                                  ║
# ║    - Compila main.cpp em vez de main.c                      ║
# ║    - Flag -std=c++17 para C++ moderno                       ║
# ║                                                              ║
# ║  COMANDOS:                                                   ║
# ║    make              → compila tudo                         ║
# ║    make test         → roda com o arquivo de teste          ║
# ║    make interativo   → abre o modo interativo               ║
# ║    make clean        → apaga arquivos gerados               ║
# ╚══════════════════════════════════════════════════════════════╝

CXX     = g++
CXXFLAGS= -std=c++17 -Wall -Iinclude -IC:\winflexbison
TARGET  = compilador

# win_flex para Windows (winflexbison3)
# flex    para Linux/Mac — troque se necessário
LEX     = win_flex

all: $(TARGET)

# ── Passo 1: Bison lê sintatico.y e gera sintatico.tab.c / sintatico.tab.h ──────
sintatico.tab.c sintatico.tab.h: sintatico.y
	win_bison -d sintatico.y

# ── Passo 2: Flex lê lexico.l e gera lex.yy.cc ──────────────────
lex.yy.cc: lexico.l sintatico.tab.h
	$(LEX) lexico.l

# ── Passo 3: g++ compila tudo ────────────────────────────────────
$(TARGET): sintatico.tab.c lex.yy.cc src/main.cpp src/ast.cpp src/symtable.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) sintatico.tab.c lex.yy.cc src/main.cpp src/ast.cpp src/symtable.cpp

# ── Modo arquivo ─────────────────────────────────────────────────
test: $(TARGET)
	./$(TARGET) tests/programa.src

# ── Modo interativo ──────────────────────────────────────────────
interativo: $(TARGET)
	./$(TARGET)

# ── Limpeza ──────────────────────────────────────────────────────
clean:
	rm -f $(TARGET) lex.yy.cc sintatico.tab.c sintatico.tab.h