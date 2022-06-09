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
#line 1 "hw2.y"

#include "SymbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define Trace(t)        printf(t)
extern FILE *yyin;
int yylex();
void yyerror(char *s);

#line 82 "y.tab.c"

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

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DE = 258,                      /* DE  */
    ME = 259,                      /* ME  */
    SE = 260,                      /* SE  */
    AE = 261,                      /* AE  */
    NE = 262,                      /* NE  */
    EQ = 263,                      /* EQ  */
    GE = 264,                      /* GE  */
    LE = 265,                      /* LE  */
    ARROW = 266,                   /* ARROW  */
    UMINUS = 267,                  /* UMINUS  */
    LOWER_THAN_ELSE = 268,         /* LOWER_THAN_ELSE  */
    FOUR = 269,                    /* FOUR  */
    FIVE = 270,                    /* FIVE  */
    BOOL = 271,                    /* BOOL  */
    BREAK = 272,                   /* BREAK  */
    CHAR = 273,                    /* CHAR  */
    CASE = 274,                    /* CASE  */
    CLASS = 275,                   /* CLASS  */
    CONTINUE = 276,                /* CONTINUE  */
    DECLARE = 277,                 /* DECLARE  */
    DO = 278,                      /* DO  */
    IF = 279,                      /* IF  */
    ELSE = 280,                    /* ELSE  */
    EXIT = 281,                    /* EXIT  */
    FLOAT = 282,                   /* FLOAT  */
    FOR = 283,                     /* FOR  */
    FUN = 284,                     /* FUN  */
    INT = 285,                     /* INT  */
    LOOP = 286,                    /* LOOP  */
    PRINT = 287,                   /* PRINT  */
    PRINTLN = 288,                 /* PRINTLN  */
    RETURN = 289,                  /* RETURN  */
    STRING = 290,                  /* STRING  */
    VAL = 291,                     /* VAL  */
    VAR = 292,                     /* VAR  */
    WHILE = 293,                   /* WHILE  */
    READ = 294,                    /* READ  */
    IN = 295,                      /* IN  */
    TRUE = 296,                    /* TRUE  */
    FALSE = 297,                   /* FALSE  */
    string = 298,                  /* string  */
    id = 299,                      /* id  */
    integer = 300,                 /* integer  */
    real = 301                     /* real  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DE 258
#define ME 259
#define SE 260
#define AE 261
#define NE 262
#define EQ 263
#define GE 264
#define LE 265
#define ARROW 266
#define UMINUS 267
#define LOWER_THAN_ELSE 268
#define FOUR 269
#define FIVE 270
#define BOOL 271
#define BREAK 272
#define CHAR 273
#define CASE 274
#define CLASS 275
#define CONTINUE 276
#define DECLARE 277
#define DO 278
#define IF 279
#define ELSE 280
#define EXIT 281
#define FLOAT 282
#define FOR 283
#define FUN 284
#define INT 285
#define LOOP 286
#define PRINT 287
#define PRINTLN 288
#define RETURN 289
#define STRING 290
#define VAL 291
#define VAR 292
#define WHILE 293
#define READ 294
#define IN 295
#define TRUE 296
#define FALSE 297
#define string 298
#define id 299
#define integer 300
#define real 301

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 12 "hw2.y"

    Hash*          symbol;
    int                      ivalue;
    char*                    str;
    float                    fvalue;
    _Bool                    bvalue;

#line 235 "y.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_DE = 3,                         /* DE  */
  YYSYMBOL_ME = 4,                         /* ME  */
  YYSYMBOL_SE = 5,                         /* SE  */
  YYSYMBOL_AE = 6,                         /* AE  */
  YYSYMBOL_NE = 7,                         /* NE  */
  YYSYMBOL_EQ = 8,                         /* EQ  */
  YYSYMBOL_GE = 9,                         /* GE  */
  YYSYMBOL_LE = 10,                        /* LE  */
  YYSYMBOL_ARROW = 11,                     /* ARROW  */
  YYSYMBOL_12_ = 12,                       /* '>'  */
  YYSYMBOL_13_ = 13,                       /* '<'  */
  YYSYMBOL_14_ = 14,                       /* '+'  */
  YYSYMBOL_15_ = 15,                       /* '-'  */
  YYSYMBOL_16_ = 16,                       /* '*'  */
  YYSYMBOL_17_ = 17,                       /* '/'  */
  YYSYMBOL_UMINUS = 18,                    /* UMINUS  */
  YYSYMBOL_LOWER_THAN_ELSE = 19,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_FOUR = 20,                      /* FOUR  */
  YYSYMBOL_FIVE = 21,                      /* FIVE  */
  YYSYMBOL_BOOL = 22,                      /* BOOL  */
  YYSYMBOL_BREAK = 23,                     /* BREAK  */
  YYSYMBOL_CHAR = 24,                      /* CHAR  */
  YYSYMBOL_CASE = 25,                      /* CASE  */
  YYSYMBOL_CLASS = 26,                     /* CLASS  */
  YYSYMBOL_CONTINUE = 27,                  /* CONTINUE  */
  YYSYMBOL_DECLARE = 28,                   /* DECLARE  */
  YYSYMBOL_DO = 29,                        /* DO  */
  YYSYMBOL_IF = 30,                        /* IF  */
  YYSYMBOL_ELSE = 31,                      /* ELSE  */
  YYSYMBOL_EXIT = 32,                      /* EXIT  */
  YYSYMBOL_FLOAT = 33,                     /* FLOAT  */
  YYSYMBOL_FOR = 34,                       /* FOR  */
  YYSYMBOL_FUN = 35,                       /* FUN  */
  YYSYMBOL_INT = 36,                       /* INT  */
  YYSYMBOL_LOOP = 37,                      /* LOOP  */
  YYSYMBOL_PRINT = 38,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 39,                   /* PRINTLN  */
  YYSYMBOL_RETURN = 40,                    /* RETURN  */
  YYSYMBOL_STRING = 41,                    /* STRING  */
  YYSYMBOL_VAL = 42,                       /* VAL  */
  YYSYMBOL_VAR = 43,                       /* VAR  */
  YYSYMBOL_WHILE = 44,                     /* WHILE  */
  YYSYMBOL_READ = 45,                      /* READ  */
  YYSYMBOL_IN = 46,                        /* IN  */
  YYSYMBOL_TRUE = 47,                      /* TRUE  */
  YYSYMBOL_FALSE = 48,                     /* FALSE  */
  YYSYMBOL_string = 49,                    /* string  */
  YYSYMBOL_id = 50,                        /* id  */
  YYSYMBOL_integer = 51,                   /* integer  */
  YYSYMBOL_real = 52,                      /* real  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* ','  */
  YYSYMBOL_59_ = 59,                       /* '='  */
  YYSYMBOL_60_ = 60,                       /* '!'  */
  YYSYMBOL_61_ = 61,                       /* '&'  */
  YYSYMBOL_62_ = 62,                       /* '|'  */
  YYSYMBOL_63_ = 63,                       /* '.'  */
  YYSYMBOL_64_ = 64,                       /* '['  */
  YYSYMBOL_65_ = 65,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 66,                  /* $accept  */
  YYSYMBOL_program = 67,                   /* program  */
  YYSYMBOL_classes = 68,                   /* classes  */
  YYSYMBOL_class = 69,                     /* class  */
  YYSYMBOL_declaration_and_function = 70,  /* declaration_and_function  */
  YYSYMBOL_declarations_and_functions = 71, /* declarations_and_functions  */
  YYSYMBOL_functions = 72,                 /* functions  */
  YYSYMBOL_function = 73,                  /* function  */
  YYSYMBOL_arguments = 74,                 /* arguments  */
  YYSYMBOL_argument = 75,                  /* argument  */
  YYSYMBOL_seperator = 76,                 /* seperator  */
  YYSYMBOL_returnValue = 77,               /* returnValue  */
  YYSYMBOL_statements = 78,                /* statements  */
  YYSYMBOL_type = 79,                      /* type  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_return = 81,                    /* return  */
  YYSYMBOL_expression = 82,                /* expression  */
  YYSYMBOL_expression_list = 83,           /* expression_list  */
  YYSYMBOL_boolean = 84,                   /* boolean  */
  YYSYMBOL_integer_expression = 85,        /* integer_expression  */
  YYSYMBOL_bool_expresssion = 86,          /* bool_expresssion  */
  YYSYMBOL_condition = 87,                 /* condition  */
  YYSYMBOL_loop = 88,                      /* loop  */
  YYSYMBOL_comparison = 89,                /* comparison  */
  YYSYMBOL_declarations = 90,              /* declarations  */
  YYSYMBOL_declaration = 91,               /* declaration  */
  YYSYMBOL_constant_declaration = 92,      /* constant_declaration  */
  YYSYMBOL_variable_declaration = 93,      /* variable_declaration  */
  YYSYMBOL_arrays_declaration = 94         /* arrays_declaration  */
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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   357

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  66
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  88
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  179

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   301


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
       2,     2,     2,    60,     2,     2,     2,     2,    61,     2,
      55,    56,    16,    14,    58,    15,    63,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,     2,
      13,    59,    12,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    64,     2,    65,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,    62,    54,     2,     2,     2,     2,
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
       5,     6,     7,     8,     9,    10,    11,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50,
      51,    52
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    70,    70,    71,    74,    75,    78,    84,    85,    88,
      89,    94,    95,    98,   101,   102,   105,   107,   108,   111,
     112,   115,   116,   119,   120,   121,   122,   125,   126,   127,
     128,   129,   130,   131,   132,   133,   134,   137,   139,   140,
     141,   142,   143,   144,   145,   146,   147,   148,   151,   152,
     153,   156,   157,   160,   161,   162,   163,   164,   167,   168,
     169,   172,   173,   174,   175,   176,   177,   180,   181,   182,
     183,   186,   187,   188,   189,   190,   191,   194,   195,   198,
     199,   200,   203,   204,   207,   208,   209,   210,   213
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
  "\"end of file\"", "error", "\"invalid token\"", "DE", "ME", "SE", "AE",
  "NE", "EQ", "GE", "LE", "ARROW", "'>'", "'<'", "'+'", "'-'", "'*'",
  "'/'", "UMINUS", "LOWER_THAN_ELSE", "FOUR", "FIVE", "BOOL", "BREAK",
  "CHAR", "CASE", "CLASS", "CONTINUE", "DECLARE", "DO", "IF", "ELSE",
  "EXIT", "FLOAT", "FOR", "FUN", "INT", "LOOP", "PRINT", "PRINTLN",
  "RETURN", "STRING", "VAL", "VAR", "WHILE", "READ", "IN", "TRUE", "FALSE",
  "string", "id", "integer", "real", "'{'", "'}'", "'('", "')'", "':'",
  "','", "'='", "'!'", "'&'", "'|'", "'.'", "'['", "']'", "$accept",
  "program", "classes", "class", "declaration_and_function",
  "declarations_and_functions", "functions", "function", "arguments",
  "argument", "seperator", "returnValue", "statements", "type",
  "statement", "return", "expression", "expression_list", "boolean",
  "integer_expression", "bool_expresssion", "condition", "loop",
  "comparison", "declarations", "declaration", "constant_declaration",
  "variable_declaration", "arrays_declaration", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-87)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-40)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      22,   -43,   -40,    50,    31,   -26,   -87,   -87,   -87,   -44,
     -22,   -87,   -32,    31,    35,    40,   -87,    22,    -8,   180,
      -8,   180,    28,    22,    31,    32,    22,    40,   -87,   -87,
     -87,   -87,    43,   180,   -87,   -87,   -87,    52,   -87,   -87,
     180,    25,   329,    18,   -87,   -87,   -87,   -53,   329,   -26,
     -87,   -87,    63,   -87,   -87,   180,   -87,   180,   116,   -87,
     180,   180,   180,   180,   180,   180,   180,   180,   180,   180,
      25,    25,   180,    39,   -26,    62,   -87,   -87,    64,    66,
      63,   329,   329,    12,   -87,     7,     7,     7,     7,     7,
       7,    77,    77,   -87,   -87,   -87,   -87,   329,    53,   -87,
     -87,    -8,    78,   -87,   -87,   180,   -87,    76,    -8,    67,
     329,   -87,   -87,   -87,   174,    81,    82,   194,   208,   180,
      83,    69,    95,   111,   174,   -87,   -87,   -87,   -87,   180,
     127,   180,   329,   180,   329,   329,   180,   -87,   180,   -87,
     -87,   132,   150,   143,   154,   166,   329,    61,   180,   340,
     340,   231,   174,   167,    46,   174,   -87,   146,   248,   134,
     147,   171,   174,   -87,   180,   -87,   265,   149,   177,   174,
     -87,   -87,   282,   151,   174,   -87,   -87,   152,   -87
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
      78,     0,     0,     0,     0,    78,    79,    80,    81,     0,
      84,     1,     0,     5,     0,    12,    77,    78,     0,     0,
       0,     0,     0,    78,     5,     0,    78,    12,    25,    26,
      24,    23,     0,     0,    51,    52,    45,    43,    44,    47,
       0,     0,    82,    46,    38,    41,    42,    85,    86,    10,
       3,     4,    15,     2,    11,     0,    54,    48,     0,    58,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    10,     0,     8,     7,     0,     0,
      15,    83,    49,     0,    39,    76,    73,    75,    72,    74,
      71,    53,    55,    56,    57,    59,    60,    87,     0,     9,
       6,     0,    19,    14,    40,     0,    88,    18,     0,     0,
      50,    17,    16,    20,    21,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    21,    31,    28,    29,    27,     0,
       0,     0,    33,     0,    35,    37,     0,    36,     0,    13,
      22,     0,     0,     0,     0,     0,    30,     0,     0,    32,
      34,     0,    21,    62,     0,    21,    68,     0,     0,     0,
       0,    61,    21,    64,     0,    67,     0,     0,     0,    21,
      66,    65,     0,     0,    21,    70,    63,     0,    69
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -87,   -87,   183,   207,   -87,   141,   193,     0,   145,   -87,
     -87,   -87,   -86,   -19,   -80,   -87,   -21,   -87,   -39,   -87,
     -87,   -87,   -87,   -87,     4,     3,   -87,   -87,   -87
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     3,    23,    24,    74,    75,    26,    27,    79,    80,
     112,   109,   123,    32,   124,   125,    42,    83,    43,    44,
      45,   126,   127,    46,    16,   128,     6,     7,     8
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      48,    47,    59,     5,     4,    15,    72,     9,    17,    14,
      10,    73,    56,    18,    28,    19,     1,     2,    22,    58,
      17,    66,    67,    68,    69,    29,    17,    50,    30,    17,
      53,    95,    96,    31,    81,    20,    82,    21,   140,    85,
      86,    87,    88,    89,    90,    91,    92,    93,    94,    76,
      11,    97,    77,    60,    61,    62,    63,    12,    64,    65,
      66,    67,    68,    69,     1,     2,   157,   153,   104,   160,
     105,   156,    34,    35,    76,    14,   167,    77,   163,    70,
      71,    49,   107,   173,   110,    25,   170,    52,   177,   113,
      98,   115,   175,    68,    69,   116,   132,   134,   135,   117,
     118,   119,    55,     1,     2,   120,   121,    57,   141,   159,
     143,   122,   144,    78,   152,   145,   100,   146,   106,   137,
     114,   101,   102,    60,    61,    62,    63,   154,    64,    65,
      66,    67,    68,    69,   111,   108,   129,   130,   136,    60,
      61,    62,    63,   168,    64,    65,    66,    67,    68,    69,
      60,    61,    62,    63,   138,    64,    65,    66,    67,    68,
      69,    60,    61,    62,    63,   139,    64,    65,    66,    67,
      68,    69,    84,    60,    61,    62,    63,   142,    64,    65,
      66,    67,    68,    69,    60,    61,    62,    63,   147,    64,
      65,    66,    67,    68,    69,    33,   148,   164,   158,   149,
     161,   165,   166,   171,   115,   176,   178,    51,   116,    33,
     150,    13,   117,   118,   119,    99,     1,     2,   120,   121,
      54,     0,   151,    33,   122,   103,     0,    34,    35,    36,
      37,    38,    39,   172,     0,    40,     0,     0,     0,     0,
      41,    34,    35,    36,    37,    38,    39,     0,     0,   131,
       0,     0,     0,     0,    41,    34,    35,    36,    37,    38,
      39,   115,     0,   133,     0,   116,     0,     0,    41,   117,
     118,   119,     0,     1,     2,   120,   121,     0,   115,     0,
       0,   122,   116,     0,   155,     0,   117,   118,   119,     0,
       1,     2,   120,   121,     0,   115,     0,     0,   122,   116,
       0,   162,     0,   117,   118,   119,     0,     1,     2,   120,
     121,     0,   115,     0,     0,   122,   116,     0,   169,     0,
     117,   118,   119,     0,     1,     2,   120,   121,     0,     0,
       0,     0,   122,     0,     0,   174,    60,    61,    62,    63,
       0,    64,    65,    66,    67,    68,    69,   -39,   -39,   -39,
     -39,     0,   -39,   -39,   -39,   -39,   -39,   -39
};

static const yytype_int16 yycheck[] =
{
      21,    20,    41,     0,     0,     5,    59,    50,     5,    35,
      50,    64,    33,    57,    22,    59,    42,    43,    50,    40,
      17,    14,    15,    16,    17,    33,    23,    23,    36,    26,
      26,    70,    71,    41,    55,    57,    57,    59,   124,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    49,
       0,    72,    49,     7,     8,     9,    10,    26,    12,    13,
      14,    15,    16,    17,    42,    43,   152,   147,    56,   155,
      58,   151,    47,    48,    74,    35,   162,    74,   158,    61,
      62,    53,   101,   169,   105,    50,   166,    55,   174,   108,
      51,    30,   172,    16,    17,    34,   117,   118,   119,    38,
      39,    40,    59,    42,    43,    44,    45,    55,   129,    63,
     131,    50,   133,    50,    53,   136,    54,   138,    65,    50,
      53,    57,    56,     7,     8,     9,    10,   148,    12,    13,
      14,    15,    16,    17,    58,    57,    55,    55,    55,     7,
       8,     9,    10,   164,    12,    13,    14,    15,    16,    17,
       7,     8,     9,    10,    59,    12,    13,    14,    15,    16,
      17,     7,     8,     9,    10,    54,    12,    13,    14,    15,
      16,    17,    56,     7,     8,     9,    10,    50,    12,    13,
      14,    15,    16,    17,     7,     8,     9,    10,    56,    12,
      13,    14,    15,    16,    17,    15,    46,    63,    31,    56,
      54,    54,    31,    54,    30,    54,    54,    24,    34,    15,
      56,     4,    38,    39,    40,    74,    42,    43,    44,    45,
      27,    -1,    56,    15,    50,    80,    -1,    47,    48,    49,
      50,    51,    52,    56,    -1,    55,    -1,    -1,    -1,    -1,
      60,    47,    48,    49,    50,    51,    52,    -1,    -1,    55,
      -1,    -1,    -1,    -1,    60,    47,    48,    49,    50,    51,
      52,    30,    -1,    55,    -1,    34,    -1,    -1,    60,    38,
      39,    40,    -1,    42,    43,    44,    45,    -1,    30,    -1,
      -1,    50,    34,    -1,    53,    -1,    38,    39,    40,    -1,
      42,    43,    44,    45,    -1,    30,    -1,    -1,    50,    34,
      -1,    53,    -1,    38,    39,    40,    -1,    42,    43,    44,
      45,    -1,    30,    -1,    -1,    50,    34,    -1,    53,    -1,
      38,    39,    40,    -1,    42,    43,    44,    45,    -1,    -1,
      -1,    -1,    50,    -1,    -1,    53,     7,     8,     9,    10,
      -1,    12,    13,    14,    15,    16,    17,     7,     8,     9,
      10,    -1,    12,    13,    14,    15,    16,    17
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    42,    43,    67,    90,    91,    92,    93,    94,    50,
      50,     0,    26,    69,    35,    73,    90,    91,    57,    59,
      57,    59,    50,    68,    69,    50,    72,    73,    22,    33,
      36,    41,    79,    15,    47,    48,    49,    50,    51,    52,
      55,    60,    82,    84,    85,    86,    89,    79,    82,    53,
      90,    68,    55,    90,    72,    59,    82,    55,    82,    84,
       7,     8,     9,    10,    12,    13,    14,    15,    16,    17,
      61,    62,    59,    64,    70,    71,    73,    91,    50,    74,
      75,    82,    82,    83,    56,    82,    82,    82,    82,    82,
      82,    82,    82,    82,    82,    84,    84,    82,    51,    71,
      54,    57,    56,    74,    56,    58,    65,    79,    57,    77,
      82,    58,    76,    79,    53,    30,    34,    38,    39,    40,
      44,    45,    50,    78,    80,    81,    87,    88,    91,    55,
      55,    55,    82,    55,    82,    82,    55,    50,    59,    54,
      78,    82,    50,    82,    82,    82,    82,    56,    46,    56,
      56,    56,    53,    80,    82,    53,    80,    78,    31,    63,
      78,    54,    53,    80,    63,    54,    31,    78,    82,    53,
      80,    54,    56,    78,    53,    80,    54,    78,    54
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    66,    67,    67,    68,    68,    69,    70,    70,    71,
      71,    72,    72,    73,    74,    74,    75,    76,    76,    77,
      77,    78,    78,    79,    79,    79,    79,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    81,    82,    82,
      82,    82,    82,    82,    82,    82,    82,    82,    83,    83,
      83,    84,    84,    85,    85,    85,    85,    85,    86,    86,
      86,    87,    87,    87,    87,    87,    87,    88,    88,    88,
      88,    89,    89,    89,    89,    89,    89,    90,    90,    91,
      91,    91,    92,    92,    93,    93,    93,    93,    94
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     4,     4,     2,     0,     5,     1,     1,     2,
       0,     2,     0,     9,     2,     0,     4,     1,     0,     0,
       2,     0,     2,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     4,     2,     4,     2,     2,     2,     1,     3,
       4,     1,     1,     1,     1,     1,     1,     1,     0,     1,
       3,     1,     1,     3,     2,     3,     3,     3,     2,     3,
       3,     7,     5,    11,     7,     9,     9,     7,     5,    12,
      10,     3,     3,     3,     3,     3,     3,     2,     0,     1,
       1,     1,     4,     6,     2,     4,     4,     6,     7
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
  case 6: /* class: CLASS id '{' declarations_and_functions '}'  */
#line 79 "hw2.y"
                {
                Trace("Reducing to program\n");
                }
#line 1463 "y.tab.c"
    break;

  case 58: /* bool_expresssion: '!' boolean  */
#line 167 "hw2.y"
                                            {(yyval.bvalue) = !(yyvsp[0].bvalue);}
#line 1469 "y.tab.c"
    break;


#line 1473 "y.tab.c"

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

#line 222 "hw2.y"


void yyerror(char *msg)
{
    fprintf(stderr, "%s\n", msg);
}

int main(int argc, char** argv)
{
    /* open the source program file */
    if (argc != 2) {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");         /* open input file */

    /* perform parsing */
    if (yyparse() == 1)                 /* parsing */
        yyerror("Parsing error !");     /* syntax error */
}
