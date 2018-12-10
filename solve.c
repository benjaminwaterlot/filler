/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:12:17 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/10 11:55:03 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

t_coords	*make_coords(int line, int col)
{
	t_coords	*coords;

	coords = (t_coords *)ft_memalloc(sizeof(t_coords));
	coords->line = line;
	coords->col = col;
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

int			try_match(t_board *board, t_board *piece, int s_line, int s_col)
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
			overlapings += fit(board->value[s_line + line][s_col + col], piece->value[line][col]);
			if (overlapings > 1)
				return (0);
			col++;
		}
		line++;
	}
	return (overlapings == 1) ? 1 : 0;
}

t_coords	*find_place(t_board *board, t_board *piece)
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
				return (make_coords(line, col));
			col++;
		}
		line++;
	}
	return (NULL);
}

t_coords	*fill_board(t_board *board, t_board *piece)
{
	t_coords	*coords;

	coords = (t_coords *)ft_memalloc(sizeof(t_coords));
	coords = find_place(board, piece);
	return (coords);
}