/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:19:32 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/21 21:06:53 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	set_precision_len(int precision, char *tmp)
{
	if (precision <= ft_strclen(tmp, ' '))
		return (-3);
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

	if (ft_atoll(data->precision) > MAX_FIELD_WIDTH ||
		ft_atoll(data->precision) < 0)
		return (0);
	precision = ft_atoi(data->precision);
	tmp = data->value_format;
	i = (ft_strnequ(tmp, "0x", 2)) ? 2 : 0;
	if ((length = set_precision_len(precision, &(tmp[i])) + i) < 0)
		return (1);
	if (!(data->value_format = ft_strnew(length)))
		return (0);
	ft_memset(data->value_format, '0', (size_t)length);
	if (i == 2)
		ft_strncpy(data->value_format, "0x", 2);
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

	if ((id = has_flag("#", data->flags)) >= 0 && !ft_strequ(data->value, "0"))
		if (!(hexa_hashtag_flag(data, id)))
			return (0);
	if ((id = has_flag("-", data->flags)) >= 0)
		if (!(generic_minus_flag(data, id)))
			return (0);
	if ((id = has_flag("0", data->flags)) >= 0 && data->precision == NULL)
		if (!(hexa_zero_flag(data, id)))
			return (0);
	if ((id = has_flag("0", data->flags)) >= 0 && data->precision != NULL)
		if (!(data->min_field_width = ft_strdup(&(data->flags[id][1]))))
			return (0);
	return (1);
}

int		convert_hexa(t_data *data)
{
	char *nb;
	char *tmp;

	nb = ft_ulltoa_base(ft_atoull(data->value), 16);
	data->value_format = nb;
	tmp = NULL;
	if (data->precision != NULL && ft_strequ(data->precision, "0")
		&& ft_strequ(data->value, "0"))
	{
		tmp = data->value_format;
		data->value_format = ft_strdupwc(tmp, '0');
		ft_strdel(&tmp);
		if (data->value_format == NULL)
			return (0);
	}
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