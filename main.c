#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>
#include <float.h>
#include <math.h>

int		main(void)
{
	printf("%d\n", 54);
	ft_printf("%d\n", 54);

	printf("%.32d\n", 54);
	ft_printf("%.32d\n", 54);
	
	printf("%ld\n", 54545654445641);
	ft_printf("%ld\n", 54545654445641);
	
	printf("%045.32hd\n", 54545654445641);
	ft_printf("%045.32hd\n", 54545654445641);
	
	printf("%i\n", 54);
	ft_printf("%i\n", 54);
	
	printf("%o\n", 54);
	ft_printf("%o\n", 54);
	
	printf("%#032o\n", 10);
	ft_printf("%#032o\n", 10);
	
	printf("%#.32x\n", 10);
	ft_printf("%#.32x\n", 10);
	
	printf("%-25d\n", 54);
	ft_printf("%-25d\n", 54);
	
	printf("%-32.45X\n", 54);
	ft_printf("%-32.45X\n", 54);
	
	printf("% +d\n", 54);
	ft_printf("% +d\n", 54);
	
	printf("%+-10.45u\n", 54);
	ft_printf("%+-10.45u\n", 54);
	
	printf("%-*s\n", 45, "Bonjour les potos");
	ft_printf("%-*s\n", 45, "Bonjour les potos");
	
	printf("%.8s\n", "Salut \0 ca va ?");
	ft_printf("%.8s\n", "Salut \0 ca va ?");
	
	printf("%20*s\n", 50, "Lol");
	//ft_printf("%**s\n", 50, 50, "Lol");

	printf("%**s\n", 100, 50, "Lol");
	ft_printf("%**s\n", 50, 50, "Lol");
	
	printf("%f\n", -0);
	ft_printf("%f\n", -0);
	
	printf("%f\n", 3.45544);
	ft_printf("%f\n", 3.45544);
	
	printf("%#+f\n", 54.32);
	ft_printf("%#+f\n", 54.32);
	
	//printf("%.32f\n", -0.0);
	//ft_printf("%.32f\n", -0.0);
	
	printf("%d\n", -0);
	ft_printf("%d\n", -0);
	
	return (0);
}