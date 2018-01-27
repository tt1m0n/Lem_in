/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_cross_rez.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:51:30 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 23:51:32 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		compare_rez(t_rezult **rez, int i)
{
	t_rezult	*tmpnext;
	t_rezult	*tmpprev;
	int			j;

	tmpnext = rez[i];
	while (tmpnext->next != NULL)
	{
		j = 0;
		while (i - j - 1 >= 0)
		{
			tmpprev = rez[i - j - 1];
			while (tmpprev->next != NULL)
			{
				if (ft_strcmp(tmpnext->name, tmpprev->name) == 0)
					return (free_dublicat_rez(&rez[i], &rez, i));
				tmpprev = tmpprev->next;
			}
			j++;
		}
		tmpnext = tmpnext->next;
	}
	return (1);
}

void	del_cross_rez(t_rezult **rez)
{
	int i;

	i = 0;
	while (rez[i] != NULL)
	{
		if (i != 0)
			if (!(compare_rez(rez, i)))
				i--;
		i++;
	}
}
