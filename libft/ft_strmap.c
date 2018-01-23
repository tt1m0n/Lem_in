/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 17:56:43 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 17:31:06 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	char	*p;
	size_t	len;

	i = 0;
	if ((s == NULL) || (f == NULL))
		return (NULL);
	while (s[i] != 0)
		i++;
	len = i;
	i = 0;
	p = (char *)malloc(len + 1);
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		p[i] = f(s[i]);
		i++;
	}
	p[i] = '\0';
	return (p);
}
