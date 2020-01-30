/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_floats.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:16:00 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_ll(t_ulli i)
{
	int count;

	if (i == 0)
		return (1);
	count = 0;
	while (i)
	{
		i /= 10;
		count++;
	}
	return (count);
}

static float	too_big(float num)
{
	t_ulli	tmp_ulli;
	int		len;

	tmp_ulli = (t_ulli)num;
	len = count_ll(tmp_ulli);
	while (len--)
		tmp_ulli /= 10;
	num -= count_ll((t_ulli)num) * tmp_ulli;
	return (num);
}

static void		ftoa_init(t_floats *t, float *number, char *tmp)
{
	t->ret = &(tmp[500]);
	t->ret_ptr = t->ret + 1;
	ft_bzero(tmp, 1000);
	t->neg = (*number < 0) ? -1 : 1;
	*number *= t->neg;
	t->ipart = (t_ulli)*number;
	t->f = *number;
	t->ilen = count_ll(t->ipart);
}

char			*ft_ftoa(float number, int prec)
{
	t_floats	t;
	char		tmp[1000];

	t = (t_floats){0, 0, 0, 0, 0, 0, 0};
	ftoa_init(&t, &number, tmp);
	if (t.ipart)
		while (t.ipart)
			t.ipart /= \
			(*(t.ret--) = t.ipart % 10 + '0') > -1 ? 10 : 1;
	else
		*(t.ret--) = '0';
	*t.ret = t.neg == -1 ? '-' : 0;
	prec ? *(t.ret_ptr++) = '.' : 0;
	if (ft_strlen(t.ret + 1) < 8)
		while (prec--)
		{
			number *= 10;
			number = (number > 10000000 ? too_big(number) : number);
			*(t.ret_ptr++) = (t_ulli)number % 10 + '0';
		}
	else
		while (prec--)
			*(t.ret_ptr++) = '0';
	return (t.neg == 1 ? ft_strdup(t.ret + 1) : ft_strdup(t.ret));
}
