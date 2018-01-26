/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_strstr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 22:07:45 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/18 22:07:46 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_prnt_strstr(const char *haystack, const char *needle)
{
	int len;

	len = ft_strlen(needle);
	while (*haystack != '\0')
	{
		if ((*haystack == *needle) && (*haystack != '\0'))
			if (ft_strncmp(haystack, needle, len) == 0)
				return (1);
		haystack++;
	}
	return (0);
}
