#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<time.h>

int DivideAndConquer(int a[], int Left, int Right);
int MaxSubsequenceSum3(int a[], int n);
int MaxSubsequenceSum4(int a[], int n);

void run(int(*f)(int*, int), int a[], int n, int case_n);  //声明时间测试函数，这样才能在该源文件里使用

int main()
{
	int n, i;
	int* a = NULL;

	scanf_s("%d", &n);

	a = (int*)malloc(sizeof(int) * n);  //为数组分配动态内存
	srand((unsigned int)time(0));  //初始化种子为随机值

	if (a != NULL)  //避免a分配内存出错成为空指针
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

int DivideAndConquer(int a[], int Left, int Right)//分而治之
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
	}//基础条件 Base Case

	Center = (Left + Right) / 2;
	LeftSum = DivideAndConquer(a, Left, Center);
	RightSum = DivideAndConquer(a, Center + 1, Right);//递归调用

	MaxLeftBorderSum = 0;
	LeftBorderSum = 0;
	for (i = Center; i >= Left; i--)
	{
		LeftBorderSum += a[i];
		if (LeftBorderSum > MaxLeftBorderSum)
			MaxLeftBorderSum = LeftBorderSum;
	}//遍历中间偏左值，求左最大和

	MaxRightBorderSum = 0;
	RightBorderSum = 0;
	for (i = Center + 1; i <= Right; i++)
	{
		RightBorderSum += a[i];
		if (RightBorderSum > MaxRightBorderSum)
			MaxRightBorderSum = RightBorderSum;
	}//遍历中间偏右，求右最大和

	Max = RightSum > LeftSum ? RightSum : LeftSum;
	Max = Max > (MaxLeftBorderSum + MaxRightBorderSum) ? Max : (MaxLeftBorderSum + MaxRightBorderSum);
	return Max;
}

int MaxSubsequenceSum3(int a[], int n)
{/*保持相同函数接口*/
	return DivideAndConquer(a, 0, n - 1);
}

int MaxSubsequenceSum4(int a[], int n)//在线处理
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