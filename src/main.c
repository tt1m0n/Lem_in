/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 20:56:46 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 20:56:50 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	start_first(t_map *head)
{
	t_room	*tmp;
	t_room	*prev;

	prev = head->allroom;
	tmp = head->allroom->nextroom;
	if (prev->flag == 1)
		return ;
	while (tmp != NULL)
	{
		if (tmp->flag == 1)
		{
			prev->nextroom = tmp->nextroom;
			tmp->nextroom = head->allroom;
			head->allroom = tmp;
			return ;
		}
		tmp = tmp->nextroom;
		prev = prev->nextroom;
	}
}

int		main(void)
{
	t_map	head;

	if (read_map(&head) == 0)
	{
		ft_putstr("ERROR\n");
		free_all_map(&head);
		return (0);
	}
	start_first(&head);
	main_alg(&head);
	free_all_map(&head);
//	system("leaks lem-in");
	return (0);
}
