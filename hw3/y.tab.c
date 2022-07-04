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
#line 1 "hw3.y"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include "token.h"
#include "SymbolTable.h"
#include "SymbolDesc.h"

#define Trace(t)        printf(t)
extern FILE *yyin;
int yylex(void);
extern "C"
{
    int yyparse(void);
    int yywrap()
    {
        return 1;
    }
}

void yyerror(char *s);
FILE *output;
Hash *idtab, *current_idtab;
bool has_error = false;
int varList[255]={-1};
int size = 0;
int LabelIndex = 0;
std::string ClassName;

union uDependency{
	int low;
	int high;
	int baseType;
	int retType;
	int argType;
	
	int _int;
	bool _bool;
	double _real;
	char * _str;
	void * value;
};

struct SymbolDesc
{
    int symtype = vunknown;
    bool readonly = false;
    bool global = false;
    bool hasValue = false;
	bool returnByFun = false;
    int iValue;
    char * sValue;
    bool bValue;
    std::vector<uDependency> symdeps;
    int symindex;
};


char* SymType2Str(int type){
	switch(type){
	case sinteger :
		return "int";
	case sreal :
		return "float";
	case sboolean :
		return "bool";
	case sstring :
		return "java.lang.String";
	case none :
		return "void";
	default:
		return "unknown";
	}
}
std::string SymType2JBStr(int type){
	switch(type){
	case sinteger :
		return "int";
	case sreal :
		return "float";
	case sboolean :
		return "bool";
	case sstring :
		return "java.lang.String";
	case sarray :
		return "array";
	case sfunction :
		return "function";
	case sprocedure :
		return "procedure";
	case none :
		return "void";
	default:
		return "unknown";
	}
}


int Symbol2Token(int symbol){
	switch(symbol){
		case SymbolType::sinteger:
			return  TokenType::vint;
		break;
		case SymbolType::sreal:
			return  TokenType::vreal;
		break;
		case SymbolType::sstring:
			return  TokenType::vstring;
		break;
		case SymbolType::sboolean:
			return  TokenType::vbool;
		break;
		case SymbolType::none:
			return TokenType::blank;
		break;
		default:
			return TokenType::vunknown;
		break;
	}
}

int Token2Symbol(int token){
	switch(token){
		case vint:
			return sinteger;
		break;
		case vreal : 
			return sreal;
		break;
		case vstring :
			return sstring;
		break;
		case vbool :
			return sboolean;
		break;
		case blank:
			return none;
		break;
		default:
			return sunknown;
		break;
	}
}

std::vector<std::map<std::string,SymbolDesc>> SymTableStack;
std::vector<int> SymTableIndexStack;
std::vector<int> SCOPERET;

void InitialTableStack(){
	SymTableStack.push_back(std::map<std::string,SymbolDesc>());
	SymTableIndexStack.push_back(0);
}

void ENTERSCOPE(){
	SymTableStack.push_back(std::map<std::string,SymbolDesc>());
	SymTableIndexStack.push_back(0);
}

void LEAVESCOPE(){
	SymTableStack.pop_back();
	SymTableIndexStack.pop_back();
}


int GETSCOPERETURN(){
	if(SCOPERET.size()==0){
		return SymbolType::none;
	}
	else {
		return SCOPERET.back();
	}
}



bool seize(std::string id,SymbolDesc *& sd){
	for(int i = SymTableStack.size() - 1 ; i>=0;--i){
		if(SymTableStack[i].count(id)){
			sd = &(SymTableStack[i][id]);
			return true;
		}
	}
	return false;
}

bool seize(std::string id,SymbolDesc & sd){
	for(int i = SymTableStack.size() - 1 ; i>=0;--i){
		if(SymTableStack[i].count(id)){
			sd = (SymTableStack[i][id]);
			return true;
		}
	}
	return false;
}

bool inScope(std::string id){
	if(SymTableStack.back().count(id)){
		return true;
	}
	return false;
}

bool insert(std::string id,SymbolDesc& sd){
	if(inScope(id)){
		return false;
	}
	if(sd.symtype <= SymbolType::sarray){
		//Variable IDs
		if(!sd.readonly){
			//Non Constant Variable IDs
			if(SymTableStack.size()==1){
				//Global Non Constant Variable IDs
				sd.global = true;
				fprintf(output, "\tfield static %s %s", SymType2JBStr(sd.symtype).c_str(), id.c_str());
                                if(sd.hasValue){
                                        if(sd.symtype == sinteger){
                                                fprintf(output, " = %d", sd.iValue);
                                        }else if(sd.symtype == sboolean){
                                                if(sd.bValue){
                                                        fprintf(output, " = true");
                                                }else{
                                                        fprintf(output, " = false");
                                                }
                                        }else if(sd.symtype == sstring){
                                                fprintf(output, " = %s", sd.sValue);
                                        }else if(sd.symtype == sreal){
                                                fprintf(output, " = %d", sd.iValue);
                                        }
                                }
                                fprintf(output, "\n");
			}
			else{
				//Local Non Constan Variable IDs
				sd.symindex = (SymTableIndexStack.back())++;
				if(sd.hasValue){
					if(!sd.returnByFun){
						if(sd.symtype == sinteger){
							printf("...%s %d...", id.c_str(), sd.iValue);
							fprintf(output, "sipush %d\n", sd.iValue);
						}else if(sd.symtype == sboolean){
							if(sd.bValue){
								fprintf(output, "iconst_1\n");
							}
							else {
								fprintf(output, "iconst_0\n");
							}
						}else if(sd.symtype == sstring){
							fprintf(output, "\t\tldc %s\n", sd.sValue);
						}else if(sd.symtype == sreal){
							fprintf(output, "sipush %d\n", sd.iValue);
						}
					}
				}	
					switch(sd.symtype){
						case SymbolType::sinteger:
						fprintf(output, "istore %d\n",  sd.symindex);
						break;
						case SymbolType::sreal:
						fprintf(output, "fstore  %d\n", sd.symindex);
						break;
						case SymbolType::sstring:
						fprintf(output, "astore  %d\n", sd.symindex);
						break;
					}	
			}
		}
	}
	else{
		//Unknown,Function,Procedure IDs
	}
	SymTableStack.back()[id] = sd;
	return true;
}

bool insert(std::vector<std::string> list,SymbolDesc& sd){
	bool success = true;
	for(int i = 0 ; i < list.size() ; ++i){
		insert(list[i],sd);
	}
	return success;
}

bool insert(std::string id,SymbolDesc& sd,int scope){
	std::map<std::string,SymbolDesc> & EarlyScope =   SymTableStack[SymTableStack.size()-1-scope];
	int & EarlySymIndex = SymTableIndexStack[SymTableIndexStack.size()-scope];
	if(EarlyScope.count(id)){
		return false;
	}
	if(sd.symtype <= SymbolType::sarray){
		//Variable IDs
		if(!sd.readonly){
			//Non Constant Variable IDs
			if(SymTableStack.size() - scope == 1){
				//Global Non Constant Variable IDs
				sd.global = true;
				fprintf(output, "field static %s %s\n", SymType2JBStr(sd.symtype).c_str(), id.c_str());
			}
			else{
				//Local Non Constan Variable IDs
				sd.symindex = EarlySymIndex++;
				// switch(sd.symtype){
				// 	case SymbolType::sinteger:
				// 	fprintf(output, "istore %d\n",  sd.symindex);
				// 	break;
				// 	case SymbolType::sreal:
				// 	fprintf(output, "fstore  %d\n", sd.symindex);
				// 	break;
				// 	case SymbolType::sstring:
				// 	fprintf(output, "astore  %d\n", sd.symindex);
				// 	break;
				// }		
			}
		}
	}
	else{
		//Unknown,Function,Procedure IDs
	}
	EarlyScope[id] = sd;
	return true;
}

bool insertArg(std::string id,SymbolDesc& sd){
	if(inScope(id)){
		return false;
	}
	sd.symindex = (SymTableIndexStack.back())++;
	SymTableStack.back()[id] = sd;
	return true;
}

void insertList(int type){
        varList[size++] = type;
}

void resetList(){
        int i = 0;
        for(i;i<255;i++){
                varList[i] = -1;
        }
}

bool matchArgs(std::vector<int>& list,SymbolDesc & sd){
	if(list.size()  != sd.symdeps.size() - 1){
		return false;
	}
	else{
		for(int i = 0; i < list.size();++i){
			if(list[i] !=sd.symdeps[i+1].argType) return false;
		}	
	}
	return true;
}

// ast_node_t* n(ast_node_type_t t, YYLTYPE l) { return new_ast_node(t, l.first_line, l.first_column); }
// void vid(ast_node_t *n, LinkedList *v) { if (v) ast_node_set_value_identifier(n, v); }
// void vopt(ast_node_t *n, int v) { ast_node_set_value_operatr(n, v); }
// void vint(ast_node_t *n, int v) { ast_node_set_value_integer(n, v); }
// void vstr(ast_node_t *n, char *v) { ast_node_set_value_string(n, v); }
// void ich(ast_node_t *n, ast_node_t *child) { ast_node_insert_child(n, child); }
// void isb(ast_node_t *n, ast_node_t *sibling) { ast_node_insert_sibling(n, sibling); }
// void esp(LinkedList *sid) { current_idtab = idtab_entry_idtab_create(current_idtab, sid); }
// void lsp() { if (current_idtab->upper_idtab) current_idtab = current_idtab->upper_idtab; }

#line 440 "y.tab.c"

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
    ELSE = 269,                    /* ELSE  */
    BREAK = 270,                   /* BREAK  */
    CHAR = 271,                    /* CHAR  */
    CASE = 272,                    /* CASE  */
    CLASS = 273,                   /* CLASS  */
    CONTINUE = 274,                /* CONTINUE  */
    DECLARE = 275,                 /* DECLARE  */
    DO = 276,                      /* DO  */
    IF = 277,                      /* IF  */
    EXIT = 278,                    /* EXIT  */
    FOR = 279,                     /* FOR  */
    FUN = 280,                     /* FUN  */
    LOOP = 281,                    /* LOOP  */
    PRINT = 282,                   /* PRINT  */
    PRINTLN = 283,                 /* PRINTLN  */
    RETURN = 284,                  /* RETURN  */
    VAL = 285,                     /* VAL  */
    VAR = 286,                     /* VAR  */
    WHILE = 287,                   /* WHILE  */
    READ = 288,                    /* READ  */
    IN = 289,                      /* IN  */
    TRUE = 290,                    /* TRUE  */
    FALSE = 291,                   /* FALSE  */
    str = 292,                     /* str  */
    id = 293,                      /* id  */
    integer = 294,                 /* integer  */
    real = 295,                    /* real  */
    KW_STRING = 296,               /* KW_STRING  */
    INT = 297,                     /* INT  */
    FLOAT = 298,                   /* FLOAT  */
    BOOL = 299                     /* BOOL  */
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
#define ELSE 269
#define BREAK 270
#define CHAR 271
#define CASE 272
#define CLASS 273
#define CONTINUE 274
#define DECLARE 275
#define DO 276
#define IF 277
#define EXIT 278
#define FOR 279
#define FUN 280
#define LOOP 281
#define PRINT 282
#define PRINTLN 283
#define RETURN 284
#define VAL 285
#define VAR 286
#define WHILE 287
#define READ 288
#define IN 289
#define TRUE 290
#define FALSE 291
#define str 292
#define id 293
#define integer 294
#define real 295
#define KW_STRING 296
#define INT 297
#define FLOAT 298
#define BOOL 299

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 370 "hw3.y"

    //Hash*          symbol;
    //int                      ivalue;
    //char*                    str;
    //float                    fvalue;
    //_Bool                    bvalue;
    //TokenType                valueType;
    Token                    token;
    //ast_node_t*              ast_node;

#line 592 "y.tab.c"

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
  YYSYMBOL_ELSE = 20,                      /* ELSE  */
  YYSYMBOL_BREAK = 21,                     /* BREAK  */
  YYSYMBOL_CHAR = 22,                      /* CHAR  */
  YYSYMBOL_CASE = 23,                      /* CASE  */
  YYSYMBOL_CLASS = 24,                     /* CLASS  */
  YYSYMBOL_CONTINUE = 25,                  /* CONTINUE  */
  YYSYMBOL_DECLARE = 26,                   /* DECLARE  */
  YYSYMBOL_DO = 27,                        /* DO  */
  YYSYMBOL_IF = 28,                        /* IF  */
  YYSYMBOL_EXIT = 29,                      /* EXIT  */
  YYSYMBOL_FOR = 30,                       /* FOR  */
  YYSYMBOL_FUN = 31,                       /* FUN  */
  YYSYMBOL_LOOP = 32,                      /* LOOP  */
  YYSYMBOL_PRINT = 33,                     /* PRINT  */
  YYSYMBOL_PRINTLN = 34,                   /* PRINTLN  */
  YYSYMBOL_RETURN = 35,                    /* RETURN  */
  YYSYMBOL_VAL = 36,                       /* VAL  */
  YYSYMBOL_VAR = 37,                       /* VAR  */
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_READ = 39,                      /* READ  */
  YYSYMBOL_IN = 40,                        /* IN  */
  YYSYMBOL_TRUE = 41,                      /* TRUE  */
  YYSYMBOL_FALSE = 42,                     /* FALSE  */
  YYSYMBOL_str = 43,                       /* str  */
  YYSYMBOL_id = 44,                        /* id  */
  YYSYMBOL_integer = 45,                   /* integer  */
  YYSYMBOL_real = 46,                      /* real  */
  YYSYMBOL_KW_STRING = 47,                 /* KW_STRING  */
  YYSYMBOL_INT = 48,                       /* INT  */
  YYSYMBOL_FLOAT = 49,                     /* FLOAT  */
  YYSYMBOL_BOOL = 50,                      /* BOOL  */
  YYSYMBOL_51_ = 51,                       /* '{'  */
  YYSYMBOL_52_ = 52,                       /* '}'  */
  YYSYMBOL_53_ = 53,                       /* '('  */
  YYSYMBOL_54_ = 54,                       /* ')'  */
  YYSYMBOL_55_ = 55,                       /* ':'  */
  YYSYMBOL_56_ = 56,                       /* ','  */
  YYSYMBOL_57_ = 57,                       /* '='  */
  YYSYMBOL_58_ = 58,                       /* '%'  */
  YYSYMBOL_59_ = 59,                       /* '!'  */
  YYSYMBOL_60_ = 60,                       /* '&'  */
  YYSYMBOL_61_ = 61,                       /* '|'  */
  YYSYMBOL_62_ = 62,                       /* '.'  */
  YYSYMBOL_63_ = 63,                       /* '['  */
  YYSYMBOL_64_ = 64,                       /* ']'  */
  YYSYMBOL_YYACCEPT = 65,                  /* $accept  */
  YYSYMBOL_program = 66,                   /* program  */
  YYSYMBOL_class = 67,                     /* class  */
  YYSYMBOL_68_1 = 68,                      /* $@1  */
  YYSYMBOL_declaration_and_function = 69,  /* declaration_and_function  */
  YYSYMBOL_declarations_and_functions = 70, /* declarations_and_functions  */
  YYSYMBOL_function = 71,                  /* function  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_73_3 = 73,                      /* @3  */
  YYSYMBOL_arguments = 74,                 /* arguments  */
  YYSYMBOL_argument = 75,                  /* argument  */
  YYSYMBOL_seperator = 76,                 /* seperator  */
  YYSYMBOL_returnType = 77,                /* returnType  */
  YYSYMBOL_statements = 78,                /* statements  */
  YYSYMBOL_type = 79,                      /* type  */
  YYSYMBOL_statement = 80,                 /* statement  */
  YYSYMBOL_81_4 = 81,                      /* $@4  */
  YYSYMBOL_82_5 = 82,                      /* $@5  */
  YYSYMBOL_return = 83,                    /* return  */
  YYSYMBOL_returnValue = 84,               /* returnValue  */
  YYSYMBOL_declaration_value = 85,         /* declaration_value  */
  YYSYMBOL_expression = 86,                /* expression  */
  YYSYMBOL_expression_list = 87,           /* expression_list  */
  YYSYMBOL_boolean = 88,                   /* boolean  */
  YYSYMBOL_integer_expression = 89,        /* integer_expression  */
  YYSYMBOL_bool_expresssion = 90,          /* bool_expresssion  */
  YYSYMBOL_condition = 91,                 /* condition  */
  YYSYMBOL_92_6 = 92,                      /* $@6  */
  YYSYMBOL_93_7 = 93,                      /* $@7  */
  YYSYMBOL_IF_PREACT = 94,                 /* IF_PREACT  */
  YYSYMBOL_loop = 95,                      /* loop  */
  YYSYMBOL_96_8 = 96,                      /* @8  */
  YYSYMBOL_97_9 = 97,                      /* $@9  */
  YYSYMBOL_98_10 = 98,                     /* @10  */
  YYSYMBOL_99_11 = 99,                     /* $@11  */
  YYSYMBOL_one_or_multiple_line = 100,     /* one_or_multiple_line  */
  YYSYMBOL_comparison = 101,               /* comparison  */
  YYSYMBOL_declaration = 102,              /* declaration  */
  YYSYMBOL_constant_declaration = 103,     /* constant_declaration  */
  YYSYMBOL_variable_declaration = 104,     /* variable_declaration  */
  YYSYMBOL_arrays_declaration = 105        /* arrays_declaration  */
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
#define YYFINAL  2
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   499

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  65
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  41
/* YYNRULES -- Number of rules.  */
#define YYNRULES  104
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  177

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   299


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
       2,     2,     2,    59,     2,     2,     2,    58,    60,     2,
      53,    54,    16,    14,    56,    15,    62,    17,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    55,     2,
      13,    57,    12,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    63,     2,    64,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    51,    61,    52,     2,     2,     2,     2,
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
      41,    42,    43,    44,    45,    46,    47,    48,    49,    50
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   434,   434,   435,   436,   437,   444,   444,   455,   456,
     459,   460,   469,   472,   469,   528,   547,   573,   579,   580,
     583,   587,   592,   593,   596,   597,   598,   599,   602,   603,
     604,   605,   634,   638,   638,   663,   663,   687,   690,   693,
     694,   696,   699,   702,   735,   738,   739,   837,   843,   849,
     855,   864,   867,   870,   904,   907,   910,  1007,  1013,  1019,
    1025,  1033,  1037,  1043,  1050,  1051,  1054,  1059,  1064,  1069,
    1074,  1079,  1086,  1091,  1095,  1101,  1113,  1113,  1133,  1133,
    1156,  1163,  1167,  1163,  1181,  1196,  1181,  1224,  1225,  1228,
    1240,  1252,  1264,  1276,  1288,  1306,  1307,  1308,  1311,  1334,
    1360,  1368,  1377,  1398,  1421
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
  "'/'", "UMINUS", "LOWER_THAN_ELSE", "ELSE", "BREAK", "CHAR", "CASE",
  "CLASS", "CONTINUE", "DECLARE", "DO", "IF", "EXIT", "FOR", "FUN", "LOOP",
  "PRINT", "PRINTLN", "RETURN", "VAL", "VAR", "WHILE", "READ", "IN",
  "TRUE", "FALSE", "str", "id", "integer", "real", "KW_STRING", "INT",
  "FLOAT", "BOOL", "'{'", "'}'", "'('", "')'", "':'", "','", "'='", "'%'",
  "'!'", "'&'", "'|'", "'.'", "'['", "']'", "$accept", "program", "class",
  "$@1", "declaration_and_function", "declarations_and_functions",
  "function", "$@2", "@3", "arguments", "argument", "seperator",
  "returnType", "statements", "type", "statement", "$@4", "$@5", "return",
  "returnValue", "declaration_value", "expression", "expression_list",
  "boolean", "integer_expression", "bool_expresssion", "condition", "$@6",
  "$@7", "IF_PREACT", "loop", "@8", "$@9", "@10", "$@11",
  "one_or_multiple_line", "comparison", "declaration",
  "constant_declaration", "variable_declaration", "arrays_declaration", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-118)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-61)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    -118,   224,  -118,   -21,   -12,    14,    19,  -118,  -118,  -118,
    -118,  -118,  -118,   -37,  -118,   -31,   -26,  -118,    11,    32,
     385,    32,   385,    23,  -118,  -118,  -118,  -118,  -118,    12,
     406,  -118,  -118,   206,    58,   226,   237,   406,   406,  -118,
     261,   292,   316,   327,   347,   -41,  -118,    23,    33,  -118,
    -118,   -29,   385,  -118,    37,  -118,  -118,   406,    45,  -118,
    -118,  -118,  -118,   406,    85,   261,   406,   406,   406,   406,
     406,   406,   406,   406,   406,   406,   406,   406,   406,   385,
      59,  -118,  -118,    53,    57,  -118,  -118,   406,   116,   261,
      30,   382,    -5,    -5,    -5,    -5,    -5,    -5,   362,   362,
      45,    45,   261,   261,   261,  -118,    49,    32,    32,  -118,
      35,  -118,   402,   406,  -118,    61,  -118,   436,  -118,   261,
    -118,  -118,    67,    68,  -118,  -118,   406,  -118,    70,    77,
     455,  -118,  -118,  -118,  -118,  -118,  -118,   406,    91,   406,
     406,  -118,   261,    83,  -118,   406,    86,   455,   140,    97,
     261,   261,   406,   261,  -118,  -118,  -118,   406,   151,   436,
     261,  -118,   122,    79,   436,  -118,    82,  -118,   436,   436,
     406,  -118,  -118,   171,  -118,   436,  -118
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       5,     0,     1,     0,     0,     0,     0,     4,     3,     2,
      95,    96,    97,     0,    12,     0,   100,     6,     0,     0,
       0,     0,     0,    11,    16,    24,    25,    27,    26,     0,
       0,    64,    65,    48,    46,    47,    50,     0,     0,    98,
       0,    49,    41,    44,    45,   101,   102,    11,     0,     9,
       8,     0,     0,    58,    56,    57,    60,     0,    67,    59,
      51,    54,    55,    61,     0,    72,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    10,     7,     0,    20,    15,    99,    61,     0,    62,
       0,    42,    94,    91,    93,    90,    92,    89,    66,    68,
      69,    70,    71,    73,    74,   103,     0,     0,     0,    13,
       0,    52,    43,     0,   104,    19,    21,     0,    53,    63,
      18,    17,     0,     0,    33,    35,    40,    81,     0,     0,
      22,    88,    32,    29,    30,    14,    28,     0,     0,     0,
       0,    38,    39,     0,    37,     0,     0,    22,     0,     0,
      34,    36,     0,    31,    87,    23,    80,     0,     0,     0,
      84,    82,    75,     0,     0,    76,     0,    83,     0,     0,
       0,    77,    79,     0,    85,     0,    86
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -118,  -118,  -118,  -118,  -118,   104,   161,  -118,  -118,  -118,
    -118,  -118,  -118,    22,   -20,  -117,  -118,  -118,  -118,  -118,
      -1,   -30,    84,   -18,   -17,    -3,  -118,  -118,  -118,  -118,
    -118,  -118,  -118,  -118,  -118,   121,    -2,     5,  -118,  -118,
    -118
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     1,     7,    23,    47,    48,    49,    18,   117,    51,
      85,   121,   109,   146,    29,   131,   139,   140,   132,   141,
      39,    40,    90,    59,    60,    61,   133,   168,   169,   159,
     134,   143,   164,   163,   175,   135,    62,   136,    10,    11,
      12
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      58,    45,    41,    42,    41,    42,     9,    64,    65,    72,
      73,    74,    75,   147,    17,    83,    79,    43,    44,    43,
      44,    46,    80,    13,    19,    84,    20,    88,    50,    21,
     147,    22,    14,    89,    41,    42,    92,    93,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,    43,
      44,    86,    50,    76,     4,    77,    78,    89,    15,     5,
       6,    41,    42,    16,    24,   -56,   -56,   -56,   -56,    52,
     -56,   -56,   -56,   -56,   -56,   -56,    43,    44,   105,    25,
      26,    27,    28,   119,   112,    82,   113,   115,   116,   118,
      87,   113,    66,    67,    68,    69,   142,    70,    71,    72,
      73,    74,    75,    76,   106,    77,    78,   148,   107,   150,
     151,    63,   108,   114,   144,   153,   -56,   120,   -56,   -56,
     137,   138,   158,    66,    67,    68,    69,   160,    70,    71,
      72,    73,    74,    75,   145,   149,   152,   157,   154,    91,
     173,   166,   165,    76,   170,    77,    78,    66,    67,    68,
      69,    81,    70,    71,    72,    73,    74,    75,    66,    67,
      68,    69,     8,    70,    71,    72,    73,    74,    75,   155,
     111,   110,     0,     0,    76,     0,    77,    78,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,     0,
       0,     0,     0,     0,   156,     0,     0,     0,    76,     0,
      77,    78,     0,     0,     0,   161,     0,     0,     0,    76,
       0,    77,    78,   -58,   -58,   -58,   -58,     0,   -58,   -58,
     -58,   -58,   -58,   -58,     2,   174,     0,     0,     0,    76,
       0,    77,    78,   -57,   -57,   -57,   -57,     0,   -57,   -57,
     -57,   -57,   -57,   -57,   -60,   -60,   -60,   -60,     3,   -60,
     -60,   -60,   -60,   -60,   -60,     4,     0,     0,     0,     0,
       5,     6,     0,     0,   -58,     0,   -58,   -58,    66,    67,
      68,    69,     0,    70,    71,    72,    73,    74,    75,     0,
     162,     0,     0,     0,   -57,   167,   -57,   -57,     0,   171,
     172,     0,     0,     0,     0,   -60,   176,   -60,   -60,   -59,
     -59,   -59,   -59,     0,   -59,   -59,   -59,   -59,   -59,   -59,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    76,
       0,    77,    78,   -51,   -51,   -51,   -51,     0,   -51,   -51,
     -51,   -51,   -51,   -51,   -54,   -54,   -54,   -54,     0,   -54,
     -54,   -54,   -54,   -54,   -54,     0,     0,     0,     0,     0,
     -59,     0,   -59,   -59,   -55,   -55,   -55,   -55,     0,   -55,
     -55,   -55,   -55,   -55,   -55,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   -51,     0,   -51,   -51,    74,    75,
       0,     0,     0,     0,     0,   -54,     0,   -54,   -54,   -52,
     -52,   -52,   -52,     0,   -52,   -52,   -52,   -52,   -52,   -52,
      30,     0,     0,     0,     0,   -55,     0,   -55,   -55,   -53,
     -53,   -53,   -53,     0,   -53,   -53,   -53,   -53,   -53,   -53,
      76,    30,    77,    78,     0,     0,    31,    32,    33,    34,
      35,    36,     0,     0,     0,     0,     0,     0,    37,     0,
     -52,     0,   -52,   -52,    38,     0,     0,    31,    32,    53,
      54,    55,    56,     0,     0,     0,     0,     0,     0,    57,
     -53,     0,   -53,   -53,   122,    38,   123,     0,     0,   124,
     125,   126,     5,     6,   127,   128,     0,     0,     0,     0,
     129,     0,     0,   122,     0,   123,     0,   130,   124,   125,
     126,     5,     6,   127,   128,     0,     0,     0,     0,   129
};

static const yytype_int16 yycheck[] =
{
      30,    21,    20,    20,    22,    22,     1,    37,    38,    14,
      15,    16,    17,   130,    51,    44,    57,    20,    20,    22,
      22,    22,    63,    44,    55,    54,    57,    57,    23,    55,
     147,    57,    44,    63,    52,    52,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    52,
      52,    52,    47,    58,    31,    60,    61,    87,    44,    36,
      37,    79,    79,    44,    53,     7,     8,     9,    10,    57,
      12,    13,    14,    15,    16,    17,    79,    79,    79,    47,
      48,    49,    50,   113,    54,    52,    56,   107,   108,    54,
      53,    56,     7,     8,     9,    10,   126,    12,    13,    14,
      15,    16,    17,    58,    45,    60,    61,   137,    55,   139,
     140,    53,    55,    64,    44,   145,    58,    56,    60,    61,
      53,    53,   152,     7,     8,     9,    10,   157,    12,    13,
      14,    15,    16,    17,    57,    44,    53,    40,    52,    54,
     170,    62,    20,    58,    62,    60,    61,     7,     8,     9,
      10,    47,    12,    13,    14,    15,    16,    17,     7,     8,
       9,    10,     1,    12,    13,    14,    15,    16,    17,   147,
      54,    87,    -1,    -1,    58,    -1,    60,    61,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,    -1,
      60,    61,    -1,    -1,    -1,    54,    -1,    -1,    -1,    58,
      -1,    60,    61,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,     0,    54,    -1,    -1,    -1,    58,
      -1,    60,    61,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,     7,     8,     9,    10,    24,    12,
      13,    14,    15,    16,    17,    31,    -1,    -1,    -1,    -1,
      36,    37,    -1,    -1,    58,    -1,    60,    61,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,    16,    17,    -1,
     159,    -1,    -1,    -1,    58,   164,    60,    61,    -1,   168,
     169,    -1,    -1,    -1,    -1,    58,   175,    60,    61,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    58,
      -1,    60,    61,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      58,    -1,    60,    61,     7,     8,     9,    10,    -1,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    58,    -1,    60,    61,    16,    17,
      -1,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      15,    -1,    -1,    -1,    -1,    58,    -1,    60,    61,     7,
       8,     9,    10,    -1,    12,    13,    14,    15,    16,    17,
      58,    15,    60,    61,    -1,    -1,    41,    42,    43,    44,
      45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,    -1,
      58,    -1,    60,    61,    59,    -1,    -1,    41,    42,    43,
      44,    45,    46,    -1,    -1,    -1,    -1,    -1,    -1,    53,
      58,    -1,    60,    61,    28,    59,    30,    -1,    -1,    33,
      34,    35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,
      44,    -1,    -1,    28,    -1,    30,    -1,    51,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    44
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    66,     0,    24,    31,    36,    37,    67,    71,   102,
     103,   104,   105,    44,    44,    44,    44,    51,    72,    55,
      57,    55,    57,    68,    53,    47,    48,    49,    50,    79,
      15,    41,    42,    43,    44,    45,    46,    53,    59,    85,
      86,    88,    89,    90,   101,    79,    85,    69,    70,    71,
     102,    74,    57,    43,    44,    45,    46,    53,    86,    88,
      89,    90,   101,    53,    86,    86,     7,     8,     9,    10,
      12,    13,    14,    15,    16,    17,    58,    60,    61,    57,
      63,    70,    52,    44,    54,    75,    85,    53,    86,    86,
      87,    54,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    85,    45,    55,    55,    77,
      87,    54,    54,    56,    64,    79,    79,    73,    54,    86,
      56,    76,    28,    30,    33,    34,    35,    38,    39,    44,
      51,    80,    83,    91,    95,   100,   102,    53,    53,    81,
      82,    84,    86,    96,    44,    57,    78,    80,    86,    44,
      86,    86,    53,    86,    52,    78,    54,    40,    86,    94,
      86,    54,   100,    98,    97,    20,    62,   100,    92,    93,
      62,   100,   100,    86,    54,    99,   100
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    65,    66,    66,    66,    66,    68,    67,    69,    69,
      70,    70,    72,    73,    71,    74,    74,    75,    76,    76,
      77,    77,    78,    78,    79,    79,    79,    79,    80,    80,
      80,    80,    80,    81,    80,    82,    80,    80,    83,    84,
      84,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    87,    87,    87,    88,    88,    89,    89,    89,    89,
      89,    89,    90,    90,    90,    91,    92,    91,    93,    91,
      94,    96,    97,    95,    98,    99,    95,   100,   100,   101,
     101,   101,   101,   101,   101,   102,   102,   102,   103,   103,
     104,   104,   104,   104,   105
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     2,     2,     0,     0,     6,     1,     1,
       2,     0,     0,     0,     9,     2,     0,     4,     1,     0,
       0,     2,     0,     2,     1,     1,     1,     1,     1,     1,
       1,     3,     1,     0,     3,     0,     3,     2,     2,     1,
       0,     1,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     1,     3,     4,     1,     1,     1,     1,     1,     1,
       1,     0,     1,     3,     1,     1,     3,     2,     3,     3,
       3,     3,     2,     3,     3,     6,     0,     9,     0,     9,
       0,     0,     0,     7,     0,     0,    12,     3,     1,     3,
       3,     3,     3,     3,     3,     1,     1,     1,     4,     6,
       2,     4,     4,     6,     7
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
  case 6: /* $@1: %empty  */
#line 444 "hw3.y"
                             {
                        fprintf(output, "class %s {\n", (yyvsp[-1].token)._str);
                        ClassName = std::string((yyvsp[-1].token)._str);
                        resetList();
                }
#line 1871 "y.tab.c"
    break;

  case 7: /* class: CLASS id '{' $@1 declarations_and_functions '}'  */
#line 449 "hw3.y"
                                              {
                        fprintf(output, "}");
                }
#line 1879 "y.tab.c"
    break;

  case 12: /* $@2: %empty  */
#line 469 "hw3.y"
                       {
                        ENTERSCOPE();
                }
#line 1887 "y.tab.c"
    break;

  case 13: /* @3: %empty  */
#line 472 "hw3.y"
                                    {
						SymbolDesc * sd = new SymbolDesc();	
						std::vector<int> * varlist2 =(std::vector<int> *)(yyvsp[-2].token)._ptr;
						SymbolDesc * retype = (SymbolDesc*)(yyvsp[0].token)._ptr; 
						sd->symtype = SymbolType::sfunction;
						uDependency dep;
						dep.retType = (yyvsp[0].token).type;
						printf("<%d>", dep.retType);
						sd->symdeps.push_back(dep);
						SCOPERET.push_back(dep.retType);
                        fprintf(output, "\tmethod public static ");
                        fprintf(output, "%s ", SymType2Str((yyvsp[0].token).type));
                        fprintf(output, "%s", (yyvsp[-5].token)._str);
                        fprintf(output, "(");
                        if(strcmp((yyvsp[-5].token)._str, "main") != 0){
                                // if(varList != NULL){
                                //         int i = 0;
                                //         for(i;i<255 && varList[i]!=-1;i++){
                                //                 if(i!=0){
                                //                         fprintf(output, ", ");
                                //                 }
                                //                 fprintf(output, "%s", SymType2Str(varList[i]));
                                //         }
                                // }
								if(varlist2 != nullptr) {
									for(int i = 0 , j = varlist2->size() ;  i < j; ++i){
										dep.argType = (*varlist2)[i];
										sd->symdeps.push_back(dep);
										if(i!=0){
                                            fprintf(output, ", ");
                                        }
										fprintf(output, "%s", SymType2Str((*varlist2)[i]));
									}
								}
                                fprintf(output, ")\n");
                                resetList();
                        }else{
                                fprintf(output, "java.lang.String[])\n");  
                                //fprintf(output, ""); 
                        }
						(yyval.token)._ptr = sd;
                        fprintf(output, "\tmax_stack 15\n\tmax_locals 15\n");
						delete varlist2,retype;
						sd->returnByFun = false;
						insert(std::string((yyvsp[-5].token)._str),*sd,1);	
						fprintf(output, "\t{\n");
                }
#line 1939 "y.tab.c"
    break;

  case 14: /* function: FUN id $@2 '(' arguments ')' returnType @3 one_or_multiple_line  */
#line 519 "hw3.y"
                                      {
                        if(strcmp((yyvsp[-7].token)._str, "main") == 0){
                                fprintf(output, "\t\treturn\n");
                        }
                        fprintf(output, "\t}\n");
                        LEAVESCOPE();
                 }
#line 1951 "y.tab.c"
    break;

  case 15: /* arguments: arguments argument  */
#line 528 "hw3.y"
                             {
				//printf("123");
				SymbolDesc sd;
				uDependency value;
                // int i = 0;
                // for(i;i<255 && varList[i]!=-1;i++){
                //         printf("%d", varList[i]);
                // }
				sd.symtype = Token2Symbol((yyvsp[0].token).type);
				value.value = (yyvsp[0].token)._ptr;
                                
				sd.symdeps.push_back(value);
				insertArg((yyvsp[0].token)._str, sd);
				(yyval.token) = (yyvsp[-1].token);
				//printf("%d", sd.symtype);
				(yyval.token).type = TokenType::typeList;
				((std::vector<int>*)(yyval.token)._ptr)->push_back(sd.symtype);
                //insertList($2.type);
        }
#line 1975 "y.tab.c"
    break;

  case 16: /* arguments: %empty  */
#line 547 "hw3.y"
                      {
				(yyval.token).type = TokenType::typeList;
				(yyval.token)._ptr = new std::vector<int>();
			}
#line 1984 "y.tab.c"
    break;

  case 17: /* argument: id ':' type seperator  */
#line 573 "hw3.y"
                                {
		//printf("123");
        (yyval.token) = (yyvsp[-3].token);
		(yyval.token).type = (yyvsp[-1].token).type;
}
#line 1994 "y.tab.c"
    break;

  case 20: /* returnType: %empty  */
#line 583 "hw3.y"
                    {
        (yyval.token).type = none;
		(yyval.token)._ptr = nullptr;
        }
#line 2003 "y.tab.c"
    break;

  case 21: /* returnType: ':' type  */
#line 587 "hw3.y"
                      {
                (yyval.token).type = (yyvsp[0].token).type;
            }
#line 2011 "y.tab.c"
    break;

  case 24: /* type: KW_STRING  */
#line 596 "hw3.y"
                   {(yyval.token).type = sstring;}
#line 2017 "y.tab.c"
    break;

  case 25: /* type: INT  */
#line 597 "hw3.y"
                {(yyval.token).type = sinteger;}
#line 2023 "y.tab.c"
    break;

  case 26: /* type: BOOL  */
#line 598 "hw3.y"
                {(yyval.token).type = sboolean;}
#line 2029 "y.tab.c"
    break;

  case 27: /* type: FLOAT  */
#line 599 "hw3.y"
                {(yyval.token).type = sreal;}
#line 2035 "y.tab.c"
    break;

  case 31: /* statement: id '=' expression  */
#line 605 "hw3.y"
                           {
			SymbolDesc * pSD;
		if(seize(std::string((yyvsp[-2].token)._str),pSD)){
			if(pSD->readonly){
				//Error("Assignment to Readonly Variable!");
			}
			else if(pSD->symtype != Token2Symbol((yyvsp[0].token).type)){
				//Error("Type Unmatch");
			}
			else {
				if(pSD->global){
					fprintf(output, "putstatic %s %s.%s\n", SymType2JBStr(pSD->symtype).c_str(), ClassName.c_str(), (yyvsp[-2].token)._str);
				}
				else{
					switch(pSD->symtype){
						case SymbolType::sinteger:
						fprintf(output, "istore %d\n",  pSD->symindex);
						break;
						case SymbolType::sreal:
						fprintf(output, "fstore  %d\n", pSD->symindex);
						break;
						case SymbolType::sstring:
						fprintf(output, "astore  %d\n", pSD->symindex);
						break;
					}
				}
			}
		}
		}
#line 2069 "y.tab.c"
    break;

  case 32: /* statement: return  */
#line 634 "hw3.y"
                {
                fprintf(output, "\t\tireturn\n");
        }
#line 2077 "y.tab.c"
    break;

  case 33: /* $@4: %empty  */
#line 638 "hw3.y"
                {
                fprintf(output, "\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
        }
#line 2085 "y.tab.c"
    break;

  case 34: /* statement: PRINT $@4 expression  */
#line 640 "hw3.y"
                    {
                fprintf(output, "\t\tinvokevirtual void java.io.PrintStream.print(");
                switch((yyvsp[0].token).type){
		case vint:
			fprintf(output, "int");
			break;
		case vreal:
			fprintf(output, "float");
			break;
		case vbool:
			fprintf(output, "boolean");
			break;
		case vstring:
			fprintf(output, "java.lang.String");
			break;
		case blank:
			fprintf(output, "void");
		default:
			break;
		}
                fprintf(output, ")\n");
        }
#line 2112 "y.tab.c"
    break;

  case 35: /* $@5: %empty  */
#line 663 "hw3.y"
                  {
                fprintf(output, "\t\tgetstatic java.io.PrintStream java.lang.System.out\n");
        }
#line 2120 "y.tab.c"
    break;

  case 36: /* statement: PRINTLN $@5 expression  */
#line 665 "hw3.y"
                   {
                fprintf(output, "\t\tinvokevirtual void java.io.PrintStream.println(");
                switch((yyvsp[0].token).type){
		case vint:
			fprintf(output, "int");
			break;
		case vreal:
			fprintf(output, "float");
			break;
		case vbool:
			fprintf(output, "boolean");
			break;
		case vstring:
			fprintf(output, "java.lang.String");
			break;
		case blank:
			fprintf(output, "void");
		default:
			break;
		}
                fprintf(output, ")\n");
        }
#line 2147 "y.tab.c"
    break;

  case 41: /* declaration_value: integer_expression  */
#line 696 "hw3.y"
                                     {
					(yyval.token).returnByFun = false;
				}
#line 2155 "y.tab.c"
    break;

  case 42: /* declaration_value: '(' expression ')'  */
#line 699 "hw3.y"
                                {
                (yyval.token) = (yyvsp[-1].token);
            }
#line 2163 "y.tab.c"
    break;

  case 43: /* declaration_value: id '(' expression_list ')'  */
#line 702 "hw3.y"
                                        {
				SymbolDesc * pSD;
				(yyval.token).returnByFun = true;
				std::string idName = std::string((yyvsp[-3].token)._str);
				delete (yyvsp[-3].token)._str;

				if(seize(idName,pSD)){
					std::vector<int> * list = (std::vector<int>*)(yyvsp[-1].token)._ptr;
					if(pSD->symtype != SymbolType::sfunction){
						//Error(id + ": Is not a Function");
					}
					else if(!matchArgs(*list,*pSD)){
						//Error("Argument type Unmatch");
					}
					else{
						fprintf(output, "invokestatic %s %s.%s(", SymType2JBStr(pSD->symdeps[0].retType).c_str(), ClassName.c_str(), idName.c_str());
						for(int i = 0 ; i < list->size();++i ){
							fprintf(output, "%s", SymType2JBStr((*list)[i]).c_str());
							if(i != list->size()-1){
								fprintf(output, ", ");
							}
						}
						fprintf(output, ")\n");

						(yyval.token).type = Symbol2Token(pSD->symdeps[0].retType);
						//$$.type = SymbolType::sfunction;
						delete list;
					}
				}
				else {
					(yyval.token).type = TokenType::blank;
				}
			}
#line 2201 "y.tab.c"
    break;

  case 44: /* declaration_value: bool_expresssion  */
#line 735 "hw3.y"
                              {
				(yyval.token).returnByFun = false;
			}
#line 2209 "y.tab.c"
    break;

  case 46: /* declaration_value: id  */
#line 739 "hw3.y"
                {
                SymbolDesc * pSD;
				(yyval.token).returnByFun = false;
				if(seize(std::string((yyvsp[0].token)._str),pSD)){
					(yyval.token).type = Symbol2Token(pSD->symtype);
					
					if(pSD->readonly){
						switch(pSD->symtype){
							case SymbolType::sinteger:
							fprintf(output, "sipush %d\n", pSD->symdeps[0]._int);
							(yyval.token).type = TokenType::vint;
							break;
							case SymbolType::sboolean:
							if(pSD->symdeps[0]._bool){
								fprintf(output, "iconst_1\n");
							}
							else {
								fprintf(output, "iconst_0\n");
							}
							(yyval.token).type = TokenType::vbool;
							break;
							case SymbolType::sstring:
							fprintf(output, "ldc %s\n", pSD->symdeps[0]._str);
							(yyval.token).type = TokenType::vstring;
							break;
							case SymbolType::sreal:
							fprintf(output, "ldc %sf\n", pSD->symdeps[0]._real);
							break;
							default:
							break;

						}
					}
					else {
						//If ID is a Variable.
						if(pSD->global){
							//If ID is global variable.
							fprintf(output, "getstatic");
							switch(pSD->symtype){
								case SymbolType::sinteger:
								fprintf(output, " int ");
								(yyval.token).type = TokenType::vint;
								break;
								case SymbolType::sreal:
								fprintf(output, " float ");
								(yyval.token).type = TokenType::vreal;
								break;
								case SymbolType::sstring:
								fprintf(output, " java.lang.String ");
								(yyval.token).type = TokenType::vstring;
								break;
								/*case SymbolType::boolean:
								jbfile << " boolean ";
								$$.type = TokenType::vbool;
								break;
								case SymbolType::array:
								jbfile << " array ";
								$$.type = TokenType::varray;
								break;*/
								default:
								break;
							}
							fprintf(output, "%s.%s\n", ClassName.c_str(), (yyvsp[0].token)._str);
						}
						else{
							//If ID is local variable.
							switch(pSD->symtype){
								case SymbolType::sinteger:
								fprintf(output, "iload %d\n", pSD->symindex);
								(yyval.token).type = TokenType::vint;
								break;
								case SymbolType::sreal:
								fprintf(output, "fload %d\n", pSD->symindex);
								(yyval.token).type = TokenType::vreal;
								break;
								case SymbolType::sstring:
								fprintf(output, "aload %d\n", pSD->symindex);
								(yyval.token).type = TokenType::vstring;
								break;
								/*case SymbolType::boolean:
								jbfile << "cload " << <<endl;
								break;
								case SymbolType::std::string:
								jbfile << "sload " << <<endl;
								break;
								case SymbolType::array:
								jbfile << "aload " << <<endl;
								break;*/
								default:
								break;
							}
						}
					}
				}
				else {
				}
				delete (yyvsp[0].token)._str;
            }
#line 2312 "y.tab.c"
    break;

  case 47: /* declaration_value: integer  */
#line 837 "hw3.y"
                      {
                (yyval.token) = (yyvsp[0].token);
                (yyval.token).type = vint;
				(yyval.token).returnByFun = false;
                //fprintf(output, "sipush %d\n", $1._int);
            }
#line 2323 "y.tab.c"
    break;

  case 48: /* declaration_value: str  */
#line 843 "hw3.y"
                  {
                (yyval.token) = (yyvsp[0].token);
                (yyval.token).type = vstring;
				(yyval.token).returnByFun = false;
                //fprintf(output, "\t\tldc %s\n", $1._str);
            }
#line 2334 "y.tab.c"
    break;

  case 49: /* declaration_value: boolean  */
#line 849 "hw3.y"
                      {
                (yyval.token) = (yyvsp[0].token);
                (yyval.token).type = vbool;
				(yyval.token).returnByFun = false;
                //fprintf(output, "ldc %s\n", $1);
            }
#line 2345 "y.tab.c"
    break;

  case 50: /* declaration_value: real  */
#line 855 "hw3.y"
                   {
                (yyval.token) = (yyvsp[0].token);
                (yyval.token).type = vreal;
				(yyval.token).returnByFun = false;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                        
                //fprintf(output, "ldc %s\n", $1);
            }
#line 2356 "y.tab.c"
    break;

  case 51: /* expression: integer_expression  */
#line 864 "hw3.y"
                              {
				(yyval.token).returnByFun = false;
			}
#line 2364 "y.tab.c"
    break;

  case 52: /* expression: '(' expression ')'  */
#line 867 "hw3.y"
                                {
                (yyval.token) = (yyvsp[-1].token);
            }
#line 2372 "y.tab.c"
    break;

  case 53: /* expression: id '(' expression_list ')'  */
#line 870 "hw3.y"
                                        {
				SymbolDesc * pSD;
		std::string idName = std::string((yyvsp[-3].token)._str);
		delete (yyvsp[-3].token)._str;

		if(seize(idName,pSD)){
			std::vector<int> * list = (std::vector<int>*)(yyvsp[-1].token)._ptr;
			if(pSD->symtype != SymbolType::sfunction){
				//Error(id + ": Is not a Function");
			}
			else if(!matchArgs(*list,*pSD)){
				//Error("Argument type Unmatch");
			}
			else{
				printf("%d", pSD->symdeps[0].retType);
				fprintf(output, "invokestatic %s %s.%s(", SymType2JBStr(pSD->symdeps[0].retType).c_str(), ClassName.c_str(), idName.c_str());
				for(int i = 0 ; i < list->size();++i ){
					fprintf(output, "%s", SymType2JBStr((*list)[i]).c_str());
					if(i != list->size()-1){
						fprintf(output, ", ");
					}
				}
				fprintf(output, ")\n");

				(yyval.token).type = Symbol2Token(pSD->symdeps[0].retType);
				(yyval.token).returnByFun = true;
				//$$.type = SymbolType::sfunction;
				delete list;
			}
		}
		else {
			(yyval.token).type = TokenType::blank;
		}
			}
#line 2411 "y.tab.c"
    break;

  case 54: /* expression: bool_expresssion  */
#line 904 "hw3.y"
                              {
				(yyval.token).returnByFun = false;
			}
#line 2419 "y.tab.c"
    break;

  case 55: /* expression: comparison  */
#line 907 "hw3.y"
                        {
				(yyval.token).returnByFun = false;
			}
#line 2427 "y.tab.c"
    break;

  case 56: /* expression: id  */
#line 910 "hw3.y"
                {
                SymbolDesc * pSD;
				(yyval.token).returnByFun = false;
				if(seize(std::string((yyvsp[0].token)._str),pSD)){
					(yyval.token).type = Symbol2Token(pSD->symtype);
					if(pSD->readonly){
						switch(pSD->symtype){
							case SymbolType::sinteger:
							fprintf(output, "sipush %d\n", pSD->symdeps[0]._int);
							(yyval.token).type = TokenType::vint;
							break;
							case SymbolType::sboolean:
							if(pSD->symdeps[0]._bool){
								fprintf(output, "iconst_1\n");
							}
							else {
								fprintf(output, "iconst_0\n");
							}
							(yyval.token).type = TokenType::vbool;
							break;
							case SymbolType::sstring:
							fprintf(output, "ldc %s\n", pSD->symdeps[0]._str);
							(yyval.token).type = TokenType::vstring;
							break;
							case SymbolType::sreal:
							fprintf(output, "ldc %sf\n", pSD->symdeps[0]._real);
							break;
							default:
							break;

						}
					}
					else {
						//If ID is a Variable.
						if(pSD->global){
							//If ID is global variable.
							fprintf(output, "getstatic");
							switch(pSD->symtype){
								case SymbolType::sinteger:
								fprintf(output, " int ");
								(yyval.token).type = TokenType::vint;
								break;
								case SymbolType::sreal:
								fprintf(output, " float ");
								(yyval.token).type = TokenType::vreal;
								break;
								case SymbolType::sstring:
								fprintf(output, " java.lang.String ");
								(yyval.token).type = TokenType::vstring;
								break;
								/*case SymbolType::boolean:
								jbfile << " boolean ";
								$$.type = TokenType::vbool;
								break;
								case SymbolType::array:
								jbfile << " array ";
								$$.type = TokenType::varray;
								break;*/
								default:
								break;
							}
							fprintf(output, "%s.%s\n", ClassName.c_str(), (yyvsp[0].token)._str);
						}
						else{
							//If ID is local variable.
							switch(pSD->symtype){
								case SymbolType::sinteger:
								fprintf(output, "iload %d\n", pSD->symindex);
								(yyval.token).type = TokenType::vint;
								break;
								case SymbolType::sreal:
								fprintf(output, "fload %d\n", pSD->symindex);
								(yyval.token).type = TokenType::vreal;
								break;
								case SymbolType::sstring:
								fprintf(output, "aload %d\n", pSD->symindex);
								(yyval.token).type = TokenType::vstring;
								break;
								/*case SymbolType::boolean:
								jbfile << "cload " << <<endl;
								break;
								case SymbolType::std::string:
								jbfile << "sload " << <<endl;
								break;
								case SymbolType::array:
								jbfile << "aload " << <<endl;
								break;*/
								default:
								break;
							}
						}
					}
				}
				else {
				}
				delete (yyvsp[0].token)._str;
            }
#line 2529 "y.tab.c"
    break;

  case 57: /* expression: integer  */
#line 1007 "hw3.y"
                      {
                (yyval.token) = (yyvsp[0].token);
                (yyval.token).type = vint;
				(yyval.token).returnByFun = false;
                fprintf(output, "sipush %d\n", (yyvsp[0].token)._int);
            }
#line 2540 "y.tab.c"
    break;

  case 58: /* expression: str  */
#line 1013 "hw3.y"
                  {
                (yyval.token) = (yyvsp[0].token);
                (yyval.token).type = vstring;
				(yyval.token).returnByFun = false;
                fprintf(output, "\t\tldc %s\n", (yyvsp[0].token)._str);
            }
#line 2551 "y.tab.c"
    break;

  case 59: /* expression: boolean  */
#line 1019 "hw3.y"
                      {
                (yyval.token) = (yyvsp[0].token);
                (yyval.token).type = vbool;
				(yyval.token).returnByFun = false;
                //fprintf(output, "ldc %s\n", $1);
            }
#line 2562 "y.tab.c"
    break;

  case 60: /* expression: real  */
#line 1025 "hw3.y"
                   {
                (yyval.token) = (yyvsp[0].token);
                (yyval.token).type = vreal;
				(yyval.token).returnByFun = false;                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                  
                //fprintf(output, "ldc %s\n", $1);
            }
#line 2573 "y.tab.c"
    break;

  case 61: /* expression_list: %empty  */
#line 1033 "hw3.y"
                 {
					(yyval.token).type = TokenType::typeList;
					(yyval.token)._ptr = new std::vector<int>();
				}
#line 2582 "y.tab.c"
    break;

  case 62: /* expression_list: expression  */
#line 1037 "hw3.y"
                           {
					(yyval.token).type = TokenType::typeList;
					std::vector<int> & list = *(new std::vector<int>());
					list.push_back(Token2Symbol((yyvsp[0].token).type));
					(yyval.token)._ptr = &list;
				}
#line 2593 "y.tab.c"
    break;

  case 63: /* expression_list: expression_list ',' expression  */
#line 1043 "hw3.y"
                                                               {
					(yyval.token) = (yyvsp[-2].token);
					std::vector<int> & list = *(std::vector<int>*)(yyval.token)._ptr;
					list.push_back(Token2Symbol((yyvsp[0].token).type));
				}
#line 2603 "y.tab.c"
    break;

  case 64: /* boolean: TRUE  */
#line 1050 "hw3.y"
                { (yyval.token)._bool = 1; }
#line 2609 "y.tab.c"
    break;

  case 65: /* boolean: FALSE  */
#line 1051 "hw3.y"
                { (yyval.token)._bool = 0; }
#line 2615 "y.tab.c"
    break;

  case 66: /* integer_expression: expression '+' expression  */
#line 1054 "hw3.y"
                                             {
						(yyval.token)._int = (yyvsp[-2].token)._int + (yyvsp[0].token)._int;
						(yyval.token).type = vint;
						fprintf(output, "\t\tiadd\n"); 
                    }
#line 2625 "y.tab.c"
    break;

  case 67: /* integer_expression: '-' expression  */
#line 1059 "hw3.y"
                                                   {
						(yyval.token)._int = -(yyvsp[0].token)._int;
                        (yyval.token).type = TokenType::vint;
						fprintf(output, "ineg\n");
                    }
#line 2635 "y.tab.c"
    break;

  case 68: /* integer_expression: expression '-' expression  */
#line 1064 "hw3.y"
                                               {
						(yyval.token)._int = (yyvsp[-2].token)._int - (yyvsp[0].token)._int;
						(yyval.token).type = TokenType::vint;
						fprintf(output, "isub\n");
		   			}
#line 2645 "y.tab.c"
    break;

  case 69: /* integer_expression: expression '*' expression  */
#line 1069 "hw3.y"
                                               {
						(yyval.token).type = TokenType::vint;
						(yyval.token)._int = (yyvsp[-2].token)._int * (yyvsp[0].token)._int;
						fprintf(output, "imul\n");
					}
#line 2655 "y.tab.c"
    break;

  case 70: /* integer_expression: expression '/' expression  */
#line 1074 "hw3.y"
                                               {
						(yyval.token)._int = (yyvsp[-2].token)._int / (yyvsp[0].token)._int;
						(yyval.token).type = TokenType::vint;
						fprintf(output, "idiv\n");
					}
#line 2665 "y.tab.c"
    break;

  case 71: /* integer_expression: expression '%' expression  */
#line 1079 "hw3.y"
                                               {
						(yyval.token)._int = (yyvsp[-2].token)._int % (yyvsp[0].token)._int;
						(yyval.token).type = TokenType::vint;
						fprintf(output, "irem\n");
					}
#line 2675 "y.tab.c"
    break;

  case 72: /* bool_expresssion: '!' expression  */
#line 1086 "hw3.y"
                                 {
                        (yyval.token).type = TokenType::vbool;
						fprintf(output, "iconst_1\n");
                        fprintf(output, "ixor\n");
                }
#line 2685 "y.tab.c"
    break;

  case 73: /* bool_expresssion: expression '&' expression  */
#line 1091 "hw3.y"
                                           {
                        (yyval.token).type = TokenType::vbool;
                        fprintf(output, "iand\n");
                }
#line 2694 "y.tab.c"
    break;

  case 74: /* bool_expresssion: expression '|' expression  */
#line 1095 "hw3.y"
                                           {
                        (yyval.token).type = TokenType::vbool;
                        fprintf(output, "ior\n");
                }
#line 2703 "y.tab.c"
    break;

  case 75: /* condition: IF '(' expression ')' IF_PREACT one_or_multiple_line  */
#line 1101 "hw3.y"
                                                                                       {	
			if((yyvsp[-3].token).type != TokenType::vbool){
				//Error("Expression must be boolean");
			}
			fprintf(output, "L%d:\n", (yyvsp[-1].token)._int-1);
		}
#line 2714 "y.tab.c"
    break;

  case 76: /* $@6: %empty  */
#line 1113 "hw3.y"
                                                                      {
			fprintf(output, "goto L%d\n", (yyvsp[-2].token)._int);
			fprintf(output, "L%d:\n", (yyvsp[-2].token)._int - 1);
		}
#line 2723 "y.tab.c"
    break;

  case 77: /* condition: IF '(' expression ')' IF_PREACT one_or_multiple_line ELSE $@6 one_or_multiple_line  */
#line 1117 "hw3.y"
                                      {	
			if((yyvsp[-6].token).type != TokenType::vbool){
				//Error("Expression must be boolean");
			}
			fprintf(output, "L%d:\n", (yyvsp[-4].token)._int);
		}
#line 2734 "y.tab.c"
    break;

  case 78: /* $@7: %empty  */
#line 1133 "hw3.y"
                                                                     {
			fprintf(output, "goto L%d\n", (yyvsp[-2].token)._int);
			fprintf(output, "L%d:\n", (yyvsp[-2].token)._int - 1);
		}
#line 2743 "y.tab.c"
    break;

  case 79: /* condition: IF '(' expression ')' IF_PREACT one_or_multiple_line ELSE $@7 one_or_multiple_line  */
#line 1137 "hw3.y"
                               {	
			if((yyvsp[-6].token).type != TokenType::vbool){
				//Error("Expression must be boolean");
			}
			fprintf(output, "L%d:\n", (yyvsp[-4].token)._int);
		}
#line 2754 "y.tab.c"
    break;

  case 80: /* IF_PREACT: %empty  */
#line 1156 "hw3.y"
           {
		fprintf(output, "ifeq L%d\n", LabelIndex++);
		(yyval.token)._int = LabelIndex++;
		printf("%d", LabelIndex);
	}
#line 2764 "y.tab.c"
    break;

  case 81: /* @8: %empty  */
#line 1163 "hw3.y"
            {
		fprintf(output, "L%d:\n", LabelIndex++);
		(yyval.token)._int = LabelIndex++;
	}
#line 2773 "y.tab.c"
    break;

  case 82: /* $@9: %empty  */
#line 1167 "hw3.y"
                          {
		 if((yyvsp[-1].token).type != TokenType::vbool){
			//Error("Expression must be boolean");
		}
		fprintf(output, "ifeq L%d\n", (yyvsp[-3].token)._int);
		}
#line 2784 "y.tab.c"
    break;

  case 83: /* loop: WHILE @8 '(' expression ')' $@9 one_or_multiple_line  */
#line 1173 "hw3.y"
                                     { 
		
		fprintf(output, "goto L%d\n", (yyvsp[-5].token)._int - 1);
		fprintf(output, "L%d:\n", (yyvsp[-5].token)._int);
		
		//Trail("While Stmt"); 
	}
#line 2796 "y.tab.c"
    break;

  case 84: /* @10: %empty  */
#line 1181 "hw3.y"
                               {
			SymbolDesc sd;
			uDependency value;

			sd.symtype = Token2Symbol((yyvsp[0].token).type);
			sd.iValue = (yyvsp[0].token)._int;
			value.value = (yyvsp[0].token)._ptr;
							
			sd.symdeps.push_back(value);
			sd.returnByFun = false;
			insert(std::string((yyvsp[-2].token)._str),sd);
			fprintf(output, "L%d:\n", LabelIndex++);
			(yyval.token)._int = LabelIndex++;
			fprintf(output, "iload %d\n", sd.symindex);
		}
#line 2816 "y.tab.c"
    break;

  case 85: /* $@11: %empty  */
#line 1196 "hw3.y"
                                       {
			std::string L1 = "L" + std::to_string(LabelIndex++);
			std::string L2 = "L" + std::to_string(LabelIndex++);
			fprintf(output, "isub\n");
			fprintf(output, "ifle %s\n", L1.c_str());
			fprintf(output, "iconst_0\n");
			fprintf(output, "goto %s\n", L2.c_str());
			fprintf(output, "%s:\n", L1.c_str());
			fprintf(output, "iconst_1\n");
			fprintf(output, "%s:\n", L2.c_str());
			fprintf(output, "ifeq L%d\n", (yyvsp[-4].token)._int);
		}
#line 2833 "y.tab.c"
    break;

  case 86: /* loop: FOR '(' id IN expression @10 '.' '.' expression ')' $@11 one_or_multiple_line  */
#line 1208 "hw3.y"
                                     { 
			SymbolDesc * pSD;
			if(seize(std::string((yyvsp[-9].token)._str),pSD)){
				fprintf(output, "iload %d\n", pSD->symindex);
				fprintf(output, "sipush 1\n");
				fprintf(output, "iadd\n");
				fprintf(output, "istore %d\n", pSD->symindex);
				fprintf(output, "goto L%d\n", (yyvsp[-6].token)._int - 1);
				fprintf(output, "L%d:\n", (yyvsp[-6].token)._int);
				
			}
			//Trail("While Stmt"); 
		}
#line 2851 "y.tab.c"
    break;

  case 89: /* comparison: expression '<' expression  */
#line 1228 "hw3.y"
                                     {
				(yyval.token).type = TokenType::vbool;
				std::string L1 = "L" + std::to_string(LabelIndex++);
				std::string L2 = "L" + std::to_string(LabelIndex++);
				fprintf(output, "isub\n");
				fprintf(output, "iflt %s\n", L1.c_str());
				fprintf(output, "iconst_0\n");
				fprintf(output, "goto %s\n", L2.c_str());
				fprintf(output, "%s:\n", L1.c_str());
				fprintf(output, "iconst_1\n");
				fprintf(output, "%s:\n", L2.c_str());
			}
#line 2868 "y.tab.c"
    break;

  case 90: /* comparison: expression LE expression  */
#line 1240 "hw3.y"
                                      {
				(yyval.token).type = TokenType::vbool;
				std::string L1 = "L" + std::to_string(LabelIndex++);
				std::string L2 = "L" + std::to_string(LabelIndex++);
				fprintf(output, "isub\n");
				fprintf(output, "ifle %s\n", L1.c_str());
				fprintf(output, "iconst_0\n");
				fprintf(output, "goto %s\n", L2.c_str());
				fprintf(output, "%s:\n", L1.c_str());
				fprintf(output, "iconst_1\n");
				fprintf(output, "%s:\n", L2.c_str());
			}
#line 2885 "y.tab.c"
    break;

  case 91: /* comparison: expression EQ expression  */
#line 1252 "hw3.y"
                                      {
				(yyval.token).type = TokenType::vbool;
				std::string L1 = "L" + std::to_string(LabelIndex++);
				std::string L2 = "L" + std::to_string(LabelIndex++);
				fprintf(output, "isub\n");
				fprintf(output, "ifeq %s\n", L1.c_str());
				fprintf(output, "iconst_0\n");
				fprintf(output, "goto %s\n", L2.c_str());
				fprintf(output, "%s:\n", L1.c_str());
				fprintf(output, "iconst_1\n");
				fprintf(output, "%s:\n", L2.c_str());
			}
#line 2902 "y.tab.c"
    break;

  case 92: /* comparison: expression '>' expression  */
#line 1264 "hw3.y"
                                       {
				(yyval.token).type = TokenType::vbool;
				std::string L1 = "L" + std::to_string(LabelIndex++);
				std::string L2 = "L" + std::to_string(LabelIndex++);
				fprintf(output, "isub\n");
				fprintf(output, "ifgt %s\n", L1.c_str());
				fprintf(output, "iconst_0\n");
				fprintf(output, "goto %s\n", L2.c_str());
				fprintf(output, "%s:\n", L1.c_str());
				fprintf(output, "iconst_1\n");
				fprintf(output, "%s:\n", L2.c_str());
			}
#line 2919 "y.tab.c"
    break;

  case 93: /* comparison: expression GE expression  */
#line 1276 "hw3.y"
                                      {
				(yyval.token).type = TokenType::vbool;
				std::string L1 = "L" + std::to_string(LabelIndex++);
				std::string L2 = "L" + std::to_string(LabelIndex++);
				fprintf(output, "isub\n");
				fprintf(output, "ifge %s\n", L1.c_str());
				fprintf(output, "iconst_0\n");
				fprintf(output, "goto %s\n", L2.c_str());
				fprintf(output, "%s:\n", L1.c_str());
				fprintf(output, "iconst_1\n");
				fprintf(output, "%s:\n", L2.c_str());
			}
#line 2936 "y.tab.c"
    break;

  case 94: /* comparison: expression NE expression  */
#line 1288 "hw3.y"
                                      {
				(yyval.token).type = TokenType::vbool;
				std::string L1 = "L" + std::to_string(LabelIndex++);
				std::string L2 = "L" + std::to_string(LabelIndex++);
				fprintf(output, "isub\n");
				fprintf(output, "ifne %s\n", L1.c_str());
				fprintf(output, "iconst_0\n");
				fprintf(output, "goto %s\n", L2.c_str());
				fprintf(output, "%s:\n", L1.c_str());
				fprintf(output, "iconst_1\n");
				fprintf(output, "%s:\n", L2.c_str());
			}
#line 2953 "y.tab.c"
    break;

  case 98: /* constant_declaration: VAL id '=' declaration_value  */
#line 1311 "hw3.y"
                                                  {
                                char * name = (yyvsp[-2].token)._str;
				SymbolDesc sd;
				uDependency value;

				sd.symtype = Token2Symbol((yyvsp[0].token).type);
				sd.readonly = true;
                                sd.hasValue = true;
                                if((yyvsp[0].token).type == vint){
                                        sd.iValue = (yyvsp[0].token)._int;
                                }else if((yyvsp[0].token).type == vbool){
                                        sd.bValue = (yyvsp[0].token)._bool;
                                }else if((yyvsp[0].token).type == vstring){
                                        sd.sValue = (yyvsp[0].token)._str;
                                }else if((yyvsp[0].token).type == vbool){
                                        sd.iValue = (yyvsp[0].token)._int;
                                }
				value.value = (yyvsp[0].token)._ptr;
                sd.returnByFun = (yyvsp[0].token).returnByFun;
				sd.symdeps.push_back(value);
				insert(std::string(name),sd);
				delete name;
                        }
#line 2981 "y.tab.c"
    break;

  case 99: /* constant_declaration: VAL id ':' type '=' declaration_value  */
#line 1334 "hw3.y"
                                                            {
                                char * name = (yyvsp[-4].token)._str;
				SymbolDesc sd;
				uDependency value;

				sd.symtype = Token2Symbol((yyvsp[-2].token).type);
				sd.readonly = true;
                                sd.hasValue = true;
                                if((yyvsp[-2].token).type == vint){
                                        sd.iValue = (yyvsp[0].token)._int;
                                }else if((yyvsp[-2].token).type == vbool){
                                        sd.bValue = (yyvsp[0].token)._bool;
                                }else if((yyvsp[-2].token).type == vstring){
                                        sd.sValue = (yyvsp[0].token)._str;
                                }else if((yyvsp[-2].token).type == vbool){
                                        sd.iValue = (yyvsp[0].token)._int;
                                }
				value.value = (yyvsp[0].token)._ptr;
                sd.returnByFun = (yyvsp[0].token).returnByFun;
				sd.symdeps.push_back(value);

				insert(std::string(name),sd);
				delete name;
                        }
#line 3010 "y.tab.c"
    break;

  case 100: /* variable_declaration: VAR id  */
#line 1360 "hw3.y"
                            { 
			char * name = (yyvsp[0].token)._str;
			SymbolDesc sd;
                        sd.symtype = sinteger;
						sd.returnByFun = false;
			insert(std::string(name),sd);
			delete name;
		    }
#line 3023 "y.tab.c"
    break;

  case 101: /* variable_declaration: VAR id ':' type  */
#line 1368 "hw3.y"
                                     { 
			std::string name((yyvsp[-2].token)._str);
			SymbolDesc sd;
                        sd.symtype = Token2Symbol((yyvsp[0].token).type);
						sd.returnByFun = false;
			insert(std::string(name),sd);

                        //printf("%s %s", name.c_str(), $2._str);
		    }
#line 3037 "y.tab.c"
    break;

  case 102: /* variable_declaration: VAR id '=' declaration_value  */
#line 1377 "hw3.y"
                                                  { 
			char * name = (yyvsp[-2].token)._str;
			SymbolDesc sd;
			uDependency value;
                        sd.symtype = Token2Symbol((yyvsp[0].token).type);
                        sd.hasValue = true;
                        if((yyvsp[0].token).type == vint){
                                sd.iValue = (yyvsp[0].token)._int;
                        }else if((yyvsp[0].token).type == vbool){
                                sd.bValue = (yyvsp[0].token)._bool;
                        }else if((yyvsp[0].token).type == vstring){
                                sd.sValue = (yyvsp[0].token)._str;
                        }else if((yyvsp[0].token).type == vbool){
                                sd.iValue = (yyvsp[0].token)._int;
                        }
			value.value = (yyvsp[0].token)._ptr;
			sd.returnByFun = (yyvsp[0].token).returnByFun;
                        sd.symdeps.push_back(value);
			insert(std::string(name),sd);
			delete name;
		    }
#line 3063 "y.tab.c"
    break;

  case 103: /* variable_declaration: VAR id ':' type '=' declaration_value  */
#line 1398 "hw3.y"
                                                           { 
			char * name = (yyvsp[-4].token)._str;
			SymbolDesc sd;
			uDependency value;
                        sd.symtype = Token2Symbol((yyvsp[-2].token).type);
                        sd.hasValue = true;
                        if((yyvsp[-2].token).type == vint){
                                sd.iValue = (yyvsp[0].token)._int;
                        }else if((yyvsp[-2].token).type == vbool){
                                sd.bValue = (yyvsp[0].token)._bool;
                        }else if((yyvsp[-2].token).type == vstring){
                                sd.sValue = (yyvsp[0].token)._str;
                        }else if((yyvsp[-2].token).type == vbool){
                                sd.iValue = (yyvsp[0].token)._int;
                        }
			value.value = (yyvsp[0].token)._ptr;
			sd.returnByFun = (yyvsp[0].token).returnByFun;
                        sd.symdeps.push_back(value);
			insert(std::string(name),sd);
			delete name;
		    }
#line 3089 "y.tab.c"
    break;


#line 3093 "y.tab.c"

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

#line 1430 "hw3.y"



/* int main(int argc, char** argv)
{
    if (argc != 2) {
        printf ("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r");         

    if (yyparse() == 1)                
        yyerror("Parsing error !");    
}
*/
void yyerror(char *msg)
{
    fprintf(stderr, "%s\n", msg);
}
int main(int argc, char **argv)
{
    /* open the source program file */
    if (argc != 2)
    {
        printf("Usage: sc filename\n");
        exit(1);
    }
    yyin = fopen(argv[1], "r"); /* open input file */

    output = fopen("output.jasm", "w");
    InitialTableStack();
    /* perform parsing */
    if (yyparse() == 1)             /* parsing */
        yyerror("Parsing error !"); /* syntax error */
    fclose(output);
}
