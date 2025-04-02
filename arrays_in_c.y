%{
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

extern int yylex();
extern int yyparse();
void yyerror(const char *s);

int is_extern = 0;  // Track extern keyword
%}

%union {
    long num;
    char* str;
    int type_kind;
}

%token <str> ID
%token <num> NUM
%token INT FLOAT CHAR EXTERN
%token LBRACKET RBRACKET LBRACE RBRACE
%token EQUAL COMMA SEMICOLON

%type <num> size
%type <type_kind> type

%%

program: 
    | program statement SEMICOLON
    ;

statement:
    array_declaration
    | array_definition
    | array_access
    | error SEMICOLON { printf("Syntax error.\n"); yyerrok; }
    ;

array_declaration:
    EXTERN type ID LBRACKET RBRACKET { 
        printf("Valid external array declaration.\n");
        is_extern = 0;
    }
    ;

array_definition:
    type ID LBRACKET size RBRACKET {
        printf("Valid array definition with size %ld.\n", $4);
    }
    | type ID LBRACKET RBRACKET EQUAL LBRACE num_list RBRACE {
        printf("Valid array definition with implicit size.\n");
    }
    ;

array_access:
    ID LBRACKET NUM RBRACKET EQUAL NUM {
        printf("Valid array assignment.\n");
    }
    ;

type:
    INT   { $$ = 0; }
    | FLOAT { $$ = 1; }
    | CHAR  { $$ = 2; }
    ;

size:
    NUM {
        if ($1 <= 0) {
            printf("Error: Array size must be greater than 0.\n");
            YYERROR;
        }
        $$ = $1;
    }
    ;

num_list:
    NUM
    | num_list COMMA NUM
    ;

%%

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

int main() {
    printf("Enter C array statements:\n");
    yyparse();
    return 0;
}
