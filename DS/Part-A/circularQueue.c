#include<stdio.h>
#include<stdlib.h>
int count=0,f=-1,r=-1,size=5,cq[100];
void insert(int item)
{   
    if(count==size)
    {
        printf("Queue Overflow");
        return;
    }
    if(f==-1&&r==-1)
        f=0;
    r=(r+1)%size;
    cq[r] = item;
    count++;
}
void delete()
{
    if(count==0)
    {
        printf("Queue Underflow\n");
        return;
    }
    printf("The element removed is %d\n",cq[f]);
    f=(f+1)%size;
    count--;
}
void display()
{
    int i;
    if(count==0)
    {
        printf("Queue Underflow");
        return;
    }
    printf("The elements are: ");
    for(i=f ; i!=r ; i=(i+1)%size)
        printf("%d\t",cq[i]);
    printf("%d\t",cq[i]);
}
int main()
{
    int ch,item;
    do
    {
        printf("\nChoose:\n1.Insert\n2.Display\n3.Delete\n4.Quit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: printf("Enter the element to be inserted:");
                    scanf("%d",&item);
                    insert(item);
            case 2: display(); break;
            case 3: delete(); break;
            case 4: break;
            default:printf("Invalid Input");
        }
    }while(ch!=4);
}