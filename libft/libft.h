/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:24:50 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/29 23:53:30 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

# define BUFF_SIZE 1
# define SPACES ((s[i] == ' ') || (s[i] == '\t') || (s[i] == '\n'))
# define NOTSPACES (s[i] != ' ') && (s[i] != '\t') && (s[i] != '\n')

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

typedef struct		s_lst
{
	char			*str;
	int				fd;
	struct s_lst	*next;
}					t_lst;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void	*dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *src);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t dstsize);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
char				*ft_strnstr(const char *haystack,
								const char *needle, size_t len);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **ap);
void				ft_strclr(char *s, int n);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_itoa(int n);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
void				ft_lstadd(t_list **alst, t_list *new);
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_get_next_line(const int fd, char **line);
int					ft_mycount_words(const char *s);
void				ft_myrev(char *s);
void				ft_foreach(int *tab, int length, void (*f)(int));
int					ft_myfactor(int nb);
int					ft_mypower(int nb, int power);

int					ft_printf(const char *format, ...);
char				*ft_prnt_itoaui(unsigned int n);
int					ft_prnt_strstr(const char *haystack, const char *needle);
char				*ft_prnt_strjoin_prsn(int size, char const *s2);
char				*ft_prnt_strjoin_width(int size, char const *s2);
char				*ft_prnt_replace_spc(char const *str);
char				*ft_prnt_strjoin_smb(char const *s, char c);
char				*ft_prnt_add_zero(char const *str);
char				*ft_prnt_space_flag(char const *str);
char				*ft_prnt_itoall(long long n);
char				*ft_prnt_itoaull(unsigned long long n);
char				*ft_prnt_itoaus(unsigned short n);
char				*ft_prnt_itoas(short n);
char				*ft_prnt_itoa_intmax(intmax_t n);
char				*ft_prnt_itoa_uintmax(uintmax_t n);
char				*ft_prnt_itoa_sizet(size_t n);
char				*ft_prnt_itoaui_octhex(unsigned int n, int base, int x);
char				*ft_prnt_itoaus_octhex(unsigned short n, int base, int x);
char				*ft_prnt_itoaull_octhex(unsigned long long n,
											int base, int x);
char				*ft_prnt_itoauimax_octhex(uintmax_t n, int base, int x);
char				*ft_prnt_smsharp(const char *str);
char				*ft_prnt_bgsharp(const char *str);
char				*ft_prnt_prs_str(int len, char const *str);
char				*ft_prnt_addsharp(char const *s, char c);
void				*ft_prnt_memalloc(size_t size);
char				*ft_prnt_sharp_p(const char *str);
void				size_spec_hh(char *str, char **rez, va_list ap);
void				size_spec_ll(char *str, char **rez, va_list ap);
void				size_spec_h(char *str, char **rez, va_list ap);
void				size_spec_l(char *str, char **rez, va_list ap);
void				size_spec_j(char *str, char **rez, va_list ap);
void				size_spec_z(char *str, char **rez, va_list ap);
int					use_ss_long(char *str, char **rez, va_list ap, char *p);
void				use_ss_short(char *str, char **rez, va_list ap, char *p);
void				check_size_spec(char *str, char **rez, va_list ap);
int					check_char(char c);
void				check_precision(char *str, char **rez);
int					count_precision(char *str, char *rez);
void				check_min_width(char *str, char **rez);
void				make_minus_flag(char **rez);
void				make_plus_flag(char **rez);
void				make_zero_flag(char *str, char **rez);
void				make_space_flag(char *str, char **rez);
void				make_sharp_flag(char *str, char **rez);
void				check_flags(char *str, char **rez);
int					check_digit_conv(char *str, va_list ap, int *n);
void				check_c_conv(char *str, char **rez, va_list ap);
void				print_unicode(char *str, unsigned int n, char **rez);
int					check_inv_char(char *str, char p, int *n);
int					check_s_conv(char *str, va_list ap, int *n);
int					check_octhex_conv(char *str, va_list ap, int *n);
void				read_unicode_string(char *str, char **rez, va_list ap);
int					check_conversion(const char *s, int i,
										va_list ap, int *ret);

#endif
