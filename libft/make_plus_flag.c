/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_plus_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:42:19 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 19:42:20 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_plus_flag(char **rez)
{
	int		i;
	char	*tmp;

	i = 0;
	while ((*rez)[i] == ' ')
		i++;
	if ((*rez)[i] != '-')
	{
		tmp = *rez;
		*rez = ft_prnt_strjoin_smb(*rez, '+');
		free(tmp);
	}
}
