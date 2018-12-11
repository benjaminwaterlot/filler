/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:12:17 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/11 14:00:12 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	make_coords(t_coords *coords, int line, int col, int is_valid)
{
	coords->line = line;
	coords->col = col;
	coords->is_valid = is_valid;
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
	int		score;
	
	overlapings = 0;
	line = 0;
	score = 1;
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
	if (!overlapings)
		return (0);
	return (score);
}

t_coords	*find_place(t_board *board, t_piece *piece)
{
	int			line;
	int			col;
	t_coords	*results;
	// t_coords	*current;
	int			current_score;

	line = 0;
	results = (t_coords *)ft_memalloc(sizeof(t_coords));
	// current = (t_coords *)ft_memalloc(sizeof(t_coords));
	// results->is_valid = 1;
	results->score = 0;
	while (line + piece->height <= board->height)
	{
		col = 0;
		while (col + piece->width <= board->width)
		{
			current_score = try_match(board, piece, line, col);
			if (current_score > 0)
			{
				if (current_score > results->score)
				{
					make_coords(results, line - piece->x_start, col - piece->y_start, 1);
					results->score = current_score;
				}
			}
			col++;
		}
		line++;
	}
	if (!results)
		make_coords(results, 0, 0, 0);
	// make_coords(results, 0, 0, 0);
	return (results);
}

t_coords	*fill_board(t_board *board, t_piece *piece)
{
	t_coords	*coords;

	coords = find_place(board, piece);
	return (coords);
}