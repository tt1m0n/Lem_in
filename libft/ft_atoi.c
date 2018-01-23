/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 10:37:26 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/23 22:06:31 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

int			ft_atoi(const char *str)
{
	size_t				i;
	int					sign;
	unsigned long int	n;

	i = 0;
	sign = 1;
	n = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		if ((n > 922337203685477580 || (n == 922337203685477580
			&& (str[i] - '0') > 7)) && sign == 1)
			return (-1);
		else if ((n > 922337203685477580 || (n == 922337203685477580
			&& (str[i] - '0') > 8)) && sign == -1)
			return (0);
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return ((int)(n * sign));
}
