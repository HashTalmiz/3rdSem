
/**
* matrixmul
*/

import java.util.Scanner;

import javax.print.event.PrintJobListener;
public class matrixmul {
    int a[][],b[][],N;
    matrixmul(int N)
    {
        this.a = new int[N][N];
        this.b = new int[N][N];
        this.N=N;
    }
    public void multiply() 
    {
        int i, j, k; 
        int c[][] = new int[N][N];
        for (i = 0; i < N; i++) 
        { 
            for (j = 0; j < N; j++) 
            { 
                c[i][j] = 0; 
                for (k = 0; k < N; k++) 
                c[i][j] += a[i][k] *  b[k][j]; 
            } 
        } 
        
    } 
    public void init() {
        
    }
    
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the size of the square matricies:");
        int n = sc.nextInt();
        matrixmul m = new matrixmul(n);
        
    }
}