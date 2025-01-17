# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 17:27:09 by vjovanov          #+#    #+#              #
#    Updated: 2018/11/21 21:41:48 by vjovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_printf

LIB_NAME= libftprintf.a

# SOURCE FILES

SRCS= ft_printf.c fill_data.c data.c config_checker.c config.c sub_checker.c \
		dispatcher.c set_type.c formatting.c
SRCS_DIR= $(addprefix srcs/, $(SRCS))

#OBJ
OBJ= $(subst .c,.o,$(SRCS))

#####

# SOURCES CONVERSION FUNCTION

SRCS_CONVERT = convert_char.c convert_double.c convert_hexa.c convert_int.c \
				convert_hexa_upper.c convert_octal.c convert_pointer.c \
				convert_string.c convert_unsigned.c convert_percent.c \
				convert_binary.c
SRCS_CONVERT_DIR= $(addprefix srcs/convert/, $(SRCS_CONVERT))

#OBJ
OBJ_CONVERT = $(subst .c,.o, $(SRCS_CONVERT))

#####

# SOURCES FLAGS FUNCTION

SRCS_FLAGS = flags.c generic_flags.c min_field_width.c octal_flags.c \
			 hexa_flags.c binary_flags.c binary_flags_ext.c

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
			ft_uitoa.c ft_dtoa/ft_dtoa.c ft_ldtoa/ft_ldtoa.c ft_strcmp.c \
			ft_atoi.c ft_isalpha.c ft_isdigit.c ft_islower.c ft_isupper.c \
			ft_isspace.c ft_memcpy.c ft_strncpy.c ft_ulltoa_base.c ft_atoull.c \
			ft_strclen.c ft_strtoupper.c ft_toupper.c ft_strchr.c ft_strndup.c \
			ft_atoll.c ft_putstr.c ft_putchar.c ft_dtoa/ft_dtoa_ext.c \
			ft_ldtoa/ft_ldtoa_ext.c ft_strreplace.c ft_strdupwc.c \
			ft_strremove.c ft_lltoa_base.c ft_strcpy.c ft_initarray.c
LIBFT_SRCS_DIR=$(addprefix libft/srcs/, $(LIBFT_SRCS))

#OBJ
LIBFT_OBJ=$(notdir $(subst .c,.o, $(LIBFT_SRCS)))
LIBFT_OBJ_DIR=$(addprefix libft/, $(LIBFT_OBJ))

#####

INC_DIR= includes/
INC_DIR_LIBFT= -Ilibft/includes -Ilibft/srcs/ft_dtoa/ -Ilibft/srcs/ft_ldtoa/

GCC= gcc
WFLAGS= -Wall -Werror -Wextra

GCCBBLUE=\033[1;91m
GCCPRESET=\033[0m

all: $(NAME)

$(NAME):
	@make --no-print-directory -C libft/
	@$(GCC) $(WFLAGS) -c $(SRCS_DIR) $(SRCS_CONVERT_DIR) $(LIBFT_SRCS_DIR) $(SRCS_FLAGS_DIR) -I $(INC_DIR) $(INC_DIR_LIBFT)
	@echo "Compilation des sources $(GCCBBLUE)<ft_printf>$(GCCPRESET)..."
	@ar rc $(LIB_NAME) $(OBJ) $(LIBFT_OBJ_DIR) $(OBJ_CONVERT) $(OBJ_FLAGS)
	@echo "Creation de la librairie $(GCCBBLUE)<ft_printf>$(GCCPRESET)..."
	@ranlib $(LIB_NAME)
	@echo "Indexation de la librairie $(GCCBBLUE)<ft_printf>$(GCCPRESET)..."

clean:
	@make --no-print-directory -C libft/ clean
	@rm -Rf $(OBJ) $(LIBFT_OBJ) $(OBJ_CONVERT) $(OBJ_FLAGS)
	@echo "Suppression des fichiers objet $(GCCBBLUE)<ft_printf>$(GCCPRESET)..."

fclean: clean
	@make --no-print-directory -C libft/ fclean	
	@rm -Rf $(LIB_NAME)
	@echo "Suppression de la librairie $(GCCBBLUE)<ft_printf>$(GCCPRESET)..."

re: fclean all

.PHONY : all clean fclean re $(NAME)