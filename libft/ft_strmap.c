/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:59:34 by vilee             #+#    #+#             */
/*   Updated: 2019/08/10 17:59:36 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	make a cpy of a string which has the function applied to it
*/

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*str;
	size_t	len;

	if (s && f)
	{
		len = ft_strlen(s);
		str = ft_strnew(len);
		while (len-- > 0 && str)
			str[len] = f(s[len]);
		return (str);
	}
	return (NULL);
}
