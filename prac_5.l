
%{
#include <stdio.h>

void print_token(const char *type, const char *token) {
    printf("%s: %s\n", type, token);
    fflush(stdout);
}

%}

%%
[ \t\r\n]+      { /* Ignore whitespace */ }

"int" | "char" | "return" | "if" | "else" | "while" | "for" | "break" | "continue" | "void" | "float" | "double" | "struct" | "typedef"  { print_token("Keyword", yytext); }

[0-9]+[a-zA-Z]+          
[a-zA-Z_][a-zA-Z0-9_]*  { print_token("Identifier", yytext); }

[0-9]+                  { print_token("Constant", yytext); }

\"(\\.|[^\\"])*\"       { print_token("String", yytext); }
\'(\\.|[^\\'])*\'       { print_token("String", yytext); }

"//".*                  { /* Ignore single-line comments */ }
"/*"(.|\n)*?"*/"        { /* Ignore multi-line comments */ }

[+\-*/=<>!&|^%]+        { print_token("Operator", yytext); }

[(){}[\],;]            { print_token("Punctuation", yytext); }

.                      { printf("Lexical Error: %s\n", yytext); }  

%%

int main(int argc, char **argv) {
    if (argc > 1) {
        FILE *file = fopen(argv[1], "r");
        if (!file) {
            printf("Error opening file %s\n", argv[1]);
            return 1;
        }
        yyin = file;
    }
    
    yylex();  // Run the lexer
    return 0;
}
int yywrap() {}