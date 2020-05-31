#include<stdio.h>
#define MAXN 100010
int a[MAXN],mid,Maxnum=0;
int find(int *a,int k)
{
    int temp,Max,i;
    Max=temp=0;
    for(i=0;i<k;i++)
    {
        temp+=a[i];
        if(temp>Max) Max=temp;
        else if (temp<0)temp=0;
    }
    return Max;
}
int main()
{
    int k,n;
    scanf("%d",&k);
    for(n=0;n<k;n++)
    {
        scanf("%d",&a[n]);
    }
    Maxnum=find(a,k);
    printf("%d",Maxnum);
    return 0;

}
