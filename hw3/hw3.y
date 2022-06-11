%{
#include "SymbolTable.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 
#include "ast.h"
#define Trace(t)        printf(t)
extern FILE *yyin;
int yylex();
void yyerror(char *s);

ast_node_t* n(ast_node_type_t t, YYLTYPE l) { return new_ast_node(t, l.first_line, l.first_column); }
void vid(ast_node_t *n, idtab_entry_t *v) { if (v) ast_node_set_value_identifier(n, v); }
void vopt(ast_node_t *n, int v) { ast_node_set_value_operatr(n, v); }
void vint(ast_node_t *n, int v) { ast_node_set_value_integer(n, v); }
void vstr(ast_node_t *n, char *v) { ast_node_set_value_string(n, v); }
void ich(ast_node_t *n, ast_node_t *child) { ast_node_insert_child(n, child); }
void isb(ast_node_t *n, ast_node_t *sibling) { ast_node_insert_sibling(n, sibling); }
void esp(idtab_entry_t *sid) { current_idtab = idtab_entry_idtab_create(current_idtab, sid); }
void lsp() { if (current_idtab->upper_idtab) current_idtab = current_idtab->upper_idtab; }
%}

%union {
    Hash*          symbol;
    int                      ivalue;
    char*                    str;
    float                    fvalue;
    _Bool                    bvalue;
    ValueType                valueType;
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

%token  BREAK CHAR CASE CLASS CONTINUE DECLARE DO IF EXIT FOR FUN LOOP PRINT PRINTLN RETURN VAL VAR WHILE READ IN

%token <bvalue> TRUE
%token <bvalue> FALSE

//%type <ivalue> integer_expression
//%type <bvalue> bool_expresssion
%type <bvalue> boolean
%type <valueType> type
%token <str> string id
%token <ivalue> integer
%token <fvalue> real
%token <valueType> STRING INT FLOAT BOOL

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

type:   STRING  {$$ = string_v;}
        | INT   {$$ = int_v;}
        | BOOL  {$$ = bool_v;}
        | FLOAT {$$ = real_v;}
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
