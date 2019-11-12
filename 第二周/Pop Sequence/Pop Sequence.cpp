#include <iostream>
using namespace std;
const int MAXSIZE = 1001;

class Stack
{
	private:
		int top;
		int capacity;
		int data[MAXSIZE];
	public:
		Stack* create_stack();
		void push(Stack *stack,int e);
		void pop(Stack* stack);
		int check_stack(int *test,int MM,int NN);
};

Stack* Stack::create_stack()
{
	Stack* mystack = new Stack;
	mystack->capacity = MAXSIZE;
	mystack->top = -1;
	return mystack;
}

void Stack::push(Stack* stack,int e)
{
	if ( stack->top == stack->capacity-1 )
		return ;
	else
	{
		stack->top++;
		stack->data[stack->top] = e;
	}
}

void Stack::pop(Stack* stack)
{
	if ( stack->top == -1)
		return ;
	else
	{
		stack->top--;
	}
}

int Stack::check_stack(int *test,int MM,int NN)
{
	Stack *ps = create_stack();
	push(ps, 0);
	int idx = 0;
	int num = 1;
	while(idx < NN){
		while(ps->data[ps->top] < test[idx] && idx < NN && ps->top < MM)
			push(ps, num++);
		if(ps->data[ps->top] == test[idx]){
			pop(ps);
			idx++;
		}
		else
			return 0;
	}
	return 1;
}

int main()
{
	int M,N,K;
	cin>>M>>N>>K;
	int *test = new int[N];
	Stack stack;
	for( ; K > 0 ; K--)
	{
		for ( int i = 0 ; i < N ; i++ )
		{
			cin>>test[i];
		}
		if ( stack.check_stack(test,M,N) )
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
}
