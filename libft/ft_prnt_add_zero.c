/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_add_zero.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/19 11:06:11 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/19 11:06:13 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_if_nothing(char const *s)
{
	int		i;
	char	*p;

	i = 0;
	p = (char*)malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	while (*s != '\0')
	{
		if (*s == ' ')
			p[i++] = '0';
		else
			p[i++] = *s;
		s++;
	}
	p[i] = '\0';
	return (p);
}

static char		*ft_if_minus(char const *s)
{
	int		i;
	char	*p;

	i = 1;
	p = (char*)malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	p[0] = '-';
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '-')
			p[i] = '0';
		else
			p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

static char		*ft_if_plus(char const *s)
{
	int		i;
	char	*p;

	i = 1;
	p = (char*)malloc(ft_strlen(s) + 1);
	if (p == NULL)
		return (NULL);
	p[0] = '+';
	while (s[i] != '\0')
	{
		if (s[i] == ' ' || s[i] == '+')
			p[i] = '0';
		else
			p[i] = s[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char			*ft_prnt_add_zero(char const *s)
{
	int		i;
	char	*p;
	int		sign;

	i = 0;
	sign = 0;
	while (s[i] != '\0')
		if (s[i++] == '-')
			sign = 1;
	i = 0;
	while (s[i] != '\0')
		if (s[i++] == '+')
			sign = 2;
	if (sign == 0)
		p = ft_if_nothing(s);
	else if (sign == 1)
		p = ft_if_minus(s);
	else
		p = ft_if_plus(s);
	return (p);
}
