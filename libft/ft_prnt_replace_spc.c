/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_replace_spc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 09:23:02 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/19 09:23:03 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prnt_replace_spc(char const *s)
{
	int		i;
	int		count;
	char	*p;

	i = 0;
	count = 0;
	p = (char*)malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == ' ')
			count++;
		else
			p[i++] = *s;
		s++;
	}
	while (count-- > 0)
		p[i++] = ' ';
	p[i] = '\0';
	return (p);
}
