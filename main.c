#include <stdio.h>
#include <string.h>
#include "includes/ft_printf.h"
#include "float.h"
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
	double  n = 3.54;
	int		a = 3;

	printf("%f\n", n - a);
	n -= a;
	n *= 10;
	printf("%f\n", n);
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

}