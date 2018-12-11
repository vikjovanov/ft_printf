/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   formatting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/11 20:15:49 by vjovanov          #+#    #+#             */
/*   Updated: 2018/12/11 20:15:50 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	formatting(const char *format, t_data *data, va_list ap)
{
	int		i;
	char	*sub;
	char	*tmp;

	tmp = NULL;
	i = 1;
	while (!is_identifier(format[i]) && format[i])
		i++;
	if ((sub = ft_strsub(format, 1, i)) == NULL ||
		(data->s_fmt_orig = ft_strjoin("%", sub)) == NULL)
		return (0);
	if (format[i] != '\0' && (tmp = check_sub((const char*)sub)) != NULL)
	{
		if ((data->s_fmt_new = ft_strjoin("%", tmp)) == NULL)
			return (0);
		if (!(check_new_sub(data->s_fmt_new)))
			return (0);
		if (!(fill_data(data, ap)))
			return (0);
	}
	else
		data->value_format = data->s_fmt_orig;
	return (1);
}
