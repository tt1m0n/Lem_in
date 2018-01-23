/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mycount_words.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:20:24 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/07 11:20:31 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_mycount_words(const char *s)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while (SPACES && (s[i] != '\0'))
			i++;
		if (s[i] == '\0')
			break ;
		while (NOTSPACES && (s[i] != '\0'))
			i++;
		count++;
	}
	return (count);
}
