#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <cstdio>
using namespace std;

const double R = 7.5; 

struct point{
	int x;
	int y;
};

class Graph{
	private:
		int V;
		int Max_Distance;
		vector<struct point> points;
		int* path;
	public:
		//¹¹Ôìº¯Êý 
		Graph(int v,int max_distance){
			this->V = v;
			this->Max_Distance = max_distance;
			this->path = new int[V];
			struct point p;
			p.x = 0;
			p.y = 0;
			this->points[0] = p;
			this->path[0] = -1;
			for( int i = 1 ; i <= this->V ; i++){
				cin>>p.x>>p.y;
				this->points[i] = p;	
				this->path[i] = -1; 
			}
		}
		
		int cmp(int i , int j){
			int p1 = pow(this->points[i].x,2) + pow(this->points[i].y,2);
			int p2 = pow(this->points[j].x,2) + pow(this->points[j].y,2);
			return p1-p2;
		}
		
		int bfs(int &v){
			vector<int> dist(this->V+1,-1);
			vector<int> first(this->V+1);
			int flag = 0;
			int firstjump;
			queue<int> q;
			dist[v] = 0;
			for ( int i = 0 ; i < this->V+1 ; i++){
				first[i] = i;
			}
			sort(first.begin(),first.end(),cmp);
			for ( int i = 1 ; i < this->V + 1; i++){
				v = first[i];
				firstjump = sqrt(pow(this->points[v].x,2)+pow(this->points[v].y,2));
				if ( firstjump > R && firstjump <= this->Max_Distance + R){
					q.push(v);
					dist[v] = 1;
					path[v] = 0;
				}
			}
			
			while(!q.empty()){
				v = q.front();
				q.pop();
				if ( fabs(this->points[v].x) + this->Max_Distance >= 50 || fabs(this->points[v].y + this->Max_Distance)>=50){
					flag = 1;
					break;
				}else{
					for ( int i = 1 ; i < this->V + 1 ; i++){
						int distX = pow(this->points[v].x-this->points[i].x,2);
						int distY = pow(this->points[v].y-this->points[i].y,2);
						int dis = sqrt(distX+distY);
						if ( dist[i] == -1 && dis <= this->Max_Distance){
							dist[i] = dist[v]+1;
							path[i] = v;
							q.push(i);
						}
					}
				}
			}
			return flag;
		}
		
		void Solve(){
			int flag;
			vector<int> spath;
			int v = 0;
			if ( this->Max_Distance + R > 50.0){
				flag = 1;
			}else{
				flag = bfs(v);
			}
			
			if ( !flag){
				cout<<"0";
			}else{
				while(v){
					spath.push_back(v);
					v = this->path[v];
				}
				cout<<spath.size()+1<<endl;
				for ( int i = spath.size()-1 ; i >= 0 ; i--){
					printf("%.0f %.0f\n",this->points[i].x,this->points[i].y);		
				}
			}
		}
};

int main()
{
	int num,max_distance;
	cin>>num>>max_distance;
	Graph graph(num,max_distance);
	graph.Solve();
	
	return 0;
}
