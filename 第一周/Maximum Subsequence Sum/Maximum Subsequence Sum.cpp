#include <stdio.h>

#define MAX 100000ul

int MaxSubsequenceSum(int *p, int N, int *start, int *end)
{
int i = 0, count = 0;
int tmp_start = 0;
int ThisSum = 0, MaxSum = 0;
for (i = 0; i < N; i++)
{
ThisSum += *(p + i);

if (ThisSum < 0)
{
count++;
ThisSum = 0;
tmp_start = i + 1;
}
else if (ThisSum > MaxSum)
{
MaxSum = ThisSum;
*start = *(p + tmp_start);
*end = *(p + i);
}
}
if (count == N)
{
MaxSum = 0;
*start = *(p + 0);
*end = *(p + N - 1);
}
return MaxSum;
}

int main(void)
{
int i;
long int k = 0;
int arr[MAX] = { 0 };
int start = 0, end = 0;

scanf("%d", &k);

for (i = 0; i < k; i++)
{
scanf("%d", &arr[i]);
}

printf("%d ", MaxSubsequenceSum(arr, k, &start, &end));
printf("%d %d", start, end);

return 0;
}
