%{
#include "arrays_in_c.tab.h"
#include <stdlib.h>
#include <string.h> 
%}

DIGIT   [0-9]
LETTER  [a-zA-Z_]
ID      {LETTER}({LETTER}|{DIGIT})*
SPACE   [ \t\r\n]+

%%
"extern"     { return EXTERN; }
"int"         { return INT; }
"float"       { return FLOAT; }
"char"        { return CHAR; }

{ID}          { yylval.str = strdup(yytext); return ID; }
{DIGIT}+      { yylval.num = atoi(yytext); return NUM; }

"["           { return LBRACKET; }
"]"           { return RBRACKET; }
"="           { return EQUAL; }
","           { return COMMA; }
";"           { return SEMICOLON; }
"{"           { return LBRACE; }
"}"           { return RBRACE; }


{SPACE}       { /* Ignore whitespace */ }
.             { return yytext[0]; }

%%

int yywrap() { return 1; }