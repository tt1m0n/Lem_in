/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_strjoin_prsn.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 08:36:00 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/19 08:36:02 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_prnt_strjoin_prsn(int len, char const *s2)
{
	int		i;
	char	*p;

	i = 0;
	p = (char*)malloc(ft_strlen(s2) + len + 1);
	if (p == NULL)
		return (NULL);
	if (s2[i] != '-')
	{
		while (len-- > 0)
			p[i++] = '0';
		while (*s2 != '\0')
			p[i++] = *(s2++);
		p[i] = '\0';
	}
	if (s2[i] == '-')
	{
		p[0] = '-';
		while (len-- > 0)
			p[++i] = '0';
		while (*(++s2) != '\0')
			p[++i] = *s2;
		p[++i] = '\0';
	}
	return (p);
}
