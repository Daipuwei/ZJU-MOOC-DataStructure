#include <iostream>
using namespace std;

const int MAXSIZE = 1001;
const int MIN = -100001;

class MinHeap{
	private:
		int Data[MAXSIZE];
		int size;
	public:
		void Set(){
			size = 0;
			Data[0] = MIN; 
		}
		
		void Insert(int x){
			int i = ++this->size;
			for ( ; this->Data[i/2] > x ; i /= 2){
				this->Data[i] = this->Data[i/2];
			}
			this->Data[i] = x;
		}
		
		int GetData(int i){
			return this->Data[i];
		} 
};

int main()
{
	int n;
	int m;
	cin>>n>>m;
	MinHeap minheap;
	minheap.Set();
	
	for ( int i = 0 ; i < n ; i++){
		int x;
		cin>>x;
		minheap.Insert(x);
	}
	
	for ( int i = 0 ; i < m ; i ++ ){
		int j ;
		cin>>j;
		cout<<minheap.GetData(j);
		while ( j > 1){
			j /= 2;
			cout<<" "<<minheap.GetData(j);
		}
		cout<<endl;
	} 
	
	return 0;
 } 
