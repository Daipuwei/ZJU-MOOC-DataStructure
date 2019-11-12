#include <iostream>
using namespace std;

class MinHeap{
	private :
		int* data;
		int capacity;
		int size;
	public:
		MinHeap(int N){
			this->capacity = N;
			this->size = 0;
			this->data = new int[10000];
			this->data[0] = -10000;
		}
		
		int GetSize(){
			return this->size;
		} 
		
		bool IsFull(){
			return this->size == this->capacity;
		}
		
		bool IsEmpty(){
			return this->size == 0;
		}
		
		void Insert(int data){
			if ( this->IsFull()){
				return ;
			}
			int i = ++this->size;
			for ( ; this->data[i/2] > data ; i /= 2){
				this->data[i] = this->data[i/2];
			}
			this->data[i] = data;
		}
		
		void Find_Path(int index){
			if (index > this->size){
				return;
			}
			bool flag = false;
			for ( int i = index ; i >= 1 ; i /= 2){
				if (!flag){
					cout<<this->data[i];
					flag = true;
				}else{
					cout<<" "<<this->data[i];
				}
			}
		}
}; 

int main()
{
	int N,L;
	cin>>N>>L;
	MinHeap minheap(N);
	for ( int i  = 1 ; i <= N ; i++){
		int data;
		cin>>data;
		minheap.Insert(data);
	}
	
	for ( int i = 0 ; i < L ; i++){
		int index;
		cin>>index;
		minheap.Find_Path(index);
		cout<<"\n";	
	} 
	return 0;
}
