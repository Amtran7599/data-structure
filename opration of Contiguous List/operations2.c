#include <stdio.h>
#include <stdlib.h>

#define ERROR NULL
typedef int ElementType;
typedef struct LNode *PtrToLNode;
struct LNode {
    ElementType Data;
    PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

Position Find( List L, ElementType X );
List Insert( List L, ElementType X, Position P );
List Delete( List L, Position P );

int main()
{
    List L;
    ElementType X;
    Position P, tmp;
    int N;

    L = NULL;
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        L = Insert(L, X, L);
        if ( L==ERROR ) printf("Wrong Answer\n");
    }
    scanf("%d", &N);
    while ( N-- ) {
        scanf("%d", &X);
        P = Find(L, X);
        if ( P == ERROR )
            printf("Finding Error: %d is not in.\n", X);
        else {
            L = Delete(L, P);
            printf("%d is found and deleted.\n", X);
            if ( L==ERROR )
                printf("Wrong Answer or Empty List.\n");
        }
    }
    L = Insert(L, X, NULL);
    if ( L==ERROR ) printf("Wrong Answer\n");
    else
        printf("%d is inserted as the last element.\n", X);
    P = (Position)malloc(sizeof(struct LNode));
    tmp = Insert(L, X, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    tmp = Delete(L, P);
    if ( tmp!=ERROR ) printf("Wrong Answer\n");
    for ( P=L; P; P = P->Next ) printf("%d ", P->Data);
    return 0;
}
List MakeEmpty()
{
	List head;
	head = (List)malloc(sizeof(struct LNode));
	head->Next = NULL;
	head->Data = 0;
	return head;
}
Position Find(List L,ElementType X)
{
	List head = L;
	while(head)
	{
		if(head->Data == X)
			return head;
		head = head->Next;
	}
	return ERROR;
}
bool Insert(List L,ElementType X,Position P)
{
	List t = (List)malloc(sizeof(struct LNode));
	List head;
	t->Data =X;
	t->Next =NULL;
	while(head)
	{
		if(head->Next == P)
			{
				t->Next = head->Next;
				head->Next = t;
				return true;
			}
		head = head->Next;
	}
	 printf("Wrong Position for Insertion\n");
    return false;
}
bool Delete(List L,Position P)
{
	List pre;
	for(pre = L;pre&&pre->Next!=P;pre=pre->Next);
	if(pre && P)
		{
		pre->Next = P->Next;
		free(P);
		return true;
		}
	else 
	printf("Wrong Position for Deletion\n");
    return false;
}