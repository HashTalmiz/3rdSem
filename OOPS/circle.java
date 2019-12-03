import java.lang.Math;
import java.util.Scanner;
class circle
{
    double r;
    circle(double r)
    {
        this.r = r;
    }
    double area()
    {
        return Math.PI * Math.pow(r,2);
    }
}
class Sector extends circle
{
    double ctr_ang;
    Sector(double r,double ctr_ang)
    {
        super(r);
        this.ctr_ang = Math.toRadians(ctr_ang);
    }
    double area()
    {
        return 0.5 * Math.pow(r,2) * ctr_ang;
    }
}
class Segment extends circle
{
    double h;
    Segment(double r,double h)
    {
        super(r);
        this.h = h;
    }
    double area()
    {
        return Math.abs((Math.pow(r,2)*Math.toRadians((r-h)/r) - ((r-h)*Math.sqrt((2*r*h)-Math.pow(h,2))));
    }
}
class compute
{
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the radius of a circle");
        double r=sc.nextDouble();
        circle ob1 = new circle(r);
        System.out.println("Enter the central angle of a sector");
        double ang=sc.nextDouble();
        Sector ob2 = new Sector(r,ang);
        System.out.println("Enter the length of a segment in a circle");
        double l=sc.nextDouble();
        Segment ob3 = new Segment(r,l);
        System.out.println("Area of circle = "+ob1.area());
        System.out.println("Area of Sector = "+ob2.area());
        System.out.println("Area of Segment = "+ob3.area());
    }
}
