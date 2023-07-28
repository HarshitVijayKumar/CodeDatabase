import java.util.*;

class Longest_Sequence_1{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        int max_1 = 0;
        int temp=0;
        while (num>0){
            if(num%2==1){
                temp++;
                if(temp>max_1){
                    max_1 = temp;
                }
            }
            else{
                temp=0;
            }
            num = num/2;
        }
        System.out.print("The maximum number of 1's are : ");
        System.out.println(max_1);
    }
}