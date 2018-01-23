/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 22:34:03 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 23:21:02 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*tmp1;

	tmp = dst;
	tmp1 = src;
	while (n-- != 0)
	{
		if (*tmp1 == (unsigned char)c)
		{
			*tmp = *tmp1;
			tmp++;
			return (tmp);
		}
		*tmp++ = *tmp1++;
	}
	return (0);
}
