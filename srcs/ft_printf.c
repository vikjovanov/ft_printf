/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:11:46 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/21 23:24:44 by vjovanov         ###   ########.fr       */
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

static int	formatting(const char *format, t_data *data, va_list ap)
{
	int i;
	char *sub;
	char *tmp;

	tmp = NULL;
	i = 1;
	while (!is_identifier(format[i]) && format[i])
		i++;

	if ((sub = ft_strsub(format, 1, i)) == NULL ||
		(data->s_fmt_orig = ft_strjoin("%", sub)) == NULL)
		return (0);
	if(format[i] != '\0' && (tmp = check_sub((const char*)sub)) != NULL)
	{
		if ((data->s_fmt_new = ft_strjoin("%", tmp)) == NULL)
			return (0);
		if (!(check_new_sub(data->s_fmt_new)))
			return (0);
		if (!(fill_data(data, ap)))
			return (0);
	}
	else
		data->value_format = data->s_fmt_orig;
	return (1);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	t_data	data;
	int		i;
	int		bytes;

	i = 0;
	bytes = 0;
	set_data(&data);
	va_start(ap, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			if (!(formatting(&(format[i]), &data, ap)))
			{
				free_data(&data);
				return (-1);
			}
			ft_putstr(data.value_format);
			if (data.identifier == 'c' && ft_strlen(data.value) > 1)
				bytes += (int)(ft_strlen(data.value_format) - 1);
			else
				bytes += (int)ft_strlen(data.value_format);
			i += (int)ft_strlen(data.s_fmt_orig) - 1;
			free_data(&data);
		}
		else
		{
			bytes++;
			ft_putchar(format[i]);
		}
		i++;
	}
	/*
	printf("\n");
	printf("======\n");
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
	printf("value : %s\n", data.value);
	printf("=======\n");
	*/
	//printf("value_format: %s\n", data.value_format);

	va_end(ap);
	return (bytes);
}
