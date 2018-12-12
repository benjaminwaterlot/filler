/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:20:04 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/12 17:16:40 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_enemy_position(t_game *game, t_board *board)
{
	int		i;
	int		j;

	i = 0;
	while (board->value[i])
	{
		j = 0;
		while (board->value[i][j])
		{
			if (is_enemy(board->value[i][j]))
			{
				game->enemy_line = i;
				game->enemy_col = j;
				game->initialized = 1;
				return ;
			}
			j++;
		}
		i++;
	}
}

int		record_player_name(char *player)
{
	if (ft_strlen(player) <= 13)
		return (0);
	if (player[10] == '1')
		g_game->player = 'O';
	else if (player[10] == '2')
		g_game->player = 'X';
	else if (player[10] == '3')
		g_game->player = 'C';
	else if (player[10] == '4')
		g_game->player = 'D';
	else if (player[10] == '5')
		g_game->player = 'E';
	else if (player[10] == '6')
		g_game->player = 'F';
	else
		return (0);
	return (1);
}

int		run_loop(void)
{
	t_board		*board;
	t_piece		*piece;
	t_coords	*result;

	handle_input(&board, &piece);
	if (!g_game->initialized)
		get_enemy_position(g_game, board);
	result = fill_board(board, piece);
	print_coords(result);
	ft_memdel((void **)&board);
	ft_memdel((void **)&board->value);
	ft_memdel((void **)&piece);
	ft_memdel((void **)&piece->value);
	if (!result->is_valid)
		return (0);
	ft_memdel((void **)&result);
	return (1);
}

int		main(void)
{
	char		*temp_line;

	g_game = (t_game *)ft_memalloc(sizeof(t_game));
	if (!get_next_line(FILLER_STD, &temp_line))
		return (throw_usage());
	if (!record_player_name(temp_line))
		return (throw_usage());
	ft_memdel((void **)&temp_line);
	while (run_loop())
		continue ;
	ft_memdel((void **)&g_game);
	sleep(60);
	return (0);
}
