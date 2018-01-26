/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_minus_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:40:36 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 19:40:38 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_minus_flag(char **rez)
{
	char *tmp;

	if ((*rez)[0] == ' ')
	{
		tmp = *rez;
		*rez = ft_prnt_replace_spc(*rez);
		free(tmp);
	}
}
