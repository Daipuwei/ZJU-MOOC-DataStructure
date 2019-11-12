#include <iostream>
#include <stdio.h>
#include <queue> 
using namespace std;

class Graph {
	private:
		int Nv;				//顶点数
		int Ne;				//边数
		int** G;			//邻接矩阵
		int* isVisited;		//访问数组
	public:
		//构造函数
		Graph(int nv,int ne) {
			this->Nv = nv;
			this->Ne = ne;
			this->isVisited = new int[nv];
			this->G = new int*[nv];
			for ( int i = 0 ; i < nv ; i++) {
				this->G[i] = new int[nv];
				this->isVisited[i] = 0;
			}
			for ( int i = 0 ; i  < nv ; i++){
				for ( int j = 0 ; j < nv ; j++){
					this->G[i][j] = 0;
					this->G[i][i] = 1; 
				}
			}
			
			for ( int i = 0 ; i < this->Ne ; i++){
				int a,b;
				cin>>a>>b;
				this->G[a-1][b-1] = 1;
				this->G[b-1][a-1] = 1;
			}
		}

		int BFS(int start) {
			queue<int> que;
			int cnt = 1;
			int level = 0;
			int last = start;
			int tail;
			this->isVisited[start] = 1;
			que.push(start);
			while(!que.empty()) {
				int neiborgh = que.front();
				que.pop();
				for ( int i = 0 ; i < this->Nv ; i++) {
					if ( this->G[neiborgh][i] && !this->isVisited[i]) {
						que.push(i);
						this->isVisited[i] = 1;
						cnt++;	
						tail = i;
					}
				}
				if (neiborgh == last){
					level++;
					last = tail;
				}
				if ( level == 6){
					break;
				}
			}
			return cnt;
		}
		
	void SVD(){
		for ( int i = 0 ; i < this->Nv ; i++ ){
			MemSet_Visited();
			int cnt = BFS(i);
			double percent = cnt * 1.0 / this->Nv;
			printf("%d: %.2f%%\n",i+1,percent*100);
		}
	}
	
	void MemSet_Visited(){
		for(int i = 0 ; i < this->Nv ; i++){
			this->isVisited[i] = 0;
		} 
	} 
};

int main()
{
	int nv,ne;
	cin>>nv>>ne;
	Graph graph(nv,ne);	
	graph.SVD();
	
	return 0;
 } 
