#include <iostream>
using namespace std;

bool Check(int a[],int b[],int N)
{
	bool flag = true;
	for ( int i = 0 ; i < N ; i++){
		if ( a[i] != b[i]){
			flag = false;
			break;
		}
	}
	return flag;
}

void Print(int a[],int N)
{
	cout<<a[0];
	for (int i = 1 ; i < N ; i++){
		cout<<" "<<a[i];
	}
}

bool Insert_Sort(int a[],int b[],int N)
{
	bool isInsert = false;
	for ( int i = 1 ; i < N ; i++){
		int tmp = a[i];
		int j;
		for (j = i ; j > 0 && a[j-1] > tmp ; j--){
			a[j] = a[j-1];
		}
		a[j] = tmp;
		if (isInsert){
			cout<<"Insertion Sort"<<endl;
			Print(a,N);
			break;
		}else if(Check(a,b,N)){
			isInsert = true;	
		}
	}
	return isInsert;
}

void PreDown(int a[],int p,int N)
{
	int parent,child;
	int x = a[p];
	for ( parent = p ; (parent * 2 + 1) < N ; parent = child){
		child = parent * 2 + 1;
		if ( (child != N -1) && ( a[child] < a[child+1])){
			child++;
		}
		if ( x >= a[child]){
			break;
		}else{
			a[parent] = a[child];
		}
	}
	a[parent] = x;
}

void swap(int* a ,int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

bool Heap_Sort(int a[],int b[],int N)
{
	bool isHeap = false; 
	for ( int i = N/2-1 ; i >= 0 ; i--){
		PreDown(a,i,N);
	}
	for ( int i = N-1 ; i > 0 ; i--){
		swap(&a[0],&a[i]);
		PreDown(a,0,i);
		if (isHeap){
			cout<<"Heap Sort"<<endl;
			Print(a,N);
			break;
		}else if(Check(a,b,N)){
			isHeap = true;
		}
	}
 } 

int main()
{
	int len;
	cin>>len;
	int *A,*B,*C;
	A = new int[len];
	B = new int[len];
	C = new int[len]; 
	for ( int i = 0 ; i < len ; i++){
		cin>>A[i];
		C[i] = A[i];
	}
	for ( int i = 0 ; i < len ; i++){
		cin>>B[i];
	}
	
	bool isHeap = Heap_Sort(A,B,len);
	if ( isHeap){
		return 0;
	}else{
		bool isInsert = Insert_Sort(C,B,len);
		return 0;
	}
	
	return 0;
 } 
