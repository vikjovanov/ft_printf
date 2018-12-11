/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:19:46 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/21 22:19:20 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char*	ft_pow(char *number, int precision)
{
	char *new_n;
	int n;
	int report;
	char *tmp;
	char *tmp2;

	report = 0;
	new_n = ft_strremove(number, ft_strclen(number, '.'), 1);
	n = (ft_strclen(number, '.') + precision) - 1;
	tmp = NULL;
	tmp2 = NULL;
	while (n >= 0)
	{
		if (new_n[n + 1] >= '5' || report == 1)
		{
			if ((new_n[n] + 1) > '9')
			{
				new_n[n] = '0';
				report = 1;
			}
			else
			{
				new_n[n]++;
				report = 0;
				break ;
			}
		}
		else
		{
			report = 0;
			break ;
		}
		n--;
	}
	tmp = (report == 1) ? ft_strjoin("1", new_n) : ft_strdup(new_n);
	tmp2 = ft_strjoin(ft_strndup(tmp, ft_strclen(number, '.') + report), ".");
	ft_strdel(&tmp);
	tmp = ft_strjoin(tmp2, ft_strndup(&(new_n[ft_strclen(number, '.')]), ft_strlen(&(new_n[ft_strclen(number, '.')]))));
	ft_strdel(&new_n);
	ft_strdel(&number);
	ft_strdel(&tmp2);
	return (tmp);
}
/*
static char*	ft_pow(char *number, int precision)
{
	int i;
	int prec;
	int n;
	int pow;
	int report;

	pow = 0;
	report = 0;
	prec = precision;
	n = prec + ft_strclen(number, '.');
	i = 0;
	while (pow == 0)
	{
		pow = 1;
		if (number[n + 1] >= '5')
		{
			if (number[n] == '9')
			{
				number[n] = '0';
				report = 1;
			}
			else
			{
				number[n] = number + (1 + report);
				report = 0;
			}
		}
	}
}
*/
/*
static char*	ft_pow(char *number, int precision)
{
	int	i;
	int	prec;
	int	n;

	i = 0;
	prec = precision;
	n = prec + ft_strclen(number, '.');
	while (prec > 0 && number[n] != '.')
	{
		if (number[n + 1] >= '5')
		{
			if (number[n] == '9')
				i++;
			else
			{
				number[n]++;
				break ;
			}
			prec--;
			n--;
		}
		else
			break ;
	}
	while (i >= 0)
	{
		number[(precision - i) + 1] = '0';
		i--; 
	}
	return (number);
}
*/

static int	precision(t_data *data)
{
	char			*tmp;
	char			*temp;
	int				precis;

	if (ft_atoll(data->precision) > MAX_FIELD_WIDTH ||
		ft_atoll(data->precision) < 0)
		return (0);
	precis = ft_atoi(data->precision);
	if (precis < ft_strlen(&(data->value[ft_strclen(data->value, '.') + 1])))
		data->value = ft_pow(data->value, precis);
	if ((tmp = ft_strnew(precis)) == NULL)
		return (0);
	ft_memset(tmp, '0', precis);
	if (precis > ft_strlen(&(data->value[ft_strclen(data->value, '.') + 1])))
		ft_memcpy(tmp, ft_strchr(data->value, '.') + 1,
			ft_strlen(ft_strchr(data->value, '.') + 1));
	else
		ft_memcpy(tmp, ft_strchr(data->value, '.') + 1, precis);
	if ((temp = ft_strndup(data->value,
		ft_strclen(data->value, '.') + 1)) == NULL)
		return (0);
	if ((data->value_format = ft_strjoin(temp, tmp)) == NULL)
		return (0);
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
	if ((id = has_flag("0", data->flags)) >= 0)
		if (!(generic_zero_flag(data, id)))
			return (0);
	if (data->value_format == NULL)
		if ((data->value_format = ft_strdup(data->value)) == NULL)
			return (0);
	return (1);
}

int		convert_double(t_data *data)
{
	char *tmp;

	tmp = NULL;
	if (data->precision == NULL)
		if (!(data->precision = ft_strdup("6")))
			return (0);
	if (!ft_strequ(data->value, "inf") && !ft_strequ(data->value, "-inf")
		&& !ft_strequ(data->value, "nan") && !ft_strequ(data->value, "-nan")
		&& !ft_strequ(data->value, "0"))
	{
		if (data->precision != NULL)
			if (!(precision(data)))
				return (0);
		if (ft_strequ(data->precision, "0"))
		{
			tmp = data->value_format;
			data->value_format = ft_strremove(tmp, ft_strclen(tmp, '.'), 1);
			ft_strdel(&tmp);
		}
	}

	if (!(flags(data)))
		return (0);
	if (data->min_field_width != NULL)
		if (!(min_field_width(data)))
			return (0);
	return (1);
}