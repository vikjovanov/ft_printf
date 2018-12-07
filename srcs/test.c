/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:42:37 by bjovanov          #+#    #+#             */
/*   Updated: 2018/12/06 21:02:19 by vjovanov         ###   ########.fr       */
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

#include <stdlib.h>
#include <limits.h>


int		main(void)
{
	double a = 4537453357537375442385297274306560.000000;


	printf("%f\n", a);
	printf("%f\n", a);
	return 0;
}