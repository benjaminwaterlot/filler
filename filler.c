/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:20:04 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/10 13:32:48 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	t_board		*board;
	t_piece		*piece;
	t_coords	*result;
	char		player;
	char		*temp_line;

	board = NULL;
	piece = NULL;
	// open("./test", O_RDONLY);
	get_next_line(FILLER_STD, &temp_line);
	player = temp_line[10] == 1 ? 'O' : 'X';
	ft_memdel((void **)&temp_line);
	while (1)
	{
		handle_input(&board, &piece);
		result = fill_board(board, piece);
		print_coords(result);
		fflush(NULL);
		ft_memdel((void **)&board);
		ft_memdel((void **)&piece);
	}
	return (0);
}
