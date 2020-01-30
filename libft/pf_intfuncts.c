/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_intfuncts.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/08 20:09:07 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_iiappend2(char *print, t_var *v, t_intparse *t, char *p)
{
	if (v->flags['0'])
	{
		add_hash(v, &print);
		(ft_strchr("- +", *p)) ? *(print++) = *(p++) : 0;
		ft_memset((void*)print, '0', t->print_space);
		pf_intcats(print, v, p);
	}
	else
	{
		t->print_space ? ft_memset((void*)print, ' ', t->print_space) : 0;
		add_hash(v, &print);
		if (ft_strchr("- +", *p))
			*(print + (int)ft_strlen(print)) = *(p++);
		ft_memset((void*)print + ft_strlen(print), '0', t->print_zero);
		pf_intcats(print, v, p);
	}
}

void	pf_iiappend(char *print, t_var *v, t_intparse *t)
{
	char	*ptr;

	ptr = &(v->pre_mod[0]);
	if (v->flags['-'])
	{
		add_hash(v, &print);
		(ft_strchr("- +", *ptr)) ? *(print++) = *(ptr++) : 0;
		ft_memset((void*)print, '0', t->print_zero);
		pf_intcats(print, v, ptr);
		ft_memset((void*)(print + (int)(ft_strlen(print))), \
		' ', t->print_space);
	}
	else
		pf_iiappend2(print, v, t, ptr);
}

void	pf_intcats(char *print, t_var *v, char *ptr)
{
	if (v->check_num && !v->wp->after_dot && v->wp->dot)
	{
		if (ft_strchr("xX", v->specifier))
			(v->wp->width) ? ft_strcat(print + ft_strlen(print), " ") : 0;
		if (ft_strchr("o", v->specifier))
		{
			if (v->flags['#'])
			{
				ft_strcat(print + ft_strlen(print), ptr);
				return ;
			}
			(v->wp->width) ? ft_strcat(print + ft_strlen(print), " ") : 0;
			return ;
		}
		if (ft_strchr("diu", v->specifier))
			if (!v->wp->width && ft_strchr("+- ", v->pre_mod[0]))
				*print = v->pre_mod[0];
		return ;
	}
	else
		ft_strcat(print + ft_strlen(print), ptr);
}
