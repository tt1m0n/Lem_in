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

void	print_draft(t_rezult **rez)            //// DEL DEL DEL
{
	int			i;
	t_rezult	*tmp;

	i = 0;
	while (rez[i] != NULL)
	{
		tmp = rez[i];
		while (tmp != NULL)
		{
			ft_printf("(%s) ->", tmp->name);
			tmp = tmp->next;
		}
		ft_printf("\n");
		i++;
	}
}

void	swap_rez(t_rezult **rez, int i)
{
	t_rezult	*tmp;

	while (i > 0)
	{
		tmp = rez[i];
		rez[i] = rez[i - 1];
		rez[i - 1] = tmp;
		i--;
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

void	make_bfs(t_rezult ***rez, t_map *head, int numnbr_start)
{
	int		i;
	char	*end;

	i = 0;
	null_rez_array(rez, numnbr_start * 2 + 1);
	end = search_flag(head, 2);
	while (i < numnbr_start)
	{
		alg_each_nbr(end, head, &(*rez)[i], i);
		if (i != 0)
			if (len_rez((*rez)[i]) < len_rez((*rez)[i - 1]))
				swap_rez(*rez, i);
		i++;
	}
}

int		main_alg(t_map *head)
{
	t_rezult	**rez;
	int			numnbr_start;
	int			*ants_on_way;

	numnbr_start = search_st_nbr(head);
	rez = (t_rezult**)malloc(sizeof(t_rezult*) * (numnbr_start * 2 + 1));
	make_bfs(&rez, head, numnbr_start);
	del_cross_rez(rez);
	print_draft(rez);
	if (!(ants_on_way = (int*)malloc(sizeof(int) * count_rez(rez))))
		return (0);
	search_best_ways(rez, head->ant, &ants_on_way);
	print_rezult(rez, head->ant, ants_on_way);
	free_main_rez(rez);
	free(rez);
	free(ants_on_way);
	return (1);
}
