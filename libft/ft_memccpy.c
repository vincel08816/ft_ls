/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 10:04:20 by vilee             #+#    #+#             */
/*   Updated: 2019/08/09 10:04:25 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	if c is found within src, return pointer to dest at that value.
**	if out of bounds, return (NULL)
*/

void	*ft_memccpy(void *dest, void const *src, int c, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (n && i < n)
	{
		d[i] = s[i];
		if (d[i] == (unsigned char)c)
			return (d + (i + 1));
		i++;
	}
	return (NULL);
}
