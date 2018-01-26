/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_sharp_p.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/25 16:46:54 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/25 16:46:56 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_one_or_twospace(const char *str, size_t len, int i, int j)
{
	char *p;

	if (len == 0)
	{
		if (!(p = (char*)malloc(sizeof(char) * ft_strlen(str) + 3)))
			return (NULL);
		p[0] = '0';
		p[1] = 'x';
		while (str[++i] != '\0')
			p[i + 2] = str[i];
		p[i + 2] = '\0';
	}
	else
	{
		if (!(p = (char*)malloc(sizeof(char) * ft_strlen(str) + 2)))
			return (NULL);
		p[0] = '0';
		p[1] = 'x';
		while (str[++i] != '\0')
			if (str[i] != ' ')
				p[j++] = str[i];
		p[j] = '\0';
	}
	return (p);
}

static char	*ft_first_space(char **p, const char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if (str[i] == ' ' && str[i + 1] == ' ' &&
			str[i + 2] != '\0' && str[i + 2] != ' ')
		{
			(*p)[j++] = '0';
			(*p)[j] = 'x';
			i = i + 1;
		}
		else
			(*p)[j] = str[i];
		i++;
		j++;
	}
	(*p)[j] = '\0';
	return (*p);
}

static char	*ft_more_twospc(const char *str, int i, int j)
{
	char *p;

	if (!(p = (char*)malloc(sizeof(char) * ft_strlen(str) + 1)))
		return (NULL);
	if (str[0] == ' ')
		p = ft_first_space(&p, str);
	else if (str[0] != ' ')
	{
		p[0] = '0';
		p[1] = 'x';
		while (str[i + 2] != '\0')
		{
			p[j + 2] = str[i++];
			j++;
		}
		p[j + 2] = '\0';
	}
	return (p);
}

char		*ft_prnt_sharp_p(const char *str)
{
	int		i;
	char	*p;
	int		smb;
	int		sign;

	i = 0;
	smb = 0;
	sign = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
			smb++;
		i++;
	}
	if (ft_strlen(str) - (size_t)smb == 0 ||
		ft_strlen(str) - (size_t)smb == 1)
		p = ft_one_or_twospace(str, ft_strlen(str) - (size_t)smb, -1, 2);
	else
		p = ft_more_twospc(str, 0, 0);
	return (p);
}
