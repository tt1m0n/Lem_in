/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 08:45:15 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 14:45:01 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int i;

	i = 0;
	if (n == 0)
		return (0);
	while (n-- != 0)
	{
		if ((s1[i] == '\0') || (s2[i] == '\0') || (s1[i] != s2[i]))
			return ((const unsigned char)s1[i] - (const unsigned char)s2[i]);
		if (s1[i] == s2[i])
		{
			if (s1[i++] == '\0')
				break ;
		}
	}
	return ((const unsigned char)s1[i - 1] - (const unsigned char)s2[i - 1]);
}
