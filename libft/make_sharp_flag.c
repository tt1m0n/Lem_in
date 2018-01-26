/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_sharp_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:47:30 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 19:47:31 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*make_sharpwith_zero(char *str, char *rez)
{
	size_t	len;

	len = ft_strlen(str) - 1;
	if (str[len] == 'o' || str[len] == 'O')
		return (ft_prnt_strjoin_smb(rez, '0'));
	else if (str[len] == 'x' || str[len] == 'X' || str[len] == 'p')
		return (ft_prnt_addsharp(rez, 'x'));
	return (NULL);
}

void		make_sharp_flag(char *str, char **rez)
{
	char	*tmp;
	size_t	len;

	tmp = *rez;
	len = ft_strlen(str) - 1;
	if ((*rez)[0] == '0' && (*rez)[1] != '\0' && (*rez)[1] != ' ' &&
		(count_precision(str, *rez) == 0))
		*rez = make_sharpwith_zero(str, *rez);
	else
	{
		if (str[ft_strlen(str) - 1] == 'x')
			*rez = ft_prnt_smsharp(*rez);
		else if (str[len] == 'p')
			*rez = ft_prnt_sharp_p(*rez);
		else if (str[len] == 'X')
			*rez = ft_prnt_bgsharp(*rez);
		else if (str[len] == 'o')
			*rez = ft_prnt_strjoin_smb(*rez, '0');
		else if (str[len] == 'O')
			*rez = ft_prnt_strjoin_smb(*rez, '0');
	}
	free(tmp);
}
