%{
#include "lex.yy.c"
%}

%token A
%start st

%left '+' '-'
%left '*' '/'

%%

st: exp  {printf("\n result=%d\n",$$);}
;
exp:exp '+' exp  {$$=$1+$3;}
       | exp '-'exp  {$$=$1-$3;}
       | exp'*'exp  {$$=$1*$3;}
       | exp'/'exp   { 
                            if($3==0)
                            {
                            printf("divide by zero error\n");
                            exit(0);
                            }
                            else
                            {
                            $$=$1/$3;
                            }
                          }
      |'('exp')'  {$$=$2;}
      |'['exp']' {$$=$2;}
      |'+'exp    {$$=$2;}
      |'-'exp     {$$=$2;}
      |A            {$1=yylval;}
;
%%
yyerror()
{       }




