%option noyywrap
%{
#include <stdio.h>

int v=0, c=0;
%}
%%
[0-9]+ { printf("Number: %s, Length: %lu\n", yytext, yyleng); }
[a-zA-Z] ; 
[ \t\n] ;  
. ;  
%%
int main() {
    printf("Enter alphanumeric string: ");
    yylex();
    
    return 0;
}


