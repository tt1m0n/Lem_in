/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:19:01 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 23:19:02 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_used(t_used *used)
{
	t_used	*tmp;
	t_used	*prev;

	prev = used;
	tmp = used;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->predecessor);
		prev->predecessor = NULL;
		free(prev->name);
		prev->name = NULL;
		free(prev);
		prev = NULL;
	}
}

void	free_main_rez(t_rezult **rez)
{
	int i;
	t_rezult *tmp;
	t_rezult *prev;

	i = 0;
	while (rez[i] != NULL)
	{
		tmp = rez[i];
		while (tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev->predecessor);
			prev->predecessor = NULL;
			free(prev->name);
			prev->name = NULL;
			free(prev);
			prev = NULL;
		}
		i++;
	}
}

int		free_dublicat_rez(t_rezult **elem, t_rezult ***rez, int i)
{
	t_rezult *tmp;
	t_rezult *prev;

	tmp = (*elem);
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->name);
		free(prev->predecessor);
		free(prev);
	}
	(*rez)[i] = (*rez)[i + 1];
	while ((*rez)[i++] != NULL)
		(*rez)[i] = (*rez)[i + 1];
	return (0);
}

void	free_nbr(t_nbr *headnbr)
{
	t_nbr	*tmpnbr;
	t_nbr	*prevnbr;

	prevnbr = headnbr;
	tmpnbr = headnbr;
	while (tmpnbr != NULL)
	{
		tmpnbr = tmpnbr->nextnbr;
		free(prevnbr->name);
		free(prevnbr);
		prevnbr = tmpnbr;
	}
}

void	free_all_map(t_map *map)
{
	t_room	*tmproom;
	t_room	*prevroom;

	prevroom = map->allroom;
	tmproom = map->allroom;
	while (tmproom != NULL)
	{
		tmproom = tmproom->nextroom;
		free_nbr(prevroom->headnbr);
		free(prevroom->name);
		prevroom->name = NULL;
		prevroom = tmproom;
	}
}