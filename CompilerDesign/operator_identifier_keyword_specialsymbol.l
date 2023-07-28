%{
#include <stdio.h>
int count_operator=0,count_keyword=0,count_identifier=0,count_special=0;
%}
operator \+|\-|\*|\\|\%|\=
keyword auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while
identifier [a-zA-Z_][a-zA-Z_|0-9]*
special \'|\"|\;|\:|\.|\,
%%
{keyword} {count_keyword++;}
{identifier} {count_identifier++;}
{operator}[ =] {count_operator++;count_special++;}
{special} {count_special++;}
%%
int yywrap(){
    return 1;
}
int main(){
    char myString[100];
    fgets(myString,sizeof(myString),stdin);
    yy_scan_string(myString);
    yylex();
    printf("The number of operators are : %d\n",count_operator);
    printf("The number of keywords are : %d\n",count_keyword);
    printf("The number of identifiers are : %d\n",count_identifier);
    printf("The number of special symbols are : %d\n",count_special);
    return 0;
}
