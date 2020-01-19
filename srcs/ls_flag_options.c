/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ls_flag_options.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:19:20 by vilee             #+#    #+#             */
/*   Updated: 2020/01/19 00:23:55 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*	ls flag options */


void	print_norm(t_lsnode *a)
{
	printf("%-25s", a->name);
}

/*	ls sort comparisions */
int		ls_timecmp(t_lsnode *cmp, t_lsnode *insert)
{
	return (insert->stat.st_mtime - cmp->stat.st_mtime);
}

int		ls_strcmp(t_lsnode *cmp, t_lsnode *insert)
{
	return (ft_strcmp(cmp->name, insert->name));
}

/*	ls traversal order */
void	print_inorder(int *flags, t_lsnode *root)
{
	if (root == NULL)
		return ;
	if (root->left)
		print_inorder(flags, root->left);
	if (root->name[0] != '.' || flags['a'])
	{
		g_flags.ls_printformat(root);
	}
	if (root->right)
		print_inorder(flags, root->right);
}

void	print_reverse(int *flags, t_lsnode *root)
{
	if (root == NULL)
		return ;
	if (root->right)
		print_reverse(flags, root->right);
	if (root->name[0] != '.' || flags['a'])
	{
		g_flags.ls_printformat(root);
	}
	if (root->left)
		print_reverse(flags, root->left);
}
