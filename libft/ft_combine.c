/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_combine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 15:16:11 by vilee             #+#    #+#             */
/*   Updated: 2019/09/05 15:16:17 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	basically ft_strjoin but it frees the original sum string.
*/

char	*ft_combine(char *sum, char *append)
{
	size_t len;

	len = ft_strlen(sum) + ft_strlen(append);
	sum = char_remalloc(sum, len);
	len = ft_strlen(append);
	ft_strncat(sum, append, len);
	return (&sum[0]);
}
