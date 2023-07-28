import java.util.*;

class Swapping_Nibbles{
    public static int swapNibble(int x){
        return ((x & 0x0F)<<4|(x & 0xF0)>>4);
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int result = swapNibble(x);
        System.out.println(result);
    }
}

class Swapping_Nibbles{
    public static int SwapNibble(int x){
        return ((x & 0x0F)<<4|(x & 0xF0)>>4)
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int x = sc.nextInt();
        int result = SwapNibble(x);
        System.out.println(result);
    }
}