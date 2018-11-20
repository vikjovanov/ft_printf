#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
/*
void		lel(long long a)
{
	printf("%lld\n", a);
	printf("%ld\n", 245678955);
}

void		lool(void* a)
{
	lel(*((long long*)a));
}

void		caster(void* a)
{
	short b;

	b = *((short*)a);
	lool((void*)b);
}
*/
int		main(void)
{
	/*
	char a = 60;
	printf("%d\n", *(&a + 12));
	if ((&a + 1) == '\0')
		printf("OK\n");
	ft_putstr(&a);
	//caster((void*)(&a))
	//ft_printf("%#230.56ld Bonjour\n", 45);
	printf("%s\n", &a);
	*/
	//printf("%.36f\n", 3.2526584);
	//printf("%.4f\n", 3.6646524564);
	/*
	double a = 3.252658400000000060714455685229040682;

	while (a > 0)
	{
		printf("%.1f", a);
		a /= 10;
	}*/

	/*printf("%f\n", 35.6545264);
	printf("%f\n", 56.545264);
	printf("%f\n", 65.45264);
	printf("%f\n", 54.5264);
	printf("%f\n", 45.264);
	double a = 35.6545264 * 10.0;
	printf("%f\n", a);
	printf("%f\n", a -300);


	printf("%.5000f\n", FLT_MAX);
	if (FLT_MIN == 0.000000000000000000000000000000000000011754943508222875079687365372222456778186655567720875215087517062784172594547271728515625)
		printf("ok\n");*/
	/*double  n = 3.54;
	int		a = 3;

	printf("%f\n", n - a);
	n -= a;
	n *= 10;
	printf("%f\n", n);*/
	/*
	double	n2;

	n2 = n;
	int		nb;

	nb = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		
		n2 *= 10;
		n /= 10;
		nb++;
	}
	printf("nb + 1 = %d\n", nb + 1);*/
	/*
	printf("ft_print_value\n");
	printf("=============\n");
	ft_printf("%.120f\n", 3.64454154154272424);
	printf("=============\n");
	printf("printf_value: %.120f\n", 3.64454154154272424);
	*/
	//int a = 5;

	//ft_printf("%-p\n", &a);
	/*printf("ret: %-20d\n", 98);
	printf("ret: %-20f\n", 98.00);
	printf("ret: %-20p\n", "Salut");
	printf("ret: %-20x\n", 98);
	printf("ret: %-20o\n", 98);
	printf("ret: %025f\n", 98.95);
	printf("ret: %025o\n", 98);
	printf("x: %#025x\n", 98);
	printf("X: %x\n", 98);
	printf("ret: %025d\n", 98);
	printf("ret: %025p\n", "Salut");
	printf("prec: %.3d\n", 95);
	printf("prec: %026.26d\n", 95);
*/
//	ft_printf("%-9s\n", "Salut");
	/*while (i++ > INT_MAX)
	{
		printf("printf %-*s\n", i, "Salut");
		printf("NB %-*s\n", i, "Salut");
	}
	*/
	char a = 'c';
	ft_printf("%o\n", 64);
	printf("value_printf: %o\n", 64);
	return (0);
}