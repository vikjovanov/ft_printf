/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:21:10 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 23:16:29 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		generic_minus_flag(t_data *data, int flag_id)
{
	int 	value;
	int 	length;
	char 	*tmp;

	value = ft_atoi(&(data->flags[flag_id][1]));
	tmp = (data->value_format == NULL) ? data->value : data->value_format;
	if (value < 0 || value > MAX_FIELD_WIDTH)
		return (0);
	if (value <= (int)ft_strlen(tmp))
		length = (int)ft_strlen(tmp);
	else
		length = value;
	if ((data->value_format = (char*)malloc(sizeof(char)
		* (length + 1))) == NULL)
		return (0);
	data->value_format[length] = '\0';
	ft_memset(data->value_format, 32, (size_t)length);
	ft_memcpy(data->value_format, tmp, ft_strlen(tmp));
	return (1);
}

int		generic_plus_flag(t_data *data, int flag_id)
{
	char *tmp;

	tmp = (data->value_format == NULL) ? data->value : data->value_format;
	if (data->value[0] == '-')
		data->value_format = tmp;
	else if (data->value[0] != '-')
	{
		if (data->value_format != NULL)
			ft_strdel(&(data->value_format));
		if ((data->value_format = ft_strjoin("+", tmp)) == NULL)
			return (0);
		tmp = NULL;
	}
	return (1);
}

int		generic_zero_flag(t_data *data, int flag_id)
{
	int 	value;
	int		length;
	char 	*tmp;
	int		i;

	tmp = (data->value_format == NULL) ? data->value : data->value_format;
	i = (tmp[0] == '-' || tmp[0] == '+' || tmp[0] == ' ') ? 1 : 0;
	value = ft_atoi(data->flags[flag_id]);
	length = (value <= (int)ft_strlen(tmp)) ? 
		(int)ft_strlen(tmp) + i : value + i;
	if ((data->value_format = (char*)malloc(sizeof(char) * (length + 1))) == NULL)
		return (0);
	data->value_format[length] = '\0';
	ft_memset(data->value_format, '0', (size_t)length);
	if (tmp[0] == '-')
		data->value_format[0] = '-';
	else if (tmp[0] == '+')
		data->value_format[0] = '+';
	else if (tmp[0] == ' ')
		data->value_format[0] = ' ';
	ft_memcpy(&(data->value_format[length - (int)ft_strlen(tmp)]),
		&(tmp[i]), ft_strlen(tmp));
	return (1);
}

int		generic_space_flag(t_data *data, int flag_id)
{
	char *tmp;

	if (has_flag("+", data->flags) >= 0)
		return (1);
	tmp = (data->value_format == NULL) ? data->value : data->value_format;
	if (tmp[0] == '-')
	{
		if (!(data->value_format = ft_strdup(tmp)))
			return (0);
	}
	else if (data->value[0] != '-')
	{
		if (data->value_format != NULL)
			ft_strdel(&(data->value_format));
		if ((data->value_format = ft_strjoin(" ", tmp)) == NULL)
			return (0);
	}
	return (1);
}