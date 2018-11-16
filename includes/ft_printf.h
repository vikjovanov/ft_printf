/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:21:51 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/16 20:39:26 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h> // A SUPPRIMER
# include "../libft/includes/libft.h"

# define NB_FLAGS 10
# define NB_IDENTIFIERS 10

typedef struct 	s_data
{
	char		identifier;
	char		*flags[NB_FLAGS];
	int 		precision;
	int 		min_field_width;
	void		*value;
	void		*value_format;
}				t_data;

typedef struct 	s_config
{
	char		identifier;
	char		*accepted_flags[NB_FLAGS];
	char		*(*f)(t_data);
	char		*value_type;
}				t_config;

int		ft_printf(const char *format, ...);

#endif