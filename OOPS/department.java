//default package
import java.util.Scanner;
public class Faculty
{
     String name[],
        desig[],
        joining_date[];
     int n, age[],
        exp_yrs[],
        subjects_handled[];
}


// package ise
// import java.util.Scanner;
public interface Department
{
    void readdata();
    void printdata();
    void print_number_designations(int i);
    int number_research_consultancy_projs(int i);
}

public class ISE_department extends Faculty implements Department
{
    Scanner sc = new Scanner(System.in);
    public void readdata()
    {
        System.out.println("Enter the number of lecturers:");
        n = sc.nextInt();
        sc.nextLine();
        name = new String[n]; desig = new String[n]; joining_date = new String[n];
        age = new int[n]; exp_yrs = new int[n]; subjects_handled = new int[n];

        for (int i = 0; i < n; i++)
        {
            System.out.println("Enter the name");
            name[i] = sc.nextLine();
            System.out.println("Enter the age");
            age[i] = sc.nextInt();
            try
            {
                if(age[i]<1 || age[i]>58)
                    throw new Exception("Invalid Age. Should be below 58.");
            }
            catch (Exception e) {
                System.out.println("Exception Caught: " +e);
                System.exit(0);
            }
            sc.nextLine();
            System.out.println("Enter the designation (format : abc or abc,xyz,etc)");
            desig[i] = sc.nextLine();
            System.out.println("Enter the years of experience");
            exp_yrs[i] = sc.nextInt();
            sc.nextLine();
            System.out.println("Enter the joining date (format : dd/mm/yyyy)");
            joining_date[i] = sc.nextLine();
            System.out.println("Enter the number of subjects handled");
            subjects_handled[i] = sc.nextInt();
            sc.nextLine();
        }
    }
    public void printdata()
    {
        for (int i = 0; i < n; i++)
        {
            if (exp_yrs[i] >= 20)
            {
                System.out.println("\n-----------------------------------------------\n");
                System.out.println("Name : " + name[i]);
                System.out.println("Designation : " + desig[i]);
                System.out.println("Age : " + age[i]);
                System.out.println("Years of Experience : " + exp_yrs[i]);
                System.out.println("Joining Date : " + joining_date[i]);
                System.out.println("Subjects Handled : " + subjects_handled[i]);
                print_number_designations(i);
                System.out.println("Number of Research Consultancy Projects : " + number_research_consultancy_projs(i));
            }
        }
    }
    public void print_number_designations(int i)
    {
        int count = desig[i].length() - desig[i].replace(",","").length();
        System.out.println("Number of Designations : "+(count+1));
    }
    public int number_research_consultancy_projs(int i)
    {
        return (exp_yrs[i]* subjects_handled[i])/4;
    }

}

class MainClass {
    public static void main(String args[]) {
        ISE_department o = new ISE_department();
        o.readdata();
        o.printdata();
    }
}
