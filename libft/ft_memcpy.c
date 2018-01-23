/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 21:25:36 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 18:09:32 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*tmp;
	const unsigned char	*tmp1;

	tmp = dst;
	tmp1 = src;
	if (n != 0)
	{
		while (n-- != 0)
		{
			*tmp++ = *tmp1++;
		}
	}
	return (dst);
}
