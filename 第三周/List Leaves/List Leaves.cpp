#include<iostream>
using namespace std;
#define  MaxNum 10//数组的最大容量
#define ElementType int
#define Tree int
#define NUll -1//表示该节点为空
struct TreeNode{//树节点的表示
    ElementType index;//记录该节点的下标
    Tree left;//左子树
    Tree right;//右子树
}; 
int Num;//记录数组的实际大小
TreeNode T1[MaxNum];//用来记录输入的树
TreeNode T2[MaxNum];//重新排好的树
Tree BuildTree(struct TreeNode T[], int Num){
    char a;
    int i;
    int  check[MaxNum];//check数组的作用是辅助检测出根节点
    for (i = 0; i < Num; i++){ check[i] = 0; }
    for (i = 0; i < Num; i++){
        T[i].index=i;
        cin >> a;//输入左子树
        if (a != '-'){//对输入的数据进行判断
            T[i].left = a - '0';
            check[T[i].left] = 1;
        }//判断输入的类型是否是'-'，如果是的话就赋值为-1,否则转化得到的数赋给T[i]的左子树，并且在check上记录
        else { T[i].left = NUll; }
        cin >> a;//输入右子树
        if (a != '-'){
            T[i].right = a - '0';
            check[T[i].right] = 1;
        }
        else { T[i].right = NUll; }
    }
    for (i = 0; i < Num; i++){//找到根节点
        if (!check[i])
            return i;
}
int FindPos(int i){//找到插入的适合下标，并返回该下标
    for (int j = i; j < Num; j++){//从i开始查找，一直找到一个为空的项
        if (T2[j].index == NUll)
            return j;
    }
}
int Insert(int root){
    int count = 1;//记录叶子的个数
    int left, right;//记录左孩子的下标，记录右孩子的下标
    int pos;//记录要插入位置的下标
    for (int i = 0; i < MaxNum; i++){//初始化T2
        T2[i].index = T2[i].left = T2[i].right = NUll;
    }
    T2[0] = T1[root];//插入根节点
    for (int i = 1; i < Num; i++){
        left = T2[i - 1].left;
        right = T2[i - 1].right;
        if (left == NUll&&right == NUll){ count += 1; }
        if (left != NUll){//存在左孩子
            pos = FindPos(i);
            T2[pos] = T1[left];
        }
        if (right != NUll){//存在右孩子
            pos = FindPos(i);
            T2[pos] = T1[right];
        }
    }
    return count;//返回叶子的数目
}
void output(int count){//输出叶子
    int i;
    for (i = 0; count!=1; i++){
        if (T2[i].left == NUll&&T2[i].right == NUll){
            cout << T2[i].index << " ";
            count--;
        }
    }
    for (; i < Num; i++){//为了符合题目的输出要求
        if (T2[i].left == NUll&&T2[i].right == NUll)
            cout << T2[i].index;
    }
}
int main(){
    int r1;
    int count;
    cin >> Num;
    r1=BuildTree(T1, Num);
    count=Insert(r1);
    output(count);
}
