#include<stdio.h>
int gcd(int m,int n)
{
	if(n==0)
	{
		return m;
	}
	return gcd(n,m%n);
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
	
