#include <iostream>
using namespace std;

class Set{
	public:
		int* s;
		int maxsize;
	public:
		Set(int n){
			this->maxsize = n+1;
			this->s = new int[this->maxsize];
			for (int i = 0 ; i < this->maxsize ; i++ ){
				this->s[i] = i;
			} 
		}
		
		int Find(int x){
			if ( this->s[x] == x){
				return x;
			}
			return this->s[x] = Find(this->s[x]);
		}
		
		void Union(int x1,int x2){
			int root1 = this->Find(x1);
			int root2 = this->Find(x2);
			if ( root1 != root2 ){
				if ( this->s[root1] < this->s[root2]){
					s[root2] = root1;
				}
				else
					s[root1] = root2;
			}
		}
		
		int GetRoot(){
			int count = 0;
			for ( int i = 1; i < this->maxsize ; i++ ){
			if ( this->Find(i) == i){
					count++;
				}
			}
			return count;
		}
};

int  main()
{
	int n;
	cin>>n;
	Set set(n);
	int c1,c2;
	char choose;
	while(1){
		cin>>choose;
		if ( choose == 'S'){
				break;
		}
		cin>>c1>>c2;
		if ( choose == 'I')
			set.Union(c1,c2);
		if ( choose == 'C'){
			if ( set.Find(c1) == set.Find(c2)){
					cout<<"Yes"<<endl; 
			}
			else{
					cout<<"NO"<<endl;
				}
			}
	}
	int count = set.GetRoot();
	if ( count == 1){
		cout<<"The network is connected."<<endl;
	} 
	else{
		cout<<"There are "<<count<<" components."<<endl;
	}
	
	return 0;
}
