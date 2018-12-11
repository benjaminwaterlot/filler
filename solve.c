/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:12:17 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/11 09:43:22 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coords	*make_coords(int line, int col, int is_valid)
{
	t_coords	*coords;

	coords = (t_coords *)ft_memalloc(sizeof(t_coords));
	coords->line = line;
	coords->col = col;
	coords->is_valid = is_valid;
	return (coords);
}

int			fit(char board, char piece)
{
	if ((board == 'O' || board == 'o') && piece == '*')
		return (9);
	if (board == 'X' && piece == '*')
		return (1);
	return (0);
}

int			try_match(t_board *board, t_piece *piece, int s_line, int s_col)
{
	int		line;
	int		col;
	int		overlapings;
	
	overlapings = 0;
	line = 0;
	while (line < piece->height)
	{
		col = 0;
		while (col < piece->width)	
		{
			overlapings += fit(
				board->value[s_line + line][s_col + col],
				piece->value[line + piece->x_start][col + piece->y_start]);
			if (overlapings > 1)
				return (0);
			col++;
		}
		line++;
	}
	return (overlapings == 1) ? 1 : 0;
}

t_coords	*find_place(t_board *board, t_piece *piece)
{
	int		line;
	int		col;

	line = 0;
	while (line + piece->height <= board->height)
	{
		col = 0;
		while (col + piece->width <= board->width)
		{
			if (try_match(board, piece, line, col))
				return (make_coords(line - piece->x_start, col - piece->y_start, 1));
			col++;
		}
		line++;
	}
	return (make_coords(0, 0, 0));
}

t_coords	*fill_board(t_board *board, t_piece *piece)
{
	t_coords	*coords;

	coords = (t_coords *)ft_memalloc(sizeof(t_coords));
	coords = find_place(board, piece);
	return (coords);
}