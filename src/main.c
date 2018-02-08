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
	t_print *print_lines;
	int		gnl;

	gnl = 0;
	if (read_map(&head, &print_lines, gnl) == 0)
	{
		ft_printf("ERROR\n");
		free_all_map(&head);
		return (0);
	}
	start_first(&head);
	if (!(main_alg(&head, print_lines)))
		ft_printf("ERROR\n");
	free_all_map(&head);
	free_print_lines(print_lines);
	return (0);
}
