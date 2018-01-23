/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 14:07:27 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 16:14:59 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_rev(char *s)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = ft_strlen(s) - 1;
	while (i < j)
	{
		c = s[i];
		s[i] = s[j];
		s[j] = c;
		i++;
		j--;
	}
}

static	int		ft_intlen(int n)
{
	int i;
	int sign;

	i = 0;
	if (n == 0)
		i = 1;
	if (n == -2147483648)
		return (11);
	if ((sign = n) < 0)
		n = -n;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	if (sign < 0)
		i++;
	return (i);
}

static	void	ft_if(char *p, int n)
{
	int i;
	int sign;

	i = 0;
	if ((sign = n) < 0)
		n = -n;
	if (n == 0)
		p[i++] = '0';
	while (n != 0)
	{
		p[i++] = (n % 10) + '0';
		n = n / 10;
	}
	if (sign < 0)
		p[i++] = '-';
	p[i] = '\0';
}

char			*ft_itoa(int n)
{
	char *p;

	p = (char*)malloc(ft_intlen(n) + 1);
	if (p == NULL)
		return (NULL);
	if (n == -2147483648)
	{
		ft_strcpy(p, "-2147483648");
		return (p);
	}
	ft_if(p, n);
	ft_rev(p);
	return (p);
}
