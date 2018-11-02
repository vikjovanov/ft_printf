# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjovanov <vjovanov@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 17:27:09 by vjovanov          #+#    #+#              #
#    Updated: 2018/11/02 17:27:11 by vjovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_printf

LIB_NAME= libftprintf.a

SRCS= ft_printf.c
SRCS_DIR= $(addprefix srcs/, $(SRCS))
OBJ= $(subst .c,.o,$(SRCS))
INC_DIR= includes/

LIBFT_SRCS= ft_memdel.c
LIBFT_SRCS_DIR= $(addprefix libft/srcs/, $(LIBFT_SRCS))
LIBFT_OBJ=$(subst .c,.o, $(LIBFT_SRCS))

GCC= gcc
WFLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@$(GCC) $(WFLAGS) -c $(SRCS_DIR) $(LIBFT_SRCS_DIR) -I $(INC_DIR)
	@ar rc $(LIB_NAME) $(OBJ) $(LIBFT_OBJ)
	@ranlib $(LIB_NAME)

clean:
	@rm -Rf $(OBJ) $(LIBFT_OBJ)

fclean: clean	
	@rm -Rf $(LIB_NAME)

re: fclean all