/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_min_width.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:08:59 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:35:58 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_width(char **rez, int lenwidth)
{
	char *tmp;

	tmp = *rez;
	*rez = ft_prnt_strjoin_width(lenwidth, *rez);
	free(tmp);
}

static int	count_min_width(char *str)
{
	int		i;
	int		j;
	int		wd;
	char	width[11];

	i = 0;
	j = 0;
	while (str[i] != '\0')
	{
		if ((ft_isdigit(str[i]) && str[i] != '0') &&
			(i == 0 || str[i - 1] != '.'))
		{
			while (ft_isdigit(str[i]))
				width[j++] = str[i++];
			width[j] = '\0';
			break ;
		}
		i++;
	}
	wd = ft_atoi(width);
	return (wd);
}

void		check_min_width(char *str, char **rez)
{
	int		wd;
	int		i;
	size_t	l;

	i = 0;
	l = ft_strlen(str) - 1;
	wd = count_min_width(str);
	if (*rez == NULL)
	{
		*rez = ft_memalloc(10);
		while (i < wd - 1)
			(*rez)[i++] = ' ';
		return ;
	}
	if ((size_t)wd > ft_strlen(*rez))
	{
		if ((*rez)[0] == '\0' && str[ft_strlen(str) - 1] != 's' &&
			str[l] != 'x' && str[l] != 'X' && str[l] != 'o' && str[l] != 'O' &&
			str[l] != 'd' && str[l] != 'D' && str[l] != 'i' && str[l] != 'u' &&
			str[l] != 'U' && str[l] != 'S')
			make_width(rez, wd - 1 - ft_strlen(*rez));
		else
			make_width(rez, wd - ft_strlen(*rez));
	}
}
