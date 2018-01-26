/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_unicode.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:00:02 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 23:11:13 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_2_byte(int mask1, int n, char **rez)
{
	if (!(*rez = (char*)malloc(sizeof(char) * 3)))
		return ;
	(*rez)[0] = mask1 >> 8 | n >> 6;
	(*rez)[1] = (n & 63) | 128;
	(*rez)[2] = '\0';
}

void	print_3_byte(int mask2, int n, char **rez)
{
	if (!(*rez = (char*)malloc(sizeof(char) * 4)))
		return ;
	(*rez)[0] = mask2 >> 16 | n >> 12;
	(*rez)[1] = ((n >> 6) & 63) | 128;
	(*rez)[2] = (n & 63) | 128;
	(*rez)[3] = '\0';
}

void	print_4_byte(int mask3, int n, char **rez)
{
	if (!(*rez = (char*)malloc(sizeof(char) * 4)))
		return ;
	(*rez)[0] = mask3 >> 24 | n >> 18;
	(*rez)[1] = ((n >> 12) & 63) | 128;
	(*rez)[2] = ((n >> 6) & 63) | 128;
	(*rez)[3] = (n & 63) | 128;
	(*rez)[4] = '\0';
}

void	print_unicode(char *str, unsigned int n, char **rez)
{
	unsigned int	mask1;
	unsigned int	mask2;
	unsigned int	mask3;

	mask1 = 49280;
	mask2 = 14712960;
	mask3 = 4034953344;
	if (n <= 127)
	{
		if (!(*rez = (char*)malloc(sizeof(char) * 2)))
			return ;
		(*rez)[0] = n;
		(*rez)[1] = '\0';
	}
	else if (MB_CUR_MAX > 1 || str[ft_strlen(str) - 1] == 'S' ||
		str[ft_strlen(str) - 1] == 's')
	{
		if (n > 127 && n <= 2047)
			print_2_byte(mask1, n, rez);
		else if (n > 2047 && n <= 65535)
			print_3_byte(mask2, n, rez);
		else
			print_4_byte(mask3, n, rez);
	}
}
