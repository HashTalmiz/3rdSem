import java.util.*;
class string
{
    public static void main(String args[]) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter a string: ");
        String str = sc.nextLine(); // or str = new Scanner(System.in).nextLine();
        System.out.println("Enter the number of characters to be extracted: ");
        int m = sc.nextInt();
        System.out.println("Enter the index to begin at: ");
        int n = sc.nextInt();
        String sub = str.substring(n, n + m);
        System.out.println(sub);
        sc.nextLine();
        System.out.println("Enter the substring(Occourence check): ");
        sub = sc.nextLine();
        System.out.println("The count is: " + occourence(sub, str));
        System.out.println("String after replacing 'e' with 'o ':" + str.replace("e", "o"));
        System.out.println("String after sorting:");
        sort(str);
        str="MSRIT";
        sub="msrit";
        System.out.println("s1:MSRIT\ns2:msrit\ns1 equals ignore case to s2: "+str.equalsIgnoreCase(sub));
        String s3= str + sub;
        System.out.println("Concatenating s1 and s2:"+ s3);
    }
    static int occourence(String findstr, String str)
    {
        String a[] = str.split(" ");
        int count=0;
        for(int i=0;i<a.length;i++)
        {
            if(findstr.equals(a[i]))
                count++;
        }
        return count;
    }
    static void sort(String str)
    {
        int j = 0;
        char temp = 0;
        char[] chars = str.toLowerCase().toCharArray();

        for (int i = 0; i < chars.length; i++) {

            for (j = 0; j < chars.length; j++) {

                if (chars[j] > chars[i]) 
                {
                    temp = chars[i];
                    chars[i] = chars[j];
                    chars[j] = temp;
                }

            }

        }

        for (int i = 0; i < chars.length; i++) {
            System.out.print(chars[i]);
        }
        System.out.println();
    }
}
