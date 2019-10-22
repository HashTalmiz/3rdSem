package com.example.javalib;

import java.util.Scanner;

public class Personal {
    String name;
    int age, edu, yr_exp, loan_num;
    double ba, hra, da, loan_amt;

    Personal(String a, int b, int c, double d, int e) {
        name = a;
        age = b;
        edu = c;
        ba = d;
        yr_exp = e;
        loan_num = 0;
        hra = 0.0;
        da = 0.0;
        loan_amt = 0.0;
    }

    boolean isEligible() {
        if (age >= 21 && age <= 68 && yr_exp > 3 && ba >= 5000 && edu>1)
            return true;
        return false;
    }

    double taxPay()
    {
        double tax_amt=(ba+(hra/2)+da)*12,  tax=0.0;
        if(tax_amt>250000 && tax_amt<=500000)
            tax=0.05*tax_amt;
        else if(tax_amt>500000 && tax_amt<=1000000)
            tax=0.2*tax_amt;
        else if(tax_amt>1000000)
            tax=0.3*tax_amt;
        return tax;
    }
    boolean isEligiblePromotion()
    {
        if(age<50 && edu>2 && yr_exp>7)
            return true;
        return false;
    }
    void Display()
    {
        da=0.07*ba;
        hra=0.2*ba;
        System.out.println("Name : "+name);
        System.out.println("Age : "+age);
        System.out.println("Basic Monthly Salary : "+ba);
        System.out.println("Monthly HRA : "+hra);
        System.out.println("Monthly DA : "+da);
        System.out.println("Years of experience : "+yr_exp);
        if( isEligible() )
            System.out.println("Loan Eligibility : Yes");
        else
            System.out.println("Loan Eligibility : No");
        System.out.println("Number of Loans : "+loan_num);
        System.out.println("Total loan amount : "+loan_amt);
        System.out.println("Tax to be paid : "+taxPay());
        if(isEligiblePromotion())
            System.out.println("Promotion Eligibility : Yes");
        else
            System.out.println("Promotion Eligibility : No");
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        String na;
        int ag, ed, yrex, lo_nu,n,i;
        double b, h, d, lo_amt;
        System.out.println("Enter the number of employees");
        n=sc.nextInt();
        sc.nextLine();
        Personal A[] = new Personal[n];
        for(i=0; i<n; i++)
        {
            System.out.println("Enter the name");
            na=sc.nextLine();
            System.out.println("Enter the age");
            ag=sc.nextInt();
            System.out.println("Enter Education Details\n1 for 10th pass\n2 for 12th pass\n3 for UG\n4 for Pg\n5 for higher studies");
            ed=sc.nextInt();
            System.out.println("Enter the basic monthly salary");
            b=sc.nextDouble();
            System.out.println("Enter the years of experience");
            yrex=sc.nextInt();
            sc.nextLine();
            A[i] = new Personal(na,ag,ed,b,yrex);
        }
        for(i=0; i<n; i++)
        {
            A[i].Display();
            if( A[i].isEligible() )
            {
                System.out.println("Press 1 to apply for loan or any number to omit");
                int j=0;
                j=sc.nextInt();
                if(j==1)
                {
                    System.out.println("Enter loan amount");
                    A[i].loan_amt=sc.nextDouble();
                    A[i].loan_num++;
                }
            }
            System.out.println("\n\n--------------------------------------------------\n");
        }
    }
}
