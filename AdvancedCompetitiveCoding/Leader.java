import java.util.*;

class Leader{
    public static void calculate_leader(int[] a,int n){
        int max = a[n-1];
        System.out.print(max);
        System.out.print(" ");
        for(int i=n-1;i>-1;i--){
            if(a[i]>max){
                max = a[i];
                System.out.print(max);
                System.out.print(" ");
            }
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
        }
        calculate_leader(a,n);
    }
}