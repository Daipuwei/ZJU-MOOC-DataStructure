#include <iostream>
using namespace std;

typedef struct Code* code;
struct Code
{
	int coefficient;  
    int exponent;  
	code next;
};

class Polynomial
{
	private:
		int coefficient;  
    	int exponent;  
		Polynomial* next;
	public:
		Polynomial* Create_Polynomial();	
		Polynomial* MultPoly(Polynomial* ptrl1, Polynomial* ptrl2);  
		Polynomial* AddPoly(Polynomial* ptrl1, Polynomial*ptrl2); 
		void PrintPoly(Polynomial* ptrl);  
};

Polynomial* Polynomial::Create_Polynomial()
{
	int N;
	cin>>N;
	Polynomial* head,*prev,*curren;
	head = new Polynomial;
	head->next = NULL;				
	prev = head;			
	int c,e;		 
	while( N-- )
	{
		cin>>c>>e;
		Polynomial* p = new Polynomial;
		p->coefficient = c;
		p->exponent = e;
		p->next = NULL;  
    	prev->next = p;  
    	prev = p; 
	 } 
	 prev = head->next;
	 
	 return prev;
}

void Polynomial::PrintPoly(Polynomial* ptrl)
{
	int flag = 0;  
    if(!ptrl)
	{  
        cout<<"0 0";  
    }  
    while(ptrl)
	{  
        if (!flag)  
            flag = 1;  
        else  
            cout<<" ";  
        cout<<ptrl->coefficient<<" "<<ptrl->exponent;  
        ptrl = ptrl->next;  
    }  
    cout<<endl;  
}

Polynomial* Polynomial::AddPoly(Polynomial* ptrl1, Polynomial* ptrl2)
{
	if( !ptrl1 && !ptrl2 )
	{  
        if( !ptrl1 )  
            return ptrl2;  
        else  
            return ptrl1;  
    }  
    Polynomial* tmp1 = ptrl1;
	Polynomial* tmp2 = ptrl2;
    Polynomial* p1,*rear;
    p1 = new Polynomial;
	p1->next = NULL;
	rear = p1;
	while( tmp1 && tmp2 )
	{
		if ( tmp1->exponent > tmp2->exponent )
		{
			
			if ( tmp1->coefficient )
			{
				Polynomial* p = new Polynomial;
				p->coefficient = tmp1->coefficient;
				p->exponent = tmp1->exponent;
				p->next = NULL;  
    			rear->next = p;  
    			rear = p; 
			}
			tmp1 = tmp1->next;
		}
		else if ( tmp1->exponent == tmp2->exponent )
			{
				if ( tmp1->coefficient + tmp2->coefficient )
				{
					Polynomial* p = new Polynomial;
					p->coefficient = tmp1->coefficient+ tmp2->coefficient;
					p->exponent = tmp1->exponent;
					p->next = NULL;  
    				rear->next = p;  
    				rear = p;
				}
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			 } 
			 else
			 {
			 	 if ( tmp2->coefficient )
			 	 {
			 		Polynomial* p = new Polynomial;
					p->coefficient = tmp2->coefficient;
					p->exponent = tmp2->exponent;
					p->next = NULL;  
    				rear->next = p;  
    				rear = p; 
				  }
				  tmp2 = tmp2->next;
			 }
	}
	while ( tmp1 )
	{
		Polynomial* p = new Polynomial;
		p->coefficient = tmp1->coefficient;
		p->exponent = tmp1->exponent;
		p->next = NULL;  
    	rear->next = p;  
    	rear = p; 
		tmp1 = tmp1->next;
	}
	while ( tmp2 != NULL )
	{
		Polynomial* p = new Polynomial;
		p->coefficient = tmp2->coefficient;
		p->exponent = tmp2->exponent;
		p->next = NULL;  
    	rear->next = p;  
    	rear = p; 
		tmp2 = tmp2->next;
	}
	p1 = p1->next;
	
	return p1;
}

Polynomial* Polynomial::MultPoly(Polynomial* ptrl1,Polynomial* ptrl2)
{
	if( !ptrl1 || !ptrl2 )
	{
		return NULL;
	}
	Polynomial* tmp1 = ptrl1;
	Polynomial* tmp2 = ptrl2;
	int c,e;
	Polynomial* p = new Polynomial;
	Polynomial* tmp,*rear;
	p->next = NULL;
	rear = p;
	while(tmp2)
	{  
        c = tmp1->coefficient * tmp2->coefficient;  
        e = tmp1->exponent + tmp2->exponent;  
        if(c != 0){  
            Polynomial* p = new Polynomial;
			p->coefficient = c;
			p->exponent = e;
			p->next = NULL;  
    		rear->next = p;  
    		rear = p; 
            tmp2 = tmp2->next;  
        }  
    } 
    tmp1 = tmp1->next;
    while (tmp1)
	{
		tmp2 = ptrl2;
		rear = p;
		while(tmp2)
		{  
            c = tmp1->coefficient * tmp2->coefficient;  
            e = tmp1->exponent + tmp2->exponent;  
            if(c != 0)
			{  
                while(rear->next && rear->next->exponent > e)  
                    rear = rear->next;  
                if(rear->next && rear->next->exponent == e)
				{  
                    if(rear->next->coefficient + c)  
                        rear->next->coefficient += c;  
                    else
					{  
                        tmp = rear->next;  
                        rear->next = tmp->next;    
                    }  
                }  
                else
				{  
                    tmp = new Polynomial;  
                    tmp->coefficient = c;  
                    tmp->exponent = e;  
                    tmp->next = rear->next;  
                    rear->next = tmp;  
                    rear = rear->next;  
                }  
                tmp2 = tmp2->next;  
            }  
        }  
        tmp1 = tmp1->next;  
	 } 
	p = p->next;    
    return p; 
}

int main()
{
	Polynomial polynomial;
	Polynomial* ptrl1,*ptrl2,*ptrl_add,*ptrl_mul;
	ptrl1 = polynomial.Create_Polynomial();
	ptrl2 = polynomial.Create_Polynomial();
	
	ptrl_mul = polynomial.MultPoly(ptrl1,ptrl2);
	polynomial.PrintPoly(ptrl_mul);
	
	ptrl_add = polynomial.AddPoly(ptrl1,ptrl2);
	polynomial.PrintPoly(ptrl_add);
	
	return 0;
}
