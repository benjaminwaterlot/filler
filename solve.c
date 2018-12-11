/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 16:12:17 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/11 19:42:09 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		is_enemy(char c)
{
	return (c != '.' && c != g_game->player && c != g_game->player + 32);
}

int		is_ally(char c)
{
	return (c == g_game->player || c == g_game->player + 32);
}

void	make_coords(t_coords *coords, int line, int col, int is_valid)
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

// #include "assert.h"

// int			distance_to_enemy_score(int s_line, int s_col)
// {
// 	int		distance;

// 	(void)s_col;
// 	distance = s_line - g_game->enemy_line;
// 	distance = distance < 0 ? -distance : distance;
// 	assert(distance >= 0);
// 	return (1000 / distance);
// }

int			get_score(t_board *board, t_piece *piece, int s_line, int s_col)
{
	int		score;
	int		i;

	score = 0;
	i = 0;
	while (i < piece->width)
	{
		if (s_line > 0 && is_enemy(board->value[s_line - 1][s_col + i]))
			score += 1000;
		i++;
	}
	i = 0;
	while (i < piece->width)
	{
		if (s_line < board->height - piece->height && is_enemy(board->value[s_line + piece->height][s_col + i]))
			score += 1000;
		i++;
	}
	i = 0;
	while (i < piece->height)
	{
		if (s_col > 0 && is_enemy(board->value[s_line + i][s_col - 1]))
			score += 1000;
		if (s_col + piece->width < board->width && is_enemy(board->value[s_line + i][s_col + piece->width]))
			score += 1000;
		i++;
	}
	if (score > 0)
		return (score);
	// score += distance_to_enemy_score(s_line, s_col);
	// assert(score > 1);
	return (score);
}

t_coords	*find_place(t_board *board, t_piece *piece)
{
	int			line;
	int			col;
	t_coords	*results;
	int			current_score;

	line = 0;
	results = (t_coords *)ft_memalloc(sizeof(t_coords));
	results->score = -1;
	results->is_valid = 0;
	while (line + piece->height <= board->height)
	{
		col = 0;
		while (col + piece->width <= board->width)
		{
			if (try_match(board, piece, line, col))
			{
				current_score = get_score(board, piece, line, col);
				if (current_score > results->score)
				{
					make_coords(results, line - piece->start_line, col - piece->start_col, 1);
					results->score = current_score;
				}
			}
			col++;
		}
		line++;
	}
	return (results);
}

t_coords	*fill_board(t_board *board, t_piece *piece)
{
	t_coords	*coords;

	coords = find_place(board, piece);
	return (coords);
}