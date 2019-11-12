#include <stdio.h>  
#include <stdlib.h>   
  
typedef struct node{  
    int coefficient;  
    int exponent;  
    struct node * next;  
} PolyNode, *Polynomial;  
  
Polynomial ReadPoly();  
void Attach(int c, int e, Polynomial * Rear);  
Polynomial MultPoly(Polynomial P1, Polynomial P2);  
Polynomial AddPoly(Polynomial P1, Polynomial P2);  
void PrintPoly(Polynomial P);  
  
int main(int argc, char const *argv[])  
{  
    Polynomial Poly1, Poly2, PolySum, PolyMul;  
  
    Poly1 = ReadPoly();  
    Poly2 = ReadPoly();  
    PolyMul = MultPoly(Poly1, Poly2);  
    PrintPoly(PolyMul);  
    PolySum = AddPoly(Poly1, Poly2);  
    PrintPoly(PolySum);  
  
    return 0;  
}  
  
Polynomial ReadPoly()  
{  
    Polynomial P, Rear, temp;  
    P = (PolyNode*)malloc(sizeof(PolyNode));  
    P->next = NULL;  
    Rear = P;  
    int N, c, e;  
    scanf("%d", &N);  
    while(N--){  
        scanf("%d %d", &c, &e);  
        Attach(c, e, &Rear);  
    }  
    temp = P;  
    P = P->next;   
    free(temp);  
    return P;  
}  
  
void Attach(int c, int e, Polynomial * pRear)  
{  
    Polynomial P;  
    P = (PolyNode*)malloc(sizeof(PolyNode));  
    P->coefficient = c;  
    P->exponent = e;  
    P->next = NULL;  
    (*pRear)->next = P;  
    *pRear = P;  
}  
  
Polynomial MultPoly(Polynomial P1, Polynomial P2)  
{  
    Polynomial P, temp1, temp2, Rear, temp;  
    int c, e;  
    if(!P1 || !P2)  
        return NULL;  
    temp1 = P1;  
    temp2 = P2;  
    P = (PolyNode*)malloc(sizeof(PolyNode));  
    P->next = NULL;  
    Rear = P;  
    while(temp2){  
        c = temp1->coefficient * temp2->coefficient;  
        e = temp1->exponent + temp2->exponent;  
        if(c != 0){  
            Attach(c, e, &Rear);  
            temp2 = temp2->next;  
        }  
    }  
    temp1 = temp1->next;  
    while(temp1){  
        temp2 = P2, Rear = P;  
        while(temp2){  
            c = temp1->coefficient * temp2->coefficient;  
            e = temp1->exponent + temp2->exponent;  
            if(c != 0){  
                while(Rear->next && Rear->next->exponent > e)  
                    Rear = Rear->next;  
                if(Rear->next && Rear->next->exponent == e){  
                    if(Rear->next->coefficient + c)  
                        Rear->next->coefficient += c;  
                    else{  
                        temp = Rear->next;  
                        Rear->next = temp->next;  
                        free(temp);  
                    }  
                }  
                else{  
                    temp = (PolyNode*)malloc(sizeof(PolyNode));  
                    temp->coefficient = c;  
                    temp->exponent = e;  
                    temp->next = Rear->next;  
                    Rear->next = temp;  
                    Rear = Rear->next;  
                }  
                temp2 = temp2->next;  
            }  
        }  
        temp1 = temp1->next;  
    }  
    temp = P;  
    P = P->next;  
    free(temp);  
    return P;  
}  
  
Polynomial AddPoly(Polynomial P1, Polynomial P2)  
{  
    Polynomial P, temp1, temp2, Rear, temp;  
    if(!P1 && !P2){  
        if(!P1)  
            return P2;  
        else  
            return P1;  
    }  
    P = (PolyNode*)malloc(sizeof(PolyNode));  
    P->next = NULL;  
    Rear = P;  
    temp1 = P1;  
    temp2 = P2;  
    while(temp1 && temp2){  
        if(temp1->exponent > temp2->exponent){  
            if(temp1->coefficient){  
                Attach(temp1->coefficient, temp1->exponent, &Rear);                 
            }  
            temp1 = temp1->next;  
        }  
        else if(temp1->exponent == temp2->exponent){  
            if(temp1->coefficient + temp2->coefficient){  
                Attach(temp1->coefficient + temp2->coefficient, temp1->exponent, &Rear);  
            }  
            temp1 = temp1->next;  
            temp2 = temp2->next;  
        }  
        else{  
            if(temp2->coefficient){  
                Attach(temp2->coefficient, temp2->exponent, &Rear);                 
            }  
            temp2 = temp2->next;  
        }  
    }  
    while(temp1){  
        Attach(temp1->coefficient, temp1->exponent, &Rear);  
        temp1 = temp1->next;  
    }  
    while(temp2){  
        Attach(temp2->coefficient, temp2->exponent, &Rear);  
        temp2 = temp2->next;  
    }  
    temp = P;  
    P = P->next;  
    free(temp);  
    return P;  
}  
  
void PrintPoly(Polynomial P)  
{  
    int flag = 0;  
    if(!P){  
        printf("0 0");  
    }  
    while(P){  
        if (!flag)  
            flag = 1;  
        else  
            printf(" ");  
        printf("%d %d", P->coefficient, P->exponent);  
        P = P->next;  
    }  
    printf("\n");  
}   
