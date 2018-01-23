/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/29 20:44:55 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 15:53:15 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	int len;

	len = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack != '\0')
	{
		if ((*haystack == *needle) && (*haystack != '\0'))
		{
			if (ft_strncmp(haystack, needle, len) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	if (*haystack == '\0')
		haystack = NULL;
	return ((char *)haystack);
}
