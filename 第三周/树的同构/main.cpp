#include <iostream>
using namespace std;

class Tree{
	private:
		char ch;
		int left;
		int right;
		int check_flag;
	public:
		int BuildTree(Tree* tree,int n){
			char cl;
			char cr;
			for ( int i = 0 ; i < n ; i++ ){
				tree[i].check_flag = 0;
			}
			for ( int i = 0 ; i < n ; i++ ){
				cin>>tree[i].ch>>cl>>cr;
				if ( cl != '-'){
					tree[i].left = cl -'0';
					tree[tree[i].left].check_flag= 1;
				}
				else{
					tree[i].left= -1;
				} 
				if ( cr != '-'){
					tree[i].right = cr - '0';
					tree[tree[i].right].check_flag = 1;
				} 
				else{
					tree[i].right = -1;
				}
			}
			int i ;
			for ( i = 0 ; i < n ; i++ ){
				if( tree[i].check_flag == 0)
					break; 
				}
			return i;
		}
		
		int Judge(int R1, int R2 ,Tree* T1,Tree* T2)  
		{  
		    //两树都为空   
		    if(R1 == -1 && R2 == -1)  
		        return 1;  
		    //空树和非空树      
		    if((R1 == -1 && R2 != -1) || (R1 != -1 && R2 == -1))  
		        return 0;  
		    //两树的根节点不一样   
		    if(T1[R1].ch != T2[R2].ch)  
		        return 0;  
		    //若两树的左子树都空，判断右子树是否一样    
		    if(T1[R1].left == -1 && T2[R2].left == -1)  
		        return Judge(T1[R1].right, T2[R2].right,T1,T2);  
		    //若两树的左子树不空，并且左子树的结点元素都一样，判断左右子树是否一样      
		    if(((T1[R1].left != -1)&& (T2[R2].left != -1))&& ((T1[T1[R1].left].ch )== (T2[T2[R2].left].ch)) ) 
		        return Judge(T1[R1].left, T2[R2].left,T1,T2) && Judge(T1[R1].right, T2[R2].right,T1,T2);  
		    else  
		    //否则 判断两树是否同构   
		        return Judge(T1[R1].left, T2[R2].right,T1,T2) && Judge(T1[R1].right, T2[R2].left,T1,T2);                  
		}  
};

int main()
{
	int n;
	cin>>n;
	Tree tree;
	
	Tree* tree1;
	tree1 = new Tree[n];
	int root1;
	root1 = tree.BuildTree(tree1,n);
	
	cin>>n;
	Tree* tree2;
	tree2 = new Tree[n];
	int root2;
	root2 = tree.BuildTree(tree2,n);
	
	if(tree.Judge(root1, root2,tree1,tree2))  
        printf("Yes");  
    else  
        printf("No");  
	
	return 0;
 } 
