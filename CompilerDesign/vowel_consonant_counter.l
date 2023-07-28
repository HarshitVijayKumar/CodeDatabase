%{
#include <stdio.h>
int count_v=0,count_c=0;
%}
%%
[aeiou] {count_v++;}
[AEIOU] {count_v++;}
[bcdfghjklmnpqrstvwxyz] {count_c++;}
[BCDFGHJKLMNPQRSTVWXYZ] {count_c++;}
%%
int yywrap(){
    return 1;
}
int main(){
    char myString[100];
    fgets(myString,sizeof(myString),stdin);
    yy_scan_string(myString);
    yylex();
    printf("Number of vowels : %d\n",count_v);
    printf("Number of consonants : %d\n",count_c);
    return 0;
}
