import java.util.Scanner;
class complex{
	double real, img;
	
	complex(double r, double i){
		this.real = r;
		this.img = i;
	}
	
	public static void sum(complex c1, complex c2)
	{
		complex temp = new complex(0, 0);

		temp.real = c1.real + c2.real;
		temp.img = c1.img + c2.img;

		System.out.println("Sum is: ("+ temp.real+") + ("+ temp.img +")i");
	}
	public static void diff(complex c1, complex c2)
	{
		complex temp = new complex(0, 0);

		temp.real = c1.real - c2.real;
		temp.img = c1.img - c2.img;

		System.out.println("Difference is: ("+ temp.real+") + ("+ temp.img +")i");
	}
	public static void product(complex c1, complex c2)
	{
		complex temp = new complex(0, 0);

		temp.real = (c1.real * c2.real)-(c1.img * c2.img);
		temp.img = (c1.img*c2.real)+(c1.real*c2.img);

		System.out.println("Product is: ("+ temp.real+") + ("+ temp.img +")i");
	}
	public static void main(String args[]) 
	{
		Scanner in = new Scanner(System.in);
		System.out.println("Enter the real and imaginary numbers of the first complex:");
		double r=in.nextDouble();
		double i=in.nextDouble();
		complex c1 = new complex(r,i);
		System.out.println("Enter the real and imaginary numbers of the second complex:");
		r=in.nextDouble();
		i=in.nextDouble();
		complex c2 = new complex(r,i);
		int ch;
		do
		{
			System.out.println("Enter the choice:\n1.Add\n2.Subtract\n3.Multiply\n4.Exit");
			ch=in.nextInt();
			switch(ch)
			{
				case 1: sum(c1,c2);
						break;
				case 2: diff(c1,c2);
						break;
				case 3: product(c1,c2);
						break;
				case 4: break;	
			}
		}while(ch!=4);
	}
}