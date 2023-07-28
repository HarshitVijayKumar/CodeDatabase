import java.util.*;
import java.io.*;

class Block_Swapping{
    public static void leftRotation(int[] arr,int d,int n){
        int i,j;
        if((d==0)||(d==n))
            return;
        if(d>n)
            d = d%n;
        i = d;
        j = n-d;
        while(i!=j){
            if(i<j){
                swap(arr,d-i,d+j-i,i);
                j=j-i;
            }
            else{
                swap(arr,d-i,d,j);
                i=i-j;
            }
        }
        swap(arr,d-i,d,i);
    }
    public static void printarr(int[] arr,int size){
        for(int i=0;i<size;i++){
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println(" ");
    }
    public static void swap(int[] arr,int fi,int si,int d){
        int temp;
        for(int i=0;i<d;i++){
            temp = arr[fi+i];
            arr[fi+i] = arr[si+i];
            arr[si+i] = temp;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int d = sc.nextInt();
        leftRotation(arr,d,n);
        printarr(arr,n);
    }
}

class Block_Swapping{
    public static void leftRotation(int[] arr,int d,int n){
        int i,j;
        if((d==0)||(d==n)){
            return;
        }
        if(d>n){
            d = d%n;
        }
        i = d;
        j = n-d;
        while(i!=j){
            if(i<j){
                swap(arr,d-i,d+j-i,i);
                j = j-i;
            }
            else{
                swap(arr,d-i,d,j);
                i = i-j;
            }
        }
        swap(arr,d-i,d,j);
    }
    public static void printarr(int[] arr,int n){
        for(int i=0;i<n;i++){
            System.out.print(arr[i]);
            System.out.print(" ");
        }
        System.out.println(" ");
    }
    public static void swap(int[] arr,int fi,int si,int d){
        int temp;
        for(int i=0;i<d;i++){
            temp = arr[fi+i];
            arr[fi+i] = arr[si+i];
            arr[si+i] = temp;
        }
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] arr = new int[n];
        for(int i=0;i<n;i++){
            arr[i] = sc.nextInt();
        }
        int d = sc.nextInt();
        leftRotation(arr,d,n);
        printarr(arr,n);
    }
}