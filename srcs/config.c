/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   config.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 15:20:07 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/16 19:22:47 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** {identifier, *accepted_flags, pointer to the conversion function, value_type}
*/

const t_config		g_identifiers[NB_IDENTIFIERS] = {
	{'c', {"#", "0", "+", "-", " "}, &convert_char, "char"},
	{'s', {"#", "0", "+", "-", " "}, &convert_string, "string"},
	{'p', {"#", "0", "+", "-", " "}, &convert_pointer, "void*"},
	{'d', {"#", "0", "+", "-", " ", "hh", "h", "l", "ll"}, &convert_int, "int"},
	{'i', {"#", "0", "+", "-", " ", "hh", "h", "l", "ll"}, &convert_int, "int"},
	{'o', {"#", "0", "+", "-", " ", "hh", "h", "l", "ll"}, &convert_octal, "unsigned int"},
	{'u', {"#", "0", "+", "-", " ", "hh", "h", "l", "ll"}, &convert_unsigned, "unsigned int"},
	{'x', {"#", "0", "+", "-", " ", "hh", "h", "l", "ll"}, &convert_hexa, "unsigned int"},
	{'X', {"#", "0", "+", "-", " ", "hh", "h", "l", "ll"}, &convert_hexa_upper, "unsigned int"},
	{'f', {"#", "0", "+", "-", " ", "l", "L"}, &convert_double, "double"},
};
