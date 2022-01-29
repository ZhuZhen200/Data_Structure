#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

int DivideAndConquer(int a[], int Left, int Right);
int MaxSubsequenceSum3(int a[], int n);
int MaxSubsequenceSum4(int a[], int n);

void run(int(*f)(int*, int), int a[], int n, int case_n);  //����ʱ����Ժ��������������ڸ�Դ�ļ���ʹ��

int main()
{
	int n, i;
	int* a = NULL;

	scanf_s("%d", &n);

	a = (int*)malloc(sizeof(int) * n);  //Ϊ������䶯̬�ڴ�
	srand((unsigned int)time(0));  //��ʼ������Ϊ���ֵ

	if (a != NULL)  //����a�����ڴ�����Ϊ��ָ��
	{
		for (i = 0; i < n; i++)
		{
			a[i] = -100 + rand() % 200;
			printf("%d ", a[i]);
		}
	}
	printf("\n");
	run(MaxSubsequenceSum3, a, n, 3);
	run(MaxSubsequenceSum4, a, n, 4);
	printf("MaxSum3 = %d\n", MaxSubsequenceSum4(a, n));
	printf("MaxSum4 = %d\n", MaxSubsequenceSum4(a, n));
	free(a);
	a = NULL;
	return 0;
}

int DivideAndConquer(int a[], int Left, int Right)//�ֶ���֮
{
	int LeftSum, RightSum;
	int LeftBorderSum, RightBorderSum;
	int MaxLeftBorderSum, MaxRightBorderSum;
	int Center, i;
	int Max;

	if (Left == Right)
	{
		if (a[Left] > 0)
			return a[Left];
		else return 0;
	}//�������� Base Case

	Center = (Left + Right) / 2;
	LeftSum = DivideAndConquer(a, Left, Center);
	RightSum = DivideAndConquer(a, Center + 1, Right);//�ݹ����

	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (i = Center; i >= Left; i--)
	{
		LeftBorderSum += a[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}//�����м�ƫ��ֵ����������

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = Center + 1; i <= Right; i++)
	{
		RightBorderSum += a[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}//�����м�ƫ�ң���������

	Max = RightSum > LeftSum ? RightSum : LeftSum;
	Max = Max > (MaxLeftBorderSum + MaxRightBorderSum) ? Max : (MaxLeftBorderSum + MaxRightBorderSum);
	return Max;
}

int MaxSubsequenceSum3(int a[], int n)
{/*������ͬ�����ӿ�*/
	return DivideAndConquer(a, 0, n - 1);
}

int MaxSubsequenceSum4(int a[], int n)//���ߴ���
{
	int i;
	int ThisSum, MaxSum;

	ThisSum = MaxSum = 0;
	for (i = 0; i < n; i++)
	{
		ThisSum += a[i];
		if (ThisSum > MaxSum)
			MaxSum = ThisSum;
		else if (ThisSum < 0)
			ThisSum = 0;
	}
	return MaxSum;
}