%{
#include "y.tab.h"

int yylval=0;
%}
NUM [0-9]
%%
{NUM}+  {yylval=atoi(yytext);  return(A);}
.    {  return(yytext[0]); }
\n  { return 0; }
%%

int yywrap()
{
}

