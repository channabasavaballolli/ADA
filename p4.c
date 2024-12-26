#include<stdio.h>
int gcd(int m ,int n)
{
	int t;
	if(m>n)
	{
		t=m;
	}
	else
	{
		t=n;
	}
	while(t!=0)
	{
		if(m%t==0&&n%t==0)
		{
			return t;
		}
		t=t-1;
	}
	return 1;
}
int main()
{
	int m,n,res;
	printf("enter the first number:");
	scanf("%d",&m);
	printf("enter the second number:");
	scanf("%d",&n);
	res=gcd(m,n);
	printf("the gcd of %d and %d is %d",m,n,res);
	return 0;
}
