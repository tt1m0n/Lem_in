/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_memmaloc.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 21:48:16 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 23:00:06 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_prnt_memalloc(size_t size)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (void*)malloc(size);
	if (p == NULL)
		return (NULL);
	while (i < size)
		p[i++] = '0';
	return (p);
}
