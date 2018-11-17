/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:00:53 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/17 21:10:18 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	flag_cmp(const char *sub, int i)
{
	int		comp[2];
	int		ret;
	int		j;

	j = -1;
	ft_intset(comp, 2, 0);
	if ((ret = is_flag(&(sub[0]))) > 0)
	{
		while (sub[0] != get_identifiers()[i].accepted_flags[++j][0])
			comp[0] = j;
		j = -1;
		while (sub[ret] != get_identifiers()[i].accepted_flags[++j][0])
			comp[1] = j;
		if (comp[0] > comp[1])
			return (0);
	}
	return (1);
}

static int	check_flag_order(const char *sub, int nb_flag)
{
	char	identifier;
	int		i;
	int		ret;

	identifier = sub[ft_strlen(sub) - 1];
	i = 0;
	ret = 0;
	while (identifier != get_identifiers()[i].identifier)
		i++;
	while (nb_flag - 1 > 0)
	{
		if (!(flag_cmp(&(sub[ret]), i)))
			return (0);
		nb_flag--;
		ret = is_flag(&(sub[ret]));
	}
	return (1);
}

static int	check_sub_order(const char *sub)
{
	int steps[4];
	int i;
	int ret;
	int flag;

	ret = 0;
	i = 0;
	flag = 0;
	ft_intset(steps, 4, 0);
	while (sub[i] && !is_identifier(sub[i]))
	{
		if (steps[0] != 1 && (ret = is_flag(&(sub[i]))) > 0)
			flag++;
		else if (steps[1] != 1 && (ret = is_min_field_width(&(sub[i]))) > 0)
			ft_intset(steps, 2, 1);
		else if (steps[2] != 1 && (ret = is_precision(&(sub[i]))) > 0)
			ft_intset(steps, 3, 1);
		else if (steps[3] != 1 && (ret = is_conversion_flag(&(sub[i]))) > 0)
			ft_intset(steps, 4, 1);
		else
			return (0);
		i += ret;
	}
	return ((flag > 1) ? check_flag_order(sub, flag) : 1);
}

int			check_sub(const char *sub)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while(sub[i] && !is_identifier(sub[i]))
	{
		if ((ret = is_flag(&(sub[i]))) == 0 &&
			(ret = is_conversion_flag(&(sub[i]))) == 0 &&
			(ret = is_precision(&(sub[i]))) == -1 &&
			(ret = is_min_field_width(&(sub[i]))) == 0)
			return (0);
		i += ret;
	}
	return (check_sub_order(sub));
}
