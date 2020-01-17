/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 18:00:55 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 18:00:56 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	creates a substring copy of the original given string;
**	Why does this segfault?
*/

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *result;

	if ((!s) || (ft_strlen(s) < start + len))
		return (NULL);
	result = ft_strnew(len);
	while (len-- && result)
		result[len] = s[start + len];
	return (result);
}
