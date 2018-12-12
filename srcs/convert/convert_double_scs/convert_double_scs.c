/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double_scs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:25:01 by vjovanov          #+#    #+#             */
/*   Updated: 2018/12/12 17:25:03 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_pow_add_e(char *new_n, int diff)
{
	char *tmp;
	char *tmp2;

	if (!(tmp = ft_strjoin(new_n, "e+")))
		return (NULL);
	ft_strdel(&new_n);
	if (diff < 10)
	{
		if(!(new_n = ft_strjoin(tmp, "0")))
			return (NULL);
		ft_strdel(&tmp);
		if (!(tmp = ft_strjoin(new_n, ft_itoa(diff))))
			return (NULL);
		ft_strdel(&new_n);
	}
	else
	{
		if (!(new_n = ft_strjoin(tmp, ft_itoa(diff))))
			return (NULL);
		ft_strdel(&tmp);
	}
	return ((tmp == NULL) ? new_n : tmp);
}


static char	*ft_pow_ext(char *number, char *new_n, int report, long precision)
{
	char	*tmp;
	char	*tmp2;
	int		diff;

	diff = (ft_strclen(number, '.') - 1) + report;
	tmp = (report == 1) ? ft_strjoin("1", new_n) : ft_strdup(new_n);
	if (tmp == NULL)
		return (NULL);
	if (!(tmp2 = ft_strjoin(ft_strndup(tmp, 1), ".")))
		return (NULL);
	ft_strdel(&tmp);
	if (!(tmp = ft_strjoin(tmp2, ft_strndup(&(new_n[1]), precision))))
		return (NULL);
	ft_strdel(&new_n);
	ft_strdel(&number);
	ft_strdel(&tmp2);
	return (ft_pow_add_e(tmp, diff));
}

static char	*ft_pow(char *number, long precision)
{
	char	*new_n;
	long	n;
	int		report;

	report = 0;
	if (!(new_n = ft_strremove(number, (int)ft_strclen(number, '.'), 1)))
		return (NULL);
	n = ((1 + precision) - 1) + 1;
	while (--n >= 0)
		if (new_n[n + 1] >= '5' || report == 1)
		{
			if ((new_n[n] + 1) > '9' && (new_n[n] = '0') == '0')
				report = 1;
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
	return (ft_pow_ext(number, new_n, report, precision));
}

/*
** int p = precision
*/

static int	precision(t_data *data)
{
	char			*tmp;
	char			*temp;
	long			p;

	if (ft_atoll(data->precision) > MAX_FIELD_WIDTH ||
		ft_atoll(data->precision) < 0)
		return (1);
	p = (long)ft_atoll(data->precision);
	if (p < (long)ft_strlen(&(data->value[ft_strclen(data->value, '.') + 1])))
		if (!(data->value = ft_pow(data->value, p)))
			return (0);
	if ((tmp = ft_strnew((size_t)p)) == NULL)
		return (0);
	if (ft_memset(tmp, '0', p) != NULL && p > (long)ft_strlen(
		&(data->value[ft_strclen(data->value, '.') + 1])))
		ft_memcpy(tmp, ft_strchr(data->value, '.') + 1,
			ft_strlen(ft_strchr(data->value, '.') + 1));
	else
		ft_memcpy(tmp, ft_strchr(data->value, '.') + 1, (size_t)p);
	if ((temp = ft_strndup(data->value,
		ft_strclen(data->value, '.') + 1)) == NULL)
		return (0);
	if ((data->value_format = ft_strjoin(temp, tmp)) == NULL)
		return (0);
	data->value_format = ft_pow_add_e(data->value_format, 0);
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

int			convert_double_scs(t_data *data)
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
		if (data->precision != NULL && !(precision(data)))
			return (0);
		if (ft_strequ(data->precision, "0") && has_flag("#", data->flags) < 0)
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