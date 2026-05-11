/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SINTATICO_TAB_H_INCLUDED
# define YY_YY_SINTATICO_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "sintatico.y"

    #include "ast.h"

#line 53 "sintatico.tab.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    KW_INT = 258,                  /* KW_INT  */
    KW_FLOAT = 259,                /* KW_FLOAT  */
    KW_BOOL = 260,                 /* KW_BOOL  */
    KW_STRING = 261,               /* KW_STRING  */
    KW_IF = 262,                   /* KW_IF  */
    KW_ELSE = 263,                 /* KW_ELSE  */
    KW_WHILE = 264,                /* KW_WHILE  */
    KW_ENDDO = 265,                /* KW_ENDDO  */
    KW_PRINT = 266,                /* KW_PRINT  */
    KW_RETURN = 267,               /* KW_RETURN  */
    LIT_INT = 268,                 /* LIT_INT  */
    LIT_FLOAT = 269,               /* LIT_FLOAT  */
    LIT_STRING = 270,              /* LIT_STRING  */
    LIT_TRUE = 271,                /* LIT_TRUE  */
    LIT_FALSE = 272,               /* LIT_FALSE  */
    LIT_CPF = 273,                 /* LIT_CPF  */
    LIT_CNPJ = 274,                /* LIT_CNPJ  */
    LIT_EMAIL = 275,               /* LIT_EMAIL  */
    LIT_DATA = 276,                /* LIT_DATA  */
    LIT_HORA = 277,                /* LIT_HORA  */
    LIT_TEL = 278,                 /* LIT_TEL  */
    LIT_CEP = 279,                 /* LIT_CEP  */
    LIT_HEX = 280,                 /* LIT_HEX  */
    LIT_RG = 281,                  /* LIT_RG  */
    LIT_MOEDA = 282,               /* LIT_MOEDA  */
    LIT_URL = 283,                 /* LIT_URL  */
    LIT_IP = 284,                  /* LIT_IP  */
    LIT_PERCENT = 285,             /* LIT_PERCENT  */
    IDENTIFICADOR = 286,           /* IDENTIFICADOR  */
    OP_MAIS = 287,                 /* OP_MAIS  */
    OP_MENOS = 288,                /* OP_MENOS  */
    OP_MULTI = 289,                /* OP_MULTI  */
    OP_DIVID = 290,                /* OP_DIVID  */
    OP_PORCENT = 291,              /* OP_PORCENT  */
    OP_EQ = 292,                   /* OP_EQ  */
    OP_NEQ = 293,                  /* OP_NEQ  */
    OP_LT = 294,                   /* OP_LT  */
    OP_GT = 295,                   /* OP_GT  */
    OP_LE = 296,                   /* OP_LE  */
    OP_GE = 297,                   /* OP_GE  */
    OP_AND = 298,                  /* OP_AND  */
    OP_OR = 299,                   /* OP_OR  */
    OP_NOT = 300,                  /* OP_NOT  */
    OP_ASSIGN = 301,               /* OP_ASSIGN  */
    LPAREN = 302,                  /* LPAREN  */
    RPAREN = 303,                  /* RPAREN  */
    LBRACE = 304,                  /* LBRACE  */
    RBRACE = 305,                  /* RBRACE  */
    SEMICOLON = 306,               /* SEMICOLON  */
    COMMA = 307,                   /* COMMA  */
    UNKNOWN = 308                  /* UNKNOWN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 14 "sintatico.y"

    int iValue;
    float fValue;
    char* sValue;
    bool bValue;
    class Expr* expr;
    class Stmt* stmt;
    DataType dataType;
    Operator opType;

#line 134 "sintatico.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_SINTATICO_TAB_H_INCLUDED  */
