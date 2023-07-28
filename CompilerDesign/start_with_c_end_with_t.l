%{
#include <stdio.h>
int count=0;
%}
%%
[ \t]+
[cC][a-zA-Z]*[tT] {printf("%s\n",yytext);count++;}
[a-zA-Z]+
%%
int yywrap(){
    return 1;
}
int main(){
    char myString[100];
    fgets(myString,sizeof(myString),stdin);
    yy_scan_string(myString);
    yylex();
    printf("The number of strings are : %d\n",count);
}
