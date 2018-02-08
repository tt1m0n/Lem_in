/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/29 14:55:26 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/29 14:55:27 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_print_lines(t_print *print_lines)
{
	t_print	*tmp;
	t_print	*prev;

	tmp = print_lines;
	prev = NULL;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->line);
		free(prev);
	}
}

void	print_all_lines(t_print *print_lines)
{
	while (print_lines != NULL)
	{
		ft_printf(print_lines->line);
		print_lines = print_lines->next;
	}
}
