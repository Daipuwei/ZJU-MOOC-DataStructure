#include <iostream>
#include <cstring> 
using namespace std;

int main()
{
	int num;
	int person[55];
	memset(person,0,sizeof(int)*55);
	cin>>num;
	for ( int i = 0 ; i < num ; i++){
		int old;
		cin>>old;
		person[old]++;
	}
	
	for(int i = 0 ; i < sizeof(person)/sizeof(person[0]) ; i++){
		if ( person[i] != 0){
			cout<<i<<":"<<person[i]<<endl; 
		}
	}
	
	return 0;
 } 
