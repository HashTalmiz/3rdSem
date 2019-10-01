import java.util.Scanner;
class fibonacc
{
	static void printfib(int count,int n1,int n2,int n3)
	{		
		if(count>0)
		{
			n3 = n1 + n2;
			System.out.print(" "+n3);       
			n1 = n2;    
			n2 = n3;    		        
			printfib(count-1,n1,n2,n3);    
		}
	}    
	

	public static void main(String args[])
	{
		int n1=0,n2=1,n3=0,count;	
		System.out.println("Choose the method:\n1.Iterative Method\n2.Recursive Method");
		Scanner s = new Scanner(System.in);
		int c = s.nextInt();
		switch(c)
		{
			case 1:
			System.out.print("Enter the number of elements:");	
			count= s.nextInt();
			if(count==1)
				System.out.println(n1);
			else if(count==2)
				System.out.println(n2);
			else 
			{
				System.out.print(n1+" "+n2+" ");
				while((count--)>2)
				{
					n3=n2+n1;
					System.out.print(n3+" ");
					n1=n2;
					n2=n3;
				}
				System.out.print("\n");
			}
			break;
			case 2: System.out.print("Enter the number of elements:");
			count= s.nextInt();
			if(count==1)
				System.out.println(n1);
			else if(count==2)
				System.out.println(n1+" "+n2);
			else 
			{
				System.out.print(n1+" "+n2);
				printfib(count-2,n1,n2,n3);
				System.out.print("\n");
			}
			break;
			default:System.out.println("Invalid Input");
			
		}
	}
}

