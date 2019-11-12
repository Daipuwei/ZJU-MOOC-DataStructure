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

void Merge(int a[],int left ,int right , int rightend)
{
	int tmp[rightend-left+1];
	int leftend = right-1;
	int len = rightend - left +1;
	int i = left , j = right ,k = 0;
	while(i <= leftend && j <= rightend){
		if( a[i] <= a[j]){
			tmp[k++] = a[i++];
		}else{
			tmp[k++] = a[j++];
		}
	}
	
	while(i <= leftend){
		tmp[k++] = a[i++];
	}
	while(j <= rightend){
		tmp[k++] = a[j++];
	}
	
	for(i = left, k = 0; i <= rightend; i++){
        a[i] = tmp[k++];
    }
}

bool Merge_Sort(int a[],int b[],int N)
{
	bool isMerge = false;
	for ( int i = 1 ; i < N ; i *= 2){
		for ( int j = 0 ; j < N ; j += i*2){
			if ( j + i*2 <= N){
				Merge(a,j,j+i,j+i*2-1);
			}else if( j + i <= N) {
				Merge(a,j,j+i,N-1);
			}
		}
		if (isMerge){
			cout<<"Merge Sort"<<endl;
			Print(a,N);
			break;
		}else if (Check(a,b,N)){
			isMerge = true;
		}
	}
	return isMerge;
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
	
	bool isMerge = Merge_Sort(A,B,len);
	if ( isMerge){
		return 0;
	}else{
		bool isInsert = Insert_Sort(C,B,len);
		return 0;
	}
	
	return 0;
 } 
