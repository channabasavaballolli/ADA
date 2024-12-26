#include<stdio.h>
int main()
{
	int m,n,r;
	printf("enter the first number:");
	scanf("%d",&m);
	printf("enter the second number:");
	scanf("%d",&n);
	while(n!=0)
	{
		r=m%n;
		m=n;
		n=r;
	}
	printf("the gcd is %d",m);
	return 0;
}

	
