/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:09:03 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_uibase(va_list ap, t_var *var, int base)
{
	unsigned int	n;
	char			*s;
	char			tmp[100];

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = va_arg(ap, unsigned int);
	var->check_num = n == 0 ? 1 : 0;
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (unsigned int)base;
	}
	return (ft_strdup(s + 1));
}

char	*pf_uhbase(va_list ap, t_var *var, int base)
{
	unsigned short	n;
	char			*s;
	char			tmp[100];

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (unsigned short)va_arg(ap, int);
	var->check_num = n == 0 ? 1 : 0;
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (unsigned short)base;
	}
	return (ft_strdup(s + 1));
}

char	*pf_lbase(va_list ap, t_var *var, int base)
{
	long	n;
	char	*s;
	char	tmp[100];
	int		is_neg;

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (long)va_arg(ap, long);
	var->check_num = n == 0 ? 1 : 0;
	is_neg = (n < 0 ? 1 : 0);
	n *= (!is_neg ? 1 : -1);
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (long)base;
	}
	*s = (is_neg ? '-' : 0);
	return ((is_neg ? ft_strdup(s) : ft_strdup(s + 1)));
}

char	*pf_ulbase(va_list ap, t_var *var, int base)
{
	unsigned long	n;
	char			*s;
	char			tmp[100];

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (unsigned long)va_arg(ap, unsigned long);
	var->check_num = n == 0 ? 1 : 0;
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (unsigned long)base;
	}
	return (ft_strdup(s + 1));
}

char	*pf_llbase(va_list ap, t_var *var, int base)
{
	long long	n;
	char		*s;
	char		tmp[100];
	int			is_neg;

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (long long)va_arg(ap, long long);
	var->check_num = n == 0 ? 1 : 0;
	is_neg = (n < 0 ? 1 : 0);
	n *= (!is_neg ? 1 : -1);
	if (n < -9223372036854775807)
		return (ft_strdup("-9223372036854775808"));
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (long long)base;
	}
	*s = (is_neg ? '-' : 0);
	return ((is_neg ? ft_strdup(s) : ft_strdup(s + 1)));
}
