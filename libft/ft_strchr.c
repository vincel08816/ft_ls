/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/09 15:54:26 by vilee             #+#    #+#             */
/*   Updated: 2019/09/05 08:41:59 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	returns the a pointer to the first occurrence of c
**	if that pointer does not exist, return (NULL)
*/

char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != c)
		str++;
	if (!*str && c)
		return (0);
	return ((char*)str);
}
