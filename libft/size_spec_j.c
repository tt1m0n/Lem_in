/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_spec_j.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:51:54 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 18:51:56 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	size_spec_j(char *str, char **rez, va_list ap)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'd' || str[i] == 'i')
		*rez = ft_prnt_itoa_intmax((intmax_t)va_arg(ap, void*));
	else if (str[i] == 'u')
		*rez = ft_prnt_itoa_uintmax((uintmax_t)va_arg(ap, void*));
	else if (str[i] == 'o')
		*rez = ft_prnt_itoauimax_octhex((uintmax_t)va_arg(ap, void*), 8, 0);
	else if (str[i] == 'x')
		*rez = ft_prnt_itoauimax_octhex((uintmax_t)va_arg(ap, void*), 16, 0);
	else if (str[i] == 'O')
		*rez = ft_prnt_itoauimax_octhex((uintmax_t)va_arg(ap, void*), 8, 1);
	else if (str[i] == 'X')
		*rez = ft_prnt_itoauimax_octhex((uintmax_t)va_arg(ap, void*), 16, 1);
}
