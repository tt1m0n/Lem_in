/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_pipe.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 22:57:49 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 22:57:51 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	init_new_nbr(t_nbr *nbr, char *name)
{
	nbr->name = ft_strdup(name);
	nbr->nextnbr = NULL;
}

int		add_nbr(t_room *head, char *name, t_check *check)
{
	t_nbr	*tmp;
	t_nbr	*new_nbr;

	tmp = head->headnbr;
	if (head->flag == 1)
		check->count_st_path++;
	if (head->flag == 2)
		check->count_end_path++;
	new_nbr = (t_nbr*)malloc(sizeof(t_nbr));
	init_new_nbr(new_nbr, name);
	if (tmp == NULL)
	{
		head->headnbr = new_nbr;
		return (1);
	}
	while (tmp->nextnbr != NULL)
		tmp = tmp->nextnbr;
	if (ft_strcmp(tmp->name, new_nbr->name) == 0)
	{
		free(new_nbr->name);
		free(new_nbr);
		return (0);
	}
	tmp->nextnbr = new_nbr;
	return (1);
}

int		check_add_nbr(char *room, char *nbr, t_map *head, t_check *check)
{
	t_room	*tmp;

	tmp = head->allroom;
	while (tmp != NULL)
	{
		if (ft_strcmp(room, tmp->name) == 0)
		{
			if (add_nbr(tmp, nbr, check) == 0)
				return (0);
			return (1);
		}
		tmp = tmp->nextroom;
	}
	return (0);
}

int		add_pipe(char **split, t_map *head, t_check *check)
{
	if (check_add_nbr(split[0], split[1], head, check) == 0 ||
		check_add_nbr(split[1], split[0], head, check) == 0)
		return (0);
	return (1);
}

void	write_pipe(char *line, t_map *head, t_check *check)
{
	char **split;

	split = ft_strsplit(line, '-');
	if (add_pipe(split, head, check))
		check->pipe++;
	free(split[0]);
	free(split[1]);
	free(split);
}
