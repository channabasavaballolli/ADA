#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 50000

int main()
{
	int arr[Max],pos,temp;
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
	for(int i=0;i<Max-2;i++)
	{
		pos=i;
		for(int j=i+1;j<Max-1;j++)
		{
			if(arr[j]<arr[pos])
			{
				pos=j;
			}
		}
		temp=arr[i];
		arr[i]=arr[pos];
		arr[pos]=temp;
	}
	t2=clock();
	
	printf("sorted array elements are\n");
	for(int i=0;i<10;i++)
	{
		printf("%d\n",arr[i]);
	}
	printf("\n");
	
	float sec=(float)(t2-t1)/CLK_TCK;
	printf("time taken to sort:%f\n",sec);
	
	return 0;
}
		
