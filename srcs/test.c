/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:42:37 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/17 23:24:04 by bjovanov         ###   ########.fr       */
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
	printf("% +-45.33d\n", 14);
	return (0);
}
