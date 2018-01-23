/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/28 13:57:26 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 23:47:15 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		i;
	size_t		n;
	int			j;

	i = ft_strlen(dst);
	j = 0;
	if (dstsize > i)
		n = i;
	else
		n = dstsize;
	while ((src[j] != '\0') && ((i + 1) < dstsize))
	{
		dst[i] = src[j];
		j++;
		i++;
	}
	dst[i] = '\0';
	return (n + ft_strlen(src));
}
