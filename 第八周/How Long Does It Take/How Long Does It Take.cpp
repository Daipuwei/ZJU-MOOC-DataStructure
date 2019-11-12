#include <iostream>
#include <cstring>
#include <vector>
#define INF 1 << 30 
#define N 1002
using namespace std;

struct Edge{
	int v1;
	int v2;
	int weight;
};

class Graph{
	private:
		int** G;
		int nv;							//结点个数 
		int* dist;						//距离数组 
		int* parent;					//父节点下标数组 
		vector<struct Edge> MST;		 
	public:
		Graph(int nv,int ne){
			this->nv = nv;
			this->G = new int*[nv];
			this->dist = new int[nv];
			this->parent = new int[nv];
			memset(this->parent,0,sizeof(int)*nv);
			for ( int i = 0 ; i < nv ; i++){
				this->G[i] = new int[nv];
				memset(this->G[i],0,sizeof(int)*nv);
				this->G[i][i] = 0;
			}
			
			for ( int i = 0 ; i < ne ; i++){
				int a,b,c;
				cin>>a>>b>>c;
				this->G[a][b] =c;
				this->G[b][a] =c;
			}
		}
		
		int FindMinDist(){
			int mindist = INF;
			int minindex = 0;
			for ( int i = 0 ; i < this->nv ; i++){
				if ( this->dist[i] != 0&&this->dist[i] < mindist){
					mindist = this->dist[i];
					minindex = i;
				}
			} 
			
			if ( mindist < INF){
				return minindex;
			}else{
				return -1;
			}
		}
		
		int Prime(){
			int cnt = 0;
			int total_sum = 0;
			this->dist[0] = 0;
			this->parent[0] = -1;
			struct Edge edge;
			
			for (int i = 0 ; i < this->nv ; i++){
				this->dist[i] = this->G[0][i];
				this->parent[i] = 0;
			}
			cnt++;
			this->parent[0] = -1; 
			
			while(1){
				int V = this->FindMinDist();
				if ( V == -1){
					break;
				}
				
				edge.v1 = this->parent[V];
				edge.v2 = V;
				edge.weight = this->dist[V];
				MST.push_back(edge);
				total_sum += this->dist[V];
				this->dist[V] = 0;
				cnt++;
				
				for ( int i = 0 ; i < this->nv ; i++){
					if ( this->G[V][i] < INF){
						if ( this->G[V][i] < this->dist[i]){
							this->dist[i] = this->G[V][i];
							this->parent[i] = V;
						}
					}
				} 
			}
			if ( cnt < this->nv){
				total_sum = -1;
			}
			return total_sum;
		}
		
		void Print(){
			for ( int i = 0 ; i < this->nv ; i++){
				for ( int j = 0 ; j < this->nv ; j++){
					cout<<this->G[i][j]<<" "; 
				}
				cout<<endl;
			}
		}
};

int main()
{
	int city_num,road_num;
	cin>>city_num>>road_num;
	
	Graph graph(city_num,road_num);
	//graph.Print();
	int sum = graph.Prime();
	cout<<sum;
	if ( sum != -1){
		cout<<sum;	
	}else{
		cout<<"Impossible";
	}
	
	return 0;
 }  
