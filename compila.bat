win_flex lexico.l
g++ -std=c++17 -Wall -Iinclude -IC:\winflexbison -o compilador lex.yy.cc src/main.cpp