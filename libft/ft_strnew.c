/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 13:41:59 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 16:08:53 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*p;

	i = 0;
	p = (char*)malloc(size + 1);
	if (p == NULL)
		return (NULL);
	while (i < size)
		p[i++] = '\0';
	p[i] = '\0';
	return (p);
}
