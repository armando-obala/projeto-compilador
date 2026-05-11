%{
#include <iostream>
#include <string>
#include <cstring>
#include "ast.h"
#include "sintatico.tab.h"
%}

%option c++
%option noyywrap
%option yylineno

DIGITO      [0-9]
LETRA       [a-zA-Z_]
ALFANUM     [a-zA-Z0-9_]

CPF_PAD     {DIGITO}{3}"."{DIGITO}{3}"."{DIGITO}{3}"-"{DIGITO}{2}
CNPJ_PAD    {DIGITO}{2}"."{DIGITO}{3}"."{DIGITO}{3}"/"{DIGITO}{4}"-"{DIGITO}{2}
EMAIL_PAD   [a-zA-Z0-9._%+-]+"@"[a-zA-Z0-9.-]+"."+[a-zA-Z]{2,}
DATA_PAD    {DIGITO}{2}"/"{DIGITO}{2}"/"{DIGITO}{4}
HORA_PAD    {DIGITO}{2}":"{DIGITO}{2}(":"{DIGITO}{2})?
TEL_PAD     "("+{DIGITO}{2}+")"+{DIGITO}{4,5}"-"{DIGITO}{4}
CEP_PAD     {DIGITO}{5}"-"{DIGITO}{3}
HEX_PAD     "0"[xX][0-9a-fA-F]+
RG_PAD      {DIGITO}{2}"."{DIGITO}{3}"."{DIGITO}{3}"-"{DIGITO}
MOEDA_PAD   "R\$"[ \t]?{DIGITO}{1,3}("."{DIGITO}{3})*(","{DIGITO}{2})?
URL_PAD     (http|https)"://"[^ \t\r\n]+|"www."[^ \t\r\n]+
IP_PAD      {DIGITO}{1,3}"."{DIGITO}{1,3}"."{DIGITO}{1,3}"."{DIGITO}{1,3}
PERCENT_PAD {DIGITO}+"%"

%%

 /* PALAVRAS-CHAVE — devem vir antes de IDENTIFICADOR */
"int"       { return KW_INT;    }
"float"     { return KW_FLOAT;  }
"bool"      { return KW_BOOL;   }
"string"    { return KW_STRING; }
"if"        { return KW_IF;     }
"else"      { return KW_ELSE;   }
"while"     { return KW_WHILE;  }
"enddo"     { return KW_ENDDO;  }
"print"     { return KW_PRINT;  }
"return"    { return KW_RETURN; }
"true"      { return LIT_TRUE;  }
"false"     { return LIT_FALSE; }

 /* TOKENS ESPECIAIS — adicione novos padroes aqui */
{CPF_PAD}   { return LIT_CPF;   }
{CNPJ_PAD}  { return LIT_CNPJ;  }
{EMAIL_PAD} { return LIT_EMAIL;  }
{DATA_PAD}  { return LIT_DATA;   }
{HORA_PAD}  { return LIT_HORA;   }
{TEL_PAD}   { return LIT_TEL;    }
{CEP_PAD}   { return LIT_CEP;    }
{HEX_PAD}   { return LIT_HEX;    }
{RG_PAD}    { return LIT_RG;     }
{MOEDA_PAD} { return LIT_MOEDA;  }
{URL_PAD}   { return LIT_URL;    }
{IP_PAD}    { return LIT_IP;     }
{PERCENT_PAD} { return LIT_PERCENT; }

 /* LITERAIS NUMERICOS — float antes de int */
{DIGITO}+"."{DIGITO}+   { yylval.fValue = std::stof(yytext); return LIT_FLOAT;  }
{DIGITO}+               { yylval.iValue = std::stoi(yytext); return LIT_INT;    }

 /* STRING */
\"[^\"]*\"  { yylval.sValue = strdup(yytext); return LIT_STRING; }

 /* IDENTIFICADOR — depois das keywords */
{LETRA}{ALFANUM}*   { yylval.sValue = strdup(yytext); return IDENTIFICADOR; }

 /* OPERADORES DE 2 CHARS — devem vir antes dos de 1 char */
"=="    { return OP_EQ;  }
"!="    { return OP_NEQ; }
"<="    { return OP_LE;  }
">="    { return OP_GE;  }
"&&"    { return OP_AND; }
"||"    { return OP_OR;  }

 /* OPERADORES DE 1 CHAR */
"="     { return OP_ASSIGN;  }
"+"     { return OP_MAIS;    }
"-"     { return OP_MENOS;   }
"*"     { return OP_MULTI;   }
"/"     { return OP_DIVID;   }
"%"     { return OP_PORCENT; }
"<"     { return OP_LT;      }
">"     { return OP_GT;      }
"!"     { return OP_NOT;     }

 /* DELIMITADORES */
"("     { return LPAREN;    }
")"     { return RPAREN;    }
"{"     { return LBRACE;    }
"}"     { return RBRACE;    }
";"     { return SEMICOLON; }
","     { return COMMA;     }

 /* COMENTARIOS — ignorados */
"//".*                      { }
"/*"([^*]|\*+[^*/])*\*+"/"  { }

 /* ESPACOS — ignorados */
[ \t\r\n]+  { }

 /* CARACTERE DESCONHECIDO — sempre por ultimo */
.   {
        std::cerr << "  ERRO LEXICO [linha " << yylineno
                  << "]: caractere nao reconhecido: '"
                  << yytext << "'\n";
        return UNKNOWN;
    }

%%
