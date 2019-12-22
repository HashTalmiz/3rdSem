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
	int n;
	printf("Enter the number of nodes:");
	scanf("%d",&n);
	int *a=(int*)malloc(n*sizeof(int));
	printf("Enter the node elements:");
	for(int i=0;i<n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<n;i++)
		root=insert(root,a[i]);
	printf("The inorder traversal of the Binary Search Tree is: ");
	inorder(root);
	free(a);
	return 0;
}
