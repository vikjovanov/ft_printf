/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:19:12 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/20 00:01:54 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	precision(t_data *data)
{
	char *tmp;
	int precision;
	int length;
	int i;

	if (atoi(data->precision) > MAX_FIELD_WIDTH)
		return (0);
	tmp = data->value_format;
	i = (tmp[0] == '-' || tmp[0] == '+' || tmp[0] == ' ') ? 1 : 0;
	precision = ft_atoi(data->precision);
	length = (precision <= (int)ft_strlen(tmp) - i) ? 
		(int)ft_strlen(tmp) : precision + i;
	if (!(data->value_format = ft_strnew(length)))
		return (0);
	ft_memset(data->value_format, '0', (size_t)length);
	if (tmp[0] == '-')
		data->value_format[0] = '-';
	else if (tmp[0] == '+')
		data->value_format[0] = '+';
	else if (tmp[0] == ' ')
		data->value_format[0] = ' ';
	ft_memcpy(&(data->value_format[length - (int)ft_strlen(tmp) + i]),
		&(tmp[i]), ft_strlen(tmp));
	return (1);
}

static int	flags(t_data *data)
{
	int id;

	if ((id = has_flag(" ", data->flags)) >= 0)
		if (!(generic_space_flag(data, id)))
			return (0);
	if ((id = has_flag("+", data->flags)) >= 0)
		if (!(generic_plus_flag(data, id)))
			return (0);
	if ((id = has_flag("-", data->flags)) >= 0)
		if (!(generic_minus_flag(data, id)))
			return (0);
	if ((id = has_flag("0", data->flags)) >= 0 && data->precision == NULL)
		if (!(generic_zero_flag(data, id)))
			return (0);
	if (data->value_format == NULL)
		if ((data->value_format = ft_strdup(data->value)) == NULL)
			return (0);
	return (1);
}

static int 	min_field_width(t_data *data)
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

int		convert_int(t_data *data)
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