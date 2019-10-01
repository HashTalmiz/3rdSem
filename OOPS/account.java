import java.util.Scanner;
class Account
{
	Scanner s=new Scanner(System.in);
	int accno;
	String name;
	long phoneno;
	float balance_amt;
	public void getinput()
	{
		System.out.print("Enter the Name:");
		name=s.nextLine();
		System.out.print("Enter the account number:");
		accno=s.nextInt();
		System.out.print("Enter the phone number:");
		phoneno=s.nextLong();
		System.out.print("Enter the Balance amount:");
		balance_amt=s.nextInt();
	}
	public void deposit()
	{
		System.out.print("Enter the deposit:");
		int deposit=s.nextInt();
		balance_amt+=deposit;
	}
	public void withdraw()
	{
		System.out.print("Enter the amount to be withdrawn:");
		int withdraw=s.nextInt();
		balance_amt-=withdraw;
	}
	public void display()
	{
		System.out.println("\nName:"+name+"\nAccount Number:"+accno+"\nPhone Number:"+phoneno+"\nBalance Amount:"+balance_amt);
	}
}
class account
{
	public static void main(String[] args)
	{
		Account a1=new Account();
		Scanner s=new Scanner(System.in);
		a1.getinput();
		int ch;
		do
		{
			System.out.println("\nEnter your choice:\n1.Deposit\n2.Withdraw\n3.Display\n4.Exit");
                	ch=s.nextInt();
			switch(ch)
			{
				case 1: a1.deposit();
					break;
				case 2: a1.withdraw();
					break;
				case 3: a1.display();
					break;
				case 4: break;
				default:System.out.println("Invalid Input");
			}
		}while(ch!=4);
	}
}
