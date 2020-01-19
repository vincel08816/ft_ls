/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 09:51:13 by vilee             #+#    #+#             */
/*   Updated: 2019/08/09 09:51:20 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	copies from src to dst without considering '\0'.
**	count is the size of the copying
**	fast for copying but doesn't have a safety for overflow
** the safe alternative would be strcpy
*/

void	*ft_memcpy(void *dst, void const *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	if (!dst && !src && n > 0)
		return (NULL);
	i = 0;
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dst);
}
