/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_rezult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:42:55 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 23:42:56 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_print_ant(t_rezult **ant, t_rezult **rez, int count, int *ants_on_way)
{
	int		i;
	int 	j;

	i = 0;
	while (i < count)
	{
		j = 0;
		while (j < count_rez(rez))
		{
			if (ants_on_way[j] > 0)
			{	
				ant[i] = rez[j];
				ants_on_way[j] = ants_on_way[j] - 1;
				i++;
				j++;
			}
			else
				j++;	
		}
	}
}

int		check_ant_end(t_rezult **print_ant, int ant)
{
	int		i;

	i = 0;
	while (i < ant)
	{
		if (print_ant[i] != NULL)
			return (0);
		i++;
	}
	return (1);
}

void	print_rezult(t_rezult **rez, int ant, int *ants_on_way)
{
	int	j;
	int size_print;
	int step;
	t_rezult *print_ant[ant];

	size_print = count_notzero_way(ants_on_way, rez);
	step = size_print;
	init_print_ant(print_ant, rez, ant, ants_on_way);
	while (1)
	{
		j = 0;
		while (j < size_print && j < ant)
		{
			if (print_ant[j] != NULL)
			{	
				ft_printf ("L%d-%s ", j + 1, print_ant[j]->name);
				print_ant[j] = print_ant[j]->next;
			}
			j++;
		}
		ft_printf("\n");
		size_print = size_print + step;
		if (check_ant_end(print_ant, ant))
			break;
	}
}

