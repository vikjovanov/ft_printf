/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/20 23:51:51 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/20 23:59:18 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		hexa_hashtag_flag(t_data *data, int flag_id)
{
	char *tmp;

	tmp = NULL;
	if ((tmp = ft_strjoin("0x", data->value_format)) == NULL)
		return (0);
	ft_strdel(&(data->value_format));
	data->value_format = tmp;
	return (1);
}

int		hexa_zero_flag(t_data *data, int flag_id)
{
	long	value;
	long	length;
	char	*tmp;
	long	i;

	tmp = data->value_format;
	i = (ft_strnequ(tmp, "0x", 2)) ? 2 : 0;
	value = (long)ft_atoll(data->flags[flag_id]);
	length = (value <= (int)ft_strlen(tmp)) ?
		(int)ft_strlen(tmp) + i : value + i;
	if ((data->value_format =
		(char*)malloc(sizeof(char) * (length + 1))) == NULL)
		return (0);
	data->value_format[length] = '\0';
	ft_memset(data->value_format, '0', (size_t)length);
	if (i == 2)
		ft_strncpy(data->value_format, "0x", 2);
	ft_memcpy(&(data->value_format[length - (int)ft_strlen(tmp)]),
		&(tmp[i]), ft_strlen(tmp));
	return (1);
}
