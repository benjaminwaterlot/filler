/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:12:17 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 17:01:19 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void		save_coords(t_coords *coords, int line, int col, int is_valid)
{
	coords->line = line;
	coords->col = col;
	coords->is_valid = is_valid;
}

int			fit(char board, char piece)
{
	if (is_enemy(board) && piece == '*')
		return (9);
	if (is_ally(board) && piece == '*')
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
				piece->value[line + piece->start_line][col + piece->start_col]);
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
	int			line;
	int			col;
	t_coords	*results;
	int			current_score;

	line = -1;
	results = (t_coords *)ft_memalloc(sizeof(t_coords));
	results->score = -1000000000;
	results->is_valid = 0;
	while (++line + piece->height <= board->height)
	{
		col = -1;
		while (++col + piece->width <= board->width)
			if (try_match(board, piece, line, col))
			{
				current_score = get_score(board, piece, line, col);
				if (current_score > results->score)
				{
					save_coords(results, line - piece->start_line,
								col - piece->start_col, 1);
					results->score = current_score;
				}
			}
	}
	return (results);
}

t_coords	*fill_board(t_board *board, t_piece *piece)
{
	t_coords	*coords;

	coords = find_place(board, piece);
	return (coords);
}
