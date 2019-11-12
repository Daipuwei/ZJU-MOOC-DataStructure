#include <iostream>
using namespace std;

const int MAXSIZE = 64;
const int MIN = -10;

typedef struct TreeNode HuffmanTree;

struct TreeNode{
	int weight;
	HuffmanTree* Left ;
	HuffmanTree* Right;
};

struct JNode{
	int flag = 0;
	struct JNode* Left ;
	struct JNode* Right ;
};

class MinHeap{
	private:
		HuffmanTree Data[MAXSIZE];
		int size;
	public:
		MinHeap(){
			size = 0;
			Data[size].weight = MIN;
		}
		
		void Insert(HuffmanTree *x){
			int i = ++this->size;
			for ( ; this->Data[i/2].weight > x->weight ; i /= 2 ){
				Data[i].weight = this->Data[i/2].weight;
			} 
			this->Data[i] = *x;
		}
		
		HuffmanTree* DeletMin(){
			int parent = 0;
			int child = 0;
			
			HuffmanTree* Min = new HuffmanTree;
			*Min = this->Data[1];
			HuffmanTree tmp;
			tmp = this->Data[this->size--];
			
			for ( parent = 1 ; parent * 2 < this->size ; parent = child ){
				child = parent * 2;
				if ( (child != this->size) && (this->Data[child].weight > this->Data[child+1].weight)){
					child++;  
				}
				if ( tmp.weight <= this->Data[child].weight){
					this->Data[parent] = this->Data[child];
				}
				else{
					break;
				} 
			}
			this->Data[parent] = tmp;			
			return Min;
		}
		
		void Set(int* A,int N){
			int value;
			char s;
			for ( int i = 0 ; i < N ; i++){
				cin>>s>>value;
				A[i] = value;
				HuffmanTree* tmp = new HuffmanTree;
				tmp->weight = value;
				this->Insert(tmp);
			}
		}
		
		HuffmanTree* Huffman(){
			int num = this->size;
			HuffmanTree* T = new HuffmanTree;
			for ( int i = 0 ; i < num - 1 ; i++ ){
				T->Left = this->DeletMin();
				T->Right = this->DeletMin();
				T->weight = T->Left->weight + T->Right->weight;
				this->Insert(T);
			}
			T = this->DeletMin();
			return T;
		}
};

int WPL(HuffmanTree* T ,int Depth)
{
			if ( T->Left == NULL && T->Right == NULL){
				return Depth*T->weight;
			}
			else{
				return (WPL(T->Left,Depth+1)+WPL(T->Right,Depth+1));
			}
}

bool Judge(string S,JNode *J)//判断该次编码能否符合前缀编码的要求  
{  
    int i=0;  
    for (; i<S.length(); ++i)  
    {  
        if (S[i]=='0')  
        {  
            if (J->Left==NULL)  
            {  
                JNode *J_1=new(JNode);  
                J->Left=J_1;  
            }else  
            {  
                if (J->Left->flag==1)  
                {  
                    return false;  
                }  
            }  
            J=J->Left;  
        }else  
        {  
            if (J->Right==NULL)  
            {  
                JNode *J_1=new(JNode);  
                J->Right=J_1;  
            }else  
            {  
                if (J->Right->flag==1)  
                {  
                    return false;  
                }  
            }  
            J=J->Right;  
        }  
    }  
    J->flag=1;  
    if (J->Left==NULL&&J->Right==NULL)  
    {  
        return true;  
    }else  
    {  
        return false;  
    }  
}  

int main()
{
	int N;
	cin>>N;
	MinHeap minheap;
	int Value[MAXSIZE];
	minheap.Set(Value,N); 
	HuffmanTree* T = minheap.Huffman();
	int wpl = WPL(T,0);
	
	int n;
	cin>>n;  
    string temp="\0";  
    char c='\0';  
    bool result=false;  
    
    for (int i=0; i<n; ++i)  
    {  
        int count=0,flag=0;  
        JNode *J=new(JNode);  
        for (int k=0; k<N; ++k)  
        {  
            cin>>c>>temp;  
            count+=temp.length()*Value[k];  
            if (!flag)  
            {  
                result=Judge(temp,J);  
                if (!result)  
                {  
                    flag=1;  
                }  
            }  
              
              
        }  
        delete J;  
        if (result&&(count==wpl))//前缀编码且编码长度之和与Huffman编码相同  
        {  
            cout<<"Yes"<<endl;  
        }else{  
            cout<<"No"<<endl;  
        }  
    }
	
	return 0;
 } 
