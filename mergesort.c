#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 5000

void merge(int b[],int c[],int a[],int p,int q)
{
	int i=0;
	int j=0;
	int k=0;
	
	while(i<p && j<q)
	{
		if(b[i]<=c[j])
		{
			a[k]=b[i];
			i++;
		}
		else
		{
			a[k]=c[j];
			j++;
		}
		k++;
	}
	while(i<p)
	{
		a[k]=b[i];
		i++;
		k++;
	}
	while(j<q)
	{
		a[k]=c[j];
		j++;
		k++;
	}
}

void mergesort(int a[],int n)
{
	if(n<2)
	return;
	
	int mid=n/2;
	int b[mid],c[n-mid];
	
	for(int i=0;i<mid;i++)
	{
		b[i]=a[i];
	}
	for(int i=mid;i<n;i++)
	{
		c[i-mid]=a[i];
	}
	mergesort(b,mid);
	mergesort(c,n-mid);
	merge(b,c,a,mid,n-mid);
}
	
int main() 
	{
    int a[Max];
    clock_t t1, t2;

    // Generate random elements
    for (int i = 0; i < Max; i++) {
        a[i] = rand();
    }

    printf("Elements: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    t1 = clock();
    mergesort(a,Max);

    t2 = clock();

    printf("Sorted array: ");
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");

    float sec = (float)(t2 - t1) / CLOCKS_PER_SEC;
    printf("Runtime of program: %f\n", sec);

    return 0;
}

