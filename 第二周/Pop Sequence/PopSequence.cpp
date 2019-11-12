#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int M;	//栈的最大容量 
int N;	//测试数据的长度 
int K;	//测试数据的组数 

/*
	这题是模拟给定序列出栈过程
	思路如下：
		当我们遇见输出x时，则要考虑的是x前的元素，即小于等于x的元素都先push栈，才会有pop x；
		1。栈为空时，判断需要填入的数 是否小于 栈的容量(即M)
		2。若后一个数比前一个数大，又要push其之前的数 再判断　
		3。若后一个数比前一个数小，则要判断栈顶元素是否与其相等
*/

bool Check_Seq(vector<int> &v)
{
	int i = 0;
	int num = 1;
	int cap = M+1;
	stack<int> sta;
	sta.push(0);
	while(i < N ){
		while(sta.size() < cap && v[i] > sta.top()){
			sta.push(num++); 
		}
		if ( v[i++] == sta.top()){
			sta.pop();
		}else{
			return false;
		}
	} 
	return true;
 } 

int main()
{
	cin>>M>>N>>K;
	vector<int> seq;
	
	for (int i = 0 ; i < K ; i++){
		for ( int j = 0 ; j < N ; j++){
			int tmp;
			cin>>tmp;
			seq.push_back(tmp);
		}
		if(Check_Seq(seq)){
			cout<<"YES"<<endl;
		}else{
			cout<<"NO"<<endl;
		}
		seq.clear();
	}
	
	return 0;
}
