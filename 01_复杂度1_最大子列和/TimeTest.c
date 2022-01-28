#include<stdio.h>
#include<math.h>
#include<time.h>

clock_t start, stop;
double duration;
#define MAXN 10  /*���ö���ʽ���������*/
#define MAXK 1e4 /*���⺯�����ظ����ô���*/

void run(int(*f)(int*, int), int a[], int n, int case_n)
{/*run�������ڲ��Ա��⺯����*f��������ʱ�䣬case_n�Ǻ�����ţ�1��f1��2��f2*/
	int i;

	start = clock();
	for (i = 0; i < MAXK; i++)
		(*f)(a, n);
	stop = clock();

	duration = ((double)(stop - start)) / CLK_TCK / MAXK;
	printf("ticks%d=%f\n", case_n, (double)(stop - start));
	printf("duration%d=%6.2e\n", case_n, duration);
}