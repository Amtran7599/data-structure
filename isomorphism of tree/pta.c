#include<stdio.h>
#define MaxTree 10
#define ElementType char
#define Tree int
#define Null -1
struct TreeNode
{
    ElementType Node;
    Tree Left;
    Tree Right;
}T1[MaxTree],T2[MaxTree];
Tree BuiltTree(struct TreeNode T[])
{
    int N,i,check[MaxTree],root = -1;
    char cl,cr;
    scanf("%d\n",&N);
    if(N)
    {
        for(i = 0;i < N;i++)
        check[i] = 0;
    for(i = 0;i < N;i++)
    {
        scanf("%c %c %c\n",&T[i].Node,&cl,&cr);
        if(cl != '-')
        {
            T[i].Left = cl - '0';
            check[T[i].Left] = 1;
        }  
        else T[i].Left = Null;

        if(cr != '-') 
        {
            T[i].Right = cr - '0';
            check[T[i].Right] = 1;
        }
        else T[i].Right = Null;
    }
    for (i = 0;i < N;i++)
    {
        if(!check[i]) break;
    }
    root = i;
    }
    return root;
}
int isomorphic(int root1, int root2)
 {
     if( (root1 == Null) && (root2 == Null))
         return 1;
     if( (root1 == Null)&&(root2 != Null) || (root1 != Null)&&(root2 == Null))
         return 0;
     if(T1[root1].Node != T2[root2].Node)   return 0;  
     if( (T1[root1].Left == Null) && (T2[root2].Left == Null) ) 
         return isomorphic(T1[root1].Right, T2[root2].Right);
         
     if((T1[root1].Left != Null) && (T2[root2].Left != Null) &&
         ( T1[T1[root1].Left].Node == T2[T2[root2].Left].Node) )
         return (isomorphic(T1[root1].Left, T2[root2].Left) &&   
                 isomorphic(T1[root1].Right, T2[root2].Right) );
     else  
         return (isomorphic(T1[root1].Left, T2[root2].Right) &&  
                 isomorphic(T1[root1].Right, T2[root2].Left) );
     
 }
int main()
{
    Tree R1,R2;
    int ok;
    R1 = BuiltTree(T1);
    R2 = BuiltTree(T2);
    ok = isomorphic(R1,R2);
    if(ok)
        printf("Yes\n");
    else 
        printf("No\n");
    return  0;
}