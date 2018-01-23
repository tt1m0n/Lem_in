/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:01:20 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 22:54:16 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t length;
	size_t tmp;

	length = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while ((*haystack != '\0') && (len-- > 0))
	{
		if ((*haystack == *needle) && (*haystack != '\0'))
		{
			if (len + 1 < length)
				return (NULL);
			tmp = len;
			if (ft_strncmp(haystack, needle, length) == 0)
				return ((char *)haystack);
			else
				len = tmp;
		}
		haystack++;
	}
	return (NULL);
}
