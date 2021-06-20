// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <Windows.h>
#include <stdio.h>
#include <math.h>
int candp(int a, int b, int c)//计算a^b%c,余数的乘法定理
{
	int r = 1;
	b = b + 1;
	while (b != 1)
	{
		r = r * a;
		r = r % c;
		b--;
	}
	return r;
}
int isprime(int X)
{
	int tmp = sqrt(X);
	if (X == 2)
	{
		return 0;
	}
	if (X % 2 == 0)
	{
		return 0;
	}
	for (int i = 3; i <= tmp; i = i + 2)
	{
		if (X % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
/*int isprime_2(int num)
{ //两个较小数另外处理
	if (num == 2 || num == 3)
	{
		return 1;
	}
	//不在6的倍数两侧的一定不是质数
	if (num % 6 != 1 && num % 6 != 5)
	{
		return 0;
	}
	int tmp =sqrt( num);
	//在6的倍数两侧的也可能不是质数
	for (int j = 5; j <= tmp; j += 6) {
		if (num % j == 0 || num % (j + 2) == 0)
		{
			return 0;
		}
	}
	//排除所有，剩余的是质数
	return 1 ;
} */
int ifprimeable(int a, int b)//a大于b
{
	int q;
	do {
		q = a % b;
		a = b;
		b = q;
	} while (q != 0);
	if (a == 1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}
void main()
{
	int p = 0, q = 0, e = 0, d = 0, m = 0, n = 0, t = 0, c = 0;
	char s = 0, r = 0;
	printf("常用质数2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97\n");
	printf("输入质数p: ");
	scanf_s("%d", &p);
	while (isprime(p) == 0)
	{
		printf("p不是质数，重新输入:");
		scanf_s("%d", &p);
	}
	printf("输入质数q: ");
	scanf_s("%d", &q);
	while (isprime(q) == 0)
	{
		printf("q不是质数，重新输入:");
		scanf_s("%d", &q);
	}
	n = p * q;
	printf("n为%d\n", n);
	t = (p - 1) * (q - 1);
	printf("n的欧拉函数为%d\n", t);
	printf("输入公钥的e，e要与%d互质且小于%d:", t, t);
	scanf_s("%d", &e);
	while ((e<1 || e>t) || ifprimeable(t, e) == 0)
	{
		printf("e不符合要求，重新输入:");
		scanf_s("%d", &e);
	}
	d = 1;
	while (((e * d) % t) != 1)
		d++;
	printf("生成公钥（%d，%d），私钥（%d，%d）\n", n, e, n, d);
	bool flag = true;
	printf("**************************************\n");
	printf("退出按r ");
	printf("明文转密文按q ");
	printf("密文转明文按w\n");
	while (flag == true)
	{
		switch (r)
		{
		case 'r':
			flag = false;
			break;
		case 'q': printf("输入明文m(m<n=%d) ", n); /*输入要加密的明文数字*/
			scanf_s("%d", &m);
			c = candp(m, e, n);
			printf("密文为%d\n", c);
			flag = true;
			printf("**************************************\n");
			printf("退出按r ");
			printf("明文转密文按q ");
			printf("密文转明文按w\n");
			break;
		case 'w': printf("输入密文"); /*输入要解密的密文数字*/
			scanf_s("%d", &c);
			m = candp(c, d, n);
			printf("明文为%d\n", m);
			flag = true;
			printf("**************************************\n");
			printf("退出按r ");
			printf("明文转密文按q ");
			printf("密文转明文按w\n");
			break;
		}
		r = getchar();
	}
	system("pause");
}


// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
