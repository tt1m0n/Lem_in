/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_conversion.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/27 14:22:44 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/27 14:22:46 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_conversion(const char *s, int i, va_list ap, int *ret)
{
	int		j;
	int		sign;
	char	*mainstr;

	j = 0;
	sign = 1;
	mainstr = (char*)malloc(sizeof(char) * 50);
	ft_strclr(mainstr, 50);
	while (sign && s[i] != '\0')
	{
		mainstr[j++] = s[i];
		if (s[i] == 'd' || s[i] == 'D' || s[i] == 'i' ||
			s[i] == 'u' || s[i] == 'U')
			*ret = *ret + check_digit_conv(mainstr, ap, &sign);
		if (s[i] == 'o' || s[i] == 'O' || s[i] == 'x' || s[i] == 'X' ||
			s[i] == 'p' || s[i] == '%' || s[i] == 'c' || s[i] == 'C')
			*ret = *ret + check_octhex_conv(mainstr, ap, &sign);
		if (s[i] == 's' || s[i] == 'S')
			*ret = *ret + check_s_conv(mainstr, ap, &sign);
		if (check_char(s[i]))
			*ret = *ret + check_inv_char(mainstr, s[i], &sign);
		i++;
	}
	free(mainstr);
	return (i);
}
