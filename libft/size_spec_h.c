/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_spec_h.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:50:03 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 18:50:05 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	size_spec_h(char *str, char **rez, va_list ap)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'd' || str[i] == 'i')
		*rez = ft_prnt_itoas((short)va_arg(ap, void*));
	else if (str[i] == 'u')
		*rez = ft_prnt_itoaus((unsigned short)va_arg(ap, void*));
	else if (str[i] == 'o')
		*rez = ft_prnt_itoaus_octhex((unsigned short)va_arg(ap, void*), 8, 0);
	else if (str[i] == 'x')
		*rez = ft_prnt_itoaus_octhex((unsigned short)va_arg(ap, void*), 16, 0);
	else if (str[i] == 'O')
		*rez = ft_prnt_itoaus_octhex((unsigned short)va_arg(ap, void*), 8, 1);
	else if (str[i] == 'X')
		*rez = ft_prnt_itoaus_octhex((unsigned short)va_arg(ap, void*), 16, 1);
}
