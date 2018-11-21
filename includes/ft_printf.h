/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:21:51 by vjovanov          #+#    #+#             */
/*   Updated: 2018/11/21 22:00:21 by vjovanov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdio.h> // A SUPPRIMER
# include "../libft/includes/libft.h"

# define MAX_FIELD_WIDTH 2147483614
# define NB_CONVERSION_FLAGS 5
# define NB_FLAGS 5
# define NB_IDENTIFIERS 10

typedef struct 	s_data
{
	char		identifier;
	char		*flags[NB_FLAGS + 1];
	char		*conversion_flags[NB_CONVERSION_FLAGS + 1];
	char 		*precision;
	char		*min_field_width;
	char		*value_format;	
	char		*value;
	char		*s_fmt;
}				t_data;

typedef struct 	s_config
{
	char		identifier;
	char		*accepted_flags[NB_FLAGS];
	char		*accepted_conversion_flag[NB_CONVERSION_FLAGS];
	int			(*f)(t_data*);
	char		*value_type;
}				t_config;

int				ft_printf(const char *format, ...);
char			*fill_conv_flags(char *s_fmt, int ret);
char			*fill_precision(char *s_fmt, va_list ap, int ret);
char			*fill_field_width(char *s_fmt, va_list ap, int ret);
char			*fill_flags(char *s_fmt, va_list ap, int ret);
int				fill_data(t_data *data, va_list ap);
char			fill_id(char *s_fmt);
int				is_acceptable_flag(char identifier, char flag);
int				is_acceptable_conv_flag(char identifier, char *flag, int len);
int				is_identifier(const char c);
int				is_flag(const char *c);
int				is_conversion_flag(const char *c);
int				is_precision(const char *c);
int				is_min_field_width(const char *c);
const t_config	*get_identifiers();
const char		**get_flags();
const char		**get_conversion_flags();
int				has_flag(char *flag, char **flags);
void			set_data(t_data *data);
void			free_data(t_data *data);
int				check_sub(const char *sub);
int				dispatcher(t_data *data, va_list ap);
void			set_int(t_data *data, va_list ap);
void			set_unsigned_int(t_data *data, va_list ap);
void			set_char(t_data *data, va_list ap);
void			set_double(t_data *data, va_list ap);


int				convert_char(t_data *data);
int				convert_double(t_data *data);
int				convert_hexa(t_data *data);
int				convert_hexa_upper(t_data *data);
int				convert_int(t_data *data);
int				convert_octal(t_data *data);
int				convert_pointer(t_data *data);
int				convert_string(t_data *data);
int				convert_unsigned(t_data *data);

int				generic_minus_flag(t_data *data, int flag_id);
int				generic_plus_flag(t_data *data, int flag_id);
int				generic_zero_flag(t_data *data, int flag_id);
int				generic_space_flag(t_data *data, int flag_id);
int 			min_field_width(t_data *data);

int				octal_hashtag_flag(t_data *data, int flag_id);
int				hexa_hashtag_flag(t_data *data, int flag_id);
int				hexa_zero_flag(t_data *data, int flag_id);
int				double_hashtag_flag(t_data *data, int flag_id);

#endif