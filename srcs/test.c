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


int		main(void)
{
	ft_printf("%d", 14, 16);
	return 0;
}
