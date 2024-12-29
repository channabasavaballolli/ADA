#include<stdio.h>
int count =0;
void sumfun(int set[],int sub[],int n,int index,int sum)
{
    if(sum==0)
    {
        count=1;
        printf("{");
        for(int i=0;i<index;i++)
        printf("%d ",sub[i]);
        printf("}\t");
        return ;
    }
    if(n==0)
    return ;
    sub[index]=set[n-1];
    sumfun(set,sub,n-1,index+1,sum-sub[index]);
    sumfun(set,sub,n-1,index,sum);
}
int main()
{
    int n,sum;
    printf("Enter no of ele\n");
    scanf("%d",&n);
    int set[n],sub[n];
    printf("Enter nos\n");
    for(int i=0;i<n;i++)
    scanf("%d",&set[i]);
    printf("Enter sum\n");
    scanf("%d",&sum);
    sumfun(set,sub,n,0,sum);
    return 0;
}
