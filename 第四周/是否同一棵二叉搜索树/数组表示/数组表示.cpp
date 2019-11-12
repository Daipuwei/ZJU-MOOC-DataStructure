#include <iostream>
using namespace std;
 
class SearchTree{
    private:
        int  capacity;
        int* data;
        int* Lower_Data;       
        int* Greater_Data;      
    public:
        void set_SearchTree(int capacity){
            this->capacity = capacity;
            this->data = new int[this->capacity];
            for ( int i = 0 ; i < this->capacity ; i++ ){
                cin>>data[i];
            }
            this->Greater_data();
            this->Lower_data();
        }
         
        void Lower_data(){                 
            int count = 0;
            for ( int i = 1 ; i < this->capacity ; i++){
                if ( this->data[i] < this->data[0] ){
                    count++;
                }
            }
            this->Lower_Data = new int[count];
            int j = 0;
            for ( int i = 1 ; i < this->capacity ; i++){
                if ( this->data[i] < this->data[0] ){
                    this->Lower_Data[j++] = this->data[i];
                }
            }
        }
         
        void Greater_data(){
            int count = 0;
            for ( int i = 1 ; i < this->capacity ; i++){
                if ( this->data[i] > this->data[0] ){
                    count++;
                }
            }
            this->Greater_Data = new int[count];
            int k = 0;
            for ( int i = 1 ; i < this->capacity ; i++){
                if ( this->data[i] > this->data[0] ){
                    this->Greater_Data[k++] = this->data[i];
                }
            }
        }
         
        void Judge(){
            int flag1 = 1;
            int flag2 = 1;
            SearchTree tmp;
            tmp.set_SearchTree(this->capacity);
            if ( this->data[0] != tmp.data[0]){
            	cout<<"No"<<endl;
			}
			else{
				for ( int i = 0 ; i < sizeof(this->Lower_Data)/sizeof(this->Lower_Data[0]) ; i++){
	                if ( this->Lower_Data[i] != tmp.Lower_Data[i]){
	                    flag1 =0;
	                    break;
	                }
	            }
	            for ( int i = 0 ; i < sizeof(this->Greater_Data)/sizeof(this->Greater_Data[0]) ; i++ ){
	                if ( this->Greater_Data[i] != tmp.Greater_Data[i] ){
	                    flag1 = 0;
	                    break;
	                }
	            }
	            if ( flag1 == 1 && flag2 == 1 ){
	                cout<<"Yes"<<endl;
	            }
	            else
	                cout<<"No"<<endl;
				}
        }
};
 
int main()
{
    int capacity;
    int n;
    cin>>capacity; 
    SearchTree tree;
    while ( capacity){
        cin>>n;
        tree.set_SearchTree(capacity);
        for ( int i = 0 ; i < n ;i++){
            tree.Judge();
        }
        cin>>capacity;
    }
     
    return 0;
}
