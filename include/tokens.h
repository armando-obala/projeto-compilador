#pragma once
/* ╔══════════════════════════════════════════════════════════════╗
   ║  tokens.h  —  Definição de todos os tipos de token (C++)     ║
   ║                                                              ║
   ║  IMPORTANTE: valores começam em 256 para não conflitar       ║
   ║  com os caracteres ASCII que o Flex usa internamente.        ║
   ╚══════════════════════════════════════════════════════════════╝ */

#include <string>

/* ── Enum de tipos de token ─────────────────────────────────────
   enum class é mais seguro que enum simples em C++.
   Com enum class você PRECISA escrever TokenType::KW_INT,
   o que evita confusão com outros nomes no programa.           */
enum class TokenType : int {

    END_OF_FILE = 256,  /* Fim do arquivo                        */

    /* ── Palavras-chave ────────────────────────────────────────
       Palavras RESERVADAS — não podem ser usadas como
       nome de variável pelo programador.                        */
    KW_INT,       /* int    */
    KW_FLOAT,     /* float  */
    KW_BOOL,      /* bool   */
    KW_STRING,    /* string */
    KW_IF,        /* if     */
    KW_ELSE,      /* else   */
    KW_WHILE,     /* while  */
    KW_ENDDO,     /* enddo  */
    KW_PRINT,     /* print  */
    KW_RETURN,    /* return */

    /* ── Literais ──────────────────────────────────────────────
       Valores escritos diretamente no código.
       Ex: 42 → LIT_INT, 3.14 → LIT_FLOAT, "oi" → LIT_STRING   */
    LIT_INT,
    LIT_FLOAT,
    LIT_STRING,
    LIT_TRUE,
    LIT_FALSE,

    /* ════════════════════════════════════════════════════════
       ★ TOKENS ESPECIAIS — ÁREA DE EXTENSÃO ★

       Aqui ficam tokens com padrão específico (CPF, email, etc).

       COMO ADICIONAR UM NOVO TOKEN:
         1. Adicione o valor aqui     →  LIT_SEU_TOKEN,
         2. Adicione o nome abaixo    →  em tokenTypeName()
         3. Adicione a regra          →  em lexico.l
    ════════════════════════════════════════════════════════ */
    LIT_CPF,      /* CPF:       000.000.000-00              */
    LIT_CNPJ,     /* CNPJ:      00.000.000/0000-00          */
    LIT_EMAIL,    /* Email:     usuario@dominio.com         */
    LIT_DATA,     /* Data:      DD/MM/AAAA                  */
    LIT_HORA,     /* Hora:      HH:MM ou HH:MM:SS           */
    LIT_TEL,      /* Telefone:  (00)00000-0000              */
    LIT_CEP,      /* CEP:       00000-000                   */
    LIT_HEX,      /* Hex:       0xFF                        */
    /* ════════════════════════════════════════════════════
       ★ FIM DA ÁREA DE EXTENSÃO ★
    ════════════════════════════════════════════════════ */

    /* ── Identificador ─────────────────────────────────────────
       Nome criado pelo programador: variáveis, funções.
       Começa com letra ou _, seguido de letras/dígitos/_        */
    IDENTIFICADOR,

    /* ── Operadores Aritméticos ─────────────────────────────── */
    OP_MAIS,      /* +  */
    OP_MENOS,     /* -  */
    OP_MULTI,     /* *  */
    OP_DIVID,     /* /  */
    OP_PORCENT,   /* %  */

    /* ── Operadores Relacionais ─────────────────────────────────
       Os de 2 chars (==, !=, <=, >=) são reconhecidos antes
       dos de 1 char (=, <, >) no lexico.l — veja os comentários
       lá para entender o motivo.                                */
    OP_EQ,        /* == */
    OP_NEQ,       /* != */
    OP_LT,        /* <  */
    OP_GT,        /* >  */
    OP_LE,        /* <= */
    OP_GE,        /* >= */

    /* ── Operadores Lógicos ─────────────────────────────────── */
    OP_AND,       /* && */
    OP_OR,        /* || */
    OP_NOT,       /* !  */

    /* ── Atribuição ─────────────────────────────────────────── */
    OP_ASSIGN,    /* =  */

    /* ── Delimitadores ──────────────────────────────────────── */
    LPAREN,       /* (  */
    RPAREN,       /* )  */
    LBRACE,       /* {  */
    RBRACE,       /* }  */
    SEMICOLON,    /* ;  */
    COMMA,        /* ,  */

    /* ── Erro ───────────────────────────────────────────────── */
    UNKNOWN
};

/* ── Função de conversão tipo → nome ────────────────────────────
   Implementada no main.cpp.
   Retorna uma std::string legível para cada TokenType.
   Ex: TokenType::KW_INT → "KW_INT"                             */
std::string tokenTypeName(TokenType t);