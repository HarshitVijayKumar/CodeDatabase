import java.util.*;

class MaxProduct{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
        }

        int max=a[0],min=a[0],m=a[0],temp=0;
        for(int i=1;i<n;i++){
            if(a[i]>0){
                max = Math.max(a[i],a[i]*max);
                min = Math.min(a[i],a[i]*min);
            }
            else if(a[i]==0){
                min = max = 0;
            }
            else{
                temp = max;
                max = Math.max(a[i],min*a[i]);
                min = Math.max(a[i],temp*a[i]);
            }
            m = Math.max(m,max);
        }
        System.out.println(m);
    }
}




class MaxProduct{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
        }
        int max=a[0],min=a[0],m=a[0],temp=0;
        for(i=1;i<n;i++){
            if(a[i]>0){
                max = Math.max(a[i],a[i]*max);
                min = Math.min(a[i],a[i]*min);
            }
            else if(a[i]==0){
                min = max = 0;
            }
            else{
                temp = max;
                max = Math.max(a[i],a[i]*min);
                min = Math.min(a[i],a[i]*temp);
            }
            m = Math.max(max,m);
        }
        System.out.println(m);
    }
}