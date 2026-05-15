/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "sintatico.y"

#include <iostream>
#include <string>
#include "ast.h"

int yylex();
void yyerror(const char* s);
extern int get_linha();

extern ProgramNode* rootProgram;

#line 83 "sintatico.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "sintatico.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_KW_INT = 3,                     /* KW_INT  */
  YYSYMBOL_KW_FLOAT = 4,                   /* KW_FLOAT  */
  YYSYMBOL_KW_BOOL = 5,                    /* KW_BOOL  */
  YYSYMBOL_KW_STRING = 6,                  /* KW_STRING  */
  YYSYMBOL_KW_IF = 7,                      /* KW_IF  */
  YYSYMBOL_KW_ELSE = 8,                    /* KW_ELSE  */
  YYSYMBOL_KW_WHILE = 9,                   /* KW_WHILE  */
  YYSYMBOL_KW_ENDDO = 10,                  /* KW_ENDDO  */
  YYSYMBOL_KW_PRINT = 11,                  /* KW_PRINT  */
  YYSYMBOL_KW_RETURN = 12,                 /* KW_RETURN  */
  YYSYMBOL_LIT_INT = 13,                   /* LIT_INT  */
  YYSYMBOL_LIT_FLOAT = 14,                 /* LIT_FLOAT  */
  YYSYMBOL_LIT_STRING = 15,                /* LIT_STRING  */
  YYSYMBOL_LIT_TRUE = 16,                  /* LIT_TRUE  */
  YYSYMBOL_LIT_FALSE = 17,                 /* LIT_FALSE  */
  YYSYMBOL_LIT_CPF = 18,                   /* LIT_CPF  */
  YYSYMBOL_LIT_CNPJ = 19,                  /* LIT_CNPJ  */
  YYSYMBOL_LIT_EMAIL = 20,                 /* LIT_EMAIL  */
  YYSYMBOL_LIT_DATA = 21,                  /* LIT_DATA  */
  YYSYMBOL_LIT_HORA = 22,                  /* LIT_HORA  */
  YYSYMBOL_LIT_TEL = 23,                   /* LIT_TEL  */
  YYSYMBOL_LIT_CEP = 24,                   /* LIT_CEP  */
  YYSYMBOL_LIT_HEX = 25,                   /* LIT_HEX  */
  YYSYMBOL_LIT_RG = 26,                    /* LIT_RG  */
  YYSYMBOL_LIT_MOEDA = 27,                 /* LIT_MOEDA  */
  YYSYMBOL_LIT_URL = 28,                   /* LIT_URL  */
  YYSYMBOL_LIT_IP = 29,                    /* LIT_IP  */
  YYSYMBOL_LIT_PERCENT = 30,               /* LIT_PERCENT  */
  YYSYMBOL_IDENTIFICADOR = 31,             /* IDENTIFICADOR  */
  YYSYMBOL_OP_MAIS = 32,                   /* OP_MAIS  */
  YYSYMBOL_OP_MENOS = 33,                  /* OP_MENOS  */
  YYSYMBOL_OP_MULTI = 34,                  /* OP_MULTI  */
  YYSYMBOL_OP_DIVID = 35,                  /* OP_DIVID  */
  YYSYMBOL_OP_PORCENT = 36,                /* OP_PORCENT  */
  YYSYMBOL_OP_EQ = 37,                     /* OP_EQ  */
  YYSYMBOL_OP_NEQ = 38,                    /* OP_NEQ  */
  YYSYMBOL_OP_LT = 39,                     /* OP_LT  */
  YYSYMBOL_OP_GT = 40,                     /* OP_GT  */
  YYSYMBOL_OP_LE = 41,                     /* OP_LE  */
  YYSYMBOL_OP_GE = 42,                     /* OP_GE  */
  YYSYMBOL_OP_AND = 43,                    /* OP_AND  */
  YYSYMBOL_OP_OR = 44,                     /* OP_OR  */
  YYSYMBOL_OP_NOT = 45,                    /* OP_NOT  */
  YYSYMBOL_OP_ASSIGN = 46,                 /* OP_ASSIGN  */
  YYSYMBOL_LPAREN = 47,                    /* LPAREN  */
  YYSYMBOL_RPAREN = 48,                    /* RPAREN  */
  YYSYMBOL_LBRACE = 49,                    /* LBRACE  */
  YYSYMBOL_RBRACE = 50,                    /* RBRACE  */
  YYSYMBOL_SEMICOLON = 51,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 52,                     /* COMMA  */
  YYSYMBOL_UNKNOWN = 53,                   /* UNKNOWN  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_programa = 55,                  /* programa  */
  YYSYMBOL_lista_declaracoes = 56,         /* lista_declaracoes  */
  YYSYMBOL_declaracao = 57,                /* declaracao  */
  YYSYMBOL_declaracao_variavel = 58,       /* declaracao_variavel  */
  YYSYMBOL_tipo = 59,                      /* tipo  */
  YYSYMBOL_comando = 60,                   /* comando  */
  YYSYMBOL_comando_if = 61,                /* comando_if  */
  YYSYMBOL_comando_while = 62,             /* comando_while  */
  YYSYMBOL_comando_atribuicao = 63,        /* comando_atribuicao  */
  YYSYMBOL_comando_print = 64,             /* comando_print  */
  YYSYMBOL_comando_return = 65,            /* comando_return  */
  YYSYMBOL_bloco = 66,                     /* bloco  */
  YYSYMBOL_67_1 = 67,                      /* @1  */
  YYSYMBOL_lista_declaracoes_bloco = 68,   /* lista_declaracoes_bloco  */
  YYSYMBOL_token_especial_isolado = 69,    /* token_especial_isolado  */
  YYSYMBOL_expressao = 70,                 /* expressao  */
  YYSYMBOL_literal = 71                    /* literal  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  49
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   279

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  106

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   308


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    72,    72,    73,    77,    78,    82,    83,    84,    88,
      89,    93,    94,    95,    96,   100,   101,   102,   103,   104,
     108,   109,   113,   117,   121,   125,   129,   129,   130,   134,
     135,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   155,   156,   157,   158,   159,   160,
     161,   162,   163,   164,   165,   166,   167,   168,   169,   170,
     171,   175,   176,   177,   178,   179
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "KW_INT", "KW_FLOAT",
  "KW_BOOL", "KW_STRING", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_ENDDO",
  "KW_PRINT", "KW_RETURN", "LIT_INT", "LIT_FLOAT", "LIT_STRING",
  "LIT_TRUE", "LIT_FALSE", "LIT_CPF", "LIT_CNPJ", "LIT_EMAIL", "LIT_DATA",
  "LIT_HORA", "LIT_TEL", "LIT_CEP", "LIT_HEX", "LIT_RG", "LIT_MOEDA",
  "LIT_URL", "LIT_IP", "LIT_PERCENT", "IDENTIFICADOR", "OP_MAIS",
  "OP_MENOS", "OP_MULTI", "OP_DIVID", "OP_PORCENT", "OP_EQ", "OP_NEQ",
  "OP_LT", "OP_GT", "OP_LE", "OP_GE", "OP_AND", "OP_OR", "OP_NOT",
  "OP_ASSIGN", "LPAREN", "RPAREN", "LBRACE", "RBRACE", "SEMICOLON",
  "COMMA", "UNKNOWN", "$accept", "programa", "lista_declaracoes",
  "declaracao", "declaracao_variavel", "tipo", "comando", "comando_if",
  "comando_while", "comando_atribuicao", "comando_print", "comando_return",
  "bloco", "@1", "lista_declaracoes_bloco", "token_especial_isolado",
  "expressao", "literal", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-68)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      85,   -68,   -68,   -68,   -68,   -32,    -6,    -3,    55,   -68,
     -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,    -4,    45,    85,   -68,   -68,    15,   -68,   -68,
     -68,   -68,   -68,   -68,   -68,    55,    55,    55,   -68,   -68,
     -68,   -68,   -68,   -68,    55,    55,    86,   -68,    55,   -68,
     -68,   -40,   146,   163,   180,   -68,   197,    55,    55,    55,
      55,    55,    55,    55,    55,    55,    55,    55,    55,    55,
     -68,   106,    55,   -68,     0,     0,    -1,   -68,   -22,   -22,
     -68,   -68,   -68,   237,   237,     2,     2,     2,     2,   226,
     214,   -68,   126,     1,    39,   -68,   -68,   -68,   -68,    85,
       0,   -68,    -2,   -68,   -68,   -68
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       3,    11,    12,    13,    14,     0,     0,     0,     0,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    43,     0,     0,     2,     4,     6,     0,     7,    15,
      16,    17,    18,    19,     8,     0,     0,     0,    61,    62,
      63,    64,    65,    59,     0,     0,     0,    60,     0,     1,
       5,     0,     0,     0,     0,    57,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      25,     0,     0,    10,     0,     0,     0,    58,    44,    45,
      46,    47,    48,    49,    50,    51,    52,    53,    54,    55,
      56,    23,     0,    26,    20,    22,    24,     9,    28,     0,
       0,    29,     0,    21,    27,    30
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -68,   -68,   -68,   -24,   -68,   -68,   -68,   -68,   -68,   -68,
     -68,   -68,   -67,   -68,   -68,   -68,    -5,   -68
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    94,    99,   102,    34,    46,    47
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      50,     1,     2,     3,     4,     5,    72,     6,    95,     7,
       8,    73,    59,    60,    61,    35,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      52,    53,    54,   103,    57,    58,    59,    60,    61,    55,
      56,    36,    48,    71,    37,    49,    51,   100,   104,    93,
      96,    98,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,    92,    38,    39,
      40,    41,    42,     0,     0,   101,     0,     0,   105,     0,
       0,     0,     0,     0,     0,     0,    43,     0,     1,     2,
       3,     4,     5,     0,     6,     0,     7,     8,     0,     0,
      44,     0,    45,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,    70,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,    91,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,     0,     0,     0,    97,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,     0,     0,     0,    74,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,     0,     0,
       0,    75,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,     0,     0,     0,    76,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,     0,     0,     0,    77,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    57,
      58,    59,    60,    61,     0,     0,    64,    65,    66,    67
};

static const yytype_int8 yycheck[] =
{
      24,     3,     4,     5,     6,     7,    46,     9,    75,    11,
      12,    51,    34,    35,    36,    47,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      35,    36,    37,   100,    32,    33,    34,    35,    36,    44,
      45,    47,    46,    48,    47,     0,    31,     8,    50,    49,
      51,    50,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    -1,    -1,    72,    13,    14,
      15,    16,    17,    -1,    -1,    99,    -1,    -1,   102,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    31,    -1,     3,     4,
       5,     6,     7,    -1,     9,    -1,    11,    12,    -1,    -1,
      45,    -1,    47,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    -1,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    -1,    -1,    -1,    51,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    43,
      44,    -1,    -1,    -1,    48,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    48,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    42,    43,    44,    -1,    -1,    -1,    48,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    48,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,    43,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    42,    32,
      33,    34,    35,    36,    -1,    -1,    39,    40,    41,    42
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     9,    11,    12,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    69,    47,    47,    47,    13,    14,
      15,    16,    17,    31,    45,    47,    70,    71,    46,     0,
      57,    31,    70,    70,    70,    70,    70,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      51,    70,    46,    51,    48,    48,    48,    48,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    51,    70,    49,    66,    66,    51,    51,    50,    67,
       8,    57,    68,    66,    50,    57
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    57,    57,    58,
      58,    59,    59,    59,    59,    60,    60,    60,    60,    60,
      61,    61,    62,    63,    64,    65,    67,    66,    66,    68,
      68,    69,    69,    69,    69,    69,    69,    69,    69,    69,
      69,    69,    69,    69,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    71,    71,    71,    71,    71
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     1,     1,     1,     5,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       5,     7,     5,     4,     5,     3,     0,     4,     2,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     3,     1,
       1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* lista_declaracoes: declaracao  */
#line 77 "sintatico.y"
               { if ((yyvsp[0].stmt)) rootProgram->addStatement((yyvsp[0].stmt)); }
#line 1248 "sintatico.tab.c"
    break;

  case 5: /* lista_declaracoes: lista_declaracoes declaracao  */
#line 78 "sintatico.y"
                                   { if ((yyvsp[0].stmt)) rootProgram->addStatement((yyvsp[0].stmt)); }
#line 1254 "sintatico.tab.c"
    break;

  case 6: /* declaracao: declaracao_variavel  */
#line 82 "sintatico.y"
                        { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1260 "sintatico.tab.c"
    break;

  case 7: /* declaracao: comando  */
#line 83 "sintatico.y"
              { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1266 "sintatico.tab.c"
    break;

  case 8: /* declaracao: token_especial_isolado  */
#line 84 "sintatico.y"
                             { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1272 "sintatico.tab.c"
    break;

  case 9: /* declaracao_variavel: tipo IDENTIFICADOR OP_ASSIGN expressao SEMICOLON  */
#line 88 "sintatico.y"
                                                     { (yyval.stmt) = new VarDeclStmt(get_linha(), (yyvsp[-4].dataType), std::string((yyvsp[-3].sValue)), (yyvsp[-1].expr)); free((yyvsp[-3].sValue)); }
#line 1278 "sintatico.tab.c"
    break;

  case 10: /* declaracao_variavel: tipo IDENTIFICADOR SEMICOLON  */
#line 89 "sintatico.y"
                                   { (yyval.stmt) = new VarDeclStmt(get_linha(), (yyvsp[-2].dataType), std::string((yyvsp[-1].sValue)), nullptr); free((yyvsp[-1].sValue)); }
#line 1284 "sintatico.tab.c"
    break;

  case 11: /* tipo: KW_INT  */
#line 93 "sintatico.y"
           { (yyval.dataType) = DataType::INT; }
#line 1290 "sintatico.tab.c"
    break;

  case 12: /* tipo: KW_FLOAT  */
#line 94 "sintatico.y"
               { (yyval.dataType) = DataType::FLOAT; }
#line 1296 "sintatico.tab.c"
    break;

  case 13: /* tipo: KW_BOOL  */
#line 95 "sintatico.y"
              { (yyval.dataType) = DataType::BOOL; }
#line 1302 "sintatico.tab.c"
    break;

  case 14: /* tipo: KW_STRING  */
#line 96 "sintatico.y"
                { (yyval.dataType) = DataType::STRING; }
#line 1308 "sintatico.tab.c"
    break;

  case 15: /* comando: comando_if  */
#line 100 "sintatico.y"
               { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1314 "sintatico.tab.c"
    break;

  case 16: /* comando: comando_while  */
#line 101 "sintatico.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1320 "sintatico.tab.c"
    break;

  case 17: /* comando: comando_atribuicao  */
#line 102 "sintatico.y"
                         { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1326 "sintatico.tab.c"
    break;

  case 18: /* comando: comando_print  */
#line 103 "sintatico.y"
                    { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1332 "sintatico.tab.c"
    break;

  case 19: /* comando: comando_return  */
#line 104 "sintatico.y"
                     { (yyval.stmt) = (yyvsp[0].stmt); }
#line 1338 "sintatico.tab.c"
    break;

  case 20: /* comando_if: KW_IF LPAREN expressao RPAREN bloco  */
#line 108 "sintatico.y"
                                        { (yyval.stmt) = new IfStmt(get_linha(), (yyvsp[-2].expr), (yyvsp[0].stmt), nullptr); }
#line 1344 "sintatico.tab.c"
    break;

  case 21: /* comando_if: KW_IF LPAREN expressao RPAREN bloco KW_ELSE bloco  */
#line 109 "sintatico.y"
                                                        { (yyval.stmt) = new IfStmt(get_linha(), (yyvsp[-4].expr), (yyvsp[-2].stmt), (yyvsp[0].stmt)); }
#line 1350 "sintatico.tab.c"
    break;

  case 22: /* comando_while: KW_WHILE LPAREN expressao RPAREN bloco  */
#line 113 "sintatico.y"
                                           { (yyval.stmt) = new WhileStmt(get_linha(), (yyvsp[-2].expr), (yyvsp[0].stmt)); }
#line 1356 "sintatico.tab.c"
    break;

  case 23: /* comando_atribuicao: IDENTIFICADOR OP_ASSIGN expressao SEMICOLON  */
#line 117 "sintatico.y"
                                                { (yyval.stmt) = new AssignStmt(get_linha(), std::string((yyvsp[-3].sValue)), (yyvsp[-1].expr)); free((yyvsp[-3].sValue)); }
#line 1362 "sintatico.tab.c"
    break;

  case 24: /* comando_print: KW_PRINT LPAREN expressao RPAREN SEMICOLON  */
#line 121 "sintatico.y"
                                               { (yyval.stmt) = new PrintStmt(get_linha(), (yyvsp[-2].expr)); }
#line 1368 "sintatico.tab.c"
    break;

  case 25: /* comando_return: KW_RETURN expressao SEMICOLON  */
#line 125 "sintatico.y"
                                  { (yyval.stmt) = new ReturnStmt(get_linha(), (yyvsp[-1].expr)); }
#line 1374 "sintatico.tab.c"
    break;

  case 26: /* @1: %empty  */
#line 129 "sintatico.y"
           { (yyval.stmt) = new BlockStmt(get_linha()); }
#line 1380 "sintatico.tab.c"
    break;

  case 27: /* bloco: LBRACE @1 lista_declaracoes_bloco RBRACE  */
#line 129 "sintatico.y"
                                                                                     { (yyval.stmt) = (yyvsp[-2].stmt); }
#line 1386 "sintatico.tab.c"
    break;

  case 28: /* bloco: LBRACE RBRACE  */
#line 130 "sintatico.y"
                    { (yyval.stmt) = new BlockStmt(get_linha()); }
#line 1392 "sintatico.tab.c"
    break;

  case 29: /* lista_declaracoes_bloco: declaracao  */
#line 134 "sintatico.y"
               { if ((yyvsp[0].stmt)) ((BlockStmt*)(yyvsp[-1].stmt))->addStatement((yyvsp[0].stmt)); }
#line 1398 "sintatico.tab.c"
    break;

  case 30: /* lista_declaracoes_bloco: lista_declaracoes_bloco declaracao  */
#line 135 "sintatico.y"
                                         { if ((yyvsp[0].stmt)) ((BlockStmt*)(yyvsp[-2].stmt))->addStatement((yyvsp[0].stmt)); }
#line 1404 "sintatico.tab.c"
    break;

  case 31: /* token_especial_isolado: LIT_CPF  */
#line 139 "sintatico.y"
            { (yyval.stmt) = nullptr; }
#line 1410 "sintatico.tab.c"
    break;

  case 32: /* token_especial_isolado: LIT_CNPJ  */
#line 140 "sintatico.y"
               { (yyval.stmt) = nullptr; }
#line 1416 "sintatico.tab.c"
    break;

  case 33: /* token_especial_isolado: LIT_EMAIL  */
#line 141 "sintatico.y"
                { (yyval.stmt) = nullptr; }
#line 1422 "sintatico.tab.c"
    break;

  case 34: /* token_especial_isolado: LIT_DATA  */
#line 142 "sintatico.y"
               { (yyval.stmt) = nullptr; }
#line 1428 "sintatico.tab.c"
    break;

  case 35: /* token_especial_isolado: LIT_HORA  */
#line 143 "sintatico.y"
               { (yyval.stmt) = nullptr; }
#line 1434 "sintatico.tab.c"
    break;

  case 36: /* token_especial_isolado: LIT_TEL  */
#line 144 "sintatico.y"
              { (yyval.stmt) = nullptr; }
#line 1440 "sintatico.tab.c"
    break;

  case 37: /* token_especial_isolado: LIT_CEP  */
#line 145 "sintatico.y"
              { (yyval.stmt) = nullptr; }
#line 1446 "sintatico.tab.c"
    break;

  case 38: /* token_especial_isolado: LIT_HEX  */
#line 146 "sintatico.y"
              { (yyval.stmt) = nullptr; }
#line 1452 "sintatico.tab.c"
    break;

  case 39: /* token_especial_isolado: LIT_RG  */
#line 147 "sintatico.y"
             { (yyval.stmt) = nullptr; }
#line 1458 "sintatico.tab.c"
    break;

  case 40: /* token_especial_isolado: LIT_MOEDA  */
#line 148 "sintatico.y"
                { (yyval.stmt) = nullptr; }
#line 1464 "sintatico.tab.c"
    break;

  case 41: /* token_especial_isolado: LIT_URL  */
#line 149 "sintatico.y"
              { (yyval.stmt) = nullptr; }
#line 1470 "sintatico.tab.c"
    break;

  case 42: /* token_especial_isolado: LIT_IP  */
#line 150 "sintatico.y"
             { (yyval.stmt) = nullptr; }
#line 1476 "sintatico.tab.c"
    break;

  case 43: /* token_especial_isolado: LIT_PERCENT  */
#line 151 "sintatico.y"
                  { (yyval.stmt) = nullptr; }
#line 1482 "sintatico.tab.c"
    break;

  case 44: /* expressao: expressao OP_MAIS expressao  */
#line 155 "sintatico.y"
                                { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::ADD, (yyvsp[0].expr)); }
#line 1488 "sintatico.tab.c"
    break;

  case 45: /* expressao: expressao OP_MENOS expressao  */
#line 156 "sintatico.y"
                                   { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::SUB, (yyvsp[0].expr)); }
#line 1494 "sintatico.tab.c"
    break;

  case 46: /* expressao: expressao OP_MULTI expressao  */
#line 157 "sintatico.y"
                                   { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::MUL, (yyvsp[0].expr)); }
#line 1500 "sintatico.tab.c"
    break;

  case 47: /* expressao: expressao OP_DIVID expressao  */
#line 158 "sintatico.y"
                                   { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::DIV, (yyvsp[0].expr)); }
#line 1506 "sintatico.tab.c"
    break;

  case 48: /* expressao: expressao OP_PORCENT expressao  */
#line 159 "sintatico.y"
                                     { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::MOD, (yyvsp[0].expr)); }
#line 1512 "sintatico.tab.c"
    break;

  case 49: /* expressao: expressao OP_EQ expressao  */
#line 160 "sintatico.y"
                                { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::EQ, (yyvsp[0].expr)); }
#line 1518 "sintatico.tab.c"
    break;

  case 50: /* expressao: expressao OP_NEQ expressao  */
#line 161 "sintatico.y"
                                 { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::NEQ, (yyvsp[0].expr)); }
#line 1524 "sintatico.tab.c"
    break;

  case 51: /* expressao: expressao OP_LT expressao  */
#line 162 "sintatico.y"
                                { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::LT, (yyvsp[0].expr)); }
#line 1530 "sintatico.tab.c"
    break;

  case 52: /* expressao: expressao OP_GT expressao  */
#line 163 "sintatico.y"
                                { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::GT, (yyvsp[0].expr)); }
#line 1536 "sintatico.tab.c"
    break;

  case 53: /* expressao: expressao OP_LE expressao  */
#line 164 "sintatico.y"
                                { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::LE, (yyvsp[0].expr)); }
#line 1542 "sintatico.tab.c"
    break;

  case 54: /* expressao: expressao OP_GE expressao  */
#line 165 "sintatico.y"
                                { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::GE, (yyvsp[0].expr)); }
#line 1548 "sintatico.tab.c"
    break;

  case 55: /* expressao: expressao OP_AND expressao  */
#line 166 "sintatico.y"
                                 { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::AND, (yyvsp[0].expr)); }
#line 1554 "sintatico.tab.c"
    break;

  case 56: /* expressao: expressao OP_OR expressao  */
#line 167 "sintatico.y"
                                { (yyval.expr) = new BinaryExpr(get_linha(), (yyvsp[-2].expr), Operator::OR, (yyvsp[0].expr)); }
#line 1560 "sintatico.tab.c"
    break;

  case 57: /* expressao: OP_NOT expressao  */
#line 168 "sintatico.y"
                       { (yyval.expr) = new UnaryExpr(get_linha(), Operator::NOT, (yyvsp[0].expr)); }
#line 1566 "sintatico.tab.c"
    break;

  case 58: /* expressao: LPAREN expressao RPAREN  */
#line 169 "sintatico.y"
                              { (yyval.expr) = (yyvsp[-1].expr); }
#line 1572 "sintatico.tab.c"
    break;

  case 59: /* expressao: IDENTIFICADOR  */
#line 170 "sintatico.y"
                    { (yyval.expr) = new IdentifierExpr(get_linha(), std::string((yyvsp[0].sValue))); free((yyvsp[0].sValue)); }
#line 1578 "sintatico.tab.c"
    break;

  case 60: /* expressao: literal  */
#line 171 "sintatico.y"
              { (yyval.expr) = (yyvsp[0].expr); }
#line 1584 "sintatico.tab.c"
    break;

  case 61: /* literal: LIT_INT  */
#line 175 "sintatico.y"
            { (yyval.expr) = new LiteralIntExpr(get_linha(), (yyvsp[0].iValue)); }
#line 1590 "sintatico.tab.c"
    break;

  case 62: /* literal: LIT_FLOAT  */
#line 176 "sintatico.y"
                { (yyval.expr) = new LiteralFloatExpr(get_linha(), (yyvsp[0].fValue)); }
#line 1596 "sintatico.tab.c"
    break;

  case 63: /* literal: LIT_STRING  */
#line 177 "sintatico.y"
                 { (yyval.expr) = new LiteralStringExpr(get_linha(), std::string((yyvsp[0].sValue))); free((yyvsp[0].sValue)); }
#line 1602 "sintatico.tab.c"
    break;

  case 64: /* literal: LIT_TRUE  */
#line 178 "sintatico.y"
               { (yyval.expr) = new LiteralBoolExpr(get_linha(), true); }
#line 1608 "sintatico.tab.c"
    break;

  case 65: /* literal: LIT_FALSE  */
#line 179 "sintatico.y"
                { (yyval.expr) = new LiteralBoolExpr(get_linha(), false); }
#line 1614 "sintatico.tab.c"
    break;


#line 1618 "sintatico.tab.c"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 182 "sintatico.y"


void yyerror(const char* s) {
    std::cerr << "  ERRO SINTATICO: " << s << " na linha " << get_linha() << "\n";
}
