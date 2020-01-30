/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:44:51 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:51:46 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <dirent.h>
# include <sys/stat.h>
# include <pwd.h>
# include <uuid/uuid.h>
# include <grp.h>
# include <sys/xattr.h>
# include <time.h>
# include <errno.h>
# include <stdint.h>
# include <limits.h>
# include "libft.h"
# include <stdio.h>

# define LS_FLAG_OPTIONS "alRrt"

typedef struct		s_lsnode
{
	char			*name;
	char			*path;
	char			*full_path;
	struct stat		stat;
	int				is_dir;
	struct s_lsnode	*left;
	struct s_lsnode	*right;
}					t_lsnode;

typedef	int			t_compare(t_lsnode *insert, t_lsnode *cmp);
typedef void		t_print_format(t_lsnode *root);
typedef void		t_print_order(int *flags, t_lsnode *root);

typedef struct		s_flagfns
{
	t_compare		*ls_sortcmp;
	t_print_format	*ls_ft_printformat;
	t_print_order	*ls_traverse;
}					t_flagfns;

t_flagfns	g_flags;

/*	
**	preliminary functions
*/

int					ls_setflag(int ac, int *flags, char **av);
void				ls_checkdir(int ac, int arg, char **av, int *flags);

/*
**	ls_flag_options.c
*/

void				print_norm(t_lsnode *a);
int					ls_timecmp(t_lsnode *cmp, t_lsnode *insert);
int					ls_strcmp(t_lsnode *cmp, t_lsnode *insert);
void				print_inorder(int *flags, t_lsnode *root);
void				print_reverse(int *flags, t_lsnode *root);

/*
**	long_list_format.c
*/

void				print_long(t_lsnode *a);

/*
**	ls_tree functions
*/

t_lsnode			*ls_createnode(char *tmp, char *path);
void				ls_insertnode(t_lsnode **root, t_lsnode *insert);
void				ls_freetree(t_lsnode *tmp);

/*
**	ls main functions
*/

void				ft_ls(int *flags, char *av);
void				ft_ls_start(int *flags, char *av);
void				ft_lsbigr(int *flags, char *av);

char				*build_path(char *s, char *old_path);

#endif