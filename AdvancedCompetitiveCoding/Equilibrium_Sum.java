import java.util.*;

class Equilibrium_Sum{
    public static int equilibrium(int[] arr,int n){
        int total_sum = 0;
        int left_sum = 0;
        int max_sum = Integer.MIN_VALUE;
        for(int i=0;i<n;i++){
            total_sum = total_sum+arr[i];
        }
        for(int i=0;i<n;i++){
            total_sum = total_sum-arr[i];
            if((left_sum==total_sum)&&(left_sum>max_sum)){
                max_sum = left_sum;
            }
            left_sum = left_sum+arr[i];
        }
        return max_sum;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int result = equilibrium(arr,n);
        System.out.println(result);
    }
}