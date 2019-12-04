/*Doubly linked list*/
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node *Forw;
	struct node *Back;
};
typedef struct node NODE;
NODE *newnode, *start=NULL, *currptr;

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

//Function to insert a node at the beginning
void insert_beg()
{
	int value;
	printf("\nenter the value for the node:");
	scanf("%d", &value);
	newnode=getnode(value);
	if(start==NULL)
	{
		start=newnode;
		start->Forw=NULL;
		start->Back=NULL;
	}
	else
	{
		newnode->Forw=start;
		newnode->Back=NULL;
                start->Back=newnode;
		start=newnode;
	}
}

//Function to insert a node at the end

void insert_end()
{
	int value;
	printf("\nenter the value for the node:");
	scanf("%d", &value);
	newnode=getnode(value);
	if(start==NULL)
	{
		start=newnode;
		start->Forw=NULL;
		start->Back=NULL;
	}
	else
	{	currptr=start;
		while(currptr->Forw!=NULL)
			currptr=currptr->Forw;
		
		currptr->Forw=newnode;
		newnode->Back=currptr;
		newnode->Forw=NULL;
	}
	printf("\nNODE INSERTED");
}


//Function to insert a node at the given position

void insert_atposition()
{
	int value,pos,count=0,i;
	printf("\nenter the position for the node:");
	scanf("%d", &pos);
	currptr=start;
	while(currptr!=NULL)
	{
		currptr=currptr->Forw;
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
		printf("\nenter the value for the node:");
		scanf("%d", &value);
		newnode=getnode(value);
		for(i=1;i<pos-1;i++)
		{
			currptr=currptr->Forw;
		}
		currptr->Forw->Back=newnode;		
		newnode->Forw=currptr->Forw;
		newnode->Back=currptr;
		currptr->Forw=newnode;	

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
	for(currptr=start;currptr!=NULL;currptr=currptr->Forw)
		printf("%d\t", currptr->data);
}
}

//Displaying- Reverse->linked list
void display_Reverse()
{
if(start==NULL)
{
	printf("\nList Empty, No nodes to display");
	return;
}
else
{	currptr=start;
	while(currptr->Forw!=NULL)
		currptr=currptr->Forw;
	printf("\nThe elements in the list are:");
	while(currptr!=NULL)
	{	printf("%d\t", currptr->data);
		currptr=currptr->Back;
	}
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
else if(start->Forw==NULL)
{
	currptr=start;
	start=NULL;
	free(currptr);
}
else
{
	currptr=start;
	start=start->Forw;
	start->Back=NULL;
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
if(start->Forw==NULL)
{
	currptr=start;
	start=NULL;
	printf("\n The deleted element is %d",currptr->data);
        free(currptr);
     }
else
{
	currptr=start;
	
	while(currptr->Forw!=NULL)
	{
		
           currptr=currptr->Forw;
	}
        printf("\n The last element is %d",currptr->data);
	(currptr->Back)->Forw=NULL;
	printf("\n The deleted element is %d",currptr->data);
	free(currptr);
}
}

void delete_givenPosition()
{ 	int i,pos;
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
	{	
		currptr=start;
		for(i=1;i<pos;i++)
		{
			currptr=currptr->Forw;
		}
		currptr->Back->Forw=currptr->Forw;
		currptr->Forw->Back=currptr->Back;
	
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
	printf("\nOperations on Doubly ->linked list");
	printf("\n1:Insert at Begining");
	printf("\n2:Insert at End");
	printf("\n3:Insert at Given Position");
	printf("\n4:Delete first node");
	printf("\n5:Delete Last node");
	printf("\n6:Delete node given its position");
	printf("\n7:Display the list");
	printf("\n8:Reverese Display the list");
	printf("\n9:Exit");
	
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
		case 8: display_Reverse(); break;
                case 9: exit(0);
		default: printf("\n Invalid Choice"); break;
	}
                fflush(stdin);
	}
return 0;
}
