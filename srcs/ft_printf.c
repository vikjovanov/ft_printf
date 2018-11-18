/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 18:11:46 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/18 12:15:35 by vjovanov         ###   ########.fr       */
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
	//printf("value : %d\n", *((int*)data.value));
	printf("=======\n");
	printf("\n");
	
	va_end(ap);

	return 0;
}
