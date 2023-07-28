import java.util.*;

class SegSieve{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int L = sc.nextInt();
        int R = sc.nextInt();
        boolean prime[] = new boolean[R+1];
        for(int p=2;p*p<=R;p++){
            int sm = (L/p)*p;
            if(sm<L){
                sm = sm+p;
            }
            for(int i=sm;i<=R;i = i+p){
                prime[i] = true;
            }
        }
        for(int i=L;i<=R;i++){
            if(prime[i]==false){
                System.out.print(i+" ");
            }
        }
        System.out.println(" ");
    }
}