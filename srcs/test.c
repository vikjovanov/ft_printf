/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:42:37 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/17 12:57:27 by vjovanov         ###   ########.fr       */
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
	long long int a = 50;
	printf("%*.*lld\n",65, 45, a);
	return (0);
}