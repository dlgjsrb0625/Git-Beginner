#include<stdio.h>

int add(int, int);
int sub(int, int);
int mul(int, int);
main()
{
	int a=5, b=3, y;
    y = add(a,b);
	y = y-8;
	printf("SUM 2= %d\n", y);
	y = sub(a,b);
	printf("SUM 22 = %d\n", y);

}

int add(int c, int d)
{
	int sum;
	sum = c + d;
	return sum;
	printf("SUM = %d\n", sum);
}

int sub(int c, int d)
{
	int sum;
	sum = c - d;
	return sum;
	printf("SUM = %d\n", sum);
}
int mul(int c, int d)
{
	int sum;
	sum = c * d;
	return sum;
	printf("SUM = %d\n", sum);
}

