#include <iostream>
#include <cstring> 
using namespace std;

const int MAX = 1000000;

class Graph{
	private:
		int V;
		int E;
		int** G;
	public:
		Graph(int v,int e){
			this->V = v;
			this->E = e;
			this->G = new int*[V];
			for ( int i = 0 ; i < V ; i++){
				this->G[i] = new int[V];
				for ( int j = 0 ; j < V ; j++){
					this->G[i][j] = MAX;
				}
			}
			
			for (int i = 0 ; i < e ; i++){
				int a ,b,c;
				cin>>a>>b>>c;
				this->G[a-1][b-1] = c;
				this->G[b-1][a-1] = c;
			}
		}
		
		void Floyd(){
			for (int k = 0 ; k < this->V ; k++){
				for ( int i = 0 ; i < this->V ; i++){
					for ( int j = 0 ; j < this->V ; j++){
						if ( this->G[i][k] + this->G[k][j] < this->G[i][j]){
							this->G[i][j] = this->G[i][k] + this->G[k][j];
						}
					}
				}
			}
		}
		
		int FindMaxDist(int i){
			int maxdist = -1;
			for (int j = 0 ; j < this->V ; j++){
				if( i != j && this->G[i][j] >= maxdist){
					maxdist = this->G[i][j];
				}
			}
			return maxdist;
		}
		
		void FindAnimal(){
			this->Floyd();
			int MinDist = MAX;
			int MaxDist = 0;
			int Animal;
			for ( int i = 0 ; i < this->V ; i++){
				MaxDist = this->FindMaxDist(i);
				if (MaxDist == MAX){
					cout<<"0"<<endl;
					return;
				}
				if (MaxDist < MinDist){
					MinDist = MaxDist;
					Animal = i+1;
				}
			}
			cout<<Animal<<" "<<MinDist<<endl; 
		}
};

int main()
{
	int v,e;
	cin>>v>>e;
	Graph graph(v,e);
	graph.FindAnimal();
	
	return 0;
}
