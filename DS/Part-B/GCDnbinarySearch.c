#include <stdio.h>
#include <stdlib.h>
int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = l + (r - l)/2; 
        if (arr[mid] == x)  
            return mid; 
        if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x); 
        return binarySearch(arr, mid+1, r, x); 
   } 
   return -1; 
}
int gcd(int a, int b) 
{ 
    if (a == 0) 
       return b; 
    if (b == 0) 
       return a; 
    if (a == b) 
        return a; 
    if (a > b) 
        return gcd(a-b, b); 
    return gcd(a, b-a); 
}
int main()
{
    int a,b,n,arr[100],ch;
    redo:
    printf("Choose:\n1.GCD\n2.Binary Search\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter the two numbers:");
        scanf("%d%d",&a,&b);
        a=gcd(a,b);
        printf("The GCD=%d\n",a);
    }
    else if(ch==2)
    {
        printf("Enter the number of elements:");
        scanf("%d",&n);
        printf("Enter the elements:");
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        printf("Enter the searching element:");
        scanf("%d",&b);
        int result=binarySearch(&arr[0],0,n-1,b);
        (result==-1)?printf("Element not found\n"):printf("The element was found at index %d\n",result);
    }
    else
    {
        printf("Incorrect Choice, Please try again\n");
        goto redo;
    }
}