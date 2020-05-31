#include<stdio.h>
#define MAXN 100010
int a[MAXN],mid,Maxnum=0;
int find(int h,int e)
{
    if(h==e)
    {
        if(a[h]>0) return a[h];
        else return 0;
    }

    int mid=(e+h)/2;
    int Left,Right,i,Max=0,Thisnum=0,MaxR=0,MaxL=0;
    //Max=Thisnum=MaxR=MaxL=0;
    Left=find(h,mid);
    Right=find(mid+1,e);
    for(i=mid;i>=h;i--)
    {
        Thisnum+=a[i];
        if(Thisnum>MaxL)
            MaxL=Thisnum;
    }
    Thisnum=0;
    for(i=mid+1;i<=e;i++)
    {
        Thisnum+=a[i];
        if(Thisnum>MaxR)
            MaxR=Thisnum;
    }
    Max=MaxR+MaxL;
    if(Max<Right) Max=Right;
    if(Max<Left) Max=Left;
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
    Maxnum=find(0,k-1);
    printf("%d",Maxnum);
    return 0;

}
