/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_func.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 23:54:32 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 23:54:33 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	pop_first_stack(t_qeueu **stack)
{
	t_qeueu *del;

	del = (*stack);
	(*stack) = (*stack)->next;
	free(del->predecessor);
	del->predecessor = NULL;
	free(del->name);
	del->name = NULL;
	free(del);
	del = NULL;
}

int		len_rez(t_rezult *rez)
{
	int			i;
	t_rezult	*tmp;

	i = 0;
	tmp = rez;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	add_line_toprint(t_print **print, char *line)
{
	t_print *tmp;
	t_print *new;

	tmp = *print;
	if (!(new = (t_print*)malloc(sizeof(t_print))))
		return ;
	if (ft_strcmp(line, "\n") == 0)
		new->line = ft_strdup(line);
	else
		new->line = ft_strjoin(line, "\n");
	new->next = NULL;
	if (tmp == NULL)
	{
		*print = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	add_front_used(t_used **used, t_qeueu *stack)
{
	t_used	*new;

	if (!(new = (t_used*)malloc(sizeof(t_used))))
		return ;
	new->predecessor = ft_strdup(stack->predecessor);
	new->name = ft_strdup(stack->name);
	if ((*used) == NULL)
	{
		(*used) = new;
		(*used)->next = NULL;
		return ;
	}
	new->next = (*used);
	(*used) = new;
}

int		add_rezult(t_rezult **rez, t_used *used, char *end)
{
	t_rezult	*tmp;

	tmp = (*rez);
	if (tmp == NULL)
	{
		if (search_add_end(used, rez, end) == 0)
			return (-1);
	}
	if (ft_strcmp((*rez)->name, (*rez)->predecessor) == 0)
		return (0);
	search_add_predecessor(used, rez);
	return (1);
}
