/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:37:58 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 23:38:00 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		count_rez(t_rezult **rez)
{
	int		i;

	i = 0;
	while (rez[i] != NULL)
		i++;
	return (i);
}

int		count_notzero_way(int *ants_on_way, t_rezult **rez)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (rez[i] != NULL)
	{
		if (ants_on_way[i] > 0)
			count++;
		i++;
	}
	return (count);
}

int		count_middle(t_rezult **rez, int *time)
{
	int			i;
	int			count;

	i = 0;
	count = 0;
	while (rez[i] != NULL)
	{
		count = count + time[i];
		i++;
	}
	return (count);
}

void	count_antway(t_rezult **rez, int **onway, int *time)
{
	int middle;
	int i;
	int num_rez;

	i = 0;
	num_rez = count_rez(rez);
	middle = count_middle(rez, time);
	while (rez[i] != NULL)
	{
		if (i == 0)
			(*onway)[i] = time[i] + middle / num_rez + (middle % num_rez) -
			time[i] - len_rez(rez[i]);
		else
			(*onway)[i] = time[i] + middle / num_rez -
			time[i] - len_rez(rez[i]);
		i++;
	}
}
