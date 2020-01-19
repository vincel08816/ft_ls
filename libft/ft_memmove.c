/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:36:10 by vilee             #+#    #+#             */
/*   Updated: 2019/08/09 11:29:56 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	copies "n" bytes of src to dest
**	accounts for overflow (kinda)
*/

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*s;
	unsigned char	*d;

	if (!dest && !src && len > 0)
		return (NULL);
	s = (unsigned char*)src;
	d = (unsigned char*)dest;
	i = -1;
	if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	else
		while (++i < len)
			d[i] = s[i];
	return (d);
}
