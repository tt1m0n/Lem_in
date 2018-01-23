/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 16:39:38 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/03 23:31:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		ft_count_words(const char *s, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (s == NULL)
		return (0);
	while (s[i] != '\0')
	{
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
		if (s[i] == '\0')
			break ;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		count++;
	}
	return (count);
}

static	char	**split(char const *s, char **snew, int i, char c)
{
	int j;
	int start;

	j = 0;
	while (s[i] != '\0')
	{
		start = i;
		while ((s[i] != c) && (s[i] != '\0'))
			i++;
		if (i != 0)
		{
			snew[j] = ft_strsub(s, start, i - start);
			if (snew[j] == NULL)
			{
				while (j-- > 0)
					free(snew[j]);
				free(snew);
				return (NULL);
			}
			j++;
		}
		while ((s[i] == c) && (s[i] != '\0'))
			i++;
	}
	return (snew);
}

char			**ft_strsplit(char const *s, char c)
{
	int		i;
	int		nwords;
	char	**snew;

	i = 0;
	nwords = ft_count_words(s, c);
	if (s == NULL)
		return (NULL);
	snew = (char**)malloc((ft_count_words(s, c) + 1) * sizeof(char *));
	if (snew == NULL)
		return (NULL);
	snew = split(s, snew, i, c);
	if (snew == NULL)
		return (NULL);
	snew[nwords] = NULL;
	return (snew);
}
