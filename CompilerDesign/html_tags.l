%{
#include <stdio.h>
%}
%%
\<\/?[a-zA-Z0-9]*\> {printf("%s\n",yytext);}
. ;
%%
int yywrap(){
    return 1;
}
int main(int argc, char*argv[]){
    yyin = fopen("html_test_file.txt","r");
    yylex();
    return 0;
}
