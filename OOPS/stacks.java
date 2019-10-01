import java.util.Scanner;
class stacks
{
	int top,a[],n;
	stack(int size)
	{
		top=-1;
		a= new int[size];
		n=size;
	}
	public void display()
	{
		int i;
		System.out.println("___________________________________");
		System.out.println("The stack is:");
		for(i=0;i<=top;i++)
			System.out.print(a[i]+" ");
		System.out.println("\n___________________________________");
	}
	public void push()
	{
		if(top==n-1)
		{
			System.out.println("____________________________\nSTACK OVERFLOW\n____________________________");
			return;
		}
		else
		{
			System.out.print("Enter the element:");
			a[++top]= new Scanner(System.in).nextInt();
		}
		display();
	}
	public void pop()
	{
		if(top==-1)
		{
			System.out.println("_________________\nSTACK UNDERFLOW\n_________________");
			return;
		}
		else
		{
			System.out.println("Element Removed:"+a[top--]);
			System.out.println("The Stack is:");
			display();
		}
	}

	public static void main(String[] args) 
	{
		int ch;
		Scanner sc = new Scanner(System.in);
		System.out.print("Enter the size of the stack:");
		int siz= sc.nextInt();
		stack s1= new stack(siz);
		do
		{
			System.out.println("\nEnter the Choice:\n1.Push\n2.Pop\n3.Display\n4.Exit");
			ch = sc.nextInt();
			switch(ch)
			{
				case 1:s1.push();
						break;
				case 2: s1.pop();
						break;
				case 3: s1.display();
						break;
				case 4: break;
				default:System.out.println("Invalid Input");
			}
		}while(ch!=4);
	}	
}

	
