/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:47:16 by vilee             #+#    #+#             */
/*   Updated: 2020/01/19 01:11:00 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	ls_flagzero(int *flags, char *options)
{
	flags['t'] = 0;
	flags['r'] = 0;
	flags['R'] = 0;
	flags['l'] = 0;
	flags['a'] = 0;
}

static void		ls_init_options(int *flags)
{
	if (flags['l'])
		g_flags.ls_printformat = &print_long;
	else
		g_flags.ls_printformat = &print_norm;
	if (flags['r'])
		g_flags.ls_traverse = &print_reverse;
	else
		g_flags.ls_traverse = &print_inorder;
	if (flags['t'])
		g_flags.ls_sortcmp = &ls_timecmp;
	else
		g_flags.ls_sortcmp = &ls_strcmp;
}

int		ls_setflag(int ac, int *flags, char **av)
{
	int		count;
	int		arg;

	ls_flagzero(flags, LS_FLAG_OPTIONS);
	arg = 0;
	while (++arg < ac && av[arg][0] == '-')
	{
		if (ft_strlen(av[arg]) == 1)
			return (arg);
		count = 1;
		while (av[arg][count] && ft_strchr(LS_FLAG_OPTIONS, av[arg][count]))
		{
			flags[av[arg][count]] = 1;
			count++;
		}
		if (av[arg][count] != 0)
		{
			printf("%s%c\nusage: ls [%s] [file ...]\n", \
			"ls: illegal option -- ", av[arg][count], LS_FLAG_OPTIONS);
			exit(1);
		}
	}
	ls_init_options(flags);
	return (arg);
}

void	ls_checkdir(int ac, int arg, char **av)
{
	DIR				*dr;

	while (++arg < ac)
	{
		if (!(dr = opendir(av[arg])))
			printf("ls: %s: No such file or directory\n", av[arg]);
	}
}
