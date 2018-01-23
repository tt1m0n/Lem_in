/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/27 00:29:21 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 18:11:01 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tmp;
	const char	*tmp1;
	size_t		i;

	tmp = (char*)dst;
	tmp1 = (const char*)src;
	i = 0;
	if (len != 0)
	{
		if (tmp1 < tmp)
		{
			while (len--)
				tmp[len] = tmp1[len];
		}
		else
			ft_memcpy(tmp, tmp1, len);
	}
	return (tmp);
}
