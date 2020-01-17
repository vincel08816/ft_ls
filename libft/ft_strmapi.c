/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:59:08 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 17:59:11 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	make a cpy of a string which has the function applied to it
**	has an integer pointer
*/

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*str;
	size_t	len;

	if (s && f)
	{
		len = ft_strlen(s);
		str = ft_strnew(len);
		while (len-- > 0 && str)
			str[len] = f(len, s[len]);
		return (str);
	}
	return (NULL);
}
