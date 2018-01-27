/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   search.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:11:27 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 23:11:29 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		search_st_nbr(t_map *head)
{
	int		i;
	t_nbr	*tmpnbr;

	i = 0;
	tmpnbr = head->allroom->headnbr;
	while (tmpnbr != NULL)
	{
		i++;
		tmpnbr = tmpnbr->nextnbr;
	}
	return (i);
}

t_nbr	*search_room(t_map *head, char *name)
{
	t_room	*tmp;

	tmp = head->allroom;
	while (tmp != NULL)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp->headnbr);
		tmp = tmp->nextroom;
	}
	return (NULL);
}

int		search_add_end(t_used *used, t_rezult **rez, char *end)
{
	t_rezult	*new;
	t_used		*tmpused;

	tmpused = used;
	if (!(new = (t_rezult*)malloc(sizeof(t_rezult))))
		return (0);
	new->next = NULL;
	while (tmpused != NULL)
	{
		if (ft_strcmp(tmpused->name, end) == 0)
		{
			new->name = ft_strdup(end);
			new->predecessor = ft_strdup(tmpused->predecessor);
			(*rez) = new;
			return (1);
		}
		tmpused = tmpused->next;
	}
	free(new);
	return (0);
}

void	search_add_predecessor(t_used *used, t_rezult **rez)
{
	t_rezult	*new;
	t_used		*tmpused;

	tmpused = used;
	if (!(new = (t_rezult*)malloc(sizeof(t_rezult))))
		return ;
	while (tmpused != NULL)
	{
		if (ft_strcmp(tmpused->name, (*rez)->predecessor) == 0)
		{
			new->name = ft_strdup(tmpused->name);
			new->predecessor = ft_strdup(tmpused->predecessor);
			new->next = (*rez);
			(*rez) = new;
			return ;
		}
		tmpused = tmpused->next;
	}
}

void	search_best_ways(t_rezult **rez, int ant, int **ants_on_way)
{
	int		num_ways;
	int		time[count_rez(rez)];
	int		i;

	i = 0;
	num_ways = count_rez(rez);
	if (num_ways > 1 && (ant + len_rez(rez[0]) < (ant / 2 + len_rez(rez[1]))))
	{
		(*ants_on_way)[0] = ant;
		return ;
	}
	while (i < num_ways)
	{
		if (i == 0)
			time[i] = ant / num_ways + (ant % num_ways) + len_rez(rez[0]);
		else
			time[i] = ant / num_ways + len_rez(rez[i]);
		i++;
	}
	count_antway(rez, ants_on_way, time);
}
