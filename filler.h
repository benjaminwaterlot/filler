/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:19:43 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 16:07:25 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# define FILLER_STD 0

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// TEMPORARY
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_game
{
	char	player;
	int		enemy_col;
	int		enemy_line;
	int		initialized;
}				t_game;

t_game		*g_game;

typedef struct	s_coords
{
	int		line;
	int		col;
	int		is_valid;
	int		score;
}				t_coords;

typedef struct	s_piece
{
	char	**value;
	int		start_line;
	int		start_col;
	int		width;
	int		height;
}				t_piece;

typedef struct	s_board
{
	char	**value;
	int		width;
	int		height;
}				t_board;

//				READER FUNCTIONS
void			handle_input(t_board **board, t_piece **piece);

//				SOLVER FUNCTIONS
t_coords		*fill_board(t_board *board, t_piece *piece);
int				is_enemy(char c);
int				get_score(t_board *board, t_piece *piece, int line, int col);

//				OUTPUT FUNCTIONS
void			print_board(t_board *board);

//				HELPER FUNCTIONS
int				full_of_digits(char *string);
void			print_coords(t_coords *coords);

#endif