/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:11:58 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_parse(char const **s, t_var *var)
{
	int		i;
	char	*ptr;

	i = 1;
	while (ft_strchr(A_SYM, *(*s + i)) && \
	!ft_strchr(SPEC, *(*s + i)))
		i++;
	var->specifier = (ft_strchr(SPEC, *(*s + i)) ? *(*s + i) : 0);
	if (ft_strchr("OU", var->specifier))
		var->specifier = var->specifier == 'O' ? 'o' : 'u';
	ptr = p_len(p_wp(p_flg((*s + 1), var), var), var);
	if (!(var->specifier) || ptr != *s + i++)
	{
		*s += ft_strlen(*s);
		return ;
	}
	*s += i;
}

char	*p_flg(char const *s, t_var *var)
{
	int i;

	i = 0;
	while (ft_strchr(PF_FLAG, *(s + i)))
	{
		var->flags[(int)s[i]]++;
		i++;
	}
	if (ft_strchr("ouxX", var->specifier))
	{
		var->flags['+'] = 0;
		var->flags[' '] = 0;
	}
	return ((char*)&s[i]);
}

char	*p_wp(char const *s, t_var *var)
{
	int		i;
	t_width *p;

	if (!s)
		return (0);
	p = var->wp;
	i = 0;
	p->width = ft_atoi(s + i);
	while (ft_isdigit(s[i]))
		i++;
	p->dot = (s[i] == '.' ? 1 : 0);
	s[i] == '.' ? i++ : 0;
	p->after_dot = ft_atoi(s + i);
	while (ft_isdigit(s[i]))
		i++;
	return ((char*)&s[i]);
}

char	*p_len(char const *s, t_var *var)
{
	int		i;

	if (!s)
		return (0);
	i = 0;
	while (ft_strchr(PF_LENF, s[i]) && i < 4)
	{
		var->length[i] = s[i];
		i++;
	}
	return (ft_strchr(SPEC, s[i]) ? (char*)&s[i] : 0);
}
