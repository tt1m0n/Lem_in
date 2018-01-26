/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_spec_ll.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:48:44 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 18:48:46 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	size_spec_ll(char *str, char **rez, va_list ap)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'd' || str[i] == 'i')
		*rez = ft_prnt_itoall((long long)va_arg(ap, void*));
	else if (str[i] == 'u')
		*rez = ft_prnt_itoaull((unsigned long long)va_arg(ap, void*));
	else if (str[i] == 'o')
		*rez = ft_prnt_itoaull_octhex((unsigned long long)\
										va_arg(ap, void*), 8, 0);
	else if (str[i] == 'x')
		*rez = ft_prnt_itoaull_octhex((unsigned long long)\
										va_arg(ap, void*), 16, 0);
	else if (str[i] == 'O')
		*rez = ft_prnt_itoaull_octhex((unsigned long long)\
										va_arg(ap, void*), 8, 1);
	else if (str[i] == 'X')
		*rez = ft_prnt_itoaull_octhex((unsigned long long)\
										va_arg(ap, void*), 16, 1);
}
