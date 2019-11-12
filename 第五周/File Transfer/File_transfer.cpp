#include <iostream>
#include <vector>

using namespace std;

#define Max_Node 10001

typedef struct
{
    int parent;
}Node;

int Find_Set(vector<Node> &set,int value)//寻找当前value所在的并查集的根结点
{
    while (set[value].parent>0)
    {
        value=set[value].parent;
    }
    return value;
}

void Union_Set(vector<Node> &set,int value1,int value2)//合并两个结点的并查集
{
    int root1=Find_Set(set, value1);
    int root2=Find_Set(set, value2);
    if (set[root1].parent<set[root2].parent)//以root1为根的并查集的结点个数更多，将并查集结点个数少的合并到结点个数多的并查集
    {
        set[root2].parent=root1;
        set[root1].parent--;
    }else
    {
        set[root1].parent=root2;
        set[root2].parent--;
    }
}

bool Check_Set(vector<Node> &set,int value1,int value2)//查询两结点是否在同一个并查集
{
    int root1=Find_Set(set, value1);
    int root2=Find_Set(set, value2);
    if (root1==root2)
    {
        return true;
    }else
    {
        return false;
    }
}

int Count_Set(vector<Node> &set)//查询当前并查集的个数
{
    int count=0;
    for (int i=1; i<=set.size(); ++i)
    {
        if (set[i].parent<0)//parent小于0则该结点为一个并查集的根
        {
            count++;
        }
    }
    return count;
}

int main()
{
    int N=0;
    cin>>N;
    vector<Node> Set(N+1);
    for (int i=1; i<=N; ++i)
    {
        Set[i].parent=-1;
    }
    char str;
    int value1=0,value2=0;
    while (1)
    {
        cin>>str;
        if (str=='S')
        {
            break;
        }else if(str=='I')
        {
            cin>>value1>>value2;
            Union_Set(Set, value1, value2);
        }else
        {
            cin>>value1>>value2;
            if (Check_Set(Set, value1, value2))
            {
                cout<<"yes\n";
            }else
            {
                cout<<"no\n";
            }
        }
    }
    
    int count=Count_Set(Set);
    if (count>1)
    {
        cout<<"There "<<"are "<<count<<" components.";
    }else
    {
        cout<<"The network is connected.";
    }
    return 0;
}
