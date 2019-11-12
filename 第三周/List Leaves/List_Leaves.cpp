#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node{
	int data;
	int left;
	int right;
};

//建树函数，返回根节点 
int BuildTree(vector<struct Node> &Tree,int N){
	int root = -1;
	char left,right;
	vector<int> check(N,0);
	
	for ( int i = 0 ; i < N ; i++){
		cin>>left>>right;
		Tree[i].data = i;
		//判断左子树是否为空，不为空则把ckeck数组相应位置1,否则置-1 
		if ( left != '-'){
			Tree[i].left = (int)(left-'0');
			check[Tree[i].left] = 1;
		}else{
			Tree[i].left = -1;
		}
		//判断右子树是否为空，不为空则把ckeck数组相应位置1,否则置-1 
		if ( right != '-'){
			Tree[i].right = (int)(right-'0');
			check[Tree[i].right] = 1;
		}else{
			Tree[i].right = -1;
		}
	}
	
	//寻找根节点的索引 
	for ( int i = 0 ; i < N ; i++){
		if ( check[i] == 0){
			root = i;
			break;
		}
	}
	return root;
} 

//寻找叶子节点函数
vector<int> Find_Leaves(vector<struct Node> &Tree,int root)
{
	vector<int> leaves;
	queue<struct Node> que;
	struct Node treenode;
	if ( root == -1){
		return {};
	}else{
		que.push(Tree[root]);
		while(!que.empty()){
			treenode = que.front();
			que.pop();
			if ( treenode.left == -1 && treenode.right == -1){
				leaves.push_back(treenode.data);
			}
			if ( treenode.left != -1){
				que.push(Tree[treenode.left]);
			}
			if ( treenode.right != -1){
				que.push(Tree[treenode.right]);
			}
		}
 	}
 	return leaves;
}

void Print(vector<int> & leaves)
{
	cout<<leaves[0];
	for ( int i = 1 ; i < leaves.size() ; i++){
		cout<<" "<<leaves[i];
	}
}

int main()
{
	int N;//树节点的个数 
	cin>>N;
	vector<struct Node> Tree(N); //存储树结点的数组 
	
	//完成建树过程，返回根节点索引
	int root = BuildTree(Tree,N);
	
	//寻找叶子结点数组 
	vector<int> leaves = Find_Leaves(Tree,root);
	
	//打印所有叶子结点 
	Print(leaves);
	
	return 0;
}
