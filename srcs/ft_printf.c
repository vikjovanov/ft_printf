/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:11:46 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/17 12:12:08 by vjovanov         ###   ########.fr       */
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

/*
** steps[0] = flags
** steps[1] = min_field_width
** steps[2] = precision
** steps[3] = conversion_flags
*/
%#025.*lld
int		check_sub_order(const char *sub)
{
	int steps[4];
	int i;
	int ret;

	i = -1;
	ret = 1;
	while (++i < 4)
		steps[i] = 0;
	i = 0
	while (sub[i] && !is_identifier(sub[i]))
	{
		if (steps[0] != 1 && steps[1] != 1 &&
			(ret = is_min_field_width(sub[i])) > 0 && (steps[0] = 1))
			steps[1] = 1;
		else if (steps[2] != 1 && steps[1] == 1 && steps[0] == 1
			&& (ret = is_precision(sub[i])) > 0)
			steps[2] = 1;
		else if (steps[3] != 1 && steps[2] == 1 && steps[1] == 1
			&& steps[0] == 1&& (ret = is_conversion_flag(sub[i])) > 0)
			steps[3] = 1;
		else
			return (0);
		i += ret;
	}
	return (1);
}

int		check_sub(const char *sub)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while(sub[i] && !is_identifier(sub[i]))
	{
		if ((ret = is_flag(&sub[i])) == 0 &&
			(ret = is_conversion_flag(&sub[i])) == 0 &&
			(ret = is_precision(&sub[i])) == -1 &&
			(ret = is_min_field_width(&sub[i])) == 0)
			return (0);
		i += ret;
	}
	return (check_sub_order(sub));
}

void	formatting(const char *format, t_data *data, va_list ap)
{
	int i;
	char *sub;

	i = 1;
	while (!is_identifier(format[i]) && format[i])
		i++;
	if ((sub = ft_strsub(format, 1, i - 1)) == NULL ||
		(data.sub_format = ft_strjoin("%", sub)) == NULL)
	{
		ft_strdel(&data);
		exit(EXIT_FAILURE);
	}
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