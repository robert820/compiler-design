%{
#define LIST     strcat(buf,yytext)
#define token(t) {LIST; printf("<%s>\n",#t);}
#define tokenInteger(t,i) {LIST; printf("<%s:%s>\n",#t,i); return t;}
#define tokenReal(t, r)	{LIST; printf("<%s:%s>\n", #t, r); return t;}
#define tokenString(t,s) {LIST; printf("<%s:%s>\n",#t,s); return t;}

#define MAX_LINE_LENG 256


#include "SymbolTable.h"
#include "y.tab.h"

int linenum = 1;
char buf[MAX_LINE_LENG];
Hash *symbolTable;
char *dumpResult;
%}

digit     [0-9]
letter    [A-Za-z]
identifier	{letter}({letter}|{digit})*
integer	[+-]?{digit}+
real	[+-]?{digit}*\.{digit}+([Ee]([+-]?{digit})*)?
string	\"(\\.|[^"\\])*\"
boolean true|false
%x COMMENT
%x S_COMMENT
%%
","	{
	token(',');
	return(',');
	}

":"	{
	token(':');
	return(':');
	}

";"	{
	token(';');
	return(';');
	}

"->"	{
	token('->');
	return(ARROW);
	}

"("     {
	token('(');
	return('(');
	}

")"	{
	token(')');
	return(')');
	}

"["	{
	token('[');
	return('[');
	}

"]"	{
	token(']');
	return(']');
	}

"{"	{
	token('{');
	return('{');
	}

"}"	{
	token('}');
	return('}');
	}

"+"	{
	token('+');
	return('+');
	}

"-"	{
	token('-');
	return('-');
	}

"*"	{
	token('*');
	return('*');
	}

"/"	{
	token('/');
	return('/');
	}

"%"	{
	token('%');
	return('%');
	}

"<"	{
	token('<');
	return('<');
	}

"<="	{
	token('<=');
	return(LE);
	}

">="	{
	token('>=');
	return(GE);
	}

">"	{
	token('>');
	return('>');
	}

"=="	{
	token('==');
	return(EQ);
	}

"!="	{
	token('!=');
	return(NE);
	}

"&"	{
	token('&');
	return('&');
	}

"|"	{
	token('|');
	return('|');
	}

"!"	{
	token('!');
	return('!');
	}

"="	{
	token('=');
	return('=');
	}

"+="	{
	token('+=');
	return(AE);
	}

"-="	{
	token('-=');
	return(SE);
	}

"*="	{
	token('*=');
	return(ME);
	}

"/="	{
	token('/=');
	return(DE);
	}

"class"	{
	token(CLASS);
	return(CLASS);
	}

"fun"	{
	token(FUN);
	return(FUN);
	}

"print" {
	token(PRINT);
	return(PRINT);
	}

"bool"	{
	token(BOOL);
	return(BOOL);
	}

"break"	{
	token(BREAK);
	return(BREAK);
	}

"char"	{
	token(CHAR);
	return(CHAR);
	}

"case"	{
	token(CASE);
	return(CASE);
	}

"continue"	{
		token(CONTINUE);
		return(CONTINUE);
		}

"declare"	{
		token(DECLARE);
		return(DECLARE);
		}

"do"	{
	token(DO);
	return(DO);
	}

"else"
	{
	token(ELSE);
	return(ELSE);
	}

"exit"	{
	token(EXIT);
	return(EXIT);
	}

"false"	{
	token(FALSE);
	return(FALSE);
	}

"float"	{
	token(FLOAT);
	return(FLOAT);
	}
"for"	{
	token(FOR);
	return(FOR);
	}

"if"	{
	token(IF);
	return(IF);
	}

"int"	{
	token(INT);
	return(INT);
	}

"loop"	{
	token(LOOP);
	return(LOOP);
	}

"println"	{
		token(PRINTLN);
		return(PRINTLN);
		}

"return"	{
		token(RETURN);
		return(RETURN);
		}

"string"	{
		token(STRING);
		return(STRING);
		}

"true"	{
	token(TRUE);
	return(TRUE);
	}

"val"	{
	token(VAL);
	return(VAL);
	}

"var"	{
	token(VAR);
	return(VAR);
	}

"while"	{
	token(WHILE);
	return(WHILE);
	}

"read"	{
	token(READ);
	return(READ);
	}

"in"	{
	token(IN);
	return(IN);
	}

{identifier}	{
		tokenString(id, yytext);
		insert(symbolTable, yytext);
		}

{string}	{
		tokenString(string, yytext);
		}

{integer}	{
		tokenInteger(integer, yytext);
		}

{real}	{
		tokenReal(real, yytext);
		}

\n      {
        LIST;
        printf("%d: %s", linenum++, buf);
        buf[0] = '\0';
        }

[ \t]*  { LIST; }

"/*"	{
	LIST;
	BEGIN(COMMENT);
	}
<COMMENT>"*/" {
		LIST;
		BEGIN(INITIAL);
		}
<COMMENT>.    { LIST; }

"//"	{
	LIST;
	BEGIN(S_COMMENT);
	}
<S_COMMENT>\n	{
		LIST;
		printf("%d:%s", linenum++, buf);
		buf[0] = '\0';
		BEGIN(INITIAL);
		}
<S_COMMENT>.	{ LIST; }





.       {
        LIST;
        printf("%d:%s\n", linenum+1, buf);
        printf("bad character:'%s'\n",yytext);
        exit(-1);
        }
%%
/*
int main() {
    symbolTable = create();
	
    yylex();

    printf("\nSymbol Table:\n");

	dumpResult = dump(symbolTable);
	char *cur = dumpResult;
	for(int i = 0; i < symbolTable->size; i++) {
        cur = dumpResult + i * NAME_MAX_LENGTH;
		for(int j = 0; j < NAME_MAX_LENGTH; j++){
        	printf("%c", cur[j]);
		}
		printf("\n");
    }

    exit(0);
}
*/