/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_itoa_uintmax.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 21:24:53 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/18 21:30:50 by omakovsk         ###   ########.fr       */
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

static	int		ft_intlen(uintmax_t n)
{
	int			i;

	i = 0;
	if (n == 0)
		i = 1;
	while (n != 0)
	{
		i++;
		n = n / 10;
	}
	return (i);
}

static	void	ft_if(char *p, uintmax_t n)
{
	int			i;

	i = 0;
	if (n == 0)
		p[i++] = '0';
	while (n != 0)
	{
		p[i++] = (n % 10) + '0';
		n = n / 10;
	}
	p[i] = '\0';
}

char			*ft_prnt_itoa_uintmax(uintmax_t n)
{
	char *p;

	p = (char*)malloc(ft_intlen(n) + 1);
	if (p == NULL)
		return (NULL);
	ft_if(p, n);
	ft_rev(p);
	return (p);
}
