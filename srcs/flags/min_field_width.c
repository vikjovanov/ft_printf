/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_field_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 14:27:23 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/20 14:27:24 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int 	min_field_width(t_data *data)
{
	char *tmp;
	int  length;
	int  min_width;

	min_width = ft_atoi(data->min_field_width);
	if (min_width > MAX_FIELD_WIDTH)
		return (0);
	length = (min_width < (int)ft_strlen(data->value_format)) ?
		(int)ft_strlen(data->value_format) : min_width;
	tmp = data->value_format;
	if (!(data->value_format = ft_strnew(length)))
		return (0);
	ft_memset(data->value_format, ' ', length);
	ft_memcpy(&(data->value_format[length - (int)ft_strlen(tmp)]),
		tmp, ft_strlen(tmp));
	return (1);
}
