/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:09:00 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_reg_str(char *print, const char **s)
{
	int		ret;
	char	*chk;

	chk = ft_strchr(*s, '%');
	if (chk)
		ret = (int)(chk - *s);
	else
		ret = ft_strlen(*s);
	ft_strncpy(print, *s, ret);
	*s += ret;
	return (ret);
}

int		pf_spec_main(char const **s, char *print, va_list ap)
{
	t_var	var;
	char	*ptr;

	ptr = print;
	ft_bzero(print, ft_strlen(print));
	constructp(&var);
	pf_parse(s, &var);
	pf_var(print, ap, &var);
	if (ft_strchr("diouxXpb", var.specifier))
		var.ret_len = ft_strlen(ptr);
	return (var.ret_len);
}

int		ft_printf(char const *arg, ...)
{
	char const	*s;
	char		print[BUFF_SIZE];
	int			ret;
	va_list		ap;

	s = arg;
	ret = 0;
	ft_bzero(print, BUFF_SIZE);
	va_start(ap, arg);
	if (s)
	{
		while (*s)
		{
			if (*s == '%')
				ret += pf_spec_main(&s, print + ret, ap);
			else
				ret += ft_reg_str(print + ret, &s);
		}
		write(1, print, ret);
	}
	va_end(ap);
	return (ret);
}
