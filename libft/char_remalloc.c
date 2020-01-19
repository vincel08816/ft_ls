/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_remalloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 08:42:50 by vilee             #+#    #+#             */
/*   Updated: 2019/09/05 08:50:53 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	n is the new length I'm trying to allocate to
**	basically realloc but I'm creating a new memory location every time :(
*/

char	*char_remalloc(char *s, size_t n)
{
	char *ptr;

	if (!s || !n)
		return (ft_strdup(""));
	ptr = ft_strnew(n);
	ft_bzero(ptr, n + 1);
	ptr = ft_strncat(ptr, s, n);
	free(s);
	return (ptr);
}
