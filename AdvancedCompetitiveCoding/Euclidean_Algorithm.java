import java.util.*;

class Euclidean_Algorithm{
    public static int gcd(int a,int b){
        if(a==0)
            return b;
        return gcd(b%a,a);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int g = gcd(a,b);
        System.out.println(g);
    }
}