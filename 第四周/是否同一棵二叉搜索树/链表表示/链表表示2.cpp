#include <stdio.h>  
#include <stdlib.h>  
  
  
typedef struct TreeNode{  
    int data;  
    struct TreeNode* Left;  
    struct TreeNode* Right;  
    int flag;  
}TreeNode, *Tree;  
  
  
Tree MakeTree(int N);  
Tree NewTreeNode(int tmp);  
Tree Insert(Tree T, int tmp);  
  
  
int Judge(Tree T, int N);  
int check(Tree T, int tmp);  
void FreeTree(Tree T);  
void ResetT(Tree T);  
  
  
int main(int argc, char const *argv[])  
{  
    // freopen("test.txt", "r", stdin);  
    int N, L;  
    scanf("%d", &N);  
    Tree T;  
    while(N){  
        scanf("%d", &L);  
        T = MakeTree(N);  
        for (int i = 0; i < L; ++i){  
            if(Judge(T, N))//判断两棵数是否一样  
                printf("Yes\n");  
            else  
                printf("No\n");  
            ResetT(T);//重置T中标志flag为0  
        }  
        FreeTree(T);//释放分配的空间  
        scanf("%d", &N);  
    }  
    return 0;  
}  
  
  
Tree MakeTree(int N)  
{  
    Tree T;  
    int tmp;  
    scanf("%d", &tmp);  
    T = NewTreeNode(tmp);  
    for (int i = 1; i < N; ++i){  
        scanf("%d", &tmp);  
        T = Insert(T, tmp);  
    }  
    return T;  
}  
  
  
Tree NewTreeNode(int tmp)  
{  
    Tree T = (Tree)malloc(sizeof(TreeNode));  
    T->data = tmp;  
    T->flag = 0;  
    T->Left = T->Right = NULL;  
    return T;  
}  
  
  
Tree Insert(Tree T, int tmp)  
{  
    if(!T)  
        T = NewTreeNode(tmp);  
    else{  
        if(tmp > T->data)  
            T->Right = Insert(T->Right, tmp);  
        else  
            T->Left = Insert(T->Left, tmp);  
    }  
    return T;  
}  
  
  
int Judge(Tree T, int N)  
{  
    int tmp, flag = 0;  
    scanf("%d", &tmp);  
    if(tmp != T->data)  
        flag = 1;  
    else  
        T->flag = 1;  
    for (int i = 1; i < N; ++i){  
        scanf("%d", &tmp);  
        if((!flag) && (!check(T, tmp)))  
            flag = 1;  
    }  
    if(flag)  
        return 0;  
    else  
        return 1;  
}  
  
  
int check(Tree T, int tmp)  
{  
    if(T->flag){  
        if(tmp > T->data)  
            return check(T->Right, tmp);  
        else if(tmp < T->data)  
            return check(T->Left, tmp);  
        else  
            return 0;  
    }  
    else{  
        if(tmp == T->data){  
            T->flag = 1;  
            return 1;  
        }  
        else  
            return 0;  
    }  
}  
  
  
void FreeTree(Tree T)  
{  
    if(T->Left)  
        FreeTree(T->Left);  
    if(T->Right)  
        FreeTree(T->Right);  
    free(T);  
}  
  
  
void ResetT(Tree T)  
{  
    if(T->Left)  
        ResetT(T->Left);  
    if(T->Right)  
        ResetT(T->Right);  
    T->flag = 0;  
}  
