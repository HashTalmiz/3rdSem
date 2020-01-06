#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>
typedef struct node
{       
	int data;
	struct node* left;
	struct node* right;
}Node;

Node* root=NULL;
void inorder(Node* Root)
{
    if(Root != NULL)
	{
       	inorder(Root->left);
		printf("%d  ", Root->data);
        inorder(Root->right);
 	}
}
Node* createNode(int value)
{
        Node* newnode = (Node*)malloc(sizeof(Node));
        newnode->data = value;
        newnode->left = NULL;
        newnode->right = NULL;
        return newnode;
}
Node* insert(Node* root, int data)
{
	if(root==NULL)
		root=createNode(data);
	else if(data<=root->data)
		root->left=insert(root->left,data);
	else if(data>root->data)
		root->right=insert(root->right,data);
	return root;
}
int main()
{
	int ch,x;
	do
	{
		printf("\nBinary Search Tree Operations\n1.Add Node\n2.Inorder Traverseal\n3.Quit\n");
		scanf("%d",&ch);
		switch(ch)
		{
			case 1: printf("Enter the value:");
					scanf("%d",&x);
					root=insert(root,x);break;
			case 2: inorder(root);break;
			case 3: break;
            default:printf("Incorrect Choice\n");
		}
	}while(ch!=3);
	return 0;
}
