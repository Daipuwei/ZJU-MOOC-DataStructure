#include <iostream>
#include <cstring>
#include <queue>
using namespace std;

class Graph {
	private:
		int Nv;				//顶点数
		int Ne;				//边数
		int** G;			//邻接矩阵
		int* isVisited;	//访问数组
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
				this->G[a][b] = 1;
				this->G[b][a] = 1;
			}
		}

		//深度优先遍历
		void DFS(int start) {
			cout<<" "<<start;
			this->isVisited[start] = 1;
			for ( int i = 0 ; i < this->Nv ; i++) {
				if ( this->G[start][i] && !this->isVisited[i]) {
						DFS(i);
				}
			}
		}

		void BFS(int start) {
			queue<int> que;
			this->isVisited[start] = 1;
			que.push(start);
			while(!que.empty()) {
				int neiborgh = que.front();
				cout<<" "<<neiborgh;
				que.pop();
				for ( int i = 0 ; i < this->Nv ; i++) {
					if ( this->G[neiborgh][i] && !this->isVisited[i]) {
							que.push(i);
							this->isVisited[i] = 1;
					}
				}
			}
		}

		//列出DFS连通集
		void ListCompentDFS() {
			for ( int i = 0 ; i < this->Nv ; i++){
				if ( this->isVisited[i] == 0){
					cout<<"{";
					DFS(i);
					cout<<" }"<<endl;
				} 
			} 
		}
		
		//列出BFS连通集
		void ListCompentBFS() {
			queue<int> que;
			for ( int i = 0 ; i < this->Nv ; i++){
				if (this->isVisited[i] == 0){
					cout<<"{";
					BFS(i);
					cout<<" }"<<endl;
				}
			}	
		}

		void Memset_Visited() {
			for ( int i = 0 ; i < this->Nv ; i++){
				this->isVisited[i] = 0;
			}
		}
};

int main() {
	int nv,ne;
	cin>>nv>>ne;
	Graph graph(nv,ne);
	
	graph.ListCompentDFS();
	graph.Memset_Visited();
	graph.ListCompentBFS();

	return 0;
}

