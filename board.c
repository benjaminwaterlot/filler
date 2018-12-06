/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:34:11 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 17:03:35 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	get_size(char *specs, t_board *board)
{
	while (!ft_isdigit(*specs))
		specs++;
	board->height = ft_atoi(specs);
	while (ft_isdigit(*specs))
		specs++;
	board->width = ft_atoi(specs);
}

t_board	*create_board()
{
	t_board	*board;
	char	*temp_line;
	int		i;
	int		line_start;

	i = 0;
	get_next_line(3, &temp_line);
	board = (t_board *)ft_memalloc(sizeof(t_board));
	get_size(temp_line, board);
	board->value = (char **)ft_memalloc(sizeof(char *) * (board->height + 1));
	if (!ft_strncmp(temp_line, "Plateau", ft_strlen("Plateau")))
		get_next_line(3, &temp_line);
	while (i < board->height)
	{
		line_start = 0;
		get_next_line(3, &temp_line);
		while (!ft_strchr(".*OXox", temp_line[line_start]))
			line_start++;
		board->value[i] = ft_strdup(&temp_line[line_start]);
		free(temp_line);
		i++;
	}
	board->value[i] = 0;
	return (board);
}

void	handle_input(t_board **board, t_board **piece)
{
	*board = create_board();
	*piece = create_board();
}
