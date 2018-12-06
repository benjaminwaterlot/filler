/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:19:43 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 11:33:47 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libft.h"
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

//		READER FUNCTIONS
void	handle_input(char **board, char **piece);

//		SOLVER FUNCTIONS

//		OUTPUT FUNCTIONS
void	print_board(char **board);

#endif