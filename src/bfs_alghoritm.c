/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bfs_alghoritm.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:02:36 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 23:02:38 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	swap_rez(t_rezult **rez, int i)
{
	t_rezult	*tmp;
	int			j;

	j = i;
	while (j > 0)
	{
		if (len_rez(rez[i]) < len_rez(rez[j - 1]))
		{
			tmp = rez[i];
			rez[i] = rez[j - 1];
			rez[j - 1] = tmp;
			j--;
			i--;
		}
		else
			j--;
	}
}

void	null_rez_array(t_rezult ***rez, int num)
{
	int i;

	i = 0;
	while (i <= num)
	{
		(*rez)[i] = NULL;
		i++;
	}
}

char	*search_flag(t_map *head, int flag)
{
	t_room *tmp;

	tmp = head->allroom;
	while (tmp != NULL)
	{
		if (tmp->flag == flag)
			return (tmp->name);
		tmp = tmp->nextroom;
	}
	return (NULL);
}

int		make_bfs(t_rezult ***rez, t_map *head, int numnbr_start)
{
	int		i;
	int		j;
	char	*end;

	i = 0;
	null_rez_array(rez, numnbr_start * 2 + 1);
	end = search_flag(head, 2);
	j = 0;
	while (j < numnbr_start)
	{
		if (alg_each_nbr(end, head, &(*rez)[i], j))
			i++;
		if (i != 0 && (i - 1) != 0)
			if (len_rez((*rez)[i - 1]) < len_rez((*rez)[i - 2]) &&
				(*rez)[i - 1] != NULL)
				swap_rez(*rez, i - 1);
		j++;
	}
	if (i == 0)
		return (0);
	return (1);
}

int		main_alg(t_map *head, t_print *print_lines)
{
	t_rezult	**rez;
	int			numnbr_start;
	int			*ants_on_way;

	numnbr_start = search_st_nbr(head);
	rez = (t_rezult**)malloc(sizeof(t_rezult*) * (numnbr_start * 2 + 1));
	if (!(make_bfs(&rez, head, numnbr_start)))
	{
		free_main_rez(rez);
		free(rez);
		return (0);
	}
	del_cross_rez(rez);
	if (!(ants_on_way = (int*)malloc(sizeof(int) * count_rez(rez))))
		return (0);
	search_best_ways(rez, head->ant, &ants_on_way);
	print_all_lines(print_lines);
	print_rezult(rez, head->ant, ants_on_way);
	free_main_rez(rez);
	free(rez);
	free(ants_on_way);
	return (1);
}
