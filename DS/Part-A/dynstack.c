#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
int *a,top=-1,n=0;
void push(int x)
{
    if(top==n-1)
        a=(int*)realloc(a,++n*sizeof(int));
    (a!=NULL)?a[++top]=x:printf("STACK OVERFLOW\nNot enough memory for %d elements\n",n--);
    printf("PUSH SUCCESSFULL\n");
}
void pop()
{
    if(top==-1)
        printf("-------STACK UNDERFLOW-------\n");
    else
        printf("%d has been Popped\n",a[top--]);
}

void display()
{
    if(top==-1)
    {
        printf("-------STACK UNDERFLOW-------\n");
        return;
    }
    printf("The elements of the stack are:\n");
    for(int i=0;i<=top;i++)
        printf("%d ",*(a+i));
    printf("\n");
}
int main()
{
    int ch,x;
   do
   {
       printf("\nOperations on stack\nEnter your choice:\n1.Push\n2.Pop\n3.Display\n4.Exit\n");
       scanf("%d",&ch);
       switch(ch)
       {
            case 1:printf("Enter the element to be pushed:");
                    scanf("%d",&x);
                    push(x);break;
            case 2:pop();break;
            case 3:display();
            case 4:break;
            default:printf("Incorrect Choice\n");
       }
   }while(ch!=4);
}