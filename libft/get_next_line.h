/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 17:30:28 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 10:12:01 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include "libft.h"
# define BUFF_SIZE 4096

typedef struct	s_fdstore
{
	char				*storage;
	size_t				fd;
	struct s_fdstore	*next;
}				t_fdstore;

int				get_next_line(const int fd, char **line);

#endif
