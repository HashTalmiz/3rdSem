/*Singly linked list*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
#define NULL 0
struct node
{
int data;
struct node *link;
};
typedef struct node NODE;
NODE *newnode, *start=NULL, *currptr, *prevptr;

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

void insert_beg()
{
	int value;
	printf("\n enter the value for the node:");
	scanf("%d", &value);
	newnode=getnode(value);
	if(start==NULL)
	{
		start=newnode;
		start->link=NULL;
	}
	else
	{
		currptr=start;
start=newnode;
		start->link=currptr;
	}
}


void insert_end()
{
	int value;
	printf("\n enter the value for the node:");
	scanf("%d", &value);
	newnode=getnode(value);
	if(start==NULL)
	{
		start=newnode;
		start->link=NULL;
	}
	else
	{
		currptr=start;
		while(currptr->link!=NULL)
			currptr=currptr->link;
		currptr->link=newnode;
		newnode->link=NULL;
	}
	printf("\n NODE INSERTED");
}



void insert_atposition()
{
	int value,pos,count=0,i;
	printf("\n enter the position for the node:");
	scanf("%d", &pos);
	currptr=start;
	while(currptr!=NULL)
	{
		currptr=currptr->link;
		count++;
	}
	if(pos==1)
	{
		insert_beg();
	}
	else
           if(pos>1&&pos<=count)
	{
		currptr=start;
		printf("\n enter the value for the node:");
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
printf("\n Position out of range");
}

//Displaying ->linked list
void display()
{
if(start==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
else
{
	printf("\n The elements in the list are:");
	for(currptr=start;currptr!=NULL;currptr=currptr->link)
		printf("%d\t", currptr->data);
}
}

//Delete First Node

void delete_firstnode()
{
	if(start==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
else if(start->link==NULL)
{
	currptr=start;
	start=NULL;
	free(currptr);
}
else
{
	currptr=start;
	start=start->link;
	printf("\n The deleted element is %d",currptr->data);
	free(currptr);
}
}

//Function to delete last node

void delete_lastnode()
{
	if(start==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
else if(start->link==NULL)
{
	currptr=start;
	start=NULL;
	printf("\n The deleted element is %d",currptr->data);
	free(currptr);
}
else
{
	currptr=start;
	prevptr=NULL;
	while(currptr->link!=NULL)
	{
		prevptr=currptr;
		currptr=currptr->link;
	}
	prevptr->link=NULL;
	printf("\n The deleted element is %d",currptr->data);
	free(currptr);
}
}

void delete_givenPosition()
{ int i,pos;
printf("\n enter the position for the node:");
	scanf("%d", &pos);
if(start==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
if(pos==1)
{
	delete_firstnode();
}
else
{	currptr=start;
	for(i=1;i<pos;i++)
	{
		prevptr=currptr;
		currptr=currptr->link;
	}
	prevptr->link=currptr->link;
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
	printf("\nOperations on singly ->linked list");
	printf("\n1:Insert at Begining");
	printf("\n2:Insert at End");
	printf("\n3:Insert at Given Position");
	printf("\n4:Delete first node");
	printf("\n5:Delete Last node");
	printf("\n9:Delete node given its position");
	printf("\n6:Display the list");
	printf("\n7:Exit");
	printf("\nEnter the choice");
	scanf("%d", &ch);

	switch(ch)
	{
		case 1:  insert_beg(); break;
		case 2: insert_end(); break;
		case 3: insert_atposition(); break;
		case 4: delete_firstnode(); break;
		case 5: delete_lastnode(); break;
		case 9: delete_givenPosition(); break;
		case 6: display(); break;
                case 7: exit(0);
		default: printf("\n Invalid Choice"); break;
		}
                fflush(stdin);
	}
return 0;
}
