/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_double.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 16:19:46 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 15:24:29 by vjovanov         ###   ########.fr       */
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
	printf("%s\n", number);
	return (number);

}
//ERREUR \0 A LA FIN ?????
static int	precision(t_data *data)
{
	char	*tmp;
	char	*temp;
	int		precision;

	if (ft_atoi(data->precision) > MAX_FIELD_WIDTH)
		return (0);
	precision = ft_atoi(data->precision);
	ft_pow(&(data->value[ft_strclen(data->value, '.')]), precision);
	if ((tmp = ft_strnew(precision)) == NULL)
		return (0);
	ft_memset(tmp, '0', precision);
	ft_memcpy(tmp, ft_strchr(data->value, '.') + 1, precision);
	printf("PRECISION %d\n", precision);
	printf("TMP : %s\n", tmp);
	printf("strlen(tmp) : %d\n", (int)ft_strlen(tmp));
	if ((temp = ft_strndup(data->value_format,
		ft_strclen(data->value_format, '.') + 1)) == NULL)
		return (0);
	free(data->value_format);
	if ((data->value_format = ft_strjoin(temp, tmp)) == NULL)
		return (0);
	return (1);
}	
/*
static int	precision(t_data *data)
{
	char	*tmp;
	int		precision;
	int		length;

	if (ft_atoi(data->precision) > MAX_FIELD_WIDTH)
		return (0);
	tmp = ft_strchr(data->value, '.');
		return (0);
	precision = ft_atoi(data->precision);
	if ((length = set_precision_len(precision, tmp)) < 0)
		return (1);
	if (!(data->value_format = ft_strnew(length)))
		return (0);
	ft_memset(data->value_format, '0', (size_t)length);
	if (length == precision + i)
		ft_memcpy(&(data->value_format[(precision + i) - ft_strclen(&(tmp[i]), ' ')]),
			&(tmp[i]), ft_strclen(&(tmp[i]), ' '));
	else if (length == ft_strlen(tmp))
		ft_memcpy(&(data->value_format[(precision + i) - ft_strclen(&(tmp[i]), ' ')]),
			&(tmp[i]), ((length - precision) - i) + ft_strclen(&(tmp[i]), ' '));
	return (1);
}
*/
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
	printf("DATAAAA : %s\n", data->value_format);
	if (data->precision != NULL)
		if (!(precision(data)))
			return (0);
	if (data->min_field_width != NULL)
		if (!(min_field_width(data)))
			return (0);
	return (1);
}