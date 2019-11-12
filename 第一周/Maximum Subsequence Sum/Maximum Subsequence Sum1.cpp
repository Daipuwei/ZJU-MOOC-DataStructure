#include <iostream>
using namespace std;

void MaxSubsequenceSum(int *p, int N)
{
	int This_Sum=0;
	int Max_Sum=0;
	int i=0;
	int count = 0;
	int start = 0;
	int end = 0;
	int tmp_start = 0;
	for ( i = 0 ; i < N ; i++ )
	{
		This_Sum += p[i];
		if ( This_Sum < 0)
		{
			count++;
			This_Sum = 0;
			tmp_start = i+1; 						//最大子列和小于0时，最大子列首端加1变成其 
		}
		else 
		{
			if ( This_Sum > Max_Sum)
				{
					Max_Sum = This_Sum;
					start = p[tmp_start];
					end = p[i];
				}
		}
		if ( count == N )
		{
			Max_Sum = 0;
			start = p[0];
			end = p[N-1];
		}
	}
	cout<<Max_Sum<<" "<<start<<" "<<end;
}

int main()
{
	int k;
	cin>>k;
	int a[k];
	for ( int i = 0 ; i < k ;i++ )
		cin>>a[i];
	MaxSubsequenceSum(a,k);
	
	return 0;
 } 
