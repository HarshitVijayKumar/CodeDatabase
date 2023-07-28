%{
#include <stdio.h>
int count=0;
%}
%%
[bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]*[aeiouAEIOU][bcdfghjklmnpqrstvwxyzBCDFGHJKLMNPQRSTVWXYZ]*[aeiouAEIOU][a-zA-Z]* {printf("%s\n",yytext);count++;}
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
    printf("The number of strings with atlease two vowels are : %d\n",count);
    return 0;
}
