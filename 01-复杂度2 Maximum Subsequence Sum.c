#include<stdio.h>
#include<malloc.h>

int MaxSubsequenceSum(int a[], int n, int* head, int* end);

int main()
{
	int n, i;
	int* a = NULL;

	scanf_s("%d", &n);
	a = (int*)malloc(sizeof(int) * n);
	if (a != NULL)  //����a�����ڴ�����Ϊ��ָ��
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
	MaxSum = -1;  //��������Ϊ����ʱ���Կɸ������ֵ��ʹendָ������ĩ��

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
			*head = tmphead;  //�������ֵʱ�ٸ���������head��end
			*end = i;
		}
	}
	return MaxSum;
}