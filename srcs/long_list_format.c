/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_list_format.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/18 18:24:53 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:51:46 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

/*	ls long list format	*/

/*
**	what do these files mean?
*/

static char		ls_filetype(t_lsnode *a)
{
	if (S_ISREG(a->stat.st_mode))
		return ('-');
	else if (S_ISDIR(a->stat.st_mode))
		return ('d');
	else if (S_ISCHR(a->stat.st_mode))
		return ('c');
	else if (S_ISBLK(a->stat.st_mode))
		return ('b');
	else if (S_ISFIFO(a->stat.st_mode))
		return ('p');
	else if (S_ISLNK(a->stat.st_mode))
		return ('l');
	else if (S_ISSOCK(a->stat.st_mode))
		return ('s');
	return (0);
}

/*
** research the data inside this thingy
*/

static void		ls_chmod(t_lsnode *a, char *buff)
{
	buff[0] = ls_filetype(a);
	buff[1] = (a->stat.st_mode & S_IRUSR ? 'r' : '-');
	buff[2] = (a->stat.st_mode & S_IWUSR ? 'w' : '-');
	buff[3] = (a->stat.st_mode & S_IXUSR ? 'x' : '-');
	buff[4] = (a->stat.st_mode & S_IRGRP ? 'r' : '-');
	buff[5] = (a->stat.st_mode & S_IWGRP ? 'w' : '-');
	buff[6] = (a->stat.st_mode & S_IXGRP ? 'x' : '-');
	buff[7] = (a->stat.st_mode & S_IROTH ? 'r' : '-');
	buff[8] = (a->stat.st_mode & S_IWOTH ? 'w' : '-');
	buff[9] = (a->stat.st_mode & S_IXOTH ? 'x' : '-');
	if (listxattr(a->path, NULL, 0, XATTR_NOFOLLOW) > 0)
		buff[10] = '@';
	else
		buff[10] = ' ';
}


void		print_long(t_lsnode *a)
{
	char	buff[12];
	char	*owner;
	char	*group;
	char	*time;

	ls_chmod(a, buff);
	owner = getpwuid(a->stat.st_uid)->pw_name;
	group = getgrgid(a->stat.st_gid)->gr_name;
	ft_printf("%.10s%3d %-9s %-6s", buff, a->stat.st_nlink, group, owner);
	if (!S_ISBLK(a->stat.st_mode) && !S_ISCHR(a->stat.st_mode))
		ft_printf("%6lld ", a->stat.st_size);
	else
		ft_printf("%4u, %4u", major(a->stat.st_rdev), minor(a->stat.st_rdev));
	time = ft_strdup(ctime(&(a->stat.st_mtime)));
	time[16] = '\0';
	ft_printf("%s %s\n", time + 4, a->name);
}
