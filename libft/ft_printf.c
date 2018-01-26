/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/13 18:37:54 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 23:05:25 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_format(const char *s, va_list ap)
{
	int i;
	int ret;

	i = 0;
	ret = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '%')
		{
			i++;
			i = check_conversion(s, i, ap, &ret);
			if (ret < 0)
				return (-1);
		}
		if (s[i] != '\0' && s[i] != '%')
		{
			write(1, &s[i++], 1);
			ret++;
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	va_start(ap, format);
	ret = check_format(format, ap);
	va_end(ap);
	if (ret == -1)
		return (-1);
	else
		return (ret);
}
