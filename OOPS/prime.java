import java.util.Scanner;
class prime
{
	public static void main(String args[])
	{
		int i,n,flag=0;
		System.out.print("Enter the number:");
		Scanner lol=new Scanner(System.in);
		n=lol.nextInt();
		for(i=2;i<=n/2;i++)
		{
			if(n%i==0)
			{
				System.out.println("Not a prime number");
				flag++;
				break;
			}
		}
			if(flag==0)
				System.out.println("Prime Number");
	}
}
