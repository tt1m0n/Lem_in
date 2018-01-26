/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 17:24:50 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/10 13:13:32 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

char	*ft_itoa(int n);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
void	*ft_memalloc(size_t size);
void	ft_putchar(char c);
void	ft_putstr(char const *s);
void	ft_strclr(char *s, int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_atoi(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memcpy(void *dst, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strcpy(char *dst, const char *src);

int		ft_printf(const char *format, ...);
char	*ft_prnt_itoaui(unsigned int n);
int		ft_prnt_strstr(const char *haystack, const char *needle);
char	*ft_prnt_strjoin_prsn(int size, char const *s2);
char	*ft_prnt_strjoin_width(int size, char const *s2);
char	*ft_prnt_replace_spc(char const *str);
char	*ft_prnt_strjoin_smb(char const *s, char c);
char	*ft_prnt_add_zero(char const *str);
char	*ft_prnt_space_flag(char const *str);
char	*ft_prnt_itoall(long long n);
char	*ft_prnt_itoaull(unsigned long long n);
char	*ft_prnt_itoaus(unsigned short n);
char	*ft_prnt_itoas(short n);
char	*ft_prnt_itoa_intmax(intmax_t n);
char	*ft_prnt_itoa_uintmax(uintmax_t n);
char	*ft_prnt_itoa_sizet(size_t n);
char	*ft_prnt_itoaui_octhex(unsigned int n, int base, int x);
char	*ft_prnt_itoaus_octhex(unsigned short n, int base, int x);
char	*ft_prnt_itoaull_octhex(unsigned long long n, int base, int x);
char	*ft_prnt_itoauimax_octhex(uintmax_t n, int base, int x);
char	*ft_prnt_smsharp(const char *str);
char	*ft_prnt_bgsharp(const char *str);
char	*ft_prnt_prs_str(int len, char const *str);
char	*ft_prnt_addsharp(char const *s, char c);
void	*ft_prnt_memalloc(size_t size);
char	*ft_prnt_sharp_p(const char *str);
void	size_spec_hh(char *str, char **rez, va_list ap);
void	size_spec_ll(char *str, char **rez, va_list ap);
void	size_spec_h(char *str, char **rez, va_list ap);
void	size_spec_l(char *str, char **rez, va_list ap);
void	size_spec_j(char *str, char **rez, va_list ap);
void	size_spec_z(char *str, char **rez, va_list ap);
int		use_ss_long(char *str, char **rez, va_list ap, char *p);
void	use_ss_short(char *str, char **rez, va_list ap, char *p);
void	check_size_spec(char *str, char **rez, va_list ap);
int		check_char(char c);
void	check_precision(char *str, char **rez);
int		count_precision(char *str, char *rez);
void	check_min_width(char *str, char **rez);
void	make_minus_flag(char **rez);
void	make_plus_flag(char **rez);
void	make_zero_flag(char *str, char **rez);
void	make_space_flag(char *str, char **rez);
void	make_sharp_flag(char *str, char **rez);
void	check_flags(char *str, char **rez);
int		check_digit_conv(char *str, va_list ap, int *n);
void	check_c_conv(char *str, char **rez, va_list ap);
void	print_unicode(char *str, unsigned int n, char **rez);
int		check_inv_char(char *str, char p, int *n);
int		check_s_conv(char *str, va_list ap, int *n);
int		check_octhex_conv(char *str, va_list ap, int *n);
void	read_unicode_string(char *str, char **rez, va_list ap);
int		check_conversion(const char *s, int i, va_list ap, int *ret);

#endif
