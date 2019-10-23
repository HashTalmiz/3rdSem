import java.util.Scanner;
public class matrixproduct
{
    Scanner sc = new Scanner(System.in);
    int m,n,A[][],i,j,k;
    matrixproduct()
    {
        System.out.println("Enter number of rows and columns of the matrix");
        m=sc.nextInt();
        n=sc.nextInt();
        A = new int[m][n];
    }
    matrixproduct(matrixproduct ob1,matrixproduct ob2)
    {
        m=ob1.m;
        n=ob2.n;
        A = new int [m][n];
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                A[i][j]=0;
                for(k=0;k<ob2.m;k++)
                    A[i][j] += ob1.A[i][k] * ob2.A[k][j];
            }
        }
    }
    void inputMatrix()
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
            {
                A[i][j]=sc.nextInt();
            }
        }
    }
    void display()
    {
        for(i=0;i<m;i++)
        {
            for(j=0;j<n;j++)
                System.out.print(A[i][j]+" ");
            System.out.println();
        }
    }
    public static void main(String args[])
    {
        matrixproduct ob1 = new matrixproduct();
        matrixproduct ob2 = new matrixproduct();
        if(ob1.n==ob2.m)
        {
            System.out.println("Enter the elements for the first Matrix");
            ob1.inputMatrix();
            System.out.println("Enter the elements for the second Matrix");
            ob2.inputMatrix();
            matrixproduct ob3 = new matrixproduct(ob1,ob2);
            System.out.println("---First Matrix---");
            ob1.display();
            System.out.println("---Second Matrix---");
            ob2.display();
            System.out.println("---Product Matrix---");
            ob3.display();
        }
        else
            System.out.println("Multiplication not possible");

    }
}
