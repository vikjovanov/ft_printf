/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:20:07 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/17 11:57:14 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** {identifier, *accepted_flags, *accepted_conversion_flags,
**  pointer to the conversion function, value_type}
*/

const char			*g_flags = {
	"#", "0", "+", "-", " "
};

const char			*g_conversion_flags = {
	"hh", "h", "ll", "l", "L"
};

const t_config		g_identifiers[NB_IDENTIFIERS] = {
	{'c', {"#", "0", "+", "-", " "}, {}, &convert_char, "char"},
	{'s', {"#", "0", "+", "-", " "}, {}, &convert_string, "string"},
	{'p', {"#", "0", "+", "-", " "}, {}, &convert_pointer, "void*"},
	{'d', {"#", "0", "+", "-", " "}, {"hh", "h", "ll", "l"}, &convert_int, "int"},
	{'i', {"#", "0", "+", "-", " "}, {"hh", "h", "ll", "l"}, &convert_int, "int"},
	{'o', {"#", "0", "+", "-", " "}, {"hh", "h", "ll", "l"}, &convert_octal, "unsigned int"},
	{'u', {"#", "0", "+", "-", " "}, {"hh", "h", "ll", "l"}, &convert_unsigned, "unsigned int"},
	{'x', {"#", "0", "+", "-", " "}, {"hh", "h", "ll", "l"}, &convert_hexa, "unsigned int"},
	{'X', {"#", "0", "+", "-", " "}, {"hh", "h", "ll", "l"}, &convert_hexa_upper, "unsigned int"},
	{'f', {"#", "0", "+", "-", " "}, {"l", "L"}, &convert_double, "double"},
};


int		is_identifier(char c)
{
	int i;

	i = 0;
	while (i < NB_IDENTIFIERS)
	{
		if (g_identifiers[i].identifier == c)
			return (1);
		i++;
	}
	return (0);
}

int		is_flag(char *c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	if (*c == '0' || *c == '-')
	{
		if (c[j + 1] == '*')
			return (2);
		while((ft_isdigit(c[j + 1]) && *c != '\0'))
			j++;
		return (j + 1);
	}
	while (i < NB_FLAGS)
	{
		if (*c == g_flag[i])
			return (1);
		i++;
	}
	return (0);
}

int		is_conversion_flag(char *c)
{
	int i;
	size_t length;

	i = 0;
	while (i < NB_CONVERSION_FLAGS)
	{
		length = ft_strlen(g_conversion_flags[i]);
		if (ft_strncmp(c, g_conversion_flags[i], length) == 0)
			return ((int)length);
		i++;
	}
	return (0);
}

int		is_precision(char *c)
{
	int nb_digits;

	nb_digits = 0;
	if (*c == '.')
	{
		if (*(c + 1) == '*')
			return (2);
		while (ft_isdigit(*(c + 1)))
			nb_digits++;
		return (nb_digits);
	}
	return (-1);
}

int		is_min_field_width(char *c)
{
	int i;

	i = 0;
	if (*c == '*')
		return (1);
	while (ft_isdigit(*c) && *c != '\0')
		i++;
	return (i);
}