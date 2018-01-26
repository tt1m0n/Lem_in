/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_digit_conv.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:56:14 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:34:04 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	conv_d_i(char *str, char **rez, va_list ap)
{
	check_size_spec(str, rez, ap);
	if (*rez == NULL && str[ft_strlen(str) - 1] != 'D')
		*rez = ft_itoa(va_arg(ap, int));
	else if (*rez == NULL && str[ft_strlen(str) - 1] == 'D')
		*rez = ft_prnt_itoall((long long)va_arg(ap, void*));
	check_precision(str, rez);
	check_min_width(str, rez);
	check_flags(str, rez);
}

static void	conv_u(char *str, char **rez, va_list ap)
{
	check_size_spec(str, rez, ap);
	if (*rez == NULL && str[ft_strlen(str) - 1] == 'u')
		*rez = ft_prnt_itoaui((unsigned int)va_arg(ap, void*));
	else if (*rez == NULL && str[ft_strlen(str) - 1] == 'U')
		*rez = ft_prnt_itoaull((unsigned long long)va_arg(ap, void*));
	check_precision(str, rez);
	check_min_width(str, rez);
	check_flags(str, rez);
}

int			check_digit_conv(char *str, va_list ap, int *n)
{
	int		i;
	int		len;
	char	*rez;

	rez = NULL;
	*n = 0;
	i = ft_strlen(str) - 1;
	if (str[i] == 'd' || str[i] == 'i' || str[i] == 'D')
		conv_d_i(str, &rez, ap);
	else if (str[i] == 'u' || str[i] == 'U')
		conv_u(str, &rez, ap);
	len = ft_strlen(rez);
	write(1, rez, len);
	ft_strclr(rez, ft_strlen(rez));
	free(rez);
	return (len);
}
