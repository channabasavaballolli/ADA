#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 5000

int main()
{
	int arr[Max],temp;
	clock_t t1,t2;
	
	for(int i=0;i<Max;i++)
	{
		arr[i]=rand();
	}
	for(int i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
	t1=clock();
	for(int i=0;i<Max-1;i++)
	{
		for(int j=0;j<Max-i-1;j++)
		{
			if(arr[j]>arr[j+1])
			{
				temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
	t2=clock();
	
	printf("sorted elements are\n");
	for(int i=0;i<10;i++)
	{
		printf("%d\n",arr[i]);
	}
	
	float sec=(float)(t2-t1)/CLK_TCK;
	printf("%f\n",sec);
	
	return 0;
}
	
	
