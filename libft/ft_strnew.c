/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:00:28 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 18:00:29 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**makes a copy of a string with '\0' at the end.
*/

char	*ft_strnew(size_t size)
{
	char *str;

	if (size == 0)
		return (ft_strdup(""));
	if (!(str = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	str[size] = 0;
	while (size--)
		str[size] = 0;
	return (str);
}
