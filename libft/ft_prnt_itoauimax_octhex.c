/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_itoauimax_octhex.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 10:24:55 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/20 10:24:57 by omakovsk         ###   ########.fr       */
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

static	int		ft_intlen(uintmax_t n, unsigned int base)
{
	int			i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / base;
	}
	return (i);
}

static char		ft_conv(uintmax_t n, unsigned int base, int x)
{
	unsigned int rez;

	rez = n % base;
	if (base == 8)
		return (rez + '0');
	else
	{
		if (rez <= 9)
			return (rez + '0');
		else if (rez > 9 && rez <= 15)
		{
			if (x == 0)
				return ('a' + rez - 10);
			else if (x == 1)
				return ('A' + rez - 10);
		}
	}
	return ('0');
}

static	void	ft_if(char *p, uintmax_t n, int base, int x)
{
	int			i;

	i = 0;
	if (n == 0)
		p[i++] = '0';
	while (n != 0)
	{
		p[i++] = ft_conv(n, base, x);
		n = n / base;
	}
	p[i] = '\0';
}

char			*ft_prnt_itoauimax_octhex(uintmax_t n, int base, int x)
{
	char *p;

	p = (char*)malloc(ft_intlen(n, base) + 1);
	if (p == NULL)
		return (NULL);
	ft_if(p, n, base, x);
	ft_rev(p);
	return (p);
}
