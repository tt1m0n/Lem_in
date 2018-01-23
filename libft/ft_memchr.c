/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 15:17:51 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 14:39:30 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		p;
	const unsigned char	*str;

	p = (unsigned char)c;
	str = (unsigned char *)s;
	while (n-- > 0)
	{
		if (*str == p)
			return ((void *)str);
		str++;
	}
	return (NULL);
}
