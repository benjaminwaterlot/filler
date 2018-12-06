# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 10:13:41 by bwaterlo          #+#    #+#              #
#    Updated: 2018/12/06 11:04:04 by bwaterlo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		filler

CFLAGS	+=		-Wall\
				-Wextra\
				-Werror\
				-I $(LIBFT_DIR)

CC		=		gcc

SRCS	=		filler.c\
				board.c\
				helpers.c\

LIBFT_DIR =		libft/

LIBFT_PATH =	$(LIBFT_DIR)libft.a

OBJS=			$(SRCS:.c=.o)

.PHONY: all clean fclean re

$(NAME): $(OBJS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT_PATH) -I $(LIBFT_DIR)
	@echo "Filler compilated."

all: $(NAME)

clean:
	@rm -f $(OBJS)
	@echo "Objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@echo "Executable cleaned."

re: fclean all

t: all
	@cat test | ./filler