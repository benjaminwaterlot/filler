/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bwaterlo <bwaterlo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 12:43:43 by bwaterlo          #+#    #+#             */
/*   Updated: 2018/11/12 14:46:39 by bwaterlo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t size)
{
	t_list	*element;

	element = (t_list *)ft_memalloc(sizeof(t_list));
	if (!element)
		return (NULL);
	if (content)
	{
		element->content = ft_memcpy(ft_memalloc(size), content, size);
		element->content_size = size;
	}
	else
	{
		element->content = NULL;
		element->content_size = 0;
	}
	element->next = NULL;
	return (element);
}
