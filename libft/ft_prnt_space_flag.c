/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_space_flag.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:37:15 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/19 11:37:18 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_prnt_space_flag(char const *str)
{
	int		i;
	char	*p;

	i = 0;
	p = (char*)malloc(ft_strlen(str) + 1);
	if (p == NULL)
		return (NULL);
	p[0] = ' ';
	while (str[i + 1] != '\0')
	{
		p[i + 1] = str[i];
		i++;
	}
	p[i + 1] = '\0';
	return (p);
}
