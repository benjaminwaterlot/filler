# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/06 10:13:41 by bwaterlo          #+#    #+#              #
#    Updated: 2018/12/12 16:13:17 by bwaterlo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=		bwaterlo.filler

CFLAGS	+=		-Wall				\
				-Wextra				\
				-Werror				\
				-g					\
				-I $(LIBFT_DIR)		\

CC		=		gcc

SRCS	=		filler.c			\
				board.c				\
				helpers.c			\
				solve.c				\
				get_score.c			\
				is_ally_or_enemy.c	\

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
	@make clean -C $(LIBFT_DIR)
	@echo "Filler objects cleaned."

fclean: clean
	@rm -f $(NAME)
	@make fclean -C $(LIBFT_DIR)
	@echo "Filler executable cleaned."

re: fclean all

test_1: $(NAME)
	@echo "Launching tests"
	@./resources/filler_vm -f ./resources/maps/map02 -p1 ./resources/players/carli.filler -p2 ./$(NAME)

test_2: $(NAME)
	@echo "Launching tests"
	@./resources/filler_vm -f ./resources/maps/map01 -p1 ./$(NAME) -p2 ./$(NAME)

