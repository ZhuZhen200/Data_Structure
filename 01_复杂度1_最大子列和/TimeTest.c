#include<stdio.h>
#include<math.h>
#include<time.h>

clock_t start, stop;
double duration;
#define MAXN 10  /*设置多项式的最大项数*/
#define MAXK 1e4 /*被测函数的重复调用次数*/

void run(int(*f)(int*, int), int a[], int n, int case_n)
{/*run函数用于测试被测函数（*f）的运行时间，case_n是函数编号，1是f1，2是f2*/
	int i;

	start = clock();
	for (i = 0; i < MAXK; i++)
		(*f)(a, n);
	stop = clock();

	duration = ((double)(stop - start)) / CLK_TCK / MAXK;
	printf("ticks%d=%f\n", case_n, (double)(stop - start));
	printf("duration%d=%6.2e\n", case_n, duration);
}