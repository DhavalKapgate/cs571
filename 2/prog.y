%{
#include <stdio.h>
%}

%token TOK_SEMICOLON TOK_ADD TOK_SUB TOK_MUL TOK_DIV TOK_NUM TOK_PRINT 
%token TOK_ROUNDSTART TOK_ROUNDEND TOK_EQU TOK_MAIN TOK_PLUSEQUAL
%token TOK_MINEQUAL TOK_START TOK_END

%union
{
        int int_val;
}

%type <int_val> expr TOK_NUM 
%left TOK_ADD TOK_SUB
%left TOK_MUL TOK_DIV
%%

program:
	TOK_MAIN '{' stmt '}'
	;
stmt:
	/*empty*/
	| stmt ';' expr_stmt
	;
expr_stmt:
	expr ';'
	| TOK_PRINT expr ';'
		{
			fprintf(stdout, "the value is %d\n", $2);
		} 
	;
expr:
	expr TOK_ADD expr
	  {
		$$ = $1 + $3;
	  }
	| expr TOK_SUB expr
	  {
		$$ = $1 - $3;
	  }
	| expr TOK_MUL expr
	  {
		$$ = $1 * $3;
	  }
	| expr TOK_DIV expr
	  {
		$$ = $1 / $3;
	  }
	| TOK_NUM
	  {
		fprintf(stdout, "the value is %d\n", $1);
	  }
	;
%% 

int yyerror(char *s) 
{
	fprintf(stderr, "%s\n",s);
	return 0;
}
int main() 
{
   yyparse();
   return 0;
}
