/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:18:29 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 20:24:48 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flags(t_data *data)
{
	int id;

	if ((id = has_flag("-", data->flags)) >= 0)
		if (!(generic_minus_flag(data, id)))
			return (0);
	if (data->value_format == NULL)
		if ((data->value_format = ft_strdup(data->value)) == NULL)
			return (0);
	return (1);
}

static int	precision(t_data *data)
{
	int length;
	int	precision;
	char *tmp;

	precision = ft_atoi(data->precision);
	length = (precision < (int)ft_strlen(data->value_format)) ?
		precision : (int)ft_strlen(data->value_format);
	tmp = ft_strnew(length);
	ft_strncpy(tmp, data->value_format, length);
	free(data->value_format);
	data->value_format = tmp;
	return (1);
}

int			convert_string(t_data *data)
{

	if (!(flags(data)))
		return (0);
	if (data->precision != NULL)
		if (!(precision(data)))
			return (0);
	if (data->min_field_width != NULL)
		if (!(min_field_width(data)))
			return (0);
	return (1);
}