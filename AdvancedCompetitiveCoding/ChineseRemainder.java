import java.util.*;

class ChineseRemainder{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int size = sc.nextInt();
        int div[] = new int[size];
        int rem[] = new int[size];
        int i;
        System.out.println("Enter the divisors : ");
        for(i=0;i<size;i++){
            div[i] = sc.nextInt();
        }
        System.out.println("Enter the remainders : ");
        for(i=0;i<size;i++){
            rem[i] = sc.nextInt();
        }
        int j,x=1;
        while(true){
            for(j=0;j<size;j++){
                if (x%div[j]!=rem[j])
                    break;
            }
            if(j==size)
                System.out.print(x);
            x++;
        }
    }
}