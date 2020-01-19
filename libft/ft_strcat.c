/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:37:57 by vilee             #+#    #+#             */
/*   Updated: 2019/08/09 15:42:31 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, char const *src)
{
	size_t dest_len;

	dest_len = ft_strlen(dest);
	while (*src)
		dest[dest_len++] = *(src++);
	dest[dest_len] = '\0';
	return (dest);
}
