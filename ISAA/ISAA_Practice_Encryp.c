#include <stdio.h>
#include <stdlib.h>

int main(){
    char crpt[100];
    FILE *fptr;
    fptr = fopen("test.txt","r+");
    if(fptr==NULL){
        printf("Error!");
        exit(1);
    }
    fgets(crpt,100,fptr);
    printf("The word read is : %s\n",crpt);
    fclose(fptr);
    
    for(int i=0;crpt[i]!='\0';i++){
        crpt[i] = crpt[i]+3;
    }
    printf("The encrpyted word is : %s\n",crpt);
    fptr = fopen("test.txt","a");
    fputs("\n",fptr);
    fputs(crpt,fptr);
    fclose(fptr);
    return 0;
}