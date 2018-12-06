/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 11:03:55 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 13:13:23 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	print_board(char **board)
{
	int		i;

	i = 0;
	printf("\n================\n");
	printf("Current board : \n");
	printf("================\n");
	while (board[i])
	{
		printf("%s\n", board[i]);
		i++;
	}
}