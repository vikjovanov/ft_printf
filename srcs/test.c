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

int		main(void)
{
	double x = 5434354324354354354324.562416564354354354354;
	//double b;
//	double c;
	
	while (x > 1.0)
	{
		printf("::: %f\n", x);
		x /= 10;
	}
	if (x == 0.0)
		printf("0\n");
	else
		printf("1\n");
	//int size = set_before_comma(a);
//	b = modf(a, &c);
//	printf("%f = %f + %f\n", a, c, b);
	//printf("%d\n", (int)(a / ft_exp(10, size - 1)));
	//double a = -DBL_MAX;
	//printf("%f\n", a * 1.00001);
}