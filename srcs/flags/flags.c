/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 15:28:14 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/19 19:24:34 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		has_flag(char *flag, char **flags)
{
	int i;

	i = 0;
	while (flags[i])
	{
		if (flags[i][0] == flag[0])
			return (i);
		i++;
	}
	return (-1);
}
