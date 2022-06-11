#include "stdlib.h"
#include "stdio.h"
#include "SymbolTable.h"
#include "GenerateCode.h"
#include "y.tab.h"
extern FILE *yyin;

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

    /* perform parsing */
    if (yyparse() == 1)             /* parsing */
        yyerror("Parsing error !"); /* syntax error */
    FILE *output = fopen("output.jasm", "w");
    GenerateCode();
}