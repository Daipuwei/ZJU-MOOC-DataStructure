#include <iostream>
#include <map>
using namespace std;

int main()
{
	int N;
	map<string,string> qq_pwd;
	cin>>N;
	for ( int i = 0 ; i < N ; i++){
		char ch;
		string qq;
		string pwd;
		cin>>ch>>qq>>pwd;
		if (ch == 'L'){
			auto p = qq_pwd.find(qq);
			if ( p == qq_pwd.end()){
				cout<<"ERROR: Not Exist"<<endl;
			}else if(p->second == pwd){
				cout<<"Login: OK"<<endl;
			}else{
				cout<<"ERROR: Wrong PW"<<endl;
			}
		}else if ( ch == 'N'){
			auto it = qq_pwd.insert(pair<string,string>(qq,pwd));
			if(it.second == true){
				cout<<"New: OK"<<endl;
			}else{
				cout<<"ERROR: Exist"<<endl;
			}
		}
	}
	
	return 0;
}
