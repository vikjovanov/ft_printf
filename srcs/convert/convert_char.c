/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:18:56 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 15:24:33 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int char_min_field_width(t_data *data)
{
	char *tmp;
	int  length;
	int  min_width;

	min_width = ft_atoi(data->min_field_width)
		+ ((int)ft_strlen(data->value) - 1);
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

static int	char_minus_flag(t_data *data, int flag_id)
{
	int 	value;
	int 	length;
	char 	*tmp;

	value = ft_atoi(&(data->flags[flag_id][1]))
	+ ((int)ft_strlen(data->value) - 1);
	tmp = (data->value_format == NULL) ? data->value : data->value_format;
	if (value < 0 || value > MAX_FIELD_WIDTH)
		return (0);
	if (value <= (int)ft_strlen(tmp))
		length = (int)ft_strlen(tmp);
	else
		length = value;
	if ((data->value_format = (char*)malloc(sizeof(char)
		* (length + 1))) == NULL)
		return (0);
	data->value_format[length] = '\0';
	ft_memset(data->value_format, 32, (size_t)length);
	ft_memcpy(data->value_format, tmp, ft_strlen(tmp));
	return (1);
}


static int		flags(t_data *data)
{
	int id;

	if ((id = has_flag("-", data->flags)) >= 0)
		if (!(char_minus_flag(data, id)))
			return (0);
	if (data->value_format == NULL)
		if ((data->value_format = ft_strdup(data->value)) == NULL)
			return (0);
	return (1);	
}

int				convert_char(t_data *data)
{
	if (!flags(data))
		return (0);
	if (data->min_field_width != NULL)
		if (!(char_min_field_width(data)))
			return (0);
	return (1);
}