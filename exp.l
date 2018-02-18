%{
#include "y.tab.h"
#include <string.h>

extern int lineno;
extern int fileno();
%}

%option noyywrap nounput noinput

%%
[ \t]+        /* ignore */;
\n              lineno++;

return          return tRETURN;
"="             return tEQUAL;
"=="            return tEQUALTO;
"!="            return tNEQUALTO;
"&&"            return tAND;
"|"             return tPIPE;
"("             return tLPAREN;
")"             return tRPAREN;
"{"             return tLBRACE;
"}"             return tRBRACE;
"<"             return tSMALLER;
">"             return tBIGGER;
"<="            return tSMALEQUAL;
">="            return tBIGEQUAL;
"%"             return tMOD;
"*"             return tMULT;
"/"             return tDIV;
"+"             return tPLUS;
"-"             return tSUB;

0|([1-9][0-9]*)        { yylval.intconst = atoi(yytext);
                       return tINTCONST; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                         sprintf(yylval.stringconst,"%s",yytext);
                         return tIDENTIFIER; }
.               /* ignore */;
%%
