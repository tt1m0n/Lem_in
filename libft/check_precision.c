/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_precision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:02:29 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:36:32 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	make_precision(char *str, char **rez, int lenprsn)
{
	int		i;
	char	*tmp;

	tmp = *rez;
	i = ft_strlen(str) - 1;
	if (str[i] != 'c' && str[i] != 'C' && str[i] != '%')
	{
		*rez = ft_prnt_strjoin_prsn(lenprsn, *rez);
		free(tmp);
	}
}

static void	make_precision_str(char **rez, int len)
{
	char *tmp;

	tmp = *rez;
	*rez = ft_prnt_prs_str(len, *rez);
	free(tmp);
}

void		check_precision(char *str, char **rez)
{
	int		prsn;
	size_t	lenrez;
	size_t	lenstr;

	lenrez = ft_strlen(*rez);
	lenstr = ft_strlen(str) - 1;
	prsn = count_precision(str, *rez);
	if (prsn == -1)
		(*rez)[0] = '\0';
	else
	{
		if (((size_t)prsn > lenrez) && (*rez)[0] != '-' &&
			str[lenstr] != 's')
			make_precision(str, rez, prsn - lenrez);
		if ((*rez)[0] == '-' && (size_t)prsn > lenrez - 1 &&
			str[lenstr] != 's')
			make_precision(str, rez, prsn - lenrez + 1);
		if (((size_t)prsn < lenrez) && (str[lenstr] == 's' ||
			str[lenstr] == 'S') && prsn != 0)
			make_precision_str(rez, prsn);
	}
}
