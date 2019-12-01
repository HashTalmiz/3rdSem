import java.nio.DoubleBuffer;
import java.util.Scanner;
// package ResultPackage
class InvalidSGPA extends Exception 
{
    private double input;
    InvalidSGPA(Double i)
    {
        input = i;
    }
    public String toString() 
    {
        return input+" is not a valid SGPA. It must lie between 0 and 10.";
    }
}
class grade
{
    String sub1,sub2,sub3;
    void getGrade()
    {
        sub1="A";
        sub2="A";
        sub3="S";
    }
    void display()
    {
        System.out.println("Grade of Registered subject");
        System.out.println(" Grade of subject1:"+sub1);
        System.out.println(" Grade of subject2:"+sub2);
        System.out.println(" Grade of subject3:"+sub3);
    }
    void sgpa()
    {
        double input;
        Scanner scan = new Scanner(System.in);
        System.out.println("Enter an sgpa: ");
        input = scan.nextDouble();
        try
        {
            if(input> 10)
            throw new InvalidSGPA(input);
            else
            System.out.println("sgpa is: " + input);
        }
        catch (InvalidSGPA e)
        {
            System.out.println("Caught: " + e);
        }
    }
}
public class ResultSGPA {
    public static void main(String[] args)
    {
        grade g=new grade();
        g.getGrade();
        g.display();
        g.sgpa();
    }
}