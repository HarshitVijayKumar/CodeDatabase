import java.util.*;

class Karatsuba_Algorithm{
    public static long Karatsuba(long x,long y){
        if((x<10)||(y<10)){
            return x*y;
        }
        else{
            int n = Math.max(Long.toString(x).length(),Long.toString(y).length());
            int half = (n+1)/2;
            long a = x/(long)Math.pow(10,half);
            long b = x%(long)Math.pow(10,half);
            long c = y/(long)Math.pow(10,half);
            long d = y%(long)Math.pow(10,half);
            long ac = Karatsuba(a,c);
            long bd = Karatsuba(b,d);
            long adbc = Karatsuba(a+b,c+d)-ac-bd;

            return (long)(ac*(Math.pow(10,2*half))+adbc*(Math.pow(10,half))+bd);
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long x = sc.nextInt();
        long y = sc.nextInt();
        long result = Karatsuba(x,y);
        System.out.println(result);
    }
}