/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:18:29 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/21 21:07:22 by vjovanov         ###   ########.fr       */
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


// NE FONCTIONNE PLUS A RECHECK
static int	precision(t_data *data)
{
	long	precision;
	char	*tmp;
	int		id;
	long	length;

	precision = (long)ft_atoll(data->precision);
	length = 0;
	if (precision >= (int)ft_strlen(data->value))
		return (1);
	if ((id = has_flag("-", data->flags)) >= 0
		&& precision < (long)ft_atoll(&(data->flags[id][1])))
	{
		tmp = ft_strnew((long)ft_atoll(&(data->flags[id][1])));
		length = (long)ft_atoll(&(data->flags[id][1]));
	}
	else
	{
		tmp = ft_strnew(precision);
		length = precision;
	}
	ft_memset(tmp, ' ', length);
	ft_strncpy(tmp, data->value, precision);
	free(data->value_format);
	data->value_format = tmp;
	return (1);
}

int			convert_string(t_data *data)
{
	if (!(flags(data)))
		return (0);
	if (data->precision != NULL && (ft_atoll(data->precision) < MAX_FIELD_WIDTH
		&& ft_atoll(data->precision) > 0))
			if (!(precision(data)))
				return (0);
	if (data->min_field_width != NULL)
		if (!(min_field_width(data)))
			return (0);
	return (1);
}
