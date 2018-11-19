/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:20:07 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 20:59:03 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** {identifier, *accepted_flags, *accepted_conversion_flags,
**  pointer to the conversion function, value_type}
*/

const char			*g_flags[NB_FLAGS] = {
	" ", "#", "+", "-", "0"
};

const char			*g_conversion_flags[NB_CONVERSION_FLAGS] = {
	"hh", "h", "ll", "l", "L"
};

const t_config		g_identifiers[NB_IDENTIFIERS] = {
	{'c', {"-"}, {}, &convert_char, "char"},
	{'s', {"-"}, {}, &convert_string, "string"},
	{'p', {" ", "+", "-"}, {}, &convert_pointer, "void*"},
	{'d', {" ", "+", "-", "0"}, {"hh", "h", "ll", "l"}, &convert_int, "int"},
	{'i', {" ", "+", "-", "0"}, {"hh", "h", "ll", "l"}, &convert_int, "int"},
	{'o', {"#", "-", "0"}, {"hh", "h", "ll", "l"}, &convert_octal, "unsigned int"},
	{'u', {"-", "0"}, {"hh", "h", "ll", "l"}, &convert_unsigned, "unsigned int"},
	{'x', {"#", "-", "0"}, {"hh", "h", "ll", "l"}, &convert_hexa, "unsigned int"},
	{'X', {"#", "-", "0"}, {"hh", "h", "ll", "l"}, &convert_hexa_upper, "unsigned int"},
	{'f', {" ", "#", "+", "-", "0"}, {"l", "L"}, &convert_double, "double"},
};

const char **get_flags()
{
	return (g_flags);
}

const char **get_conversion_flags()
{
	return (g_conversion_flags);
}

const t_config *get_identifiers()
{
	return (g_identifiers);
}

int		is_acceptable_flag(char identifier, char flag)
{
	int i;
	int j;

	i = 0;
	while (g_identifiers[i].identifier != identifier)
		i++;
	j = 0;
	while (j < ft_array_length((void**)g_identifiers[i].accepted_flags))
	{
		if (g_identifiers[i].accepted_flags[j][0] == flag)
			return (1);
		j++;
	}
	return (0);
}

int		is_acceptable_conv_flag(char identifier, char *flag, int len)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (g_identifiers[i].identifier != identifier)
		i++;
	while (j < ft_array_length(
		(void**)g_identifiers[i].accepted_conversion_flag))
	{
		if (ft_strnequ(g_identifiers[i].accepted_conversion_flag[j],
			flag, len))
			return (1);
		j++;
	}
	return (0);
}