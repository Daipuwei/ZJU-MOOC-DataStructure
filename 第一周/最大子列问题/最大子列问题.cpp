#include <iostream>
using namespace std;

int MaxSubseqsum(int *a,int k)
{
	int This_Sum = 0;
	int Max_Sum = 0 ;
	for ( int i = 0 ; i < k ; i++ )
	{
		This_Sum += a[i];
		if ( This_Sum > Max_Sum )
			Max_Sum = This_Sum;
		else if ( This_Sum < 0 )
				This_Sum = 0;
	}
	return Max_Sum;
}

int main()
{
	int k;
	cin>>k;
	int a[k];
	for (int i = 0 ; i < k ; i++ )
		cin>>a[i];
	int Max = MaxSubseqsum(a,k);
	cout<< Max; 
	
	return 0;
}

