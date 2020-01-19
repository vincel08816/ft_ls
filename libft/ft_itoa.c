/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 17:28:29 by vilee             #+#    #+#             */
/*   Updated: 2019/09/02 15:33:26 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**  I'm using recursion (like putnbr) to input the digits into the string
*/

static void		translate(int n, int count, char **ret)
{
	if (n >= 10)
		translate((n / 10), count - 1, ret);
	*(*ret + (size_t)count - 1) = n % 10 + '0';
}

char			*ft_itoa(int n)
{
	int		count;
	char	*ret;

	if (n == __INT_MIN)
		return (ft_strdup("-2147483648"));
	(n >= 0) ? (count = count_digits(n)) : \
	(count = count_digits(n) + 1);
	if (!(ret = (char *)malloc(sizeof(char) * count + 1)))
		return (NULL);
	(n < 0) ? (ret[0] = '-') : 0;
	(n < 0) ? n = -n : 0;
	translate(n, count, &ret);
	ret[count] = '\0';
	return (ret);
}
