#include<stdio.h>
#include<stdlib.h>
int binarySearch(int arr[], int l, int r, int x) 
{ 
   if (r >= l) 
   { 
        int mid = (l + r)/2; 
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
    int a,b,ch,n,arr[100];
    Redo:
    printf("Choose:\n1.GCD\n2.Binary Search\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter the two numbers:");
        scanf("%d%d",&a,&b);
        printf("The GCD=%d\n",gcd(a,b));
    }
    else if(ch==2)
    {
        printf("Enter the number of elements:\n");
        scanf("%d",&n);
        printf("Enter the numbers in sorted order:\n");
        for(int i=0;i<n;i++)
            scanf("%d",&arr[i]);
        printf("Enter the element to be searched for:");
        int x;
        scanf("%d",&x);
        int result = binarySearch(arr, 0, n-1, x); 
        (result == -1)? printf("Element is not present in array\n") 
                 : printf("Element is present at index %d\n", result); 
    }
    else
    {
        printf("Incorrect Input, Try Again\n");
        goto Redo;
    }
}