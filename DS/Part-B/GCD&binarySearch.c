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
    int a,b;
    printf("Choose:\n1.GCD\n2.Binary Search\n");
    scanf("%d",&ch);
    if(ch==1)
    {
        printf("Enter the two numbers:");
        scanf("%d%d",&a,&b);
        a=GCD(a,b);
        printf("The GCD=%d",a);
    }
}