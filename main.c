#include <stdio.h>
#include "ft_printf.h"
#include <limits.h>

int		main(void)
{
	double a = 64.3654494499494494949949949;
	ft_printf("%# .500f\n", a);
	printf("value_printf: %# .500f\n", a);

	printf("value_printf: %-8.3o\n", 64);
	return (0);
}