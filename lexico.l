%{
#include <iostream>
#include <string>
#include "tokens.h"
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
"int"       { return (int)TokenType::KW_INT;    }
"float"     { return (int)TokenType::KW_FLOAT;  }
"bool"      { return (int)TokenType::KW_BOOL;   }
"string"    { return (int)TokenType::KW_STRING; }
"if"        { return (int)TokenType::KW_IF;     }
"else"      { return (int)TokenType::KW_ELSE;   }
"while"     { return (int)TokenType::KW_WHILE;  }
"enddo"     { return (int)TokenType::KW_ENDDO;  }
"print"     { return (int)TokenType::KW_PRINT;  }
"return"    { return (int)TokenType::KW_RETURN; }
"true"      { return (int)TokenType::LIT_TRUE;  }
"false"     { return (int)TokenType::LIT_FALSE; }

 /* TOKENS ESPECIAIS — adicione novos padroes aqui */
{CPF_PAD}   { return (int)TokenType::LIT_CPF;   }
{CNPJ_PAD}  { return (int)TokenType::LIT_CNPJ;  }
{EMAIL_PAD} { return (int)TokenType::LIT_EMAIL;  }
{DATA_PAD}  { return (int)TokenType::LIT_DATA;   }
{HORA_PAD}  { return (int)TokenType::LIT_HORA;   }
{TEL_PAD}   { return (int)TokenType::LIT_TEL;    }
{CEP_PAD}   { return (int)TokenType::LIT_CEP;    }
{HEX_PAD}   { return (int)TokenType::LIT_HEX;    }
{RG_PAD}    { return (int)TokenType::LIT_RG;     }
{MOEDA_PAD} { return (int)TokenType::LIT_MOEDA;  }
{URL_PAD}   { return (int)TokenType::LIT_URL;    }
{IP_PAD}    { return (int)TokenType::LIT_IP;     }
{PERCENT_PAD} { return (int)TokenType::LIT_PERCENT; }

 /* LITERAIS NUMERICOS — float antes de int */
{DIGITO}+"."{DIGITO}+   { return (int)TokenType::LIT_FLOAT;  }
{DIGITO}+               { return (int)TokenType::LIT_INT;    }

 /* STRING */
\"[^\"]*\"  { return (int)TokenType::LIT_STRING; }

 /* IDENTIFICADOR — depois das keywords */
{LETRA}{ALFANUM}*   { return (int)TokenType::IDENTIFICADOR; }

 /* OPERADORES DE 2 CHARS — devem vir antes dos de 1 char */
"=="    { return (int)TokenType::OP_EQ;  }
"!="    { return (int)TokenType::OP_NEQ; }
"<="    { return (int)TokenType::OP_LE;  }
">="    { return (int)TokenType::OP_GE;  }
"&&"    { return (int)TokenType::OP_AND; }
"||"    { return (int)TokenType::OP_OR;  }

 /* OPERADORES DE 1 CHAR */
"="     { return (int)TokenType::OP_ASSIGN;  }
"+"     { return (int)TokenType::OP_MAIS;    }
"-"     { return (int)TokenType::OP_MENOS;   }
"*"     { return (int)TokenType::OP_MULTI;   }
"/"     { return (int)TokenType::OP_DIVID;   }
"%"     { return (int)TokenType::OP_PORCENT; }
"<"     { return (int)TokenType::OP_LT;      }
">"     { return (int)TokenType::OP_GT;      }
"!"     { return (int)TokenType::OP_NOT;     }

 /* DELIMITADORES */
"("     { return (int)TokenType::LPAREN;    }
")"     { return (int)TokenType::RPAREN;    }
"{"     { return (int)TokenType::LBRACE;    }
"}"     { return (int)TokenType::RBRACE;    }
";"     { return (int)TokenType::SEMICOLON; }
","     { return (int)TokenType::COMMA;     }

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
        return (int)TokenType::UNKNOWN;
    }

%%