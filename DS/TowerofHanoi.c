#include <stdio.h>
void toh(int n, char source, char tmp, char dest)
{
    if (n==1)
    {
        printf("Move disk for %c to %c\n",source,dest);
    }
    else
    {
        toh(n-1,source,dest,tmp);
        printf("Move disk from %c to %c\n",source,dest);
        toh(n-1,tmp,source,dest);
    }
}
int main()
{
    int n;
    printf("Enter the number of disks:");
    scanf("%d",&n);
    toh(n,'A','B','C');
	return 0;
}
