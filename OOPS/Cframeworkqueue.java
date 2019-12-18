import java.util.*;
public class Cframeworkqueue
{
    ArrayList<String> alist = new ArrayList<>();
    void insert(String s)
    {
        alist.add(s);
    }
    void delete()
    {
        if (alist.isEmpty())
            System.out.println("UNDERFLOW");
        else {
            System.out.println("String deleted is " + alist.get(0));
            alist.remove(0);
        }
    }
    void display()
    {
        if (alist.isEmpty())
            System.out.println("UNDERFLOW");
        else
            System.out.println(alist);
    }
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        Cframeworkqueue ob = new Cframeworkqueue();
        int ch;
        while (true)
        {
            System.out.println("Press 1 to insert\nPress 2 to delete\nPress 3 to display\nPress 4 to exit");
            ch = sc.nextInt();
            switch (ch) {
                case 1: System.out.println("Enter a string");
                        sc.nextLine();
                        ob.insert(sc.nextLine());
                        break;
                case 2: ob.delete();
                        break;
                case 3: ob.display();
                        break;
                case 4: System.exit(0);
                default:System.out.println("Incorrect choice");
            }
        }
    }
}
