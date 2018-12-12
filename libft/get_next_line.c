/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 13:21:11 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 10:53:48 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void			register_and_free(char **result_line, char *buff)
{
	char		*box;

	box = *result_line;
	*result_line = ft_strjoin(*result_line, buff);
	ft_memdel((void **)&box);
}

static int			read_howmuch(char *box, int fd)
{
	int		last_read;

	last_read = read(fd, box, BUFF_SIZE);
	if (last_read < 0)
		return (last_read);
	box[last_read] = '\0';
	return (last_read);
}

static int			save_a_line(t_fdstore *fdstore, char **result_line, int fd)
{
	int			lecture_begun;
	char		*box_newl;
	char		*box;

	box = fdstore->storage;
	lecture_begun = 0;
	while (*box || read_howmuch(box, fd) > 0)
	{
		if ((box_newl = ft_strchr(box, '\n')))
		{
			*box_newl = '\0';
			register_and_free(result_line, box);
			ft_strcpy(box, box_newl + 1);
			return (1);
		}
		else
		{
			register_and_free(result_line, box);
			*box = 0;
			lecture_begun = 1;
		}
	}
	return (lecture_begun ? 1 : 0);
}

static t_fdstore	*get_or_create_fd(int fd, t_fdstore **start)
{
	t_fdstore			*cursor;

	if (!*start)
	{
		*start = (t_fdstore *)ft_memalloc(sizeof(t_fdstore));
		(*start)->storage = (void *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
		(*start)->fd = (size_t)fd;
		(*start)->next = NULL;
		return (*start);
	}
	cursor = *start;
	while (1)
	{
		if (cursor->fd == (size_t)fd)
			return (cursor);
		if (cursor->next == NULL)
			break ;
		cursor = cursor->next;
	}
	cursor->next = (t_fdstore *)ft_memalloc(sizeof(t_fdstore));
	cursor->next->storage = (void *)ft_memalloc(sizeof(char) * (BUFF_SIZE + 1));
	cursor->next->fd = (size_t)fd;
	cursor->next->next = NULL;
	return (cursor->next);
}

int					get_next_line(const int fd, char **result_line)
{
	t_fdstore			*proper_fd;
	static t_fdstore	*start = NULL;

	if (fd < 0 || read(fd, NULL, 0) < 0)
		return (-1);
	*result_line = ft_strdup("\0");
	proper_fd = get_or_create_fd(fd, &start);
	return (save_a_line(proper_fd, result_line, fd));
}
