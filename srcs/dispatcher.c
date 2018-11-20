/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:02:41 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 18:30:38 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		dispatcher(t_data *data, va_list ap)
{
	int i;

	i = 0;
	while (data->identifier != get_identifiers()[i].identifier)
		i++;
	if (ft_strequ(get_identifiers()[i].value_type, "int"))
		set_int(data, ap);
	else if (ft_strequ(get_identifiers()[i].value_type, "unsigned int"))
		set_unsigned_int(data, ap);
	else if (ft_strequ(get_identifiers()[i].value_type, "char"))
		set_char(data, ap);
	else if (ft_strequ(get_identifiers()[i].value_type, "string"))
		data->value = ft_strdup(va_arg(ap, char*));
	else if (ft_strequ(get_identifiers()[i].value_type, "void*"))
		data->value = ft_ulltoa((unsigned long long)va_arg(
			ap, unsigned long long));
	else if (ft_strequ(get_identifiers()[i].value_type, "double"))
		set_double(data, ap);
	if (data->value == NULL)
		return (0);
	if (!(get_identifiers()[i].f(data)))
		return (0);
	return (1);	
}
