/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:20:04 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 16:56:32 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		main()
{
	t_board		*board;
	t_board		*piece;
	t_coords	*result;

	board = NULL;
	piece = NULL;
	open("./test", O_RDONLY);
	handle_input(&board, &piece);
	print_board(board);
	print_board(piece);
	result = fill_board(board, piece);
	print_coords(result);
	close(3);
	return (0);
}
