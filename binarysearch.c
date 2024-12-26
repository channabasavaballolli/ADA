 #include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define Max 5000
int binsc(int arr[],int n,int target)
{
	int l=0,r=n-1;
	while(l<=r)
	{
		int mid=l+(r-l)/2;
		if(arr[mid]==target)
		 return mid;
		else if(arr[mid]<target)
		 l=mid+1;
		else
		 r=mid-1;
	}
	return -1;
}
int main()
{
	int arr[Max],res,minpos,temp;
	clock_t t1,t2;
	
	for(int i=0;i<Max;i++)
	{
		arr[i]=rand();
	}

	
	t1=clock();
	    for(int i=0;i<Max-2;i++)
		{
			minpos=i;
			for(int j=i+1;j<Max-1;j++)
			{
				if(arr[j]<arr[minpos])
					minpos=j;
			}
			temp=arr[i];
			arr[i]=arr[minpos];
			arr[minpos]=temp;
		}
	      int target=arr[500];

			
	    
	
		res=binsc(arr,Max,target);
	t2=clock();

	printf("Elements are:\n");
	for(int i=0;i<10;i++)
	{
		printf("%d\t",arr[i]);
	}
	printf("\n");
	
	if (res==-1)
		printf("%d element not found\n",target);
	else
		printf("%d is found at index %d\n",target,res);

	
	float sec=(float)(t2-t1)/CLK_TCK;
	
	printf("%f is the runtime program\n",sec);
	
	return 0;
}
	
	
	
