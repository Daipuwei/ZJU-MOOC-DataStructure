#include <stdio.h>
#include <stdlib.h>  
typedef int ElementType;  
typedef struct Node *PtrToNode;  
struct Node {  
    ElementType Data;  
    PtrToNode   Next;  
};  
typedef PtrToNode List;  
List Read();
void Print(List L);   
List Merge(List L1, List L2);  
int main()  
{  
    List L1, L2,L;  
    L1 = Read();  
    L2 = Read();  
    L = Merge(L1, L2);  
    Print(L);  
    Print(L1);  
    Print(L2);  
    return 0;  
}  
List Read()  
{  
    int n;  
    List L0;  
    L0 = (List)malloc(sizeof(struct Node));  
    L0->Next = NULL;  
    scanf("%d", &n);  
    if (n)  
    {  
        List r = L0;  
        List temp0;  
        for (int i = 0; i<n; i++) {  
            temp0 = (List)malloc(sizeof(struct Node));  
            scanf("%d", &(temp0->Data));  
            r->Next = temp0;  
            r = temp0;  
        }  
        r->Next = NULL;  
    }  
    return L0;  
}  
void Print(List L)  
{  
    if (L->Next)  
    {  
        List tempp;  
        tempp = L;  
        while (tempp->Next)  
        {  
            tempp = tempp->Next;  
            printf("%d ", tempp->Data);  
        }  
        printf("\n");  
    }  
    else  
    {  
        printf("NULL\n");  
    }  
}  
List Merge(List L1, List L2)  
{  
    List p1 = L1->Next, p2 = L2->Next, r;  
    List L3;  
    L3= (List)malloc(sizeof(struct Node));  
    r = L3;  
    while (p1 != NULL&&p2 != NULL)  
    {  
        if (p1->Data<p2->Data)  
        {  
            r->Next = p1;  
            r = p1;  
            p1 = p1->Next;  
        }else {  
            r->Next = p2;  
            r = p2;  
            p2 = p2->Next;  
        }  
    }  
    if (p1 != NULL)  
        r->Next = p1;  
    if (p2 != NULL)  
        r->Next = p2;  
    L1->Next = NULL;  
    L2->Next = NULL;  
    return L3;  
}
