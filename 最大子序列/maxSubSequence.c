#include<stdio.h>
#define MAXN 10010
int a[MAXN];
int find_se1(int *a,int k) //时间复杂度O^3运行到10000个数据时超时
{
    int i,j,n,max_sum,sum;
    max_sum = 0;
    for(i = 0;i < k;i++)
     {
     for(j = i;j < k;j++)
       {
            sum = 0;
            for(n = i;n <= j;n++)
                sum += a[n];
            if(max_sum < sum) max_sum = sum;
        }
     }
    return max_sum;
}
int find_se2(int *a,int k) //时间复杂度O^2运行到1000000个数据超时
{
    int i,j,n,max_sum,sum;
    max_sum = 0;
    for(i = 0;i < k;i++)
     {
         sum = 0;
     for(j = i;j < k;j++)
       {
                sum += a[j];
            if(max_sum < sum) max_sum = sum;
        }
     }
    return max_sum;
}
int binary_find(int *a,int head,int rear) //运行1000000个数据时发生段错误，耗时13ms
{
    int mid = (head + rear)/2;
    int left_max,right_max,mid_max_L,mid_max_R,i,max_sum;
    if(head >= rear) 
        if(a[head]>0) return a[head];
        else return 0;
    left_max = binary_find(a,head,mid);
    right_max = binary_find(a,mid+1,rear);
    max_sum = 0;
    mid_max_L = mid_max_R = 0;
    for(i = mid;i >= head;i--)
    {
        max_sum += a[i];
        if(max_sum > mid_max_L) mid_max_L = max_sum;
    }
    max_sum = 0;
    for(i = mid+1;i <= rear;i++)
    {
        max_sum += a[i];
        if(max_sum > mid_max_R) mid_max_R = max_sum;
    }
    max_sum = mid_max_L+mid_max_R;
    if(left_max > max_sum) max_sum = left_max;
    if(right_max > max_sum) max_sum = right_max;
    return max_sum;                                       
}
int find_se3(int *a,int k)
{
    int max_sum;
    max_sum = binary_find(a,0,k-1);
    return max_sum;

}
int find_se4(int *a,int k)
{
    int max_sum,i,sum;
    sum = max_sum = 0;
    for(i = 0 ;i < k;i++)
    {
        
            sum += a[i];
            if(max_sum < sum) max_sum = sum;
            if(sum < 0) sum = 0;
        
    }
    return max_sum;
}
int main()
{
    int max_sub_se,i,k;
    scanf("%d",&k);
    for(i = 0;i < k ;i++ )
        scanf("%d",&a[i]);
    max_sub_se = find_se4(a,k);
    printf("%d",max_sub_se);
    return 0;
}