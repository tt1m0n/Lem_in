/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/01 21:18:51 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 18:22:48 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t		ft_count_words(const char *s)
{
	int		i;
	size_t	count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while (SPACES && (s[i] != '\0'))
			i++;
		if (s[i] == '\0')
			break ;
		while (NOTSPACES && (s[i] != '\0'))
			i++;
		count++;
	}
	return (count);
}

static	size_t		ft_count_len(const char *s)
{
	int		i;
	size_t	len;
	size_t	count_word;

	i = 0;
	len = 0;
	count_word = ft_count_words(s);
	while (s[i] != '\0')
	{
		while (SPACES && (s[i] != '\0'))
		{
			i++;
			if (count_word != ft_count_words(s))
				len++;
		}
		while (NOTSPACES && (s[i] != '\0'))
		{
			len++;
			i++;
		}
		if (--count_word == 0)
			break ;
	}
	return (len);
}

char				*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	char	*p;
	size_t	count_len;

	i = 0;
	j = 0;
	if (s == NULL)
		return (NULL);
	count_len = ft_count_len(s);
	p = (char*)malloc(count_len + 1);
	if (p == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		while ((s[i] != '\0') && SPACES)
			i++;
		while ((count_len-- > 0) && (s[i] != '\0'))
			p[j++] = s[i++];
	}
	p[j] = '\0';
	return (p);
}
