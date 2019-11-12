#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int pos = 0;
int root = 1;
int N;
vector<int> CBT;
vector<int> AVL;

void Build_CBT(int root)
{
	if ( root > N){
		return;
	}else{
		int left = 2 * root;
		int right = 2 * root + 1;
		Build_CBT(left);
		CBT[root] = AVL[pos++];
		Build_CBT(right);
	}
}

int main()
{
	cin>>N;
	AVL = vector<int>(N,0);
	CBT = vector<int>(N+1,0);
	
	for ( int i = 0 ; i < N ; i++){
		cin>>AVL[i];
	}
	sort(AVL.begin(),AVL.end());
	
	Build_CBT(root);
	
	cout<<CBT[1];
	for ( int i = 2 ; i < CBT.size() ; i++){
		cout<<" "<<CBT[i];
	}
	
	
	return 0;
 } 
