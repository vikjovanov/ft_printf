/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:11:46 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/17 18:45:37 by vjovanov         ###   ########.fr       */
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
** 
** steps[0] = flags
** steps[1] = min_field_width
** steps[2] = precision
** steps[3] = conversion_flags
*/

static int	check_sub_order(const char *sub)
{
	int steps[4];
	int i;
	int ret;

	ret = 0;
	i = 0;
	ft_intset(steps, 4, 0);
	while (sub[i] && !is_identifier(sub[i]))
	{
		if (steps[0] != 1 && (ret = is_flag(&(sub[i]))) > 0)
			ret = ret;
		else if (steps[1] != 1 && (ret = is_min_field_width(&(sub[i]))) > 0)
			ft_intset(steps, 2, 1);
		else if (steps[2] != 1 && (ret = is_precision(&(sub[i]))) > 0)
			ft_intset(steps, 3, 1);
		else if (steps[3] != 1 && (ret = is_conversion_flag(&(sub[i]))) > 0)
			ft_intset(steps, 4, 1);
		else
			return (0);
		i += ret;
	}
	return (1);
}

static int	check_sub(const char *sub)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while(sub[i] && !is_identifier(sub[i]))
	{
		if ((ret = is_flag(&(sub[i]))) == 0 &&
			(ret = is_conversion_flag(&(sub[i]))) == 0 &&
			(ret = is_precision(&(sub[i]))) == -1 &&
			(ret = is_min_field_width(&(sub[i]))) == 0)
			return (0);
		i += ret;
	}
	return (check_sub_order(sub));
}

static void	formatting(const char *format, t_data *data, va_list ap)
{
	int i;
	char *sub;

	i = 1;
	while (!is_identifier(format[i]) && format[i])
		i++;
	if ((sub = ft_strsub(format, 1, i)) == NULL ||
		(data->s_fmt = ft_strjoin("%", sub)) == NULL)
		exit(EXIT_FAILURE);	
	if(format[i] != '\0' && check_sub((const char*)sub))
		fill_data(data, ap);
	else
	{
		printf("VALEUR NON FORMATE\n");
		data->value_format = data->s_fmt;
	}

}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_data	data;
	int		i;

	i = 0;
	va_start(ap, format);
	while (format[i])
	{
		set_data(&data);
		if (format[i] == '%')
		{
			formatting(&(format[i]), &data, ap);
			break;
		}

		i++;
	}
	printf("sub_format : %s\n", data.s_fmt);
	printf("identifier : %c\n", data.identifier);
	
	int u = -1;
	printf("flags : ");
	while (data.flags[++u])
		printf("%s ", data.flags[u]);
	printf("\n");
	
	u = -1;
	printf("conversion flags : ");
	while (data.conversion_flags[++u])
		printf("%s ", data.conversion_flags[u]);
	printf("\n");
	
	printf("precision : %s\n", data.precision);
	printf("min_field_width : %s\n", data.min_field_width);
	va_end(ap);

	return 0;
}
