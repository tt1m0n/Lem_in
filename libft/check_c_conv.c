/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_c_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:57:58 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:37:24 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_c_conv(char *str, char **rez, va_list ap)
{
	if (ft_prnt_strstr(str, "l") || str[ft_strlen(str) - 1] == 'C')
		print_unicode(str, (unsigned int)va_arg(ap, void*), rez);
	else
	{
		*rez = (char*)malloc(sizeof(char) * 2);
		(*rez)[0] = (char)va_arg(ap, void*);
		(*rez)[1] = '\0';
	}
}
