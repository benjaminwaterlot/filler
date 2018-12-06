/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/06 10:34:11 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/12/06 13:33:30 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		get_height(char *specs)
{
	while (!ft_isdigit(*specs))
		specs++;
	return (ft_atoi(specs));
}

char	**create_table(char *specs)
{
	char    **table;
	char	*temp_line;
	int		i;
	int		table_height;

	i = 0;
	table_height = get_height(specs);
	table = (char **)ft_memalloc(sizeof(char *) * table_height);
	get_next_line(3, &temp_line);
	while (i < table_height)
	{
		get_next_line(3, &temp_line);
		printf("line done\n");
		while (!ft_strchr(".*OXox", *temp_line))
			temp_line++;
		table[i] = ft_strdup(temp_line);
		printf("%s\n", table[i]);
		// free(temp_line);
		i++;
	}
	table[i] = 0;
	return (table);
}

char	**create_piece(char *specs)
{
	char    **table;
	char	*temp_line;
	int		i;
	int		table_height;

	i = 0;
	table_height = get_height(specs);
	table = (char **)ft_memalloc(sizeof(char *) * table_height);
	while (i < table_height)
	{
		get_next_line(3, &temp_line);
		printf("line done\n");
		while (!ft_strchr(".*OXox", *temp_line))
			temp_line++;
		table[i] = ft_strdup(temp_line);
		printf("%s\n", table[i]);
		// free(temp_line);
		i++;
	}
	table[i] = 0;
	return (table);
}

char	**handle_input(char type)
{
	char	*current_line;
	char	**table;

	get_next_line(3, &current_line);
	if (type == 'b')
	{
		printf("SAVING BOARD.\n");
		table = create_table(current_line);
		printf("SAVED BOARD.\n");
	}
	else
	{
		printf("SAVING PIECE.\n");
		table = create_piece(current_line);
		printf("SAVED PIECE.\n");
	}
	return (table);
}
