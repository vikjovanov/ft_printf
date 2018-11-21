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
	int	i;
	int	prec;

	i = 0;
	prec = precision;
	while (prec > 0 && number[prec] != '.')
	{
		if (number[prec + 1] >= '5')
		{
			if (number[prec] == '9')
				i++;
			else
			{
				number[prec]++;
				break ;
			}
			prec--;
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
		ft_pow(&(data->value[ft_strclen(data->value, '.')]), precision);
	if ((tmp = ft_strnew(precision)) == NULL)
		return (0);
	ft_memset(tmp, '0', precision);
	if (precision > ft_strlen(data->value))
		ft_memcpy(tmp, ft_strchr(data->value, '.') + 1,
			ft_strlen(ft_strchr(data->value, '.') + 1));
	else
		ft_memcpy(tmp, ft_strchr(data->value, '.') + 1, precision);
	if ((temp = ft_strndup(data->value_format,
		ft_strclen(data->value_format, '.') + 1)) == NULL)
		return (0);
	free(data->value_format);
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