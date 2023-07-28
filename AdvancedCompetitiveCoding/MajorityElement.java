import java.util.*;

class MajorityElement{
    public static void Majority(int[] a,int n){
        int candidate=0;
        int count=0;
        for(int num:a){
            if(count==0){
                candidate = num;
                count = 1;
            }
            else if(candidate == num){
                count++;
            }
            else{
                count--;
            }
        }
        int majorityCount = 0;
        for(int num:a){
            if(num==candidate){
                majorityCount++;
            }
        }
        if(majorityCount>n/2){
            return candidate;
        }
        else{
            return -1;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] a = new int[n];
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt();
        }
        int result = Majority(a,n);
        if(result==-1){
            System.out.println("Majority Element does not exist !");
        }
        else{
            System.out.print("Majority Element is : ");
            System.out.println(result);
        }
    }
}


public static int calculate_leader(int[] a,int n){
    int candidate=0;
    int count=0;
    for(i:a){
        if(count==0){
            candidate = i;
            count++;
        }
        else if(i==candidate){
            count++;
        }
        else{
            count--;
        }
    }
    int majorityCount=0;
    for(i:a){
        if(i==candidate){
            majorityCount++;
        }
    }
    if(maorityCount>n/2){
        return candidate;
    }
    else{
        return -1;
    }
}