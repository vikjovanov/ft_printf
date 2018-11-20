# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 17:27:09 by vjovanov          #+#    #+#              #
#    Updated: 2018/11/21 00:10:19 by vjovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_printf

LIB_NAME= libftprintf.a

# SOURCE FILES

SRCS= ft_printf.c fill_data.c data.c config_checker.c config.c sub_checker.c \
		dispatcher.c set_type.c 
SRCS_DIR= $(addprefix srcs/, $(SRCS))

#OBJ
OBJ= $(subst .c,.o,$(SRCS))

#####

# SOURCES CONVERSION FUNCTION

SRCS_CONVERT = convert_char.c convert_double.c convert_hexa.c convert_int.c \
				convert_hexa_upper.c convert_octal.c convert_pointer.c \
				convert_string.c convert_unsigned.c
SRCS_CONVERT_DIR= $(addprefix srcs/convert/, $(SRCS_CONVERT))

#OBJ
OBJ_CONVERT = $(subst .c,.o, $(SRCS_CONVERT))

#####

# SOURCES FLAGS FUNCTION

SRCS_FLAGS = flags.c generic_flags.c min_field_width.c octal_flags.c \
			 hexa_flags.c

SRCS_FLAGS_DIR= $(addprefix srcs/flags/, $(SRCS_FLAGS))

#OBJ
OBJ_FLAGS = $(subst .c,.o, $(SRCS_FLAGS))

#####

# SOURCES LIBFT

LIBFT_SRCS= ft_intset.c ft_strsub.c ft_strjoin.c ft_isdigit.c \
			ft_strlen.c ft_strncmp.c ft_strnequ.c ft_itoa.c \
			ft_strnew.c ft_memset.c ft_strdup.c ft_memalloc.c ft_strdel.c \
			ft_memdel.c ft_array_length.c ft_strequ.c ft_stoa.c ft_ctoa.c \
			ft_ltoa.c ft_lltoa.c ft_ustoa.c ft_uctoa.c ft_ultoa.c ft_ulltoa.c \
			ft_uitoa.c ft_dtoa.c ft_ldtoa.c ft_strcmp.c ft_atoi.c ft_isalpha.c \
			ft_isdigit.c ft_islower.c ft_isupper.c ft_isspace.c ft_memcpy.c \
			ft_strncpy.c ft_ulltoa_base.c ft_atoull.c ft_strclen.c \
			ft_strtoupper.c ft_toupper.c
LIBFT_SRCS_DIR=$(addprefix libft/srcs/, $(LIBFT_SRCS))

#OBJ
LIBFT_OBJ=$(subst .c,.o, $(LIBFT_SRCS))
LIBFT_OBJ_DIR=$(addprefix libft/, $(LIBFT_OBJ))

#####

INC_DIR= includes/
INC_DIR_LIBFT= libft/includes

GCC= gcc
WFLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make --no-print-directory -C libft/ re
	@$(GCC) -c $(SRCS_DIR) $(SRCS_CONVERT_DIR) $(LIBFT_SRCS_DIR) $(SRCS_FLAGS_DIR) -I $(INC_DIR) -I $(INC_DIR_LIBFT)
	@ar rc $(LIB_NAME) $(OBJ) $(LIBFT_OBJ_DIR) $(OBJ_CONVERT) $(OBJ_FLAGS)
	@ranlib $(LIB_NAME)

clean:
	@make --no-print-directory -C libft/ clean
	@rm -Rf $(OBJ) $(LIBFT_OBJ) $(OBJ_CONVERT) $(OBJ_FLAGS)

fclean: clean
	@make --no-print-directory -C libft/ fclean	
	@rm -Rf $(LIB_NAME)

re: fclean all