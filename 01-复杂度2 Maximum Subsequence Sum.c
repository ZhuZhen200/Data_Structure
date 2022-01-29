#include<stdio.h>
#include<malloc.h>

int MaxSubsequenceSum(int a[], int n, int* head, int* end);

int main()
{
	int n, i;
	int* a = NULL;

	scanf_s("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	if (a != NULL)  //避免a分配内存出错成为空指针
	{
		for (i = 0; i < n; i++)
			scanf_s("%d", &a[i]);

		int MaxSum = 0;
		int head = 0;
		int end = 0;
		MaxSum = MaxSubsequenceSum(a, n, &head, &end);
		printf("%d ", MaxSum);
		printf("%d ", a[head]);
		printf("%d", a[end]);
	}
	free(a);
	a = NULL;

	return 0;
}

int MaxSubsequenceSum(int a[], int n, int* head, int* end)
{
	int i, tmphead;
	int ThisSum, MaxSum;
	tmphead = 0;
	ThisSum = 0;
	MaxSum = -1;  //所有数均为非正时，仍可更新最大值，使end指向序列末项

	for (i = 0; i < n; i++)
	{
		ThisSum += a[i];
		if (ThisSum < 0)
		{
			ThisSum = 0;
			tmphead = i + 1;
		}
		else if (ThisSum > MaxSum)
		{
			MaxSum = ThisSum;
			*head = tmphead;  //更新最大值时再更新真正的head和end
			*end = i;
		}
	}
	return MaxSum;
}