/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prnt_strjoin_smb.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 23:32:31 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/21 23:32:34 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_prnt_add(char *p, char const *s, char c)
{
	int i;

	i = 0;
	if (!(p = (char*)malloc(ft_strlen(s) + 1)))
		return (NULL);
	if (ft_isdigit(s[0]))
	{
		p[i++] = c;
		while (*(s + 1) != '\0')
			p[i++] = *(s++);
	}
	else
	{
		while (!(ft_isdigit(*(s + 1))))
			p[i++] = *(s++);
		p[i++] = c;
		while (*s != '\0')
		{
			if (ft_isdigit(*s))
				p[i++] = *s;
			s++;
		}
	}
	p[i] = '\0';
	return (p);
}

static char		*ft_add_zero(char *p, char const *s, char c, int i)
{
	if (!(p = (char*)malloc(sizeof(char) * ft_strlen(s) + 1)))
		return (NULL);
	if (s[0] == '0' && s[ft_strlen(s) - 1] == ' ')
	{
		p[0] = c;
		while (s[i + 1] != '\0')
		{
			p[i + 1] = s[i];
			i++;
		}
		p[i + 1] = '\0';
	}
	else
	{
		while (s[i] != '\0')
		{
			if (s[i] == ' ' && s[i + 1] == '0')
				if (c != '0')
					p[i++] = c;
			p[i] = s[i];
			i++;
		}
		p[i] = '\0';
	}
	return (p);
}

char			*ft_prnt_strjoin_smb(char const *s, char c)
{
	int		i;
	char	*p;

	i = 0;
	p = NULL;
	if (((s[0] == '0' && s[1] == '\0') || s[0] == '\0' ||
		(ft_isdigit(s[0]) && ft_isdigit(s[ft_strlen(s) - 1]) && s[0] != '0')))
	{
		p = (char*)malloc(ft_strlen(s) + 2);
		if (p == NULL)
			return (NULL);
		p[0] = c;
		while (s[i] != '\0' && (s[0] != '0' || c != '0'))
		{
			p[i + 1] = s[i];
			i++;
		}
		p[i + 1] = '\0';
	}
	else if ((s[0] == '0' && s[1] != '\0' && s[1] != ' ') ||
		(s[ft_strlen(s) - 1] == '0' && s[ft_strlen(s) - 2] == ' '))
		p = ft_add_zero(p, s, c, 0);
	else
		p = ft_prnt_add(p, s, c);
	return (p);
}
