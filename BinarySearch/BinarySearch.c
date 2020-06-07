#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 10
#define NotFound 0
typedef int ElementType;

typedef int Position;
typedef struct LNode *List;
struct LNode {
    ElementType Data[MAXSIZE];
    Position Last; /* �������Ա������һ��Ԫ�ص�λ�� */
};

List ReadInput(); /* ����ʵ�֣�ϸ�ڲ���Ԫ�ش��±�1��ʼ�洢 */
Position BinarySearch( List L, ElementType X );

int main()
{
    List L;
    ElementType X;
    Position P;

    L = ReadInput();
    scanf("%d", &X);
    P = BinarySearch( L, X );
    printf("%d\n", P);

    return 0;
}
//���õݹ飬�ύ���Ϊ�δ��󣬲²��ǽ����ռ���౬ջ��
/*
Position BinarySearch(List L,ElementType X)
{
    if(X>L->Data[L->Last]||L->Last==0) return 0;
    List Lf,Lr;
    int medium=(1+L->Last)/2,i;
    if(L->Data[medium]==X) return medium;
    else if(L->Data[medium]<X)
    {
        Lf->Last=medium;
        for(i=1;i<=medium;i++)
            Lf->Data[i]=(L->Data[i]);
        return BinarySearch(Lf,X);
    }
    else if(X>L->Data[medium])
    {
        Lr->Last=L->Last;
        for(i=1;i<L->Last;i++)
            Lr->Data[i]=L->Data[i+medium];
        return BinarySearch(Lr,X);
    }
}*/
Position BinarySearch(List L,ElementType X)
{
   int left,right,medium;
   left=1;
   right=L->Last;
   medium=(left+right)/2;
   while(left<=right)
   {
    if(L->Data[medium]>X) right=medium-1;
       else if(L->Data[medium]<X)
        left=medium+1;
       else
        return medium;
       medium=(left+right)/2;
   }
   return NotFound;
}
