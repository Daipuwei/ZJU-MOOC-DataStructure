#include <iostream>
#include <map>
#include <set>
#include <stdlib.h>
#include <algorithm>
using namespace std; 

struct person{
	int cnt;
	string phone;
};

long long stringToint(string str)
{
	int len = str.length();
	char ch[len];
	for ( int i = 0 ; i < len ; i++){
		ch[i] = str[i];
	}
	long long num = atoi(ch);
	return num;
 } 

bool cmp(struct person person1,struct person person2)
{
	if (person1.cnt > person2.cnt){
		return true;
	}else if (person1.cnt == person2.cnt){
		long long p1 = stringToint(person1.phone);
		long long p2 = stringToint(person2.phone);
		if ( p1 < p2 ){
			return true;
		} 
	}
	return false;
}

int main()
{
	int len;
	map<string,int> map;
	set<string> phone;
	cin>>len;
	for (int i = 0 ; i < len ; i++){
		string phone1,phone2;
		cin>>phone1>>phone2;
		phone.insert(phone1);
		phone.insert(phone2);
		if ( map.count(phone1) == 0){
			map.insert(pair<string,int>(phone1,1));
		}else{
			int cnt = map.find(phone1)->second;
			cnt++;
			map.erase(map.find(phone1)); 
			map.insert(pair<string,int>(phone1,cnt));
		}
		
		if ( !map.count(phone2)){
			map.insert(pair<string,int>(phone2,1));
		}else{
			int cnt = map.find(phone2)->second;
			cnt++;
			map.erase(map.find(phone2));
			map.insert(pair<string,int>(phone2,cnt));
		}
	}
	int size = phone.size();
	struct person rank[size];
	set<string>::iterator it = phone.begin();
	int cnt = 0;
	for ( ; it != phone.end() ; it++){
		rank[cnt].phone = *it;
		rank[cnt].cnt = map.find(rank[cnt].phone)->second;
		cnt++;
	} 
	
	sort(rank,rank+size,cmp);
	int max = rank[0].cnt;
	int index = size-1;
	for ( int i = size-1 ; i > 0 ; i--){
		if (rank[i].cnt != max){
			index--;
		}else{
			break;
		}
	}
	
	cout<<rank[0].phone<<" "<<max;
	if( index != 0){
		cout<<" "<<index+1;
	} 

	return 0;
}
