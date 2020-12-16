/* A Bison parser, made by GNU Bison 3.7.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
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
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 9 "program6.ypp"

  #include <iostream>
  #include <string>
  #include <vector>
  #include <FlexLexer.h>
  #include "Node.hpp"

  using std::vector;
  using std::string;
  using std::cout;
  using std::cerr;
  using std::endl;

  extern Root tree;
  extern yyFlexLexer scanner;
  #define yylex() scanner.yylex()
  #define YYERROR_VERBOSE 1
  void yyerror(const char*);


#line 92 "program6.tab.cpp"

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

#include "program6.tab.hpp"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ID = 3,                         /* ID  */
  YYSYMBOL_NUM = 4,                        /* NUM  */
  YYSYMBOL_CLASS = 5,                      /* CLASS  */
  YYSYMBOL_RBRACK = 6,                     /* RBRACK  */
  YYSYMBOL_LBRACK = 7,                     /* LBRACK  */
  YYSYMBOL_INT = 8,                        /* INT  */
  YYSYMBOL_COMMA = 9,                      /* COMMA  */
  YYSYMBOL_THIS = 10,                      /* THIS  */
  YYSYMBOL_DOT = 11,                       /* DOT  */
  YYSYMBOL_LPARAM = 12,                    /* LPARAM  */
  YYSYMBOL_RPARAM = 13,                    /* RPARAM  */
  YYSYMBOL_SEMI = 14,                      /* SEMI  */
  YYSYMBOL_CSB = 15,                       /* CSB  */
  YYSYMBOL_VOID = 16,                      /* VOID  */
  YYSYMBOL_PRINT = 17,                     /* PRINT  */
  YYSYMBOL_ELSE = 18,                      /* ELSE  */
  YYSYMBOL_WHILE = 19,                     /* WHILE  */
  YYSYMBOL_RET = 20,                       /* RET  */
  YYSYMBOL_IF = 21,                        /* IF  */
  YYSYMBOL_OSB = 22,                       /* OSB  */
  YYSYMBOL_NLL = 23,                       /* NLL  */
  YYSYMBOL_READ = 24,                      /* READ  */
  YYSYMBOL_NEW = 25,                       /* NEW  */
  YYSYMBOL_MUL = 26,                       /* MUL  */
  YYSYMBOL_DIV = 27,                       /* DIV  */
  YYSYMBOL_ADD = 28,                       /* ADD  */
  YYSYMBOL_MOD = 29,                       /* MOD  */
  YYSYMBOL_SUB = 30,                       /* SUB  */
  YYSYMBOL_COND_AND = 31,                  /* COND_AND  */
  YYSYMBOL_COND_OR = 32,                   /* COND_OR  */
  YYSYMBOL_NOT = 33,                       /* NOT  */
  YYSYMBOL_EQUAL = 34,                     /* EQUAL  */
  YYSYMBOL_NOT_EQUAL = 35,                 /* NOT_EQUAL  */
  YYSYMBOL_LT = 36,                        /* LT  */
  YYSYMBOL_GT = 37,                        /* GT  */
  YYSYMBOL_LE = 38,                        /* LE  */
  YYSYMBOL_GE = 39,                        /* GE  */
  YYSYMBOL_UNARY = 40,                     /* UNARY  */
  YYSYMBOL_EQ = 41,                        /* EQ  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_classdec = 44,                  /* classdec  */
  YYSYMBOL_classbody = 45,                 /* classbody  */
  YYSYMBOL_var_declarations = 46,          /* var_declarations  */
  YYSYMBOL_constructors = 47,              /* constructors  */
  YYSYMBOL_construct = 48,                 /* construct  */
  YYSYMBOL_method_declarations = 49,       /* method_declarations  */
  YYSYMBOL_method_declaration = 50,        /* method_declaration  */
  YYSYMBOL_parameterlist = 51,             /* parameterlist  */
  YYSYMBOL_parameter = 52,                 /* parameter  */
  YYSYMBOL_block = 53,                     /* block  */
  YYSYMBOL_localvardecs = 54,              /* localvardecs  */
  YYSYMBOL_localvardec = 55,               /* localvardec  */
  YYSYMBOL_statements = 56,                /* statements  */
  YYSYMBOL_statement = 57,                 /* statement  */
  YYSYMBOL_type = 58,                      /* type  */
  YYSYMBOL_multibrackets = 59,             /* multibrackets  */
  YYSYMBOL_simpletype = 60,                /* simpletype  */
  YYSYMBOL_name = 61,                      /* name  */
  YYSYMBOL_elementAccess = 62,             /* elementAccess  */
  YYSYMBOL_nameNoThis = 63,                /* nameNoThis  */
  YYSYMBOL_arglist = 64,                   /* arglist  */
  YYSYMBOL_expression = 65,                /* expression  */
  YYSYMBOL_unaryop = 66,                   /* unaryop  */
  YYSYMBOL_newexp = 67,                    /* newexp  */
  YYSYMBOL_newoexpc = 68                   /* newoexpc  */
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
typedef yytype_uint8 yy_state_t;

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
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
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
#define YYFINAL  5
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   624

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  27
/* YYNRULES -- Number of rules.  */
#define YYNRULES  107
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  219

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    52,    52,    55,    61,    67,    70,    73,    76,    79,
      82,    85,    88,    94,    99,   103,   104,   108,   113,   120,
     123,   126,   130,   135,   142,   145,   148,   151,   154,   155,
     158,   162,   166,   170,   177,   180,   183,   186,   192,   196,
     203,   206,   207,   211,   215,   221,   224,   227,   230,   233,
     236,   239,   242,   245,   248,   251,   254,   260,   263,   269,
     273,   280,   283,   289,   292,   295,   298,   301,   304,   305,
     309,   313,   320,   323,   329,   333,   339,   342,   345,   348,
     351,   354,   357,   360,   361,   362,   363,   364,   365,   366,
     367,   368,   369,   370,   371,   372,   373,   374,   379,   380,
     381,   385,   388,   391,   394,   397,   405,   409
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
  "\"end of file\"", "error", "\"invalid token\"", "ID", "NUM", "CLASS",
  "RBRACK", "LBRACK", "INT", "COMMA", "THIS", "DOT", "LPARAM", "RPARAM",
  "SEMI", "CSB", "VOID", "PRINT", "ELSE", "WHILE", "RET", "IF", "OSB",
  "NLL", "READ", "NEW", "MUL", "DIV", "ADD", "MOD", "SUB", "COND_AND",
  "COND_OR", "NOT", "EQUAL", "NOT_EQUAL", "LT", "GT", "LE", "GE", "UNARY",
  "EQ", "$accept", "program", "classdec", "classbody", "var_declarations",
  "constructors", "construct", "method_declarations", "method_declaration",
  "parameterlist", "parameter", "block", "localvardecs", "localvardec",
  "statements", "statement", "type", "multibrackets", "simpletype", "name",
  "elementAccess", "nameNoThis", "arglist", "expression", "unaryop",
  "newexp", "newoexpc", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296
};
#endif

#define YYPACT_NINF (-110)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-65)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       5,    26,    79,  -110,     0,  -110,  -110,   202,  -110,    33,
      34,  -110,  -110,   105,   252,   280,  -110,   217,  -110,   118,
      23,  -110,   534,  -110,  -110,     6,    60,    71,    60,  -110,
     308,   326,   163,  -110,  -110,   368,   177,  -110,  -110,  -110,
      60,   170,    65,    87,    17,    14,  -110,   200,  -110,   121,
     145,   101,   156,  -110,   555,  -110,    68,  -110,   138,    -4,
      60,    48,  -110,   176,  -110,   129,  -110,   544,  -110,   192,
    -110,   173,  -110,   237,  -110,  -110,   171,  -110,  -110,   193,
      53,   357,   194,   203,   216,   239,   357,   161,  -110,   357,
    -110,  -110,   209,   104,  -110,  -110,  -110,   210,   404,   357,
     357,  -110,  -110,   574,  -110,  -110,   230,   267,   357,  -110,
     215,   115,    60,  -110,    60,   126,  -110,  -110,    60,   168,
    -110,  -110,  -110,   441,   357,  -110,  -110,   235,   233,     7,
     578,   117,   365,   241,   236,   234,  -110,   295,  -110,   357,
     357,   357,   357,   357,   357,   357,   357,   357,   357,   357,
     357,   357,  -110,   385,  -110,  -110,   243,    77,   423,   115,
    -110,  -110,  -110,    60,  -110,    60,  -110,   459,   256,  -110,
     357,   247,   582,  -110,  -110,   323,   357,   244,  -110,   127,
    -110,  -110,    39,  -110,    39,  -110,    39,   592,   592,   592,
     592,   592,   592,   582,  -110,   251,  -110,  -110,  -110,  -110,
    -110,  -110,   578,  -110,  -110,  -110,   150,   477,   340,  -110,
     255,  -110,  -110,  -110,  -110,   495,   582,  -110,  -110
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     3,     0,     1,     2,     0,     4,     0,
      62,    12,    61,     0,     0,     0,    17,     0,    22,     0,
      57,    16,     0,    15,    21,     0,     0,     0,     0,     9,
       0,     0,     0,    10,    18,     0,     0,    62,    11,    23,
       0,     0,     0,    58,     0,     0,    37,     0,    45,     0,
       0,     0,     0,    56,     0,    38,     0,    43,     0,     0,
       0,     0,    30,     0,    29,     0,     6,     0,     7,     0,
       8,     0,    28,     0,    13,    59,     0,    42,    41,     0,
       0,     0,    65,     0,     0,     0,     0,     0,    76,     0,
      55,    79,     0,     0,    98,    99,   100,    77,     0,     0,
       0,    35,    39,     0,    36,    44,     0,     0,     0,    19,
       0,     0,     0,    33,     0,     0,     5,    14,     0,     0,
      60,    69,    67,     0,     0,    68,    72,    66,     0,     0,
      74,     0,     0,     0,    62,   103,    82,     0,    54,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    83,     0,    34,    40,     0,     0,     0,     0,
      31,    20,    25,     0,    24,     0,    70,     0,     0,    50,
       0,     0,     0,    97,    78,     0,     0,   104,    81,     0,
      87,    88,    84,    89,    85,    90,    86,    96,    95,    91,
      92,    93,    94,     0,    48,     0,    46,    32,    27,    26,
      71,    73,    75,    49,    53,   102,     0,     0,     0,    80,
      51,    47,   101,   106,   105,     0,     0,   107,    52
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -110,  -110,   272,  -110,  -110,   261,    -3,    29,   -13,     4,
    -109,     2,  -110,   222,   224,   -55,    -1,  -110,   189,   -22,
    -110,  -110,  -102,   -48,  -110,  -110,  -110
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     2,     3,     8,    14,    15,    16,    17,    18,    61,
      62,    53,    54,    55,    56,    57,    36,    43,    20,    97,
      82,   127,   129,   130,    99,   136,   177
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      59,   105,   160,    98,    39,   157,    19,     7,   107,    37,
       1,    24,    34,    32,    12,    79,   170,   -62,    39,    60,
     171,    58,    39,    77,    63,    80,   -64,    34,    64,     4,
      24,    78,    59,   123,    59,   179,    81,   108,   131,    21,
      22,   132,    72,    31,    35,    42,    25,    23,   105,   110,
     197,   152,   153,    58,    39,   -64,    87,   111,   122,    67,
     158,   112,   109,    47,    63,   139,   140,    22,   142,   115,
     144,    87,    63,   206,   104,    22,   167,   119,    47,     5,
      75,    59,    48,    65,     1,    49,   170,    50,    51,    52,
     195,   180,   181,   182,   183,   184,   185,   186,   187,   188,
     189,   190,   191,   192,    87,    88,    26,   134,    27,    76,
      63,    47,    12,    89,   161,    90,   162,   204,    37,    40,
     164,    41,   202,    12,    91,    92,    93,   110,   207,    94,
     172,    95,    37,    85,    96,   111,   170,    12,   210,   163,
     209,   106,   114,   139,   140,   141,   142,   143,   144,   145,
      59,   146,   147,   148,   149,   150,   151,    86,    63,   170,
     215,   218,    79,   212,    40,   198,    69,   199,   100,   110,
     -64,    59,    80,   -64,   -64,   -64,   -64,   111,    40,   113,
      71,   165,    73,    81,    74,    73,   120,   -64,   -64,   -64,
     -64,   -64,   -64,   -64,    59,   -64,   -64,   -64,   -64,   -64,
     -64,    83,   -64,     9,    73,    10,   117,   121,    11,   -63,
      12,    84,   -63,   -63,   -63,   -63,   124,   125,    13,   126,
      37,   133,   137,    38,   159,    12,   -63,   -63,   -63,   -63,
     -63,   -63,   -63,    13,   -63,   -63,   -63,   -63,   -63,   -63,
      37,   -63,    87,    88,   155,    12,   168,   169,   175,    47,
     118,    89,   128,    28,   174,    10,   176,   194,    29,   201,
      12,   203,    91,    92,    93,   211,   208,    94,    13,    95,
      87,    88,    96,   216,     6,    30,   102,    47,   103,    89,
     156,    28,   135,    10,     0,     0,    33,     0,    12,     0,
      91,    92,    93,     0,     0,    94,    13,    95,    87,    88,
      96,     0,     0,     0,     0,    47,     0,    89,   178,    28,
       0,    10,     0,     0,    66,     0,    12,     0,    91,    92,
      93,     0,     0,    94,    13,    95,    87,    88,    96,    37,
       0,     0,    68,    47,    12,    89,   205,     0,     0,     0,
       0,     0,    13,    87,    88,     0,    91,    92,    93,     0,
      47,    94,    89,    95,     0,   214,    96,     0,     0,     0,
      87,    88,     0,    91,    92,    93,     0,    47,    94,    89,
      95,    37,     0,    96,    70,     0,    12,     0,   173,     0,
      91,    92,    93,     0,    13,    94,     0,    95,     0,     0,
      96,   139,   140,   141,   142,   143,   144,   145,   193,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   145,   138,   146,
     147,   148,   149,   150,   151,     0,     0,     0,     0,     0,
     139,   140,   141,   142,   143,   144,   145,   196,   146,   147,
     148,   149,   150,   151,     0,     0,     0,     0,     0,   139,
     140,   141,   142,   143,   144,   145,   166,   146,   147,   148,
     149,   150,   151,     0,     0,     0,     0,   139,   140,   141,
     142,   143,   144,   145,   200,   146,   147,   148,   149,   150,
     151,     0,     0,     0,     0,   139,   140,   141,   142,   143,
     144,   145,   213,   146,   147,   148,   149,   150,   151,     0,
       0,     0,     0,   139,   140,   141,   142,   143,   144,   145,
     217,   146,   147,   148,   149,   150,   151,     0,     0,     0,
       0,   139,   140,   141,   142,   143,   144,   145,     0,   146,
     147,   148,   149,   150,   151,    44,     0,    45,     0,     0,
      46,    22,    12,     0,    47,     0,     0,    37,    48,     0,
     116,    49,    12,    50,    51,    52,    44,     0,    45,     0,
      13,   101,    22,    12,     0,    47,     0,     0,     0,    48,
       0,     0,    49,     0,    50,    51,    52,    87,     0,     0,
     154,    22,     0,     0,    47,    87,     0,     0,    48,    22,
       0,    49,    47,    50,    51,    52,    48,     0,     0,    49,
       0,    50,    51,    52,   139,   140,   141,   142,   143,   144,
     145,     0,   146,   147,   148,   149,   150,   151,   139,   140,
     141,   142,   143,   144,   145
};

static const yytype_int16 yycheck[] =
{
      22,    56,   111,    51,    17,   107,     7,     7,    12,     3,
       5,     9,    15,    14,     8,     1,     9,     3,    31,    13,
      13,    22,    35,     6,    25,    11,    12,    30,    26,     3,
      28,    14,    54,    81,    56,   137,    22,    41,    86,     6,
       7,    89,    40,    14,    15,    22,    12,    14,   103,     1,
     159,    99,   100,    54,    67,    41,     3,     9,    80,    30,
     108,    13,    60,    10,    65,    26,    27,     7,    29,    65,
      31,     3,    73,   175,     6,     7,   124,    73,    10,     0,
      15,   103,    14,    12,     5,    17,     9,    19,    20,    21,
      13,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,     3,     4,     1,     3,     3,    22,
     111,    10,     8,    12,   112,    14,   114,   172,     3,     1,
     118,     3,   170,     8,    23,    24,    25,     1,   176,    28,
      13,    30,     3,    12,    33,     9,     9,     8,   193,    13,
      13,     3,    13,    26,    27,    28,    29,    30,    31,    32,
     172,    34,    35,    36,    37,    38,    39,    12,   159,     9,
     208,   216,     1,    13,     1,   163,     3,   165,    12,     1,
       9,   193,    11,    12,    13,    14,    15,     9,     1,     3,
       3,    13,    12,    22,    14,    12,    15,    26,    27,    28,
      29,    30,    31,    32,   216,    34,    35,    36,    37,    38,
      39,     1,    41,     1,    12,     3,    14,    14,     6,     9,
       8,    11,    12,    13,    14,    15,    22,    14,    16,     3,
       3,    12,    12,     6,     9,     8,    26,    27,    28,    29,
      30,    31,    32,    16,    34,    35,    36,    37,    38,    39,
       3,    41,     3,     4,    14,     8,    11,    14,    12,    10,
      13,    12,    13,     1,    13,     3,    22,    14,     6,     3,
       8,    14,    23,    24,    25,    14,    22,    28,    16,    30,
       3,     4,    33,    18,     2,    14,    54,    10,    54,    12,
      13,     1,    93,     3,    -1,    -1,     6,    -1,     8,    -1,
      23,    24,    25,    -1,    -1,    28,    16,    30,     3,     4,
      33,    -1,    -1,    -1,    -1,    10,    -1,    12,    13,     1,
      -1,     3,    -1,    -1,     6,    -1,     8,    -1,    23,    24,
      25,    -1,    -1,    28,    16,    30,     3,     4,    33,     3,
      -1,    -1,     6,    10,     8,    12,    13,    -1,    -1,    -1,
      -1,    -1,    16,     3,     4,    -1,    23,    24,    25,    -1,
      10,    28,    12,    30,    -1,    15,    33,    -1,    -1,    -1,
       3,     4,    -1,    23,    24,    25,    -1,    10,    28,    12,
      30,     3,    -1,    33,     6,    -1,     8,    -1,    13,    -1,
      23,    24,    25,    -1,    16,    28,    -1,    30,    -1,    -1,
      33,    26,    27,    28,    29,    30,    31,    32,    13,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    14,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      26,    27,    28,    29,    30,    31,    32,    14,    34,    35,
      36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,    26,
      27,    28,    29,    30,    31,    32,    15,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    26,    27,    28,
      29,    30,    31,    32,    15,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    26,    27,    28,    29,    30,
      31,    32,    15,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    26,    27,    28,    29,    30,    31,    32,
      15,    34,    35,    36,    37,    38,    39,    -1,    -1,    -1,
      -1,    26,    27,    28,    29,    30,    31,    32,    -1,    34,
      35,    36,    37,    38,    39,     1,    -1,     3,    -1,    -1,
       6,     7,     8,    -1,    10,    -1,    -1,     3,    14,    -1,
       6,    17,     8,    19,    20,    21,     1,    -1,     3,    -1,
      16,     6,     7,     8,    -1,    10,    -1,    -1,    -1,    14,
      -1,    -1,    17,    -1,    19,    20,    21,     3,    -1,    -1,
       6,     7,    -1,    -1,    10,     3,    -1,    -1,    14,     7,
      -1,    17,    10,    19,    20,    21,    14,    -1,    -1,    17,
      -1,    19,    20,    21,    26,    27,    28,    29,    30,    31,
      32,    -1,    34,    35,    36,    37,    38,    39,    26,    27,
      28,    29,    30,    31,    32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     5,    43,    44,     3,     0,    44,     7,    45,     1,
       3,     6,     8,    16,    46,    47,    48,    49,    50,    58,
      60,     6,     7,    14,    53,    12,     1,     3,     1,     6,
      47,    49,    58,     6,    48,    49,    58,     3,     6,    50,
       1,     3,    22,    59,     1,     3,     6,    10,    14,    17,
      19,    20,    21,    53,    54,    55,    56,    57,    58,    61,
      13,    51,    52,    58,    53,    12,     6,    49,     6,     3,
       6,     3,    53,    12,    14,    15,    22,     6,    14,     1,
      11,    22,    62,     1,    11,    12,    12,     3,     4,    12,
      14,    23,    24,    25,    28,    30,    33,    61,    65,    66,
      12,     6,    55,    56,     6,    57,     3,    12,    41,    53,
       1,     9,    13,     3,    13,    51,     6,    14,    13,    51,
      15,    14,    61,    65,    22,    14,     3,    63,    13,    64,
      65,    65,    65,    12,     3,    60,    67,    12,    14,    26,
      27,    28,    29,    30,    31,    32,    34,    35,    36,    37,
      38,    39,    65,    65,     6,    14,    13,    64,    65,     9,
      52,    53,    53,    13,    53,    13,    15,    65,    11,    14,
       9,    13,    13,    13,    13,    12,    22,    68,    13,    64,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    13,    14,    13,    14,    52,    53,    53,
      15,     3,    65,    14,    57,    13,    64,    65,    22,    13,
      57,    14,    13,    15,    15,    65,    18,    15,    57
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    43,    44,    45,    45,    45,    45,    45,
      45,    45,    45,    46,    46,    46,    46,    47,    47,    48,
      48,    48,    49,    49,    50,    50,    50,    50,    50,    50,
      51,    51,    51,    52,    53,    53,    53,    53,    54,    54,
      55,    55,    55,    56,    56,    57,    57,    57,    57,    57,
      57,    57,    57,    57,    57,    57,    57,    58,    58,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    65,    65,
      65,    65,    65,    65,    65,    65,    65,    65,    66,    66,
      66,    67,    67,    67,    67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     1,     3,     5,     4,     4,     4,     3,
       3,     3,     2,     3,     4,     2,     2,     1,     2,     4,
       5,     2,     1,     2,     5,     5,     6,     6,     3,     3,
       1,     3,     4,     2,     4,     3,     3,     2,     1,     2,
       3,     2,     2,     1,     2,     1,     4,     5,     4,     5,
       4,     5,     7,     5,     3,     2,     1,     1,     2,     2,
       3,     1,     1,     1,     1,     2,     3,     3,     3,     3,
       3,     4,     1,     3,     1,     3,     1,     1,     3,     1,
       4,     3,     2,     2,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     1,     1,
       1,     4,     3,     1,     2,     4,     3,     4
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


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

/* This macro is provided for backward compatibility. */
# ifndef YY_LOCATION_PRINT
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif


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
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
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
    goto yyexhaustedlab;
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
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
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
  case 2: /* program: program classdec  */
#line 52 "program6.ypp"
                   {
    tree.push_back((yyvsp[0].nt));
  }
#line 1368 "program6.tab.cpp"
    break;

  case 3: /* program: classdec  */
#line 55 "program6.ypp"
             {
    tree.push_back((yyvsp[0].nt));
  }
#line 1376 "program6.tab.cpp"
    break;

  case 4: /* classdec: CLASS ID classbody  */
#line 61 "program6.ypp"
                     {
    (yyval.nt) = new ClassDec((yyvsp[-1].nt)->getIdent(), (yyvsp[0].nt));
  }
#line 1384 "program6.tab.cpp"
    break;

  case 5: /* classbody: LBRACK var_declarations constructors method_declarations RBRACK  */
#line 67 "program6.ypp"
                                                                  {
      (yyval.nt) = new ClassBody((yyvsp[-3].nt), (yyvsp[-2].nt), (yyvsp[-1].nt));
    }
#line 1392 "program6.tab.cpp"
    break;

  case 6: /* classbody: LBRACK var_declarations constructors RBRACK  */
#line 70 "program6.ypp"
                                                {
      (yyval.nt) = new ClassBody((yyvsp[-2].nt), (yyvsp[-1].nt), new NodeList());
  }
#line 1400 "program6.tab.cpp"
    break;

  case 7: /* classbody: LBRACK var_declarations method_declarations RBRACK  */
#line 73 "program6.ypp"
                                                       {
      (yyval.nt) = new ClassBody((yyvsp[-2].nt), new NodeList(), (yyvsp[-1].nt));
  }
#line 1408 "program6.tab.cpp"
    break;

  case 8: /* classbody: LBRACK constructors method_declarations RBRACK  */
#line 76 "program6.ypp"
                                                   {
      (yyval.nt) = new ClassBody(new NodeList(), (yyvsp[-2].nt), (yyvsp[-1].nt));
  }
#line 1416 "program6.tab.cpp"
    break;

  case 9: /* classbody: LBRACK var_declarations RBRACK  */
#line 79 "program6.ypp"
                                   {
      (yyval.nt) = new ClassBody((yyvsp[-1].nt), new NodeList(), new NodeList());
  }
#line 1424 "program6.tab.cpp"
    break;

  case 10: /* classbody: LBRACK constructors RBRACK  */
#line 82 "program6.ypp"
                               {
      (yyval.nt) = new ClassBody(new NodeList(), (yyvsp[-1].nt), new NodeList());
  }
#line 1432 "program6.tab.cpp"
    break;

  case 11: /* classbody: LBRACK method_declarations RBRACK  */
#line 85 "program6.ypp"
                                      {
      (yyval.nt) = new ClassBody(new NodeList(), new NodeList(), (yyvsp[-1].nt));
  }
#line 1440 "program6.tab.cpp"
    break;

  case 12: /* classbody: LBRACK RBRACK  */
#line 88 "program6.ypp"
                  {
      (yyval.nt) = new ClassBody(new NodeList(), new NodeList(), new NodeList());
  }
#line 1448 "program6.tab.cpp"
    break;

  case 13: /* var_declarations: type ID SEMI  */
#line 95 "program6.ypp"
  {
    (yyval.nt) = new NodeList();
    (yyval.nt)->push_back(new VarDec((yyvsp[-2].nt), (yyvsp[-1].nt)->getIdent()));
  }
#line 1457 "program6.tab.cpp"
    break;

  case 14: /* var_declarations: var_declarations type ID SEMI  */
#line 99 "program6.ypp"
                                  {
      (yyvsp[-3].nt)->push_back(new VarDec((yyvsp[-2].nt), (yyvsp[-1].nt)->getIdent()));
      (yyval.nt) = (yyvsp[-3].nt);
  }
#line 1466 "program6.tab.cpp"
    break;

  case 15: /* var_declarations: error SEMI  */
#line 103 "program6.ypp"
                 { yyerror("Missing semicolon"); yyerrok;}
#line 1472 "program6.tab.cpp"
    break;

  case 16: /* var_declarations: error RBRACK  */
#line 104 "program6.ypp"
                 { yyerror("Missing semicolon"); yyerrok;}
#line 1478 "program6.tab.cpp"
    break;

  case 17: /* constructors: construct  */
#line 109 "program6.ypp"
  {
    (yyval.nt) = new NodeList();
    (yyval.nt)->push_back((yyvsp[0].nt));
  }
#line 1487 "program6.tab.cpp"
    break;

  case 18: /* constructors: constructors construct  */
#line 113 "program6.ypp"
                           {
    (yyvsp[-1].nt)->push_back((yyvsp[0].nt));
    (yyval.nt) = (yyvsp[-1].nt);
  }
#line 1496 "program6.tab.cpp"
    break;

  case 19: /* construct: ID LPARAM RPARAM block  */
#line 120 "program6.ypp"
                         {
      (yyval.nt) = new ConstrDec((yyvsp[-3].nt)->getIdent(), new ParamList(), (yyvsp[0].nt)); 
  }
#line 1504 "program6.tab.cpp"
    break;

  case 20: /* construct: ID LPARAM parameterlist RPARAM block  */
#line 123 "program6.ypp"
                                         {
      (yyval.nt) = new ConstrDec((yyvsp[-4].nt)->getIdent(), (yyvsp[-2].nt), (yyvsp[0].nt));
  }
#line 1512 "program6.tab.cpp"
    break;

  case 21: /* construct: error block  */
#line 126 "program6.ypp"
                { yyerror("Syntax constructor error"); yyerrok;}
#line 1518 "program6.tab.cpp"
    break;

  case 22: /* method_declarations: method_declaration  */
#line 131 "program6.ypp"
  {
    (yyval.nt) = new NodeList();
    (yyval.nt)->push_back((yyvsp[0].nt));
  }
#line 1527 "program6.tab.cpp"
    break;

  case 23: /* method_declarations: method_declarations method_declaration  */
#line 135 "program6.ypp"
                                           {
    (yyvsp[-1].nt)->push_back((yyvsp[0].nt));
    (yyval.nt) = (yyvsp[-1].nt);
  }
#line 1536 "program6.tab.cpp"
    break;

  case 24: /* method_declaration: type ID LPARAM RPARAM block  */
#line 142 "program6.ypp"
                              {
      (yyval.nt) = new MethodDec(new ResultType((yyvsp[-4].nt)), (yyvsp[-3].nt)->getIdent(), new ParamList(), (yyvsp[0].nt));
  }
#line 1544 "program6.tab.cpp"
    break;

  case 25: /* method_declaration: VOID ID LPARAM RPARAM block  */
#line 145 "program6.ypp"
                                {
      (yyval.nt) = new MethodDec(new ResultType(), (yyvsp[-3].nt)->getIdent(), new ParamList(), (yyvsp[0].nt));
  }
#line 1552 "program6.tab.cpp"
    break;

  case 26: /* method_declaration: type ID LPARAM parameterlist RPARAM block  */
#line 148 "program6.ypp"
                                             {
      (yyval.nt) = new MethodDec(new ResultType((yyvsp[-5].nt)), (yyvsp[-4].nt)->getIdent(), (yyvsp[-2].nt), (yyvsp[0].nt));
  }
#line 1560 "program6.tab.cpp"
    break;

  case 27: /* method_declaration: VOID ID LPARAM parameterlist RPARAM block  */
#line 151 "program6.ypp"
                                              {
      (yyval.nt) = new MethodDec(new ResultType(), (yyvsp[-4].nt)->getIdent(), (yyvsp[-2].nt), (yyvsp[0].nt));
  }
#line 1568 "program6.tab.cpp"
    break;

  case 28: /* method_declaration: type error block  */
#line 154 "program6.ypp"
                     { yyerror("Missing semicolon"); yyerrok;}
#line 1574 "program6.tab.cpp"
    break;

  case 29: /* method_declaration: VOID error block  */
#line 155 "program6.ypp"
                     { yyerror("Missing semicolon"); yyerrok;}
#line 1580 "program6.tab.cpp"
    break;

  case 30: /* parameterlist: parameter  */
#line 158 "program6.ypp"
            {
    (yyval.nt) = new ParamList();
    (yyval.nt)->push_back((yyvsp[0].nt));
  }
#line 1589 "program6.tab.cpp"
    break;

  case 31: /* parameterlist: parameterlist COMMA parameter  */
#line 162 "program6.ypp"
                                   {
    (yyvsp[-2].nt)->push_back((yyvsp[0].nt));
    (yyval.nt) = (yyvsp[-2].nt);
  }
#line 1598 "program6.tab.cpp"
    break;

  case 32: /* parameterlist: parameterlist error COMMA parameter  */
#line 166 "program6.ypp"
                                        {yyerror("Possibly missing comma");yyerrok;}
#line 1604 "program6.tab.cpp"
    break;

  case 33: /* parameter: type ID  */
#line 170 "program6.ypp"
          {
    (yyval.nt) = new Parameter((yyvsp[-1].nt), (yyvsp[0].nt)->getIdent());
  }
#line 1612 "program6.tab.cpp"
    break;

  case 34: /* block: LBRACK localvardecs statements RBRACK  */
#line 177 "program6.ypp"
                                        {
    (yyval.nt) = new Block((yyvsp[-2].nt), (yyvsp[-1].nt));
  }
#line 1620 "program6.tab.cpp"
    break;

  case 35: /* block: LBRACK localvardecs RBRACK  */
#line 180 "program6.ypp"
                               {
    (yyval.nt) = new Block((yyvsp[-1].nt), new NodeList());
  }
#line 1628 "program6.tab.cpp"
    break;

  case 36: /* block: LBRACK statements RBRACK  */
#line 183 "program6.ypp"
                             {
    (yyval.nt) = new Block(new NodeList(), (yyvsp[-1].nt));
  }
#line 1636 "program6.tab.cpp"
    break;

  case 37: /* block: LBRACK RBRACK  */
#line 186 "program6.ypp"
                  {
    (yyval.nt) = new Block(new NodeList(), new NodeList());
  }
#line 1644 "program6.tab.cpp"
    break;

  case 38: /* localvardecs: localvardec  */
#line 192 "program6.ypp"
             {
    (yyval.nt) = new  NodeList();
    (yyval.nt)->push_back((yyvsp[0].nt));
  }
#line 1653 "program6.tab.cpp"
    break;

  case 39: /* localvardecs: localvardecs localvardec  */
#line 196 "program6.ypp"
                             {
    (yyvsp[-1].nt)->push_back((yyvsp[0].nt));
  }
#line 1661 "program6.tab.cpp"
    break;

  case 40: /* localvardec: type ID SEMI  */
#line 203 "program6.ypp"
               {
    (yyval.nt) = new LocalVarDec((yyvsp[-2].nt), (yyvsp[-1].nt)->getIdent());
  }
#line 1669 "program6.tab.cpp"
    break;

  case 41: /* localvardec: error SEMI  */
#line 206 "program6.ypp"
                 { yyerror("Missing semicolon"); yyerrok;}
#line 1675 "program6.tab.cpp"
    break;

  case 42: /* localvardec: error RBRACK  */
#line 207 "program6.ypp"
                 { yyerror("Missing semicolon"); yyerrok;}
#line 1681 "program6.tab.cpp"
    break;

  case 43: /* statements: statement  */
#line 211 "program6.ypp"
            {
    (yyval.nt) = new NodeList();
    (yyval.nt)->push_back((yyvsp[0].nt));
  }
#line 1690 "program6.tab.cpp"
    break;

  case 44: /* statements: statements statement  */
#line 215 "program6.ypp"
                         {
    (yyvsp[-1].nt)->push_back((yyvsp[0].nt));
  }
#line 1698 "program6.tab.cpp"
    break;

  case 45: /* statement: SEMI  */
#line 221 "program6.ypp"
       {
      (yyval.nt) = new Statement();
  }
#line 1706 "program6.tab.cpp"
    break;

  case 46: /* statement: name EQ expression SEMI  */
#line 224 "program6.ypp"
                            {
    (yyval.nt) = new AssignStatement((yyvsp[-3].nt), (yyvsp[-1].nt));
  }
#line 1714 "program6.tab.cpp"
    break;

  case 47: /* statement: name LPARAM arglist RPARAM SEMI  */
#line 227 "program6.ypp"
                                    {
    (yyval.nt) = new FuncCallStatement((yyvsp[-4].nt), (yyvsp[-2].nt));
  }
#line 1722 "program6.tab.cpp"
    break;

  case 48: /* statement: name LPARAM RPARAM SEMI  */
#line 230 "program6.ypp"
                            {
    (yyval.nt) = new FuncCallStatement((yyvsp[-3].nt), new ArgList());
  }
#line 1730 "program6.tab.cpp"
    break;

  case 49: /* statement: PRINT LPARAM arglist RPARAM SEMI  */
#line 233 "program6.ypp"
                                     {
      (yyval.nt) = new PrintStatement((yyvsp[-2].nt));
  }
#line 1738 "program6.tab.cpp"
    break;

  case 50: /* statement: PRINT LPARAM RPARAM SEMI  */
#line 236 "program6.ypp"
                             {
      (yyval.nt) = new PrintStatement(new ArgList());
  }
#line 1746 "program6.tab.cpp"
    break;

  case 51: /* statement: IF LPARAM expression RPARAM statement  */
#line 239 "program6.ypp"
                                          {
      (yyval.nt) = new IfStatement((yyvsp[-2].nt), (yyvsp[0].nt));
  }
#line 1754 "program6.tab.cpp"
    break;

  case 52: /* statement: IF LPARAM expression RPARAM statement ELSE statement  */
#line 242 "program6.ypp"
                                                         {
      (yyval.nt) = new IfElseStat((yyvsp[-4].nt), (yyvsp[-2].nt), (yyvsp[0].nt));
  }
#line 1762 "program6.tab.cpp"
    break;

  case 53: /* statement: WHILE LPARAM expression RPARAM statement  */
#line 245 "program6.ypp"
                                             {
      (yyval.nt) = new WhileStatement((yyvsp[-2].nt), (yyvsp[0].nt));
  }
#line 1770 "program6.tab.cpp"
    break;

  case 54: /* statement: RET expression SEMI  */
#line 248 "program6.ypp"
                       {
      (yyval.nt) = new ReturnStatement((yyvsp[-1].nt));
  }
#line 1778 "program6.tab.cpp"
    break;

  case 55: /* statement: RET SEMI  */
#line 251 "program6.ypp"
             {
      (yyval.nt) = new ReturnStatement();
  }
#line 1786 "program6.tab.cpp"
    break;

  case 56: /* statement: block  */
#line 254 "program6.ypp"
          {
      (yyval.nt) = new BlockStatement((yyvsp[0].nt));
  }
#line 1794 "program6.tab.cpp"
    break;

  case 57: /* type: simpletype  */
#line 260 "program6.ypp"
             {
    (yyval.nt) = new Type((yyvsp[0].nt), new NodeList());
  }
#line 1802 "program6.tab.cpp"
    break;

  case 58: /* type: simpletype multibrackets  */
#line 263 "program6.ypp"
                             {
    (yyval.nt) = new Type((yyvsp[-1].nt), (yyvsp[0].nt));
  }
#line 1810 "program6.tab.cpp"
    break;

  case 59: /* multibrackets: OSB CSB  */
#line 269 "program6.ypp"
          {
    (yyval.nt) = new Multibrackets();
    (yyval.nt)->push_back(new Node());
  }
#line 1819 "program6.tab.cpp"
    break;

  case 60: /* multibrackets: multibrackets OSB CSB  */
#line 273 "program6.ypp"
                          {
    (yyvsp[-2].nt)->push_back(new Node());
  }
#line 1827 "program6.tab.cpp"
    break;

  case 61: /* simpletype: INT  */
#line 280 "program6.ypp"
      {
    (yyval.nt) = new SimpleType("int");
  }
#line 1835 "program6.tab.cpp"
    break;

  case 62: /* simpletype: ID  */
#line 283 "program6.ypp"
       {
    (yyval.nt) = new SimpleType((yyvsp[0].nt)->getIdent());
  }
#line 1843 "program6.tab.cpp"
    break;

  case 63: /* name: THIS  */
#line 289 "program6.ypp"
       {
    (yyval.nt) = new Name("this");
  }
#line 1851 "program6.tab.cpp"
    break;

  case 64: /* name: ID  */
#line 292 "program6.ypp"
       {
    (yyval.nt) = new Name((yyvsp[0].nt)->getIdent());
  }
#line 1859 "program6.tab.cpp"
    break;

  case 65: /* name: ID elementAccess  */
#line 295 "program6.ypp"
                     {
    (yyval.nt) = new Name((yyvsp[0].nt), (yyvsp[-1].nt)->getIdent());
  }
#line 1867 "program6.tab.cpp"
    break;

  case 66: /* name: THIS DOT nameNoThis  */
#line 298 "program6.ypp"
                        {
    (yyval.nt) = new Name(new Name("this"),(yyvsp[0].nt));
  }
#line 1875 "program6.tab.cpp"
    break;

  case 67: /* name: ID DOT name  */
#line 301 "program6.ypp"
                {
    (yyval.nt) = new Name((yyvsp[-2].nt)->getIdent(), (yyvsp[0].nt));
  }
#line 1883 "program6.tab.cpp"
    break;

  case 68: /* name: THIS error SEMI  */
#line 304 "program6.ypp"
                    {yyerror("possibly missing ."); yyerrok;}
#line 1889 "program6.tab.cpp"
    break;

  case 69: /* name: ID error SEMI  */
#line 305 "program6.ypp"
                    {yyerror("possibly missing ."); yyerrok;}
#line 1895 "program6.tab.cpp"
    break;

  case 70: /* elementAccess: OSB expression CSB  */
#line 309 "program6.ypp"
                     {
    (yyval.nt) = new NodeList();
    (yyval.nt)->push_back((yyvsp[-1].nt));
  }
#line 1904 "program6.tab.cpp"
    break;

  case 71: /* elementAccess: elementAccess OSB expression CSB  */
#line 313 "program6.ypp"
                                     {
    (yyval.nt)->push_back((yyvsp[-1].nt));
  }
#line 1912 "program6.tab.cpp"
    break;

  case 72: /* nameNoThis: ID  */
#line 320 "program6.ypp"
     {
    (yyval.nt) = new Name((yyvsp[0].nt)->getIdent());
  }
#line 1920 "program6.tab.cpp"
    break;

  case 73: /* nameNoThis: nameNoThis DOT ID  */
#line 323 "program6.ypp"
                     {
    (yyval.nt) = new Name((yyvsp[-2].nt), (yyvsp[0].nt)->getIdent());
  }
#line 1928 "program6.tab.cpp"
    break;

  case 74: /* arglist: expression  */
#line 329 "program6.ypp"
            {
    (yyval.nt) = new ArgList();
    (yyval.nt)->push_back((yyvsp[0].nt));
  }
#line 1937 "program6.tab.cpp"
    break;

  case 75: /* arglist: arglist COMMA expression  */
#line 333 "program6.ypp"
                            {
    (yyval.nt)->push_back((yyvsp[0].nt));
  }
#line 1945 "program6.tab.cpp"
    break;

  case 76: /* expression: NUM  */
#line 339 "program6.ypp"
      {
    (yyval.nt) = new Expression(stoi((yyvsp[0].nt)->getIdent()));
  }
#line 1953 "program6.tab.cpp"
    break;

  case 77: /* expression: name  */
#line 342 "program6.ypp"
         {
    (yyval.nt) = new Expression((yyvsp[0].nt));
  }
#line 1961 "program6.tab.cpp"
    break;

  case 78: /* expression: READ LPARAM RPARAM  */
#line 345 "program6.ypp"
                       {
      (yyval.nt) = new ReadExp();
  }
#line 1969 "program6.tab.cpp"
    break;

  case 79: /* expression: NLL  */
#line 348 "program6.ypp"
        {
      (yyval.nt) = new Expression();
  }
#line 1977 "program6.tab.cpp"
    break;

  case 80: /* expression: name LPARAM arglist RPARAM  */
#line 351 "program6.ypp"
                               {
      (yyval.nt) = new FuncExp((yyvsp[-3].nt), (yyvsp[-1].nt), false);
  }
#line 1985 "program6.tab.cpp"
    break;

  case 81: /* expression: name LPARAM RPARAM  */
#line 354 "program6.ypp"
                       {
      (yyval.nt) = new FuncExp((yyvsp[-2].nt), new Node(), true);
  }
#line 1993 "program6.tab.cpp"
    break;

  case 82: /* expression: NEW newexp  */
#line 357 "program6.ypp"
               {
    (yyval.nt) = new NewExp((yyvsp[0].nt));
  }
#line 2001 "program6.tab.cpp"
    break;

  case 83: /* expression: unaryop expression  */
#line 360 "program6.ypp"
                                   {(yyval.nt) = new UnaryExp((yyvsp[-1].nt), (yyvsp[0].nt));}
#line 2007 "program6.tab.cpp"
    break;

  case 84: /* expression: expression ADD expression  */
#line 361 "program6.ypp"
                              {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "+", (yyvsp[0].nt));}
#line 2013 "program6.tab.cpp"
    break;

  case 85: /* expression: expression SUB expression  */
#line 362 "program6.ypp"
                              {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "-", (yyvsp[0].nt));}
#line 2019 "program6.tab.cpp"
    break;

  case 86: /* expression: expression COND_OR expression  */
#line 363 "program6.ypp"
                                  {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "||", (yyvsp[0].nt));}
#line 2025 "program6.tab.cpp"
    break;

  case 87: /* expression: expression MUL expression  */
#line 364 "program6.ypp"
                              {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "*", (yyvsp[0].nt));}
#line 2031 "program6.tab.cpp"
    break;

  case 88: /* expression: expression DIV expression  */
#line 365 "program6.ypp"
                              {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "/", (yyvsp[0].nt));}
#line 2037 "program6.tab.cpp"
    break;

  case 89: /* expression: expression MOD expression  */
#line 366 "program6.ypp"
                              {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "%", (yyvsp[0].nt));}
#line 2043 "program6.tab.cpp"
    break;

  case 90: /* expression: expression COND_AND expression  */
#line 367 "program6.ypp"
                                   {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "&&", (yyvsp[0].nt));}
#line 2049 "program6.tab.cpp"
    break;

  case 91: /* expression: expression LT expression  */
#line 368 "program6.ypp"
                             {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "<", (yyvsp[0].nt));}
#line 2055 "program6.tab.cpp"
    break;

  case 92: /* expression: expression GT expression  */
#line 369 "program6.ypp"
                             {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), ">", (yyvsp[0].nt));}
#line 2061 "program6.tab.cpp"
    break;

  case 93: /* expression: expression LE expression  */
#line 370 "program6.ypp"
                             {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "<=", (yyvsp[0].nt));}
#line 2067 "program6.tab.cpp"
    break;

  case 94: /* expression: expression GE expression  */
#line 371 "program6.ypp"
                             {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), ">=", (yyvsp[0].nt));}
#line 2073 "program6.tab.cpp"
    break;

  case 95: /* expression: expression NOT_EQUAL expression  */
#line 372 "program6.ypp"
                                    {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "!=", (yyvsp[0].nt));}
#line 2079 "program6.tab.cpp"
    break;

  case 96: /* expression: expression EQUAL expression  */
#line 373 "program6.ypp"
                                {(yyval.nt) = new BinaryExp((yyvsp[-2].nt), "==", (yyvsp[0].nt));}
#line 2085 "program6.tab.cpp"
    break;

  case 97: /* expression: LPARAM expression RPARAM  */
#line 374 "program6.ypp"
                             {(yyval.nt) = new ParanExp((yyvsp[-1].nt));}
#line 2091 "program6.tab.cpp"
    break;

  case 98: /* unaryop: ADD  */
#line 379 "program6.ypp"
      {(yyval.nt) = new UnaryOp("+");}
#line 2097 "program6.tab.cpp"
    break;

  case 99: /* unaryop: SUB  */
#line 380 "program6.ypp"
        {(yyval.nt) = new UnaryOp("-");}
#line 2103 "program6.tab.cpp"
    break;

  case 100: /* unaryop: NOT  */
#line 381 "program6.ypp"
        {(yyval.nt) = new UnaryOp("!");}
#line 2109 "program6.tab.cpp"
    break;

  case 101: /* newexp: ID LPARAM arglist RPARAM  */
#line 385 "program6.ypp"
                           {
    (yyval.nt) = new Nexp((yyvsp[-3].nt)->getIdent(), (yyvsp[-1].nt));
  }
#line 2117 "program6.tab.cpp"
    break;

  case 102: /* newexp: ID LPARAM RPARAM  */
#line 388 "program6.ypp"
                     {
    (yyval.nt) = new Nexp((yyvsp[-2].nt)->getIdent(), new NodeList());
  }
#line 2125 "program6.tab.cpp"
    break;

  case 103: /* newexp: simpletype  */
#line 391 "program6.ypp"
               {
    (yyval.nt) = new Nexp((yyvsp[0].nt));
  }
#line 2133 "program6.tab.cpp"
    break;

  case 104: /* newexp: simpletype newoexpc  */
#line 394 "program6.ypp"
                        {
    (yyval.nt) = new Nexp((yyvsp[-1].nt), (yyvsp[0].nt), new NodeList());
  }
#line 2141 "program6.tab.cpp"
    break;

  case 105: /* newexp: simpletype newoexpc OSB CSB  */
#line 397 "program6.ypp"
                                {
    Node * lastSq = new NodeList();
    lastSq->push_back(0);
    (yyval.nt) = new Nexp((yyvsp[-3].nt), (yyvsp[-2].nt), lastSq);
  }
#line 2151 "program6.tab.cpp"
    break;

  case 106: /* newoexpc: OSB expression CSB  */
#line 405 "program6.ypp"
                      {
    (yyval.nt) = new ExpressionList();
    (yyval.nt)->push_back(new SqExp((yyvsp[-1].nt))); 
  }
#line 2160 "program6.tab.cpp"
    break;

  case 107: /* newoexpc: newoexpc OSB expression CSB  */
#line 409 "program6.ypp"
                                {
    (yyval.nt)->push_back(new SqExp((yyvsp[-1].nt)));
  }
#line 2168 "program6.tab.cpp"
    break;


#line 2172 "program6.tab.cpp"

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
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
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

#line 415 "program6.ypp"

