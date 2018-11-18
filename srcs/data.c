/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:05:40 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/18 12:54:14 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		set_data_to_null(t_data *data, int *first)
{
	int i;

	i = -1;
	*first = 0;
	while (++i < NB_FLAGS + 1)
		data->flags[i] = NULL;
	i = -1;
	while (++i < NB_CONVERSION_FLAGS + 1)
		data->conversion_flags[i] = NULL;
	data->precision = NULL;
	data->min_field_width = NULL;
	data->s_fmt = NULL;
	data->value_format = NULL;
}

void			set_data(t_data *data)
{
	int i;
	static int first = 1;

	i = -1;
	data->identifier = 0;
	if (!first)
	{
		while (++i < NB_FLAGS + 1)
			ft_strdel(&(data->flags[i]));
		i = -1;
		while (++i < NB_CONVERSION_FLAGS + 1)
			ft_strdel(&(data->conversion_flags[i]));
		ft_strdel(&(data->precision));
		ft_strdel(&(data->min_field_width));
		ft_strdel(&(data->s_fmt));
		ft_strdel(&(data->value_format));
		//ft_memdel(&(data->value));
	}
	else
		set_data_to_null(data, &first);
}

static int		fill_data_extend(t_data *data, va_list ap, int i)
{
	int ret;

	ret = 0;
	if ((ret = is_precision((const char*)&(data->s_fmt[i]))) > 0)
		data->precision = fill_precision(&(data->s_fmt[i]), ap ,ret);
	else if ((ret = is_min_field_width((const char*)&(data->s_fmt[i]))) > 0)
		data->min_field_width = fill_field_width(
			&(data->s_fmt[i]), ap ,ret);
	else if ((ret = is_identifier(data->s_fmt[i])) > 0)
		data->identifier = fill_id(&(data->s_fmt[i]), data, ap);
	return (ret);
}

/*
** i[0] = i
** i[1] = j
** i[2] = k
** i[3] = ret
*/

void			fill_data(t_data *data, va_list ap)
{
	int		i[4];
	char	*tmp;

	ft_intset(i, 4, 0);
	i[0] = 1;
	tmp = NULL;
	while (data->s_fmt[i[0]])
	{
		if ((i[3] = is_flag((const char*)&(data->s_fmt[i[0]]))) > 0)
		{
			if ((tmp = fill_flags(&(data->s_fmt[i[0]]), ap ,i[3])) != NULL)
				data->flags[i[1]++] = tmp;
		}
		else if ((i[3] = is_conversion_flag(
			(const char*)&(data->s_fmt[i[0]]))) > 0)
		{
			if ((tmp = fill_conv_flags(&(data->s_fmt[i[0]]), i[3])) != NULL)
				data->conversion_flags[i[2]++] = tmp;
		}
		else
			i[3] = fill_data_extend(data, ap, i[0]);
		i[0] += i[3];
	}
	caster(data, ap);
	tmp = NULL;
}