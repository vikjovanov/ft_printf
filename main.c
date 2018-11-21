#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	/*
	double a = 64.3654494499494494949949949;
	int ret;
	ft_printf("%# .3543434324342f\n", a);
	if ((ret = printf("coucou %# .3543434324342f Coucou\n", a)) < 0)
		printf("ON A RATE\n");
	printf("ret : %d\n", ret);
	printf("value_printf: %-8.3o\n", 64);
	*/

	int a = 14;
	int ret = 0;
	//ft_printf("Coucou %s, comment vas-tu ? il y a %032.32d personnes a la maison\n", "viktor", 14);
	ret = ft_printf("a vaut %d et son adresse est %p | Sa valeur hexadecimale est %x et en octal, c'est %o et si on le formate bien c'est %#o\n", a, &a, a, a, a);
	ft_printf("ft_ret : %d\n", ret);
	//printf("ft_ret: %d\n", ret);
	//ret = printf("a vaut %d et son adresse est %p | Sa valeur hexadecimale est %x et en octal, c'est %o et si on le formate bien c'est %#o\n", a, &a, a, a, a);
	//printf("ret: %d\n", ret);	
	ret = ft_printf("Un double trop long vaut : %.3543434324342f", 3.5);
	ft_printf("double ret %d\n", ret);
	//printf("ft_ret double: %d\n", ret);
	//ret = printf("Un double trop long vaut : %.3543434324342f", 3.5);
	//printf("ret double: %d\n", ret);
	//ft_putstr(a);
	//printf("%s\n", a);
	return (0);
}