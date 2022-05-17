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
    BOOL = 269,                    /* BOOL  */
    BREAK = 270,                   /* BREAK  */
    CHAR = 271,                    /* CHAR  */
    CASE = 272,                    /* CASE  */
    CLASS = 273,                   /* CLASS  */
    CONTINUE = 274,                /* CONTINUE  */
    DECLARE = 275,                 /* DECLARE  */
    DO = 276,                      /* DO  */
    IF = 277,                      /* IF  */
    ELSE = 278,                    /* ELSE  */
    EXIT = 279,                    /* EXIT  */
    FLOAT = 280,                   /* FLOAT  */
    FOR = 281,                     /* FOR  */
    FUN = 282,                     /* FUN  */
    INT = 283,                     /* INT  */
    LOOP = 284,                    /* LOOP  */
    PRINT = 285,                   /* PRINT  */
    PRINTLN = 286,                 /* PRINTLN  */
    RETURN = 287,                  /* RETURN  */
    STRING = 288,                  /* STRING  */
    VAL = 289,                     /* VAL  */
    VAR = 290,                     /* VAR  */
    WHILE = 291,                   /* WHILE  */
    READ = 292,                    /* READ  */
    IN = 293,                      /* IN  */
    TRUE = 294,                    /* TRUE  */
    FALSE = 295,                   /* FALSE  */
    string = 296,                  /* string  */
    id = 297,                      /* id  */
    integer = 298,                 /* integer  */
    real = 299                     /* real  */
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
#define BOOL 269
#define BREAK 270
#define CHAR 271
#define CASE 272
#define CLASS 273
#define CONTINUE 274
#define DECLARE 275
#define DO 276
#define IF 277
#define ELSE 278
#define EXIT 279
#define FLOAT 280
#define FOR 281
#define FUN 282
#define INT 283
#define LOOP 284
#define PRINT 285
#define PRINTLN 286
#define RETURN 287
#define STRING 288
#define VAL 289
#define VAR 290
#define WHILE 291
#define READ 292
#define IN 293
#define TRUE 294
#define FALSE 295
#define string 296
#define id 297
#define integer 298
#define real 299

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

#line 163 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
