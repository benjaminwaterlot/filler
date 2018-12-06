/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:19:43 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 16:40:11 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

// TEMPORARY
# include <stdio.h>
# include <fcntl.h>

typedef struct	s_coords
{
	int		line;
	int		col;
}				t_coords;

typedef struct	s_piece
{
	char	**value;
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
void			handle_input(t_board **board, t_board **piece);

//				SOLVER FUNCTIONS
t_coords		*fill_board(t_board *board, t_board *piece);

//				OUTPUT FUNCTIONS
void			print_board(t_board *board);

//				HELPER FUNCTIONS
int				full_of_digits(char *string);
void			print_coords(t_coords *coords);

#endif