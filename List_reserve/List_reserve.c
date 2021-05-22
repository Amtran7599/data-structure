#include<stdio.h> //链表反转
#define MAXN 100010

struct Node
{
    int Data;
    int Next;
}node[MAXN];
int ReserveList(int AddHead,int N,int K)
{
    int New,Old,Temp,reaserved_Head,reaserved_End,Rev_New;
    int flag = 1;
    Rev_New = New = AddHead;
    Old = node[New].Next;
    int j,i;
    for(j = K;j <= N;j += K)
    { 
        for(i = 0;i < K-1;i++)      //K个节点反转K-1次
        {
            Temp = node[Old].Next;
            node[Old].Next = New;
            node[Rev_New].Next = Temp;
            New = Old;
            Old = Temp;
        }
        if (flag)//保存头次反转头节点
        {
            reaserved_Head = New;
            flag = 0;
        }
        else//将此次链表头节点连接上上次反转链表尾节点
        {
            node[reaserved_End].Next = New;
        }
        reaserved_End = Rev_New;
        Rev_New = New = node[Rev_New].Next;
        Old = node[Rev_New].Next;
    }
    return reaserved_Head;
}


void display_Node(int Address,int N)
{ 
    int i;
   for(i=0;i<N-1;i++)
    {
            printf("%05d %d %05d\n",Address,node[Address].Data,node[Address].Next);
            Address = node[Address].Next;
    }
    printf("%05d %d -1\n",Address,node[Address].Data);
}
int main()
{
    int AddHead,K,N,i,Address;
    scanf("%d%d%d",&AddHead,&N,&K);//输入头节点，节点数，反转节点数
    for(i=0;i<N;i++)
    {
        scanf("%d",&Address);
        scanf("%d%d",&node[Address].Data,&node[Address].Next);
    }
    int next = AddHead;
    int num = 1;
    while(node[next].Next != -1)
    {
        num++;
        next = node[next].Next;
    }
    i = AddHead;
    if(K > 1)
    {
        i  = ReserveList(AddHead,num,K);
    }
    display_Node(i,num);
}