# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vjovanov <vjovanov@student.19.be>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/02 17:27:09 by vjovanov          #+#    #+#              #
#    Updated: 2018/11/10 15:20:04 by vjovanov         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME= ft_printf

LIB_NAME= libftprintf.a

SRCS= ft_printf.c
SRCS_DIR= $(addprefix srcs/, $(SRCS))
OBJ= $(subst .c,.o,$(SRCS))
INC_DIR= includes/

LIBFT_SRCS= ft_memdel.c
LIBFT_OBJ=$(subst .c,.o, $(LIBFT_SRCS))
LIBFT_OBJ_DIR=$(addprefix libft/, $(LIBFT_OBJ))

GCC= gcc
WFLAGS= -Wall -Werror -Wextra

all: $(NAME)

$(NAME):
	@make -C libft/ re
	@$(GCC) $(WFLAGS) -c $(SRCS_DIR) -I $(INC_DIR)
	@ar rc $(LIB_NAME) $(OBJ) $(LIBFT_OBJ_DIR)
	@ranlib $(LIB_NAME)

clean:
	@make -C libft/ clean
	@rm -Rf $(OBJ) $(LIBFT_OBJ_DIR)

fclean: clean
	@make -C libft/ fclean	
	@rm -Rf $(LIB_NAME)

re: fclean all