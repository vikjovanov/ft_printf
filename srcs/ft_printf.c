/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bjovanov <bjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:11:46 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/17 10:20:09 by bjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** NAME:
** 	ft_printf
**
** DESCRIPTION:
**	ft_print() affiche a l'ecran la chaine de caractere 'format' avec les 
**	differents parametres recus.
**
** SYNOPSIS:
**	int ft_printf(const char *format, ...)
**
** PARAMS:
** 	format - La chaine de caractere a formater
**	... - parametres permettant le formatage de la chaine de caractere
**
** RETURN VALUE:
**	(int) le nombre de caractere ecrits. Si une erreur est survenue, 
**	retourne une valeur negative.
*/
#include <stdio.h>
#include <stdarg.h>

int		check_sub(const char *sub)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while(sub[i])
	{
		if ((ret = is_flag(&sub[i])) == 0 &&
			(ret = is_conversion_flag(&sub[i])) == 0 &&
			(ret = is_precision(&sub[i])) == -1 &&
			(ret = is_min_field_width(&sub[i])) == 0)
			return (0);
		i += ret;
	}
	return (1);
}

void	formatting(const char *format, t_data *data, va_list ap)
{
	int i;
	char *sub;

	i = 1;
	while (!is_identifier(format[i]) && format[i])
		i++;
	if ((sub = ft_strsub(format, 1, i - 1)) == NULL)
	{
		ft_strdel(&data);
		exit(EXIT_FAILURE);
	}
	data.sub_format = sub;
	if(check_sub((const char*)sub))
		fill_data(data, ap);
	else
		data.value_format = sub;

}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	t_data	data;
	char	*str;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			formatting(format[i], &data, ap);
		}
	}
	va_end(ap);

	return 0;
}

int		main()
{
	ft_printf("Test : %s suivi de %d avec un %#.32u et un autre % hola les gens", "Salut");
	return 0;
}