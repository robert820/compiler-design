%{
#include "SymbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#define Trace(t)        printf(t)
extern FILE *yyin;
int yylex();
void yyerror(char *s);
%}

%union {
    Hash*          symbol;
    int                      ivalue;
    char*                    str;
    float                    fvalue;
    _Bool                    bvalue;
    identifier_type*           identifier;
    value_type identifier_value_type;
}

%start program


/* tokens */
/*
%token SEMICOLON
*/
/*
%token id
%token string
%token integer
%token real
*/
%token DE ME SE AE NE EQ GE LE ARROW

//%token <str> identifier
//%token <ivalue> NUMBER
/*%left <integer> OP_ADDITION OP_SUBTRACTION
%left <integer> OP_MULTIPLICATION OP_DIVISION*/

%left '>' '<' LE EQ GE NE

%left '+' '-'
%left '*' '/'
%left UMINUS

%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

//%nonassoc ONE
//%nonassoc TWO
//%nonassoc THREE

//%nonassoc FOUR
//%nonassoc FIVE

%token BOOL BREAK CHAR CASE CLASS CONTINUE DECLARE DO IF EXIT FLOAT FOR FUN INT LOOP PRINT PRINTLN RETURN STRING  VAL VAR WHILE READ IN

%token <bvalue> TRUE
%token <bvalue> FALSE

//%type <ivalue> integer_expression
//%type <bvalue> bool_expresssion
%type <bvalue> boolean
%token <str> string id
%token <ivalue> integer
%token <fvalue> real

%%

program:  declaration function functions declarations
        | declarations class classes declarations
        ;

classes: class classes
        |/*empty*/
        ;

class:          CLASS id '{' declarations_and_functions '}'
                {
                Trace("Reducing to program\n");
                }
                ;

declaration_and_function: declaration
                        | function
                        ;

declarations_and_functions: declaration_and_function declarations_and_functions
                            |
                            ;



functions:      function functions
                |
                ;

function:       FUN id '(' arguments ')' returnType '{' statements '}'
                ;

arguments: argument arguments
            |/*empty*/
            ;

argument: id ':' type  seperator;

seperator: ','
            |/*empty*/
            ;

returnType:/*empty*/
            | ':' type
            ;

statements:/*empty*/
    | statement statements
    ;

type:   STRING {$$ = bool_v;}
        | INT
        | BOOL
        | FLOAT
        ;

statement: declaration
        | condition
        | loop
        | id '=' expression
        | return
        | PRINT '(' expression ')'
        | PRINT expression
        | PRINTLN '(' expression ')'
        | PRINTLN expression
        | READ id
        ;

return: RETURN returnValue
        ;

returnValue: expression
        |
        ;

expression: integer_expression
            | '(' expression ')'
            | id '(' expression_list ')'
            | bool_expresssion
            | comparison
            | id
            | integer
            | string
            | boolean
            | real
            ;

expression_list: 
                |expression
		|expression_list ',' expression
                ;

boolean: TRUE
        |FALSE
        ;

integer_expression: expression '+' expression
                    | '-' expression   %prec UMINUS
                    | expression '-' expression
                    | expression '*' expression
                    | expression '/' expression
                    ;

bool_expresssion:  '!' expression              //{$$ = !$2;}
                | expression '&' expression
                | expression '|' expression
                ;

condition: IF '(' expression ')' '{' statements '}' %prec LOWER_THAN_ELSE
        | IF '(' expression ')' statement %prec LOWER_THAN_ELSE
        | IF '(' expression ')' '{' statements '}' ELSE '{' statements '}' 
        | IF '(' expression ')' statement ELSE statement 
        | IF '(' expression ')' statement ELSE '{' statements '}'
        | IF '(' expression ')' '{' statements '}' ELSE statement 
        ;

loop: WHILE '(' expression ')' '{' statements '}'
    | WHILE '(' expression ')' statement
    | FOR '(' id IN expression '.' '.' expression ')' '{' statements '}'
    | FOR '(' id IN expression '.' '.' expression ')' statement
    ;

comparison: expression '<' expression
            | expression LE expression
            | expression EQ expression
            | expression '>' expression
            | expression GE expression
            | expression NE expression
            ;

declarations: declaration declarations
            | /*empty*/
            ;

declaration: constant_declaration
            |variable_declaration
            |arrays_declaration
            ;

constant_declaration: VAL id '=' expression
                    | VAL id ':' type '=' expression 
                    ;

variable_declaration: VAR id
                    | VAR id ':' type
                    | VAR id '=' expression
                    | VAR id ':' type '=' expression
                    ;

arrays_declaration: VAR id ':' type '[' integer ']'
                    ;

/*semi:           SEMICOLON
                {
                Trace("Reducing to semi\n");
                }
                ;
*/
%%

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
