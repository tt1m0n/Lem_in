/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alg_each_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:27:59 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 23:28:02 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_stack_used(t_nbr *tmpnbr, t_qeueu *stack, t_used *used, t_map *head)
{
	t_nbr	*startnbr;

	startnbr = head->allroom->headnbr;
	while (stack != NULL)
	{
		if (ft_strcmp(stack->name, tmpnbr->name) == 0)
			return (0);
		stack = stack->next;
	}
	while (startnbr != NULL)
	{
		if (ft_strcmp(startnbr->name, tmpnbr->name) == 0)
			return (0);
		startnbr = startnbr->nextnbr;
	}
	while (used != NULL)
	{
		if (ft_strcmp(used->name, tmpnbr->name) == 0)
			return (0);
		used = used->next;
	}
	if (ft_strcmp(head->allroom->name, tmpnbr->name) == 0)
		return (0);
	return (1);
}

void	stack_push(t_qeueu **stack, char *str, char *predecessor)
{
	t_qeueu *new;
	t_qeueu *tmp;

	tmp = *stack;
	if (!(new = (t_qeueu*)malloc(sizeof(t_qeueu))))
		return ;
	new->name = ft_strdup(str);
	new->predecessor = ft_strdup(predecessor);
	new->next = NULL;
	if ((*stack) == NULL)
	{
		(*stack) = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

int		start_alg(char *end, t_room *start, t_rezult **rez, t_map *head)
{
	t_qeueu *stack;
	t_nbr	*tmpnbr;
	t_used	*used;

	stack = NULL;
	used = NULL;
	stack_push(&stack, start->name, start->name);
	while (stack)
	{
		tmpnbr = search_room(head, stack->name);
		while (tmpnbr != NULL)
		{
			if (check_stack_used(tmpnbr, stack, used, head) == 1)
				stack_push(&stack, tmpnbr->name, stack->name);
			tmpnbr = tmpnbr->nextnbr;
		}
		add_front_used(&used, stack);
		pop_first_stack(&stack);
	}
	while (add_rezult(rez, used, end))
		;
	free_used(used);
	return (1);
}

void	alg_each_nbr(char *end, t_map *head, t_rezult **rez, int num)
{
	int		i;
	t_nbr	*tmp;
	t_room	*tmproom;

	i = 0;
	tmp = head->allroom->headnbr;
	tmproom = head->allroom;
	while (i < num)
	{
		tmp = tmp->nextnbr;
		i++;
	}
	while (tmproom != NULL)
	{
		if (strcmp(tmproom->name, tmp->name) == 0)
			start_alg(end, tmproom, rez, head);
		tmproom = tmproom->nextroom;
	}
}
