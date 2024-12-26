#include<stdio.h>
int main()
{
	int arr[1000], n, t;
    printf("enter a number to find prime numbers 2 to the number:");
    scanf("%d",&n);
    for(int i=2;i<n;i++)
    arr[i]=0;
    for(int i=2;i<n;i++)
    {
		if(arr[i]==0)
		printf("%d\t",i);
		else
		continue;
		t=i+i;
		while(t<n)
		{
			arr[t]=-1;
			t=t+i;
		}
	}
	printf("\n");
	return 0;
}
	
