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

/*	for time sorting and alpha sorting */
typedef	void		s_data_gather();
/*	for long list and normal printing */
typedef void		s_print_format();

typedef struct		s_flagfns
{
	s_data_gather	*data_pull;
	s_print_format	*format;
}					t_flagfns;

typedef struct		s_lsnode
{
	char			*name;
	char			*path;
	char			*full_path;
	struct stat		*stat;
	int				is_dir;
	struct s_lsnode	*left;
	struct s_lsnode	*right;
}					t_lsnode;

void		ft_ls(int ac, int arg, int *flags, char **av);
void 		ft_ls2(int *flags, char *av);
int			ls_checkflag(int ac, int *flags, char **av);
void		ls_checkdir(int ac, int arg, int *flags, char **av);

void		ft_lsbigr(int *flags, char *av);

/*	auxiliary flag functions */
t_lsnode	*ls_createnode(char *tmp);
void		ls_insertnode(int *flags, char *tmp, t_lsnode **root);
void		ls_inserttime1(int *flags, char *tmp, t_lsnode **root);
void		ls_freetree(t_lsnode *tmp);
void		print_long(t_lsnode *a, int *flags);


#endif