#include<stdio.h>
#define MaxNum 10
typedef struct TreeNode
{
    int Left;
    int Right;
}TreeNode;
TreeNode T[MaxNum];
int BuiltTree(TreeNode T[],int N)
{
    char cl,cr;
    int root=-1,i,j,check[MaxNum];
    if(N)
    {
        for(i = 0;i < N;i++)
            check[i] = 0;
        for(i = 0;i < N;i++)
        {
            scanf("%c %c\n",&cl,&cr);
            if(cl != '-')
                {
                    T[i].Left = cl - '0';
                    check[T[i].Left] = 1;
                }
            else
            {
                T[i].Left = -1;
            }
            
            if(cr != '-')
                {
                    T[i].Right = cr - '0';
                    check[T[i].Right] = 1;
                }
            else
            {
                T[i].Right = -1;
            }
            
        }
        for(j = 0;j < N;j++)
        {
            if(!check[j]) 
                break;
        }   
        root = j;
    }
    return root;
}
void Searchleave(int R,int N)
{
    int queue[MaxNum],head,end;
    end = head =-1;
    queue[++end] = R;
    head++;
    int flag = 0;
    while(head<N)
    {
        if(T[queue[head]].Left != -1)
            queue[++end] = T[queue[head]].Left;
        if(T[queue[head]].Right != -1)
            queue[++end] = T[queue[head]].Right;
        if((T[queue[head]].Left == -1) && (T[queue[head]].Right == -1))
           if(flag)
            printf(" %d",queue[head]);
            else
                {
                    printf("%d",queue[head]);
                    flag = 1;
                }
        head++;
    }
}
int main()
{
    int R,N;
    scanf("%d\n",&N);
    R = BuiltTree(T,N);
    Searchleave(R,N);
    return 0;
}