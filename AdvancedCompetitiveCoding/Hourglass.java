import java.util.*;

class Hourglass{
    public static int findMaxSum(int [][]mat,int R,int C){
        if((R<3)||(C<3)){
            System.out.println("Not Possible");
            System.exit(0);
        }
        int max_sum = 0;
        int temp_sum;
        for(i=0;i<R-2;i++){
            for(j=0;j<C-2;j++){
                temp_sum = mat[i][j]+mat[i][j+1]+mat[i][j+2]+mat[i+1][j+1]+mat[i+2][j]+mat[i+2][j+1]+mat[i+2][j+2];
                if(temp_sum>max_sum){
                    max_sum = temp_sum;
                }
            }
        }
        return max_sum;
    }
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int R = sc.nextInt();
        int C = sc.nextInt();
        int [][]mat = new int[R][C];
        for(int i=0;i<R;i++){
            for(int j=0;j<C;j++){
                mat[i][j] = sc.nextInt();
            }
        }
        int result = findMaxSum(mat,R,C);
        System.out.println(result);
    }
}