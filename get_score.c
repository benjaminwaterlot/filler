/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_score.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 16:06:27 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 16:06:39 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int			touch_enemy_score(t_board *board, t_piece *piece, int line, int col)
{
	int		i;
	int		score;

	i = -1;
	score = 0;
	while (++i < piece->width)
		if (line > 0 && is_enemy(board->value[line - 1][col + i]))
			score += 1000;
	i = -1;
	while (++i < piece->width)
		if (line < board->height - piece->height
			&& is_enemy(board->value[line + piece->height][col + i]))
			score += 1000;
	i = -1;
	while (++i < piece->height)
	{
		if (col > 0 && is_enemy(board->value[line + i][col - 1]))
			score += 1000;
		if (col + piece->width < board->width
			&& is_enemy(board->value[line + i][col + piece->width]))
			score += 1000;
	}
	return (score);
}

int			distance_to_enemy_score(int s_line, int s_col)
{
	int		distance;

	if (s_line > g_game->enemy_line)
		distance = s_line - g_game->enemy_line;
	else
		distance = g_game->enemy_line - s_line;
	if (s_col > g_game->enemy_col)
		distance += s_col - g_game->enemy_col;
	else
		distance += g_game->enemy_col - s_col;
	return (distance *= -1);
}

int			get_score(t_board *board, t_piece *piece, int s_line, int s_col)
{
	int		score;

	score = 0;
	score += touch_enemy_score(board, piece, s_line, s_col);
	score += distance_to_enemy_score(s_line, s_col);
	return (score);
}
