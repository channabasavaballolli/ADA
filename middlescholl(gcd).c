#include<stdio.h>
int main()
{
    int m, n, p=1;
    printf("enter the first number:");
    scanf("%d",&m);
	printf("enter the second number:");
	scanf("%d",&n);
    for (int i = 2; i <= m && i <= n; i++)
     {
        while(m % i == 0 && n % i == 0) {
            p= p*i; 
            m/=i;
            n=n/i;
        }
    }
    
    printf("gcd is: %d\n",p);
    return 0;
}

