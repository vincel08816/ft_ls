/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstree.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 19:41:10 by vilee             #+#    #+#             */
/*   Updated: 2020/01/19 01:15:19 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*	tree functions */

t_lsnode	*ls_createnode(char *tmp, char *path)
{
	t_lsnode *new;

	new = NULL;
	if (!(new = (t_lsnode*)malloc(sizeof(t_lsnode))))
		return (NULL);
	new->name = tmp;
	new->path = path;
	new->full_path = build_path(tmp, path);
	if ((lstat(new->full_path, &(new->stat)) == -1))
	{
		ft_putstr("fuck lstat T_T");
		return (0);
	}
	new->is_dir = 0;
	new->left = 0;
	new->right = 0;
	return (new);
}

void	ls_insertnode(t_lsnode **root, t_lsnode *insert)
{
	if (*root == NULL)
	{
		*root = insert;
		return ;
	}
	if (g_flags.ls_sortcmp(*root, insert) < 0)
		ls_insertnode(&((*root)->right), insert);
	else 
		ls_insertnode(&((*root)->left), insert);
}

void	ls_freetree(t_lsnode *tmp)
{
	if (tmp == NULL)
		return ;
	if (tmp->left)
		ls_freetree(tmp->left);
	if (tmp->right)
		ls_freetree(tmp->right);
	free(tmp->full_path);
	free(tmp);
}
