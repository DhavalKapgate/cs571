%{
#include <stdio.h> 
#include "prog.tab.h"
%}
 
digit ([0-9])+ 
character ([a-z)]+ 

%% 
"print"		{return(TOK_PRINT);} 
{digit} 	{yylval.int_val=atoi(yytext);return TOK_NUM;}
"main()"	{return(TOK_MAIN); } 
";" 		{return(TOK_SEMICOLON); } 
"{" 		{return(TOK_START); } 
"}"		{return(TOK_END); } 
"+" 		{return(TOK_ADD); } 
"-" 		{return(TOK_SUB); } 
"*" 		{return(TOK_MUL); } 
"/" 		{return(TOK_DIV); } 
"=" 		{return(TOK_EQU); } 
"+=" 		{return(TOK_PLUSEQUAL); } 	
"-=" 		{return(TOK_MINEQUAL); } 
"(" 		{ return(TOK_ROUNDSTART); } 
")" 		{ return(TOK_ROUNDEND); } 
[ \n\t] 	;
. 		{printf("Invalid character '%c',ignored\n",yytext[0]);}
%%

