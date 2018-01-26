/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_addsharp.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 20:30:52 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/22 20:30:55 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_add_sharp_x(char *p, char const *s, char c)
{
	int i;

	i = 0;
	if (!(p = (char*)malloc(sizeof(char) * ft_strlen(s) + 2)))
		return (NULL);
	p[0] = '0';
	p[1] = c;
	while (s[i + 1] != '\0')
	{
		p[i + 2] = s[i + 1];
		i++;
	}
	p[i + 2] = '\0';
	return (p);
}

char			*ft_prnt_addsharp(char const *s, char c)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	if (s[0] == '0' && s[1] == '0')
	{
		if (!(p = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
			return (NULL);
		p[0] = '0';
		p[1] = c;
		while (s[i + 2] != '\0')
		{
			p[i + 2] = s[i + 2];
			i++;
		}
		p[i + 2] = '\0';
	}
	else if (s[0] == '0' && s[1] != '0')
		p = ft_add_sharp_x(p, s, c);
	return (p);
}
