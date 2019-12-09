#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *Forw;
	struct node *Back;
}NODE;
NODE *newnode, *start=NULL, *ptr=NULL;

NODE *getnode(int value)
{
newnode=(NODE *)malloc(sizeof(NODE));
/*if(newnode==NULL)
{
		printf("\n Memory was not allocated");
		return;
	}
	else
	{*/
		newnode->data=value;
		newnode->Forw =NULL;
		newnode->Back =NULL;
		return newnode;	
//}
}
void insert()
{
	int value;
	printf("Enter the value for the node: ");
	scanf("%d", &value);
	newnode=getnode(value);
	if(start==NULL)
	{
		start=newnode;
		start->Forw=NULL;
		start->Back=NULL;
        return;
	}
    else if(start->data >= newnode->data)
    {
        newnode->Forw=start;
        start->Back=newnode;
		start=newnode;
	}
    else
    {
        ptr=start;
        while (ptr->Forw != NULL && ptr->Forw->data < newnode->data) 
            ptr = ptr->Forw; 
        newnode->Forw = ptr->Forw; 
        if (ptr->Forw != NULL) 
            newnode->Forw->Back = newnode; 
        ptr->Forw = newnode; 
        newnode->Back = ptr; 
    }
}
void display()
{
    if(start==NULL)
    {
	    printf("\nList Empty, No nodes to display");
	    return;
    }
    else
    {
        // printf("____________________________________");
        printf("\nThe elements in the list is/are: ");
        for(ptr=start;ptr!=NULL;ptr=ptr->Forw)
            printf("%d\t", ptr->data);
        printf("\n");
        // printf("____________________________________");
    }
}
int main()
{
    int ch=1;
    do
    {
        printf("\nOperations on Doubly linked list\n");
        printf("1:Insertion\n2.Display\n3:Quit\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1: insert();
            case 2: display(); break;
            case 3: printf("--------TERMINATED--------\n");break;
            default: printf("Incorrect Choice");
        }
    }while(ch!=3);
    return 0;
}
