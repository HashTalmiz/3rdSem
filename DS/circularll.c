#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
//#define NULL 0
struct node
{
int data;
struct node *link;
};
typedef struct node NODE;
NODE *newnode, *last=NULL, *currptr, *prevptr;

NODE *getnode(int value)
{
newnode=(NODE *)malloc(sizeof(NODE));
/*if(newnode==NULL)
{
		printf("\n Memory was not allocated");
		return;
	}
	else*/
	{
		newnode->data=value;
		newnode->link =NULL;
		return newnode;	
}
}

//Function to insert a node at the beginning
void insert_beg()
{
	int value;
	printf("\nenter the value for the node:");
	scanf("%d", &value);
	newnode=getnode(value);
	if(last==NULL)
	{
		last=newnode;
		last->link=last;
	}
	else
	{
		newnode->link=last->link;
		last->link=newnode;
	}
}

//Function to insert a node at the end

void insert_end()
{
	int value;
	printf("\nenter the value for the node:");
	scanf("%d", &value);
	newnode=getnode(value);
	if(last==NULL)
	{
		last=newnode;
		last->link=last;
	}
	else
	{
		newnode->link=last->link;
		last->link=newnode;
		last=newnode;
	}
	printf("\n NODE INSERTED");
}


//Function to insert a node at the given position

void insert_atposition()
{
	int value,pos,count=0,i;
	printf("\nenter the position for the node:");
	scanf("%d", &pos);
	currptr=last->link;
	while(currptr!=last)
	{
		currptr=currptr->link;
		count++;
	}
	count=count+1;
	if(pos==1)
	{
		insert_beg();
	}
	else
           if(pos>1&&pos<=count)
	{
		currptr=last->link;	
		printf("\nenter the value for the node:");
		scanf("%d", &value);
		newnode=getnode(value);
		for(i=1;i<pos-1;i++)
		{
			currptr=currptr->link;
		}
		newnode->link=currptr->link;
		currptr->link=newnode;	
		printf("\n NODE  INSERTED");
	}
	else
	printf("\nPosition out of range");
}

//Displaying ->linked list
void display()
{
if(last==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
else
{
	printf("\n The elements in the list are:");
	for(currptr=last->link;currptr!=last;currptr=currptr->link)
		printf("%d\t", currptr->data);
}
		printf("%d\t", currptr->data);
}

//Delete First Node

void delete_firstnode()
{
	if(last==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
else if(last->link==last)
{
	currptr=last;
	last=NULL;
	free(currptr);
}
else
{
	currptr=last->link;
	last->link=currptr->link;
	printf("\n The deleted element is %d",currptr->data);
	free(currptr);
}
}

//Function to delete last node

void delete_lastnode()
{
	if(last==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
else if(last->link==last)
{
	currptr=last;
	last=NULL;
	printf("\n The deleted element is %d",currptr->data);
	free(currptr);
}
else
{
	currptr=last->link;
	prevptr=NULL;
	while(currptr->link!=last->link)
	{
		prevptr=currptr;
		currptr=currptr->link;
	}
	prevptr->link=last->link;
	last=prevptr;
	printf("\n The deleted element is %d",currptr->data);
	free(currptr);
}
}

void delete_givenPosition()
{ int i,pos;
printf("\n enter the position for the node:");
	scanf("%d", &pos);
if(last==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
if(pos==1)
{
	delete_firstnode();
}
else
{	currptr=last->link;
	for(i=1;i<pos;i++)
	{
		prevptr=currptr;
		currptr=currptr->link;
	}
	prevptr->link=currptr->link;
	if(currptr==last)
	last=prevptr;
	printf("\n The deleted element is %d",currptr->data);
	free(currptr);
}
}
//Main Program

int main()
{
	int ch;
	
	while(1)
{
	printf("\nOperations on Circular linked list");
	printf("\n1:Insert at Begining");
	printf("\n2:Insert at End");
	printf("\n3:Insert at Given Position");
	printf("\n4:Delete first node");
	printf("\n5:Delete Last node");
	printf("\n6:Delete node given its position");
	printf("\n7:Display the list");
	printf("\n8:Exit");
	printf("\nEnter the choice");
	scanf("%d", &ch);

	switch(ch)
	{
		case 1:  insert_beg(); break;
		case 2: insert_end(); break;
		case 3: insert_atposition(); break;
		case 4: delete_firstnode(); break;
		case 5: delete_lastnode(); break;
		case 6: delete_givenPosition(); break;
		case 7: display(); break;
                case 8: exit(0);
		default: printf("\n Invalid Choice"); break;
		}
                fflush(stdin);
	}
return 0;
}