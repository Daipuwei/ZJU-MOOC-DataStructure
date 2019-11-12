#include <iostream>
using namespace std; 

int* copy(int* a,int len)
{
	int* num;
	num = new int[len];
	for ( int i = 0 ; i < len ; i++){
		num[i] = a[i];
	}
	return num;
}

void Buble_Sort(int *a ,int N)
{
	for ( int i = 0 ; i < N - 1 ; i++){
		for ( int j = i + 1 ; j < N ; j++){
			if ( a[i] > a[j]){
				a[i] = a[i] + a[j];
				a[j] = a[i] - a[j];
				a[i] = a[i] - a[j];
			}
		}
	}
}

void Insert_Sort(int *a ,int N)
{
	for ( int i = 1 ; i < N ; i++){
		int tmp = a[i];
		int j;
		for(j = i ; j > 0 && a[j-1] > tmp ; j--){
			a[j] = a[j-1];
		} 
		a[j] = tmp;
	}
}

/* 将N个元素的数组中以A[p]为根的子堆调整为最大堆 */
void PreDown(int *a , int p , int N)
{
	int parent,child;
	int x = a[p];
	for (parent = p ; (parent*2 +1) < N ; parent = child){
		child = 2 * parent+1;
		if ( (child != N-1)&& (a[child] < a[child+1])){
			child++;
		}
		if ( x >= a[child]){
			break;
		}else{
			a[parent] = a[child];
		}
	}
	a[parent] = x;
}

void Heap_Sort(int* a ,int N)
{
	int i;
	for ( i = N/2 - 1 ; i >= 0  ; i--){
		PreDown(a,i,N);
	}
	
	for ( i = N -1 ; i > 0 ; i--){
		a[0] = a[i] + a[0];
		a[i] = a[0] - a[i];
		a[0] = a[0] - a[i];
		PreDown(a,0,i);
	} 
}

void Merge1(int a[] ,int tmp[],int left ,int right,int rightend)
{
	int leftend = right-1;
	int len = rightend - left + 1;
	int x = left;
	while(left <= leftend && right <= rightend){
		if ( a[left] <= a[right]){
			tmp[x++] = a[left++];
		}else{
			tmp[x++] = a[right++];
		}
	}
	
	while(left <= leftend){
		tmp[x++] = a[left++];
	}
	while(right <= rightend){
		tmp[x++] = a[right++];
	}
	
	for( int i = rightend ; len > 0 ; len--,i--){
		a[i] = tmp[i];
	} 
}

void Mergesort(int a[],int tmp[],int left,int right)
{
	if ( left < right){
		int mid = (left+right)/2;
		Mergesort(a,tmp,left,mid);
		Mergesort(a,tmp,mid+1,right);
		Merge1(a,tmp,left,mid+1,right);
	}
}

void Merge_Sort1(int a[] ,int N)
{
	int* tmp;
	tmp = new int[N];
	if (tmp != NULL){
		Mergesort(a,tmp,0,N-1);
	}else{
		cout<<"内存不足"<<endl;
	} 
}

void swap(int* a ,int *b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int Median3(int a[],int left,int right)
{
	int center = (left + right) / 2;
    if (a[left] > a[center]) {
        swap(&a[left], &a[center]);
    }
    if (a[left] > a[right]) {
        swap(&a[left], &a[right]);
    }
    if (a[center] > a[right]) {
        swap(&a[center], &a[right]);
    }
    swap(&a[center], &a[right-1]); /* 将基准放在数组右端 */
    return a[right-1];
}

void Qsort(int a[],int left ,int right)
{
	int cutoff = 100;
	int low,high,pivot;
	if ( right - low > cutoff){
		pivot = Median3(a,left,right);
		low = left;
		high = right-1;
		while(1){
			while(a[++low] < pivot);
			while(a[--high] > pivot);
			if ( low < high){
				swap(&a[low],&a[high]);
			}else{
				break;
			}
		}
		swap(&a[low], &a[right - 1]);
        Qsort(a, left, low - 1);
        Qsort(a, low + 1, right);
	}else{
		Insert_Sort(a+left,right-left+1);
	}
}

void Quick_Sort(int a[],int N)
{
	Qsort(a,0,N-1);
 } 

void Print(int *a , int N)
{
	cout<<a[0];
	for ( int i = 1 ; i < N ; i++){
		cout<<" "<<a[i];
	}
}

int main()
{
	int len;
	cin>>len;
	int* a;
	a = new int[len];
	for ( int i = 0 ; i < len ; i++){
		cin>>a[i];
	} 
	
	//冒泡排序
	int* copy_num; 
	copy_num = copy(a,len);
	Buble_Sort(copy_num,len);
	Print(copy_num,len);
	cout<<endl;
	
	//插入排序
	copy_num = copy(a,len);
	Insert_Sort(copy_num,len);
	Print(copy_num,len);
	cout<<endl;
	
	//堆排序
	copy_num = copy(a,len);
	Heap_Sort(copy_num,len);
	Print(copy_num,len);
	cout<<endl;
	
	//归并排序（递归版） 
	copy_num = copy(a,len);
	Merge_Sort1(copy_num,len);
	Print(copy_num,len);
	cout<<endl;
	
	/*//快速排序
	copy_num = copy(a,len);
	Quick_Sort(copy_num,len);
	Print(copy_num,len);
	cout<<endl;*/ 
	
	return 0;
}
