#include <iostream>  
#include <vector>  
#include <iomanip>  
using namespace std;  
  
#define Max_Node_Num 100002  
  
typedef struct node  
{  
    int data;  
    int next;  
}Node;  
  
int Reverse(int head,int K,int N,vector<Node>& vec)//分区域逆转链表的核心函数  
{  
    int num=N/K;//需要逆转的大小为K的子链表的个数  
    int New_Begin=0;//逆转链表后新的开始结点的地址  
    int flag=0;//最早的K个结点逆转后存储新的开始地址的标志  
    while (num--)  
    {  
        int cnt=1,tmp;  
        int New=vec[head].next;//head为上一组链表逆转后的最后一个结点  
        int Record=New;  
        int Old=vec[New].next;  
        while (cnt<K)//依次逆转本组链表中的每个结点  
        {  
            tmp=vec[Old].next;  
            vec[Old].next=New;  
            New=Old;  
            Old=tmp;  
            cnt++;  
        }  
        vec[vec[head].next].next=Old;//处理完一组后把本组当前最后一个结点（逆转前为本组第一个结点）指向下一组第一个结点  
        vec[head].next=New;//上一组逆转后的链表最后一个结点指向本组逆转后的第一个结点  
        head=Record;//本组逆转后的最后一个结点作为下一组链表未逆转时的头结点  
        if (flag==0)//记录整个链表的新的开始地址（即为第一组链表逆转后的第一个结点的地址）  
        {  
            flag=1;  
            New_Begin=New;  
        }  
    }  
    return New_Begin;  
}  
  
int main(int argc, const char * argv[])  
{  
    //Input  
    vector<Node> List(Max_Node_Num);  
    int begin=0,N=0,K=0;  
    cin>>begin>>N>>K;  
    int front,value,rear;  
    for (int i=0; i<N; ++i)  
    {  
        cin>>front>>value>>rear;  
        List[front].data=value;  
        List[front].next=rear;  
    }  
     
      
    //Process  
    int Real_N=0;  
    int Begin_temp=begin;  
    while (Begin_temp!=-1)  
    {  
        Begin_temp=List[Begin_temp].next;  
        Real_N++;//Real_N代表给出的结点中在链表之中的有效结点的个数  
    }  
      
    List[100001].next=begin;  
    int head=100001;  
    int new_begin=Reverse(head, K,Real_N, List);  
      
    //Output  
    while (new_begin!=-1)  
    {  
        if (List[new_begin].next==-1)//输出－1不填充0，分开处理  
        {  
            cout<<setfill('0')<<setw(5)<<new_begin<<' '<<List[new_begin].data<<' '<<List[new_begin].next;  
            //setfill函数在setw函数规定的大小未满时填充‘0’  
        }else  
        {  
            cout<<setfill('0')<<setw(5)<<new_begin<<' '<<List[new_begin].data<<' '<<setfill('0')<<setw(5)<<List[new_begin].next;  
        }  
        new_begin=List[new_begin].next;  
        cout<<endl;  
    }  
      
    return 0;  
}  

