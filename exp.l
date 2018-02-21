%{
#include "y.tab.h"
#include <string.h>

extern int lineno;
extern int fileno();
%}

%option noyywrap nounput noinput

%%
[ \t]+          /* ignore */;
\n              lineno++;

"(*"(\n|.)*"*)"  /* multiple line comments */;
"#".*           /*rest of line comments*/ ;

int             return tTYPEINTEGER;
string          return tTYPESTRING;
return          return tRETURN;
write           return tWRITE;
allocate        return tALLOCATE;
length          return tLENGTH;
then            return tTHEN;
else            return tELSE;
while           return tWHILE;
type            return tTYPE;
func            return tFUNC;
end             return tEND;
bool            return tBOOL;
array           return tARRAY;
record          return tRECORD;
assign          return tASSIGN;
var             return tVAR;
of              return tOF;
if              return tIF;
do              return tDO;
true            return tTRUE;
false           return tFALSE;
NULL            return tNULL;
"="             return tASSIGN;
"=="            return tEQUALTO;
"!="            return tNEQUALTO;
"&&"            return tAND;
"|"             return tPIPE;
"("             return tLPAREN;
")"             return tRPAREN;
"{"             return tLBRACE;
"}"             return tRBRACE;
"["             return tLSQUARE;
"]"             return tRSQUARE;
"<"             return tSMALLER;
">"             return tBIGGER;
"<="            return tSMALEQUAL;
">="            return tBIGEQUAL;
"%"             return tMOD;
"*"             return tMULT;
"/"             return tDIV;
"+"             return tPLUS;
"-"             return tSUB;
"!"             return tNOT;
";"             return tSEMI;
":"             return tCOLON;
"."             return tDOT;

0|([1-9][0-9]*)        { yylval.intconst = atoi(yytext);
                       return tINT; }
[a-zA-Z_][a-zA-Z0-9_]* { yylval.stringconst = (char *)malloc(strlen(yytext)+1);
                         sprintf(yylval.stringconst,"%s",yytext);
                         return tID; }

.               /* ignore */;
%%
