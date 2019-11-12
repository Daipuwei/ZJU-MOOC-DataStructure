#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

struct user{
	int id;
	int perfect;
	int sum;
	int* score;
};

void Sum(struct user* user1,int K)
{
	for ( int i = 0 ; i <K ; i++){
		if (user1->score[i] != -1 && user1->score[i] != -2){
			user1->sum += user1->score[i];	
		}else{
			continue;
		} 
	}
 } 

bool cmp(struct user user1,struct user user2)
{
	if ( user1.sum > user2.sum){
		return true;
	}else if(user1.sum == user2.sum){
		if ( user1.perfect > user2.perfect){
			return true;
		}else if (user1.perfect == user2.perfect){
			if (user1.id < user2.id){
				return true;
			}
		}
	}
	return false;
}
 

int main()
{
	int N,K,M;
	cin>>N>>K>>M;
	int score[K];
	struct user users[N+1];
	vector<struct user> rank;
	for ( int i = 1 ; i < N+1 ; i++){
		users[i].score = new int[K];
		for (int j = 0 ; j < K ; j++){
			users[i].score[j] = -2;
		}  
		users[i].sum = 0;
		users[i].perfect = 0;
	}	
	for ( int i = 0 ; i < K ; i++){
		cin>>score[i];
	}
	for ( int i = 0 ; i < M ; i++){
		int id,pro_id,num_obtain,index;
		cin>>id>>pro_id>>num_obtain;
		users[id].id = id;
		if ( users[id].score[pro_id-1] < num_obtain){
			users[id].score[pro_id-1] = num_obtain;
		}
	}
	int flag;
	for ( int i = 1 ; i < N+1 ; i++){
		Sum(&users[i],K);
		for ( int j = 0 ; j < K ; j++){
			if ( users[i].score[j] == score[j]){
				users[i].perfect++;
			}
		}
		if ( users[i].sum != 0){
			rank.push_back(users[i]);
		}
	}
	sort(rank.begin(),rank.end(),cmp);
	int r = 2;
	int sum = 0;
	for ( int i = 0 ; i < rank.size(); i++){
		if ( i == 0){
			cout<<i+1;
		}else{
			if ( rank[i].sum == rank[i-1].sum){
				cout<<r;
			}else{
				cout<<i+1;
				r = i+1;
			}
		}
		printf(" %05d %d",rank[i].id,rank[i].sum);
		for ( int j = 0 ; j < K ; j++){
			if( rank[i].score[j] == -2){
				cout<<" -";
			}else if ( rank[i].score[j] == -1){
				cout<<" 0";
			}else{
				cout<<" "<<rank[i].score[j];
			}
		}
		cout<<endl;
	}
	
	return 0;
}
