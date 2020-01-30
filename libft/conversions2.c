/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversions2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:09:05 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*pf_intlen3(va_list ap, t_var *var)
{
	int		check_signed;

	check_signed = !ft_strchr("ouxX", var->specifier) ? 1 : 0;
	if (!ft_strcmp("hh", var->length))
	{
		return (check_signed ? pf_hhbase(ap, var, \
		find_base(var)) : pf_uhhbase(ap, var, find_base(var)));
	}
	if (!ft_strcmp("h", var->length))
	{
		return (check_signed ? pf_hbase(ap, var, \
		find_base(var)) : pf_uhbase(ap, var, find_base(var)));
	}
	if (!ft_strcmp("l", var->length))
	{
		return (check_signed ? pf_lbase(ap, var, \
		find_base(var)) : pf_ulbase(ap, var, find_base(var)));
	}
	if (!ft_strcmp("ll", var->length))
	{
		return (check_signed ? pf_llbase(ap, var, \
		find_base(var)) : pf_ullbase(ap, var, find_base(var)));
	}
	return (!check_signed ? pf_uibase(ap, var, \
	find_base(var)) : pf_ibase(ap, var, find_base(var)));
}

char	*pf_hhbase(va_list ap, t_var *var, int base)
{
	char	n;
	char	*s;
	char	tmp[100];
	int		is_neg;

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (char)va_arg(ap, int);
	var->check_num = n == 0 ? 1 : 0;
	is_neg = (n < 0 ? 1 : 0);
	n *= (!is_neg ? 1 : -1);
	if (!n || n == -128)
		return (ft_strdup(n == -128 ? "-128" : "0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (char)base;
	}
	*s = (is_neg ? '-' : 0);
	return ((is_neg ? ft_strdup(s) : ft_strdup(s + 1)));
}

char	*pf_uhhbase(va_list ap, t_var *var, int base)
{
	unsigned char	n;
	char			*s;
	char			tmp[100];

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (unsigned char)va_arg(ap, int);
	var->check_num = n == 0 ? 1 : 0;
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (unsigned char)base;
	}
	return (ft_strdup(s + 1));
}

char	*pf_hbase(va_list ap, t_var *var, int base)
{
	short	n;
	char	*s;
	char	tmp[100];
	int		is_neg;

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = (short)va_arg(ap, int);
	var->check_num = n == 0 ? 1 : 0;
	if (n == -32768)
		return (ft_strdup("-32768"));
	is_neg = (n < 0 ? 1 : 0);
	n *= (n < 0 ? -1 : 1);
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= (short)base;
	}
	*s = (is_neg ? '-' : 0);
	return ((is_neg ? ft_strdup(s) : ft_strdup(s + 1)));
}

char	*pf_ibase(va_list ap, t_var *var, int base)
{
	int		n;
	char	*s;
	char	tmp[100];
	int		is_neg;

	ft_bzero(tmp, 100);
	s = &tmp[98];
	n = va_arg(ap, int);
	var->check_num = n == 0 ? 1 : 0;
	is_neg = (n < 0 ? 1 : 0);
	n *= (!is_neg ? 1 : -1);
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!n)
		return (ft_strdup("0"));
	while (n)
	{
		*(s--) = base_ret(n % base, var->hex_upper);
		n /= base;
	}
	*s = (is_neg ? '-' : 0);
	return ((is_neg ? ft_strdup(s) : ft_strdup(s + 1)));
}
