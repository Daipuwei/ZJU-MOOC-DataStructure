#include <iostream>
using namespace std;

class AVL{
	private:
		int data;
		AVL* left;
		AVL* right;
		int flag;
	public:
		AVL* MakeTree(int N){
			AVL* T;
			int data;
			cin>>data;
			T = this->NewCode(data);
			for ( int i = 1 ; i < N ; i++){
				cin>>data;
				T = this->Insert(T,data);
			}
			return T;
		}
		
		AVL* NewCode(int data){
			AVL* T;
			T = new AVL();
			T->data = data;
			T->left = T->right = NULL;
			T->flag = 0;
			return T; 
		}
		
		AVL* Insert(AVL* T , int data){
			if ( !T ){
				T = this->NewCode(data);
			}
			else{
				if (T->data <data){
					T->right = this->Insert(T,data);
				}
				else
					T->left = this->Insert(T,data); 
				}
			return T;
		}
		
		int check (AVL* T,int data){
			 if(T->flag){  
		        if(data > T->data)  
		            return check(T->right, data);  
		        else if(data < T->data)  
		            return check(T->left, data);  
		        else  
		            return 0;  
		    }  
		    else{  
		        if(data== T->data){  
		            T->flag = 1;  
		            return 1;  
		        }  
		        else  
		            return 0;  
		    }  
		}
		
		int Judge( AVL* T ,int N){
			int data;
			int flag = 0;
			cin>>data;
			if ( data != T->data){
				flag = 1;
			}
			else{
				T->flag = 1;
			}
			for ( int i =0 ; i < N ; i++ ){
				cin>>data;
				if((!flag)&&(!this->check(T,data))){
					flag = 1;
				}
			if ( flag )
				return 1;
			else
				return 0;
			}
		}
		
		void Reset(AVL* T){
			if ( T->left ){
				this->Reset(T->left);
			}
			if ( T->right){
				this->Reset(T->right);
			}
			flag = 0;
		}
			
		void FreeAVL(AVL* T){
			if ( T->left ){
				this->FreeAVL(T->left);
			}
			if ( T->right){
				this->FreeAVL(T->right);
			}
			delete T;
		}
};

int main()
{
	int N;
	int L;
	cin>>N;
	AVL tree;
	AVL* T;
	while(N){
		cin>>L;
		T = tree.MakeTree(N);
		for ( int i =0 ; i < L ; i++){
			if ( tree.Judge(T,N)){
				cout<<"Yes"<<endl;
			}
			else{
				cout<<"No"<<endl; 
			}
			tree.Reset(T);
		}
		tree.FreeAVL(T);
		cin>>N;
	}
	
	return 0;
 } 
