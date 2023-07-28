import java.util.*;

class BinPallindrome{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int original = x;
        int reversed = 0;
        while(x>0){
            reversed <<=1;
            reversed |= (x&1);
            x>>=1;
        }
        if(reversed == original){
            System.out.println("Binary Pallidrome");
        }
        else{
            System.out.println("Not a Binary Pallindrome");
        }
    }
}