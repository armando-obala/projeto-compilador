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

# ── Passo 1: Flex lê lexico.l e gera lex.yy.cc ──────────────────
# Com %option c++ o Flex gera lex.yy.cc (com dois c) em vez de
# lex.yy.c — por isso o arquivo de saída tem extensão .cc
lex.yy.cc: lexico.l
	$(LEX) lexico.l

# ── Passo 2: g++ compila lex.yy.cc + main.cpp ───────────────────
$(TARGET): lex.yy.cc src/main.cpp include/tokens.h
	$(CXX) $(CXXFLAGS) -o $(TARGET) lex.yy.cc src/main.cpp

# ── Modo arquivo ─────────────────────────────────────────────────
test: $(TARGET)
	./$(TARGET) tests/programa.src

# ── Modo interativo ──────────────────────────────────────────────
interativo: $(TARGET)
	./$(TARGET)

# ── Limpeza ──────────────────────────────────────────────────────
clean:
	rm -f $(TARGET) lex.yy.cc