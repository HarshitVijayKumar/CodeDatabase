import java.util.*;

class Strobogrammatic{
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        Map<Character,Character> map = new HashMap<Character,Character>();
        map.put('6','9');
        map.put('9','6');
        map.put('1','1');
        map.put('0','0');
        map.put('8','8');
        int i=0,r=n.length()-1;
        boolean flag = true;
        while(i<=r){
            if(map.containsKey(n.charAt(i)))flag = false;
            if(map.get(n.charAt(i))!=map.get(n.charAt(r)))flag = false;
            i++;
            r--;
        }
        if(flag==true){
            System.out.println("Strobogrammatic number");
        }
        else{
            System.out.println("Strobogrammatic number");
        }
    }
}