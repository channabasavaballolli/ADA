#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 500
int i,j;
void swap(int *a,int *b)
{
	int temp=*a;
	*a=*b;
	*b=temp;
}


int partition(int a[Max],int l,int h)
{
	int pivot=a[l],i=l+1;j=h;
	while(i<=j)
	{
		while(a[i]<=pivot && i<=h)
		i++;
		while(a[j]>pivot && j>=l)
		j--;
		if(i<j)
		swap(&a[i],&a[j]);
	}
	swap(&a[l],&a[j]);
	return j;
}

		
void quicksort(int a[Max],int l,int h)
{
	if(l<h)
	{
		int pi=partition(a,l,h);
		quicksort(a,l,pi-1);
		quicksort(a,pi+1,h);
	}
}

	
	


int main()
{
	int a[Max];
	clock_t t1,t2;
	for(int i=0;i<Max;i++)
	a[i]=rand()%1000;
	printf("First 10 elements before sorting");
	for(int i=0;i<10;i++)
	printf("%d\n",a[i]);
	printf("\n");
	t1=clock();
	quicksort(a,0,Max-1);
	t2=clock();
	printf("First 10 elements after sorting");
	for(int i=0;i<50;i++)
	printf("%d\n",a[i]);
	float sec=(float)(t2-t1)/CLK_TCK;
	printf("SECS=%f",sec);
	
	return 0;
}

	
