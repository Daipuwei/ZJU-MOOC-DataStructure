#include <iostream>
#include <cstring>
#include <stack>
#define INF  100000
using namespace std; 

/* 题意要求： 保证最短距离，若距离相等 则选取总价格最低的路径
   1. dijkstra找最短路  一个新节点加入已找到最短路径的集合S后 更新其他所有点的权重时  需要增加一种情况  就是当距离不变时  更新价格为较小的
   那条路的价格 。
*/

class Graph{
	private:
		int V;
		int E;
		int** dis;						//城市之间的距离
		int** cost; 					//城市之间的路费 
		int* collected;					//判断该点是否已经求出最短路 
		int* dist;						//出发点s到图中每个城市的最短距离 
		int* cos;						//出发点s到图中每个城市的最短路费 
	public:
		//构造函数 
		Graph(int v,int e){
			this->V = v;
			this->E = e;
			this->dis = new int*[V];
			this->cost = new int*[V];
			this->collected = new int[V];
			this->dist = new int[V];
			this->cos = new int[V];
			for ( int i = 0 ; i < this->V ; i++){
				this->dis[i] = new int[this->V];
				this->cost[i] = new int[this->V];
				this->collected[i] = 0;
				for ( int j = 0 ; j < this->V ; j++){
					this->dis[i][j] = INF;
					this->cost[i][j] = INF;
				}
			}
			
			for ( int i = 0 ; i < this->E ; i++){
				int a,b,c,d;
				cin>>a>>b>>c>>d;
				this->dis[a][b] = this->dis[b][a] = c;
				this->cost[a][b] = this->cost[b][a] = d;
			}
		}
		
		//初始化最短距离和最短路费 
		void Init(int s){
			for ( int i = 0 ; i < this->V ; i++){
				dist[i] = this->dis[i][s];
				this->cos[i] = this->cost[i][s];
			}
		}
		
		//s为出发点，d为目的点，利用Dijkstra求最短距离和最少路费 
		void Dijkstra(int s){	
			int v;
			this->Init(s);
			//先将起点收入集合
			dist[s] = 0;			//初始状态 v节点属于集合 
			this->collected[s] = 1;
			for ( int k = 0 ; k < this->V ; k++){//开始主循环 每次求得v到某个顶点的最短路径 并加v到集合
				int MIN = INF;					//当前所知离v0最近的节点
				int v;
				for (int j = 0 ; j < V ; j++){
					if ( !this->collected[j] && this->dist[j] < MIN){
						MIN = dist[j];				//找到最短路径节点
						v = j;
					}
				}
				this->collected[v] = 1;
				for ( int i = 0 ; i < this->V ; i++){			//更新当前的最短路径
						if( !this->collected[i] && MIN + this->dis[v][i] < dist[i]){
							this->dist[i] = MIN + this->dis[v][i];
							this->cos[i] = this->cos[v] +this->cost[v][i]; 
						}else if(!this->collected[i] && MIN + this->dis[v][i] == dist[i]
							&& this->cos[i] > this->cos[v] + this->cost[v][i]){
								//路径长度相等则选择价格较便宜的一条
								this->cos[i] = this->cos[v] + this->cost[v][i];
						}
				}	
			}  
		}
		
		void Print(int d){ 
			cout<<this->dist[d]<<" "<<this->cos[d]<<endl; 
		}
};

int main()
{
	int v,e,s,d;
	cin>>v>>e>>s>>d;
	Graph graph(v,e);
	graph.Dijkstra(s);
	graph.Print(d);
	
	return 0;
}
