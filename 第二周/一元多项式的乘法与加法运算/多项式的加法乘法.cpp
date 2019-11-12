#include <iostream>
#include <vector>
#define Max_Expon 1001
#define Max_Mul_Expon 1000001
using namespace std;

vector<int> Polynomial_Add(Max_Expon,0);  
vector<int> Polynomial_Mul(Max_Mul_Expon,0);

//打印函数 
void Print(vector<int> Polynomial)
{ 
	int flag = 0;
	for ( int i = Polynomial.size()-1 ; i >= 0 ; i-- ){
		if ( Polynomial[i] != 0){
			if ( flag == 0){
				cout<<Polynomial[i]<<" "<<i;
				flag = 1;
			}else{
				cout<<" "<<Polynomial[i]<<" "<<i;
			}
		}
	}
	if ( flag == 0){
		cout<<"0 0";
	}
}

//多项式加法 
void Add(vector<int> Polynomial_1,vector<int> Polynomial_2){
	for ( int i = 0 ; i < Polynomial_Add.size() ; i++){
		Polynomial_Add[i] = Polynomial_1[i]+Polynomial_2[i];
	}
} 

//多项式乘法 
void Mul(vector<int> Polynomial_1,vector<int> Polynomial_2){
	for ( int i = 0 ; i < Polynomial_1.size() ; i++){
		for ( int j = 0 ; j < Polynomial_2.size() ; j++){
			Polynomial_Mul[i+j] += Polynomial_1[i]*Polynomial_2[j];
		}
	}
}

int main()
{
	vector<int> Polynomial_1(Max_Expon,0);  
    vector<int> Polynomial_2(Max_Expon,0);    
    int coef=0;		//系数  
    int expon=0;  	//指数 
    int num=0;  
    
    //初始化多项式 
	cin>>num;
	for ( int i = 0 ; i < num ; i++){
		cin>>coef>>expon;
		Polynomial_1[expon] = coef;
	}
	
	cin>>num;
	for ( int i = 0 ; i < num ; i++){
		cin>>coef>>expon;
		Polynomial_2[expon] = coef;
	}
	
	Mul(Polynomial_1,Polynomial_2);
	Print(Polynomial_Mul);
	cout<<endl;
	
	Add(Polynomial_1,Polynomial_2);
	Print(Polynomial_Add);
	
	return 0;
 } 
