/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sub_checker.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 21:00:53 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/21 21:45:21 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** ====================
**    LINUX VERSION
** ====================
**
** static int	flag_o_cmp(int *comp, const t_config *id)
** {
** 	while (get_flags()[comp[2]][0] != id->accepted_flags[comp[0]][0])
** 		comp[2]++;
** 	while (get_flags()[comp[3]][0] != id->accepted_flags[comp[1]][0])
** 		comp[3]++;
** 	if (comp[2] > comp[3])
** 		return (0);
** 	return (1);
** }
**
** static int	flag_cmp(const char *sub, const t_config *id)
** {
** 	int		comp[4];
** 	int		ret;
**
** 	ft_intset(comp, 4, 0);
** 	if ((ret = is_flag(&(sub[0]))) > 0 &&
** 		is_acceptable_flag(id->identifier, sub[0]) &&
** 		is_acceptable_flag(id->identifier, sub[ret]))
** 	{
** 		while (sub[0] != id->accepted_flags[comp[0]][0])
** 			comp[0]++;
** 		while (sub[ret] != id->accepted_flags[comp[1]][0])
** 			comp[1]++;
** 		if ((id->accepted_flags[comp[0]][0] == ' '
** 			&& id->accepted_flags[comp[1]][0] == '#')
** 		|| (id->accepted_flags[comp[1]][0] == ' '
**			&& id->accepted_flags[comp[0]][0] == '#'))
** 			return (1);
** 		return (flag_o_cmp(comp, id));
** 	}
** 	return (1);
** }
**
** static int	check_flag_order(const char *sub, int nb_flag)
** {
** 	char	identifier;
** 	int		i;
** 	int		ret;
**
** 	identifier = sub[ft_strlen(sub) - 1];
** 	i = 0;
** 	ret = 0;
** 	while (identifier != get_identifiers()[i].identifier)
** 		i++;
** 	while (nb_flag - 1 > 0)
** 	{
** 		if (!(flag_cmp(&(sub[ret]), get_identifiers() + i)))
** 			return (0);
** 		nb_flag--;
** 		ret = is_flag(&(sub[ret]));
** 	}
** 	return (1);
** }
**
** static int	check_sub_order(const char *sub)
** {
** 	int steps[4];
** 	int i;
** 	int ret;
** 	int flag;
**
** 	ret = 0;
** 	i = 0;
** 	flag = 0;
** 	ft_intset(steps, 4, 0);
** 	while (sub[i] && !is_identifier(sub[i]))
** 	{
** 		if (steps[0] != 1 && (ret = is_flag(&(sub[i]))) > 0)
** 			flag++;
** 		else if (steps[1] != 1 && (ret = is_min_field_width(&(sub[i]))) > 0)
** 			ft_intset(steps, 2, 1);
** 		else if (steps[2] != 1 && (ret = is_precision(&(sub[i]))) > 0)
** 			ft_intset(steps, 3, 1);
**   	else if (steps[3] != 1 && (ret = is_conversion_flag(&(sub[i]))) > 0)
** 			ft_intset(steps, 4, 1);
** 		else
** 			return (0);
** 		i += ret;
** 	}
** 	return ((flag > 1) ? check_flag_order(sub, flag) : 1);
** }
*/

/*
** ====================
**     MAC VERSION
** ====================
*/

int				check_new_sub(const char *sub)
{
	int	i;
	int	ret;

	i = 0;
	ret = 0;
	while (sub[i] && !is_identifier(sub[i]))
	{
		if ((ret = is_flag(&(sub[i]))) == 0 &&
			(ret = is_conversion_flag(&(sub[i]))) == 0 &&
			(ret = is_precision(&(sub[i]))) == -1 &&
			(ret = is_min_field_width(&(sub[i]))) == 0)
			return (0);
		i += ret;
	}
	return (1);
}

static int		find_last_index(char *sub, int j)
{
	int ret;
	int i;
	int index;

	ret = 0;
	i = 0;
	index = -1;
	while (sub[i] && !is_identifier(sub[i]))
	{
		if (sub[i] == get_flags()[j][0])
		{
			index = i;
			i += is_flag(&(sub[i]));
		}
		else if ((ret = is_flag(&(sub[i]))) != 0 ||
			(ret = is_precision(&(sub[i]))) != -1 ||
			(ret = is_conversion_flag(&(sub[i]))) != 0 ||
			(ret = is_min_field_width(&(sub[i]))) != 0)
			i += ret;
		else
			i++;
	}
	return (index);
}

static char		*remove_flags(char *sub, int j)
{
	int		ret;
	int		i;
	char	*tmp;

	i = 0;
	ret = 0;
	tmp = NULL;
	while (sub[i] && !is_identifier(sub[i]))
		if (sub[i] == get_flags()[j][0])
		{
			ret = is_flag(&(sub[i]));
			tmp = (char*)sub;
			sub = ft_strremove(tmp, i, ret);
			ft_strdel(&tmp);
		}
		else if ((ret = is_flag(&(sub[i]))) != 0 ||
			(ret = is_precision(&(sub[i]))) != -1 ||
			(ret = is_conversion_flag(&(sub[i]))) != 0 ||
			(ret = is_min_field_width(&(sub[i]))) != 0)
			i += ret;
		else
			i++;
	if (get_flags()[j][0] == '-')
		return (remove_flags(sub, j + 1));
	return (sub);
}

static char		*join_str(char *new_sub, const char *sub)
{
	char *tmp;
	tmp = NULL;
	if (!(tmp = ft_strjoin(new_sub, sub)))
		return (NULL);
	ft_strdel((char**)&sub);
	ft_strdel(&new_sub);
	return (tmp);
}

/*
** tab[0] = j
** tab[1] = index
*/

char			*check_sub(const char *sub)
{
	int		tab[2];
	char	*new_sub;
	char	*tmp;
	ft_intset(tab, 2, -1);
	tmp = NULL;
	if (!(new_sub = ft_strnew(ft_strlen(sub))))
		return (NULL);
	while (++tab[0] < NB_FLAGS)
	{
		if ((tab[1] = find_last_index((char*)sub, tab[0])) != -1)
		{
			tmp = new_sub;
			new_sub = ft_strjoin(tmp, ft_strndup(&(sub[tab[1]]),
				is_flag(&(sub[tab[1]]))));
			ft_strdel(&tmp);
			if (new_sub == NULL)
				return (NULL);
		}
		else
			continue;
		if (!(sub = remove_flags((char*)sub, tab[0])))
			return (NULL);
	}
	return (join_str(new_sub, sub));
}
