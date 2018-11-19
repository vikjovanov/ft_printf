/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispatcher.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 23:02:41 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/18 23:02:42 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"
int
unsigned int
char
char*
void*
double

void	dispatcher(t_data *data, va_list ap)
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
	else if (ft_strequ(get_identifiers()[i].value_type, "char*"))
		data->value = va_arg(ap, char*);
	else if (ft_strequ(get_identifiers()[i].value_type, "void*"))
		data->value = va_arg(ap, void*);
	else if (ft_strequ(get_identifiers()[i].value_type, "double"))
		set_double(data, ap);
	get_identifiers()[i].f(data);	
}
