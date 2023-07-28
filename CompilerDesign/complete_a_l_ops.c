#include <stdio.h>

int main(){
  int a,b;
  printf("Enter the integers : ");
  scanf("%d %d",&a,&b);
  printf("------------MENU-------------\n");
  printf("1. Addition\n");
  printf("2. Subtraction\n");
  printf("3. Multiplication\n");
  printf("4. Division\n");
  printf("5. Modulo Division\n");
  printf("6. AND Operation\n");
  printf("7. OR Operation\n");
  printf("8. NOT Operation\n");
  printf("9. Bitwise AND Operation\n");
  printf("10. Bitwise OR Operation\n");
  printf("11. XOR Operation\n");
  printf("12. Exit\n");
  int choice = 0;
  while (choice!=12){
    printf("Enter your command : ");
    scanf("%d",&choice);
    switch(choice){
      case 1:
      printf("%d + %d = %d\n",a,b,a+b);
      break;
      case 2:
      printf("%d - %d = %d\n",a,b,a-b);
      break;
      case 3:
      printf("%d * %d = %d\n",a,b,a*b);
      break;
      case 4:
      printf("%d / %d = %d\n",a,b,a/b);
      break;
      case 5:
      printf("%d modulo %d = %d\n",a,b,a%b);
      break;
      case 6:
      printf("%d && %d = %d\n",a,b,a&&b);
      break;
      case 7:
      printf("%d || %d = %d\n",a,b,a||b);
      break;
      case 8:
      printf("~%d = %d, ~%d = %d\n",a,~a,b,~b);
      break;
      case 9:
      printf("%d & %d = %d\n",a,b,a&b);
      break;
      case 10:
      printf("%d | %d = %d\n",a,b,a|b);
      break;
      case 11: 
      printf("%d ^ %d = %d\n",a,b,a^b);
      break;
      case 12:
      printf("----Exiting----\n");
      break;
      default:
      printf("Enter a valid input!\n");
    }
  }
  return 0;
}
