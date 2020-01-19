/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:08:47 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 17:18:09 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, char const *src, size_t n)
{
	size_t len;

	len = ft_strlen(dest);
	if (n <= len)
		return (n + ft_strlen(src));
	n -= (len + 1);
	while (n-- && *src)
		dest[len++] = *(src++);
	dest[len] = 0;
	return (len + ft_strlen(src));
}
