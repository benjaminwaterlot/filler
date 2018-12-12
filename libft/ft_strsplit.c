/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 09:55:18 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/09 10:26:53 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_length(const char *string, char sep)
{
	size_t	i;

	i = 0;
	while (string[i] && string[i] != sep)
		i++;
	return (i);
}

static size_t	ft_word_count(const char *string, char sep)
{
	size_t	i;
	size_t	words;

	i = 0;
	words = 0;
	while (string[i])
	{
		while (string[i] && string[i] == sep)
			i++;
		if (string[i])
			words++;
		i += ft_word_length(&string[i], sep);
	}
	return (words);
}

char			**ft_strsplit(const char *s, char sep)
{
	size_t	i;
	size_t	current_word;
	char	**table;

	if (!s)
		return (NULL);
	table = (char **)ft_memalloc(sizeof(char *) * (ft_word_count(s, sep) + 1));
	if (!table)
		return (NULL);
	i = 0;
	current_word = 0;
	while (s[i])
	{
		while (s[i] && s[i] == sep)
			i++;
		if (s[i])
		{
			table[current_word] = ft_strsub(s, i, ft_word_length(&s[i], sep));
			current_word++;
			i += ft_word_length(&s[i], sep);
		}
	}
	return (table);
}
