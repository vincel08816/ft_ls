/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vilee <vilee@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 10:55:52 by vilee             #+#    #+#             */
/*   Updated: 2020/01/29 16:52:44 by vilee            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdio.h>
# include <stdarg.h>
# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdint.h>
# include <float.h>
# define __INT_MIN -2147483648
# define __INT_MAX 2147483647

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *ptr, int value, size_t num);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, void const *src, size_t n);
void				*ft_memmove(void *dest, void const *src, size_t len);
void				*ft_memccpy(void *dest, void const *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(void const *s1, void const *s2, size_t n);
size_t				ft_strlen(char const *str);
char				*ft_strdup(const char *s);
char				*ft_strcpy(char *dest, char const *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, const char *src, size_t n);
size_t				ft_strlcat(char *dest, const char *src, size_t n);
char				*ft_strchr(const char *str, int c);
char				*ft_strrchr(const char *str, int c);
char				*ft_strstr (const char *s1, const char *s2);
char				*ft_strnstr (const char *s1, const char *s2, size_t n);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(const int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t t));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
long long			absolute_value(long long i);
void				set_zero(size_t *i, size_t *j, size_t *k, size_t *l);
size_t				word_len(char const *s, char c);
int					count_digits(int i);
void				ft_swap(int *a, int *b);
char				*char_remalloc(char *s, size_t n);
char				*ft_combine(char *sum, char *append);
int					ft_isspace(int ch);


/*
**	ft_printf
*/

typedef struct	s_width
{
	int			width;
	int			dot;
	int			after_dot;
	int			mem_print;
	int			str_print;
	int			tot_print;
	char		mem_s;
}				t_width;

typedef unsigned long long int	t_ulli;
typedef long long int			t_lli;

typedef struct	s_length
{
	int			if_signed;
	long long	lltmp;
	t_ulli		ulltmp;
	void		*tmp_num;
}				t_length;

typedef struct	s_intparse
{
	int			pre_pad;
	int			print_space;
	int			print_zero;
	int			pad;
	int			if_hash;
	int			len;
}				t_intparse;

typedef struct	s_floats
{
	int			ilen;
	t_ulli		ipart;
	int			neg;
	char		*ret;
	char		*ret_ptr;
	float		f;
	int			printdot;
}				t_floats;

typedef struct	s_var
{
	int			flags[127];
	char		specifier;
	t_width		wp[1];
	t_length	bs[1];
	char		length[5];
	char		pre_mod[1000];
	int			ret_len;
	int			hex_upper;
	int			base;
	char		append[1000];
	int			check_num;
}				t_var;

# define BUFF_SIZE 100000
# define SPEC "%cspdDiuUboOxXfFeEgG"
# define A_SYM "-+0 #'.123456789%cspdDiuUboOxXfFeEgGaAlhIL"
# define PF_FLAG "-+0 #'"
# define PF_LENF "lhL"
# define HASH_FLAG "aAeEfFgG"

typedef int		t_spec_funct(char *print, va_list ap, t_var *var);

int				ft_printf(char const *arg, ...);
int				ft_reg_str(char *print, const char **s);

void			pf_parse(char const **s, t_var *var);
char			*p_flg(char const *s, t_var *var);
char			*p_wp(char const *s, t_var *var);
char			*p_len(char const *s, t_var *var);

int				pf_var(char *print, va_list ap, t_var *var);
void			make_dpt(t_spec_funct *ref[127]);
int				pf_spec_c(char *print, va_list ap, t_var *var);
int				pf_spec_s(char *print, va_list ap, t_var *var);
int				pf_diouxx(char *print, va_list ap, t_var *var);
int				pf_spec_p(char *print, va_list ap, t_var *var);
int				pf_spec_f(char *print, va_list ap, t_var *var);

void			constructp(t_var *var);
void			t_length_width(char *print, t_var *var, char *s);
int				goin_fre(int ret, t_var **var);

void			di_width(char *print, t_var *var);
void			di_flags(char *print, t_var *var);

char			*lltoa_base(void *num, t_var *var, int base);
char			*ft_lltoa_base(void *num, t_var *var, int base);
char			base_ret(int n, int upper);
int				find_base(t_var *var);
char			*ft_ftoa(float number, int prec);
void			add_hash(t_var *var, char **print);

char			*pf_intlen3(va_list ap, t_var *var);
char			*pf_hhbase(va_list ap, t_var *var, int base);
char			*pf_hbase(va_list ap, t_var *var, int base);
char			*pf_uhhbase(va_list ap, t_var *var, int base);
char			*pf_uhbase(va_list ap, t_var *var, int base);
char			*pf_lbase(va_list ap, t_var *var, int base);
char			*pf_ulbase(va_list ap, t_var *var, int base);
char			*pf_llbase(va_list ap, t_var *var, int base);
char			*pf_ullbase(va_list ap, t_var *var, int base);
char			*pf_ibase(va_list ap, t_var *var, int base);

char			*pf_uibase(va_list ap, t_var *var, int base);
void			pf_int2s(char *print, t_var *v);
void			pf_iiappend(char *print, t_var *v, t_intparse *t);
void			pf_intcats(char *print, t_var *v, char *ptr);
void			pf_iiappend2(char *print, t_var *v, t_intparse *t, char *p);

#endif
