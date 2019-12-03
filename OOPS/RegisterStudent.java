import java.util.*;
import java.util.Scanner;
// package StudentPackage
public interface student 
{
    String name,branch;
    default void getDetails()
    {
        System.out.println("No Student or Branch registered");
    }
}
class CreditLimit extends Exception
{
    public String toString()
    {
        return "Total credits must be less than 30";
    }
}

class RegisterStudent implements student
{
    void total(int cd)
    {
        int TotalCredits=cd;
        try
        {
            if(TotalCredits>30)
            {
                throw new CreditLimit();
            }
            else
            {
                System.out.println("The Total credit is:"+TotalCredits);
            }
        }
        catch(CreditLimit e)
        {
            System.out.println("Caught: " + e);
        }
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the total credit:");
        int c = sc.nextInt();
        RegisterStudent r = new RegisterStudent();
        r.total(c);
    }
}

