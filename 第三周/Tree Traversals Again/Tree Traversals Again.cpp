#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>  
  
#define MAXSIZE 30  
  
typedef struct node{  
    int top;  
    int cap;  
    int data[MAXSIZE];  
} Stack;  
  
int preOrder[MAXSIZE];  
int inOrder[MAXSIZE];  
int postOrder[MAXSIZE];  
  
Stack* CreateStack();  
void Push(Stack *PtrS, int e);  
void Pop(Stack *PtrS);  
int Top(Stack *PtrS);  
void Solve(int prel, int inl, int postl, int n);  
  
int main(int argc, char const *argv[])  
{  
    for (int i = 0; i < MAXSIZE; ++i){  
        preOrder[i] = 0;  
        inOrder[i] = 0;  
        postOrder[i] = 0;  
    }  
    // freopen("test.txt", "r", stdin);  
    int NodeNum, data;  
    scanf("%d", &NodeNum);  
    int perIndex = 0, inIndex = 0, postIndex = 0;  
    Stack *PS = CreateStack();  
    Push(PS, 0);  
    char str[20];  
    for (int i = 0; i < 2 * NodeNum; ++i){  
        scanf("%s", str);  
        if(strcmp(str, "Push") == 0){  
            scanf("%d", &data);  
            preOrder[perIndex++] = data;  
            Push(PS, data);  
        }  
        else if(strcmp(str, "Pop") == 0){  
            inOrder[inIndex++] = Top(PS);  
            Pop(PS);  
        }  
    }  
    Solve(0, 0, 0, NodeNum);  
    for (int i = 0; i < NodeNum; ++i){  
        if(i == NodeNum - 1)  
            printf("%d", postOrder[i]);  
        else  
            printf("%d ", postOrder[i]);  
    }  
    return 0;  
}  
  
Stack* CreateStack()  
{  
    Stack *PtrS = (Stack*)malloc(sizeof(Stack));  
    PtrS->cap = MAXSIZE;  
    PtrS->top = -1;  
    return PtrS;  
}  
  
void Push(Stack *PtrS, int e)  
{  
    if(PtrS->top == PtrS->cap - 1)  
        return;  
    PtrS->top++;  
    PtrS->data[PtrS->top] = e;  
}  
  
int Top(Stack *PtrS)  
{  
    if(PtrS->top != -1)  
        return PtrS->data[PtrS->top];  
}  
  
void Pop(Stack *PtrS)  
{  
    if(PtrS->top == -1)  
        return;  
    PtrS->top--;  
}  
  
void Solve(int prel, int inl, int postl, int n)  
{  
    if(n == 0)  
        return;  
    if(n == 1){  
        postOrder[postl + n -1] = preOrder[prel];  
        return;  
    }  
    int L, R, root;  
    root = preOrder[prel];  
    postOrder[postl + n -1] = root;  
    for (int i = 0; i < n; ++i){  
        if(inOrder[inl + i] == root){  
            L = i;//左子树结点个数  
            R = n - i -1;//右子树结点个数  
            break;  
        }  
    }  
    Solve(prel+1, inl, postl, L);  
    Solve(prel+L+1, inl+L+1, postl+L, R);  
}  
