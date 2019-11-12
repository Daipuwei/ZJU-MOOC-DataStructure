#include <iostream>
#include <algorithm>
#include <stdlib.h>
using namespace std;

typedef struct AVLNode* AVLTree ;

struct AVLNode{
	int val;
	AVLTree left;
	AVLTree right;
	int height; 
}; 

//求数的深度的函数 
int getHeight(AVLTree t) 
{  
    if (t)  
        return max(getHeight(t->left) , getHeight(t->right)) + 1;  
    else  
        return 0;  
}  

//左旋 
AVLTree SingleLeftRotation(AVLTree a) 
{   
    AVLTree b = a->left;  
    a->left = b->right;  
    b->right = a;  
    a->height = max(getHeight(a->left),getHeight(a->right))+1;  
    b->height = max(getHeight(b->left), a->height)+1;  
    return b;  
}  

//右旋 
AVLTree SingleRightRotation(AVLTree t) 
{  
    AVLTree b = t->right;  
    t->right = b->left;  
    b->left = t;  
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;  
    b->height = max(getHeight(b->right),t->height) + 1;  
    return b;  
}  

//左右旋 
AVLTree DoubleLeftRightRotation(AVLTree t) 
{  
    t->left = SingleRightRotation(t->left);  
    return SingleLeftRotation(t);  
}  

//右左旋 
AVLTree DoubleRightLeftRotation(AVLTree t) 
{  
    t->right = SingleLeftRotation(t->right);  
    return SingleRightRotation(t);  
}  

//插入函数 
AVLTree AVL_Insertion(int x, AVLTree t)
{
	/* 插入X到AVL中 并返回调整后的AVL树 */  
    if (!t) {  
        t = (AVLTree)malloc(sizeof(struct AVLNode));  
        t->val = x;  
        t->height = 0;  
        t->left = t->right = NULL;  
    }  
    else if (x < t->val) {  
        t->left = AVL_Insertion(x, t->left);  
        if (getHeight(t->left) - getHeight(t->right) == 2) {  
            /*需要左旋*/  
            if (x < t->left->val) {  
                t = SingleLeftRotation(t);/* 左单旋 */  
            }  
            else {  
                t = DoubleLeftRightRotation(t); /* 左右双旋 */  
            }  
        }  
    }  
    else if ( x> t->val) {  
        t->right = AVL_Insertion(x, t->right);  
        if (getHeight(t->right) - getHeight(t->left) == 2) {  
            /*需要左旋*/  
            if (x > t->right->val) {  
                t = SingleRightRotation(t);/* 左单旋 */  
            }  
            else {  
                t = DoubleRightLeftRotation(t); /* 右左双旋 */  
            }  
        }  
    }  
    t->height = max(getHeight(t->left), getHeight(t->right)) + 1;  
    return t;  
 } 

//递归先序遍历 
void preOrder(AVLTree avl) 
{  
    if (avl) {  
        cout << avl->val << " ";  
        preOrder(avl->left);  
        preOrder(avl->right);  
     }  
}  

int main()
{
	int N;
	cin>>N;
	AVLTree avl = NULL;
	for ( int i = 0 ; i < N ; i++){
		int t;
		cin>>t;
		avl = AVL_Insertion(t,avl);
	}
	
	cout<<avl->val; 
	return 0;
 } 
