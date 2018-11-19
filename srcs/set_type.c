/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:38:06 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 14:01:45 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_int(t_data *data, va_list ap)
{
	if (ft_strequ(data->conversion_flags[0], "h"))
		data->value = ft_stoa(va_arg(ap, short));
	else if (ft_strequ(data->conversion_flags[0], "hh"))
		data->value = ft_ctoa(va_arg(ap, signed char));
	else if (ft_strequ(data->conversion_flags[0], "l"))
		data->value = ft_ltoa(va_arg(ap, long));
	else if (ft_strequ(data->conversion_flags[0], "ll"))
		data->value = ft_lltoa(va_arg(ap, long long));
	else
		data->value = ft_itoa(va_arg(ap, int));
}

void	set_unsigned_int(t_data *data, va_list ap)
{
	if (ft_strequ(data->conversion_flags[0], "h"))
		data->value = ft_ustoa(va_arg(ap, unsigned short));
	else if (ft_strequ(data->conversion_flags[0], "hh"))
		data->value = ft_uctoa(va_arg(ap, unsigned char));
	else if (ft_strequ(data->conversion_flags[0], "l"))
		data->value = ft_ultoa(va_arg(ap, unsigned long));
	else if (ft_strequ(data->conversion_flags[0], "ll"))
		data->value = ft_ulltoa(va_arg(ap, unsigned long long));
	else
		data->value = ft_uitoa(va_arg(ap, unsigned int));
}

void	set_char(t_data *data, va_list ap)
{
	data->value = ft_strnew(sizeof(char));
	data->value[0] = va_arg(ap, char);
}

void	set_double(t_data *data, va_list ap)
{
	if (ft_strequ(data->conversion_flags[0], "l"))
		data->value = ft_dtoa(va_arg(ap, double));
	else if (ft_strequ(data->conversion_flags[0], "L"))
		data->value = ft_ldtoa(va_arg(ap, long double));
	else
		data->value = ft_dtoa(va_arg(ap, double));
}
