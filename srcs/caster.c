/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   caster.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 12:51:12 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/18 13:59:12 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	caster(t_data *data, va_list ap)
{
	t_config id;
	int i;

	i = 0;
	while (data->identifier != get_identifier()[i].identfier)
		i++;
	id = get_identifier()[i];
	if (ft_strequ(id.value_type, "int"))
		(int*)data.value_type = va_arg(ap, int)

}