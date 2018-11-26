/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:42:37 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/21 21:58:02 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <float.h>
/*
void	aa(va_list ap)
{
	unsigned int a;
	a = va_arg(ap, unsigned int);
	printf("%u\n", a);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	unsigned int a;
	va_start(ap, format);
int i = 0;
	while (i < 2)
	{
	aa(ap);
	i++;
	}
	va_end(ap);
	return 0;
}
*/
#include <math.h>

static int	set_size_array(double n)
{
	int		nb;

	nb = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		nb++;
	}
	return (nb + 1);
}

static int	set_before_comma(double n)
{
	int nb_before_comma;
	double a;

	nb_before_comma = 0;
	a = 1.0;
	if (n < a)
		return (1);
	while (n >= a && a <= DBL_MAX)
	{
		nb_before_comma++;
		a *= 10.0;
	}
	return (nb_before_comma);
}

static long double ft_exp(double n, int exp)
{ 
	long double	value_exp;
	int			i;

	value_exp = n;
	i = 0;
	if (exp == 0)
		return (1.0);
	while (i < exp - 1)
	{
		value_exp *= n;
		i++;
	}
	return (value_exp);
}

int		main(void)
{
	double a = DBL_MAX;
	int size = set_before_comma(a);

	printf("%d\n", (int)(a / ft_exp(10, size - 1)));
	//double a = -DBL_MAX;
	//printf("%f\n", a * 1.00001);
}