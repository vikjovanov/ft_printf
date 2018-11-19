/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:38:06 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/18 23:38:06 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_int(t_data *data, va_list ap)
{
	if (ft_strequ(data->conversion_flags[0], "h"))
	{
		if ((data->value = ft_stoa(va_arg(ap, short))) == NULL)
			exit(EXIT_FAILURE);
	}
	else if (ft_strequ(data->conversion_flags[0], "hh"))
	{
		if ((data->value = ft_ctoa(va_arg(ap, signed char))) == NULL)
			exit(EXIT_FAILURE);
	}
	else if (ft_strequ(data->conversion_flags[0], "l"))
	{
		if ((data->value = ft_ltoa(va_arg(ap, long))) == NULL)
			exit(EXIT_FAILURE);
	}
	else if (ft_strequ(data->conversion_flags[0], "ll"))
	{
		if ((data->value = ft_lltoa(va_arg(ap, long long))) == NULL)
			exit(EXIT_FAILURE);
	}
	else
	{
		if ((data->value = ft_itoa(va_arg(ap, int))) == NULL)
			exit(EXIT_FAILURE);
	}
}

void	set_unsigned_int(t_data *data, va_list ap)
{
	if (ft_strequ(data->conversion_flags[0], "h"))
	{
		if ((data->value = ft_ustoa(va_arg(ap, unsigned short))) == NULL)
			exit(EXIT_FAILURE);
	}
	else if (ft_strequ(data->conversion_flags[0], "hh"))
	{
		if ((data->value = ft_uctoa(va_arg(ap, unsigned char))) == NULL)
			exit(EXIT_FAILURE);
	}
	else if (ft_strequ(data->conversion_flags[0], "l"))
	{
		if ((data->value = ft_ultoa(va_arg(ap, unsigned long))) == NULL)
			exit(EXIT_FAILURE);
	}
	else if (ft_strequ(data->conversion_flags[0], "ll"))
	{
		if ((data->value = ft_ulltoa(va_arg(ap, unsigned long long))) == NULL)
			exit(EXIT_FAILURE);
	}
	else
	{
		if ((data->value = ft_uitoa(va_arg(ap, unsigned int))) == NULL)
			exit(EXIT_FAILURE);
	}
}

void	set_char(t_data *data, va_list ap)
{
	if ((data->value = ft_strnew(1)) == NULL)
		exit(EXIT_FAILURE);
	data->value[0] = va_arg(ap, char);
}

void	set_double(t_data *data, va_list ap)
{
	if (ft_strequ(data->conversion_flags[0], "l"))
	{
		if ((data->value = ft_dtoa(va_arg(ap, double))) == NULL)
			exit(EXIT_FAILURE);
	}
	else if (ft_strequ(data->conversion_flags[0], "L"))
	{
		if ((data->value = ft_ldtoa(va_arg(ap, long double))) == NULL)
			exit(EXIT_FAILURE);
	}
	else
	{
		if ((data->value = ft_dtoa(va_arg(ap, double))) == NULL)
			exit(EXIT_FAILURE);
	}
}
