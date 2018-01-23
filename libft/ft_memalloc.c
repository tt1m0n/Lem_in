/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/31 18:51:47 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 14:37:50 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (void*)malloc(size);
	if (p == NULL)
		return (NULL);
	while (i < size)
		p[i++] = 0;
	return (p);
}
