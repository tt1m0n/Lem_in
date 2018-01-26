/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size_spec_hh.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:46:33 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 18:46:35 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	size_spec_hh(char *str, char **rez, va_list ap)
{
	int i;

	i = ft_strlen(str) - 1;
	if (str[i] == 'd' || str[i] == 'i')
		*rez = ft_itoa((char)va_arg(ap, void*));
	else if (str[i] == 'u')
		*rez = ft_itoa((unsigned char)va_arg(ap, void*));
	else if (str[i] == 'o')
		*rez = ft_prnt_itoaui_octhex((unsigned char)va_arg(ap, void*), 8, 0);
	else if (str[i] == 'x')
		*rez = ft_prnt_itoaui_octhex((unsigned char)va_arg(ap, void*), 16, 0);
	else if (str[i] == 'O')
		*rez = ft_prnt_itoaus_octhex((unsigned short)va_arg(ap, void*), 8, 1);
	else if (str[i] == 'X')
		*rez = ft_prnt_itoaui_octhex((unsigned char)va_arg(ap, void*), 16, 1);
}
