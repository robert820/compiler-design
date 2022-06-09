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

#line 167 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
