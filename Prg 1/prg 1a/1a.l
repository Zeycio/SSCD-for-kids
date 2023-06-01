%{
#include<stdio.h>
int v=0,op=0,id=0,flag=0;
%}
%%
[0-9a-zA-Z]+[0-9A-Za-z]* {id++;printf("\n identifier \t%s ",yytext);}
[\+\-\*\/\=] {op++;printf("\n operator %s",yytext);}
")" {v++;}
"(" {v--;}
";" {flag=1;}
.|\n {;}
%%
void main()
{
 printf("\n enter the experssion \n");
 yylex();
 if((op+1)==id && v==0 && flag==0)
 {
 printf("\n identifer count=%d",id);
 printf("\n opertor count=%d",op);
 printf("\n expression is valid\n");
 }
 else
 {
 printf("\n expression is invalid\n");
 }
 }
