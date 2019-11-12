#include <iostream>
using namespace std;

class AVL{
	private:
		int data;
		AVL* left;
		AVL* right;
		int height;
	public:
		int max(int a,int b){
			return a > b ? a:b; 
		} 
		
		AVL* SingleLeftRotation ( AVL *A ){
			AVL* B = NULL;
			B = A->left;
			A->left = B->right;
			B->right = A;
			A->height = this->max(this->GetHeight(A->left),this->GetHeight(A->right));
			B->height = this->max(this->GetHeight(B->left),this->GetHeight(B->right));
			
			return B;
		}
		
		AVL* SingleRightRotation ( AVL* A ){
			AVL* B = NULL;
			B = A->right;
			A->right = B->left;
			B->left = A;
			A->height = this->max(this->GetHeight(A->left),this->GetHeight(A->right));
			B->height = this->max(this->GetHeight(B->left),this->GetHeight(B->right));
			return B;
		}
		
		AVL* DoubleRightLeftRotation ( AVL* A )  
		{  
		    A->right = SingleLeftRotation(A->right);  
		    return SingleRightRotation(A);  
		}  
		
		AVL* DoubleLeftRightRotation ( AVL* A )  
		{  
		    A->left = SingleRightRotation(A->left);  
		    return SingleLeftRotation(A);  
		}  
		
		int GetHeight(AVL* A){
			if ( !A){
				return 0;
			}
			else{
				return A->height;
			}
		} 
		
		AVL* Insert(AVL* T,int x){
			if ( T ==NULL ){
				T = new AVL();
				T->data = x;
				T->height = 0;
				T->left = T->right = NULL; 
			}
			else if ( x < T->data ) {  
	        T->left = Insert( T->left, x);  
		        if ( GetHeight(T->left)-GetHeight(T->right) == 2 )  
		            if ( x < T->left->data )   
		               T = SingleLeftRotation(T);      
		            else   
		               T = DoubleLeftRightRotation(T); 
	    	}   
       
    		else if ( x > T->data ) {   
		        T->right = Insert( T->right, x );  
		        if ( GetHeight(T->left)-GetHeight(T->right) == -2 )  
		            if ( x > T->right->data )   
		               T = SingleRightRotation(T);     
		            else   
		               T = DoubleRightLeftRotation(T); 
		    } 
   			 T->height = max( GetHeight(T->left), GetHeight(T->right) ) + 1;  
		} 
		
		int GetData(AVL* tree){
			return tree->data;
		}
}; 

int main()
{
	int n;
	cin>>n;
	AVL* tree = NULL;
	AVL tmp;
	int data;
	for ( int i = 0 ; i < n ; i++ ){
		cin>>data;
		tree = tmp.Insert(tree,data);
	} 
	cout<<tmp.GetData(tree);
	
	return 0;
}
