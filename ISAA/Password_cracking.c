#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char password[6];
    printf("Enter the password : ");
    scanf("%s",password);
    char guessed_password[6];
    int i,j,k,l,m,attempts=0;

    char valid[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890";

    for(i=0;i<strlen(valid);i++){
        guessed_password[0] = (char)valid[i];
        for(j=0;j<strlen(valid);j++){
            guessed_password[1] = (char)valid[j];
            for(k=0;k<strlen(valid);k++){
                guessed_password[2] = (char)valid[k];
                for(l=0;l<strlen(valid);l++){
                    guessed_password[3] = (char)valid[l];
                    for(m=0;m<strlen(valid);m++){
                        guessed_password[4] = (char)valid[m];
                        attempts++;
                        guessed_password[5] = '\0';
                        if(strcmp(password,guessed_password)==0){
                            printf("Password cracked!\n");
                            printf("Attempts : %d\n",attempts);
                            exit(1);
                        }
                    }
                }
            }
        }
    }
    printf("Password cracking failed!\n");
    printf("Attempts : %d\n",attempts);
    return 0;
}