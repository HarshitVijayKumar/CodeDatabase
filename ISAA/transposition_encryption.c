#include<stdio.h>
#include<string.h>
#include<math.h>

int main(){
  int n,m,i,j,min,t,k;
  char temp,key[10],string[100];
  printf("Enter the key : ");
  scanf("%s",key);
  scanf("%c",&temp);
  printf("Enter the string : ");
  scanf("%[^\n]s",string);
  n = strlen(key);
  m = strlen(string);
  int row;
  if (m%n==0)
    row = m/n;
  else
    row = m/n+1;
  char table[row][n];
  int index[n];
  char encrypt_string[m];
  printf("%d\n",m);
  for (i=0;i<n;i++){
    index[i] = i;
  }
  for (i=0;i<n;i++){
    min = i;
    for (j=i+1;j<n;j++){
      if (key[j]<key[min])
        min = j;
    }
    t = index[i];
    index[i] = index[min];
    index[min] = t;
  }
  k=0;
  for(i=0;i<row;i++){
    for(j=0;j<n;j++){
      if(k<m){
        table[i][j] = string[k];
        k++;
      }
      else
        table[i][j] = '_';
    }
  }
  printf("Received String --");
  for(i=0;i<row;i++){
    for(j=0;j<n;j++){
      printf("%c",table[i][j]);
    }
  }
  printf("\n");
  printf("Encrypted String -- ");
  k = 0;
  for(i=0;i<row;i++){
    for(j=0;j<n;j++){
      printf("%c",table[i][index[j]]);
      encrypt_string[k] = table[i][index[j]];
      k++;
    }
  }
  printf("\n");
  char decrypt_string[row][n];
  k=0;
  for(i=0;i<row;i++){
    for(j=0;j<n;j++){
      decrypt_string[i][index[j]] = encrypt_string[k];
      k++;
    }
  }
  printf("Decrypted String -- ");
  for(i=0;i<row;i++){
    for(j=0;j<n;j++){
      printf("%c",decrypt_string[i][j]);
    }
  }
  printf("\n");
  return 0;
}
