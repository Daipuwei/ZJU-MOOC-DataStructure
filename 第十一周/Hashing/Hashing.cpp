#include <iostream>
#include <cstring>
using namespace std;

class HashTable{
	private:
		int* num;
		int len;
	public:
		HashTable(int len){
			this->len = this->Get_MaxPrime(len);
			num = new int[this->len];
			//cout<<"长度为"<<this->len<<endl; 
			memset(num,0,sizeof(int)*this->len);
		}
		
		bool IsPrime(int n){
			bool flag = true;
			if ( n <= 1){
				flag = false;
			}else if (n == 2){
				flag = true;
			}else{
				for ( int i = 2 ; i < n ; i++){
					if ( n % i == 0){
						flag = false;
						break;
					}
				}
			}
			return flag;
		}
		
		int Get_MaxPrime(int n){
			if ( n == 1 || n == 2){
				return 2;
			}else{
				for ( int i = n ; ; i++){
					if ( i % 2 == 0){
						continue;
					}else{
						if (this->IsPrime(i)){
							return i;					
						}		
					}
				}	
			}
		} 
		
		void Insert(int n){
			int index = n % this->len;
			if (!this->num[index]){
				num[index] = n;
				//cout<<n<<"所在的位置为："<<index<<endl; 
			}else{
				int next = -1;
				for ( int i = 1 ; i <= this->len/2 ; i++){
					next = (index + i * i) % this->len;
					if (!this->num[next]){
						this->num[next] = n;
						break;
					}
				}
				//cout<<n<<"所在的位置为："<<next<<endl; 
			}
		}
		
		int Find(int n){
			int result_index = -1;
			for ( int i = 0 ; i < this->len ; i++){
				if (this->num[i] == n){
					result_index = i;
					break;
				}
			}
			return result_index;
		}
};

int main()
{
	int Max,N;
	int* buf;
	cin>>Max>>N;
	buf = new int[N];
	HashTable hashtable(Max);
	for ( int i = 0 ; i < N ; i++){
		cin>>buf[i];
		hashtable.Insert(buf[i]);
	}
	
	for (int i = 0 ; i < N ; i++){
		buf[i] = hashtable.Find(buf[i]);
	}
	
	if(buf[0] == -1){
		cout<<"-";
	}else{
		cout<<buf[0];
	}
	for(int i = 1 ; i < N ; i++){
		cout<<" ";
		if(buf[i] == -1){
			cout<<"-";
		}else{
			cout<<buf[i];
		}
	}
	
	return 0;
}
