import java.util.Scanner;
class palindrome
{
	public static void main(String args[])
	{
		int digit,rev=0;
		System.out.print("Enter the number:");
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int copy=n;
		while(n!=0)
		{
			digit=n%10;
			rev=(rev*10)+digit;
			n=n/10;
		}
		if(rev==copy)
			System.out.println("Palindrome");
		else
			System.out.println("Not a Palindrome");
	}
}
