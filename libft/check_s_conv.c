/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_s_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:04:06 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:39:11 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*write_string(va_list ap)
{
	char	*p;
	char	*tmp;
	int		len;

	p = NULL;
	tmp = va_arg(ap, char*);
	if (!tmp)
		return (0);
	len = ft_strlen(tmp);
	if (!(p = (char*)malloc(sizeof(char) * len + 1)))
		return (0);
	ft_memcpy(p, tmp, len + 1);
	return (p);
}

static void		writenull_for_s(char **rez)
{
	if (!(*rez = (char*)malloc(sizeof(char) * 7)))
		return ;
	(*rez)[0] = '(';
	(*rez)[1] = 'n';
	(*rez)[2] = 'u';
	(*rez)[3] = 'l';
	(*rez)[4] = 'l';
	(*rez)[5] = ')';
	(*rez)[6] = '\0';
}

int				check_s_conv(char *str, va_list ap, int *n)
{
	int		len;
	char	*rez;

	rez = NULL;
	*n = 0;
	if (ft_prnt_strstr(str, "l") || str[ft_strlen(str) - 1] == 'S')
		read_unicode_string(str, &rez, ap);
	else
	{
		if (!(rez = write_string(ap)))
			writenull_for_s(&rez);
	}
	if (rez == NULL)
	{
		ft_putstr("(null)");
		return (6);
	}
	check_precision(str, &rez);
	check_min_width(str, &rez);
	check_flags(str, &rez);
	len = ft_strlen(rez);
	write(1, rez, len);
	ft_strclr(rez, len);
	free(rez);
	return (len);
}
