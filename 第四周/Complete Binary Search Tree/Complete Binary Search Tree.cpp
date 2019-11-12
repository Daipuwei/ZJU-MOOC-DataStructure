#include <stdio.h>  
#include <stdlib.h>  
  
int compare(const void *a, const void *b);  
void Solve(int ALeft, int ARight, int TRoot, int A[], int T[]);  
int Get_Left_Nodes(int n);  
int Min(int a, int b);  
  
int main(int argc, char const *argv[])  
{  
    // freopen("test.txt", "r", stdin);  
    int N, tmp;  
    scanf("%d", &N);  
    int A[N], T[N];  
    for (int i = 0; i < N; ++i){  
        scanf("%d", &tmp);  
        A[i] = tmp;  
    }  
    qsort(A, N, sizeof(int), compare);  
    int ALeft = 0, ARight = N -1, TRoot = 0;  
    Solve(ALeft, ARight, TRoot, A, T);  
    for (int i = 0; i < N; ++i){  
        if(i == 0){  
            printf("%d", T[i]);  
        }  
        else  
            printf(" %d", T[i]);  
    }  
    return 0;  
}  
  
int compare(const void *a, const void *b)  
{  
    return *(int*)a - *(int*)b;  
}  
  
void Solve(int ALeft, int ARight, int TRoot, int A[], int T[])  
{  
    int n;  
    n = ARight - ALeft + 1; //结点数n  
    if(n == 0)  
        return;  
    int L, LeftTRoot, RightTRoot;  
    L = Get_Left_Nodes(n); //计算出n个结点的完全二叉树的左子树的结点个数  
    T[TRoot] = A[ALeft + L];  
    LeftTRoot = TRoot * 2 + 1;  
    RightTRoot = LeftTRoot + 1;  
    Solve(ALeft, ALeft + L - 1, LeftTRoot, A, T);  
    Solve(ALeft + L + 1, ARight, RightTRoot, A, T);//Aleft不要忘了+1   
}  
  
int Get_Left_Nodes(int n)  
{  
    int H = 0, tmp = 1, X, L;//X为左子树最下一层的结点数   
    int N = n;  
    while(N > 1){  
        N /= 2;  
        H++;//树的高度  
    }  
    for (int i = 0; i < H - 1; ++i){  
        tmp *= 2;  
    }  
    X = n - 2 * tmp + 1;  
    X = Min( X, tmp );  
    L = tmp - 1 + X;  
    return L;  
}  
  
int Min(int a, int b)  
{  
    return (a < b) ? a : b;  
}  
