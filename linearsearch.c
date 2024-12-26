#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#define MAX 5000

int main() {
    int key,n;
    int res=-1;
    clock_t t1,t2; 
    printf("Enter number of elements: ");
    scanf("%d", &n);
    int a[n];
    printf("Enter elements: ");
    for(int i=0;i<=n;i++)
    {
		a[i]=rand();
	}
	
    
    for(int i=0;i<=200;i++)
	{
		printf("%d\n",a[i]);
	}
	printf("Enter the number to search: ");
    scanf("%d", &key);
    t1=clock();
   
    for (int i = 0;i<n; i++) {
        if (a[i] == key) {
            res = i; 
            break; 
        }
    }
    t2=clock();

    if (res != -1) {
        printf("Element found at index: %d\n", res+1);
    } else {
        printf("Element not found in the array.\n");
    }
    float sec=(float)(t2-t1)/CLK_TCK;
	printf("secs:%.6f",sec);

    return 0;
}
