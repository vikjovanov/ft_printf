/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 13:47:31 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/18 14:00:36 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*fill_conv_flags(char *s_fmt, int ret)
{
	char	*res;

	res = NULL;
	if (!(is_acceptable_conv_flag(s_fmt[(int)ft_strlen(s_fmt) - 1],
		s_fmt, ret)))
		return (NULL);
	if ((res = ft_strsub(s_fmt, 0, ret)) == NULL)
		exit(EXIT_FAILURE);
	return (res);
}

char		*fill_precision(char *s_fmt, va_list ap, int ret)
{
	int		star;
	char	*res;

	star = 0;
	res = NULL;
	if (ret == 1)
	{
		if ((res = ft_strdup("0")) == NULL)
			exit(EXIT_FAILURE);
		return (res);
	}
	if (s_fmt[ret - 1] == '*')
	{
		star = (int)va_arg(ap, int);
		if ((res = ft_itoa(star)) == NULL)
			exit(EXIT_FAILURE);
		return (res);
	}
	if ((res = ft_strsub(s_fmt, 1, ret - 1)) == NULL)
		exit(EXIT_FAILURE);
	return (res);
}

char		*fill_field_width(char *s_fmt, va_list ap, int ret)
{
	int		star;
	char	*res;

	star = 0;
	res = NULL;
	if (*s_fmt == '*')
	{
		star = (int)va_arg(ap, int);
		if ((res = ft_itoa(star)) == NULL)
			exit(EXIT_FAILURE);
		return (res);
	}
	if ((res = ft_strsub(s_fmt, 0, ret)) == NULL)
		exit(EXIT_FAILURE);
	return (res);
}

char		*fill_flags(char *s_fmt, va_list ap, int ret)
{
	int		star;
	char	*res;

	star = 0;
	res = NULL;
	if (!(is_acceptable_flag(s_fmt[(int)ft_strlen(s_fmt) - 1], s_fmt[0])))
		return (NULL);
	if (s_fmt[ret - 1] == '*')
	{
		star = (int)va_arg(ap, int);
		if ((res = ft_strjoin(ft_strsub(s_fmt, 0, 1), ft_itoa(star))) == NULL)
			exit(EXIT_FAILURE);
		return (res);
	}
	if ((res = ft_strsub(s_fmt, 0, ret)) == NULL)
		exit(EXIT_FAILURE);
	return (res);
}

char		fill_id(char *s_fmt, t_data *data, va_list ap)
{
	char id;

	id = s_fmt[0];
	return (id);
}