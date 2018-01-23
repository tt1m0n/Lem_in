/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 16:52:23 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 15:58:11 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char *save;

	save = NULL;
	while (*s != '\0')
	{
		if (*s == c)
		{
			save = (char *)s;
			break ;
		}
		s++;
	}
	if ((*s == '\0') && (c == '\0'))
		save = (char *)s;
	return (save);
}
