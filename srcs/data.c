/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   data.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 22:05:40 by bjovanov          #+#    #+#             */
/*   Updated: 2018/11/17 18:32:03 by vjovanov         ###   ########.fr       */
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
		ft_memdel(&(data->value));
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

void			fill_data(t_data *data, va_list ap)
{
	int i;
	int j;
	int k;
	int ret;
	char *tmp;

	i = 1;
	j = 0;
	k = 0;
	ret = 0;
	tmp = NULL;
	while (data->s_fmt[i])
	{
		if ((ret = is_flag((const char*)&(data->s_fmt[i]))) > 0 &&
			(tmp = fill_flags(&(data->s_fmt[i]), ap ,ret)) != NULL)
			data->flags[j++] = tmp;
		else if ((ret = is_conversion_flag((const char*)&(data->s_fmt[i]))) > 0 &&
			(tmp = fill_conv_flags(&(data->s_fmt[i]), ret)) != NULL)
			data->conversion_flags[k++] = tmp;
		else 
			ret = fill_data_extend(data, ap, i);
		i += ret;
	}
	tmp = NULL;
}