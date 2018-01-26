/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:04:40 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:46:13 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_add(char *str, char *rez, int i)
{
	if (str[i - 1] == '.' && ((str[i] == '0' ||
		ft_isalpha(str[i])) && rez[0] == '0'))
		return (-1);
	if (str[i - 1] == '.' && (str[i] == '0' || ft_isalpha(str[i])) &&
		(rez[0] == '+' || rez[0] == '-'))
		if (rez[1] == '0')
			return (-1);
	if (str[i - 1] == '.' && !ft_isdigit(str[i]) &&
		(str[ft_strlen(str) - 1] == 's' || str[ft_strlen(str) - 1] == 'S'))
		return (-1);
	return (0);
}

int			count_precision(char *str, char *rez)
{
	int		i;
	int		j;
	char	precision[20];

	i = -1;
	j = 0;
	while (str[++i] != '\0')
		if (str[i] == '.')
		{
			i++;
			if (check_add(str, rez, i) == -1)
				return (-1);
			while (ft_isdigit(str[i]))
				precision[j++] = str[i++];
			precision[j] = '\0';
			return (ft_atoi(precision));
		}
	return (0);
}
