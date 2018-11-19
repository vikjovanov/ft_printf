/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:42:37 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 16:25:47 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

/*
int		ft_printf(const char *format, ...)
{
	va_list ap;
	unsigned int a;

	va_start(ap, format);
	a = va_arg(ap, unsigned int);
	va_end(ap);
	printf("%u\n", a);
	return 0;
}
*/

int		main(void)
{
	printf("%f\n", 10.6);
	printf("%f\n", 10);
	return 0;
}
