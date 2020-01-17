/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/16 14:41:37 by vilee             #+#    #+#             */
/*   Updated: 2019/08/16 14:41:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	create a new list.
**	no content so constent size is 0
**	memcpy.... basically the same concept as strcpy
*/

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->content = NULL;
	new->content_size = 0;
	if (content)
	{
		if (!(new->content = ft_memalloc(content_size)))
		{
			free(new);
			return (NULL);
		}
		ft_memcpy(new->content, (void*)content, content_size);
		new->content_size = content_size;
	}
	new->next = NULL;
	return (new);
}
