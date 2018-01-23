/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 18:46:47 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 22:53:30 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*save;
	int		i;

	i = 0;
	save = NULL;
	while (*s != '\0')
	{
		s++;
		i++;
	}
	if ((*s == '\0') && (c == '\0'))
		save = (char*)s;
	while (i-- >= 0)
	{
		if (*s == c)
		{
			save = (char*)s;
			return (save);
		}
		s--;
	}
	return (save);
}
