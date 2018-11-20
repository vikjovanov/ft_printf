/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:19:12 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/20 23:41:50 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_precision_len(int precision, char *tmp)
{
	if (precision <= ft_strclen(tmp, ' '))
		return (-2);
	else
	{
		if (precision >= ft_strlen(tmp))
			return (precision);
		else
			return ((int)ft_strlen(tmp));
	}
	return (0);
}

static int	precision(t_data *data)
{
	char	*tmp;
	int		precision;
	int		length;
	int		i;

	if (ft_atoi(data->precision) > MAX_FIELD_WIDTH)
		return (0);
	tmp = data->value_format;
	i = (tmp[0] == '-' || tmp[0] == '+' || tmp[0] == ' ') ? 1 : 0;
	precision = ft_atoi(data->precision);
	if ((length = set_precision_len(precision, &(tmp[i])) + i) < 0)
		return (1);
	if (!(data->value_format = ft_strnew(length)))
		return (0);
	ft_memset(data->value_format, '0', (size_t)length);
	if (tmp[0] == '-' || tmp[0] == '+' || tmp[0] == ' ')
		data->value_format[0] = tmp[0];
	if (length == precision + i)
		ft_memcpy(&(data->value_format[(precision + i) - ft_strclen(&(tmp[i]), ' ')]),
			&(tmp[i]), ft_strclen(&(tmp[i]), ' '));
	else if (length == ft_strlen(tmp))
		ft_memcpy(&(data->value_format[(precision + i) - ft_strclen(&(tmp[i]), ' ')]),
			&(tmp[i]), ((length - precision) - i) + ft_strclen(&(tmp[i]), ' '));
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
	if ((id = has_flag("0", data->flags)) >= 0 && data->precision != NULL)
		if (!(data->min_field_width = ft_strdup(&(data->flags[id][1]))))
			return (0);
	if (data->value_format == NULL)
		if ((data->value_format = ft_strdup(data->value)) == NULL)
			return (0);
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