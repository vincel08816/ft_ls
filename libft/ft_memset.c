/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 09:21:41 by vilee             #+#    #+#             */
/*   Updated: 2019/08/09 09:36:51 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	fills memory blocks with particular values
*/

void	*ft_memset(void *s, int c, size_t len)
{
	char *ret;

	ret = (char *)s;
	while (len--)
		*(ret++) = (unsigned char)c;
	return (s);
}
