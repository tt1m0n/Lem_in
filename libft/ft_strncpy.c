/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 23:10:51 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 15:06:04 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	int i;

	i = 0;
	while (len-- != 0)
	{
		if ((dst[i] = src[i]) == 0)
		{
			while (len-- != 0)
			{
				i++;
				dst[i] = '\0';
			}
			break ;
		}
		i++;
	}
	return (dst);
}
