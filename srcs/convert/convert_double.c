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
	printf("number : %s\n", number);
	while (n >= 0)
	{
		//printf("new : %c\n", new_n[n + 1]);
		if (new_n[n + 1] >= '5')
		{
			if ((new_n[n] + 1) > '9')
			{
				new_n[n] = '0';
				report = 1;
			}
			else
			{
				new_n[n] += report;
				report = 0;
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
	printf("tmp : %s\n", tmp);
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
	int				precision;

	if (ft_atoll(data->precision) > MAX_FIELD_WIDTH ||
		ft_atoll(data->precision) < 0)
		return (0);
	precision = ft_atoi(data->precision);
	if (precision < ft_strlen(data->value))
		data->value = ft_pow(data->value, precision);
	if ((tmp = ft_strnew(precision)) == NULL)
		return (0);
	ft_memset(tmp, '0', precision);
	if (precision > ft_strlen(data->value))
		ft_memcpy(tmp, ft_strchr(data->value, '.') + 1,
			ft_strlen(ft_strchr(data->value, '.') + 1));
	else
		ft_memcpy(tmp, ft_strchr(data->value, '.') + 1, precision);
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

int		convert_double(t_data *data)
{
	if (data->precision == NULL)
		if (!(data->precision = ft_strdup("6")))
			return (0);
	if (data->precision != NULL)
		if (!(precision(data)))
			return (0);
	if (!(flags(data)))
		return (0);
	if (data->min_field_width != NULL)
		if (!(min_field_width(data)))
			return (0);
	return (1);
}