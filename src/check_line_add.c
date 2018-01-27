/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line_add.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 22:42:53 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 22:42:56 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	check_same_room(char **split)
{
	if (ft_strcmp(split[0], split[1]) == 0)
		return (0);
	return (1);
}

int 	check_space(char **split)
{
	int i;

	i = 0;
	while (split[0][i])
		if (split[0][i++] == ' ')
			return (0);
	i = 0;
	while (split[1][i])
		if (split[1][i++] == ' ')
			return (0);
	return (1);
}

int		check_existence(char *str, t_map *head)
{
	t_room *tmp;

	tmp = head->allroom;
	while (tmp != NULL)
	{
		if (ft_strcmp(str, tmp->name) == 0)
			return (1);
		tmp = tmp->nextroom;
	}
	return (0);
}

int 	check_if_alpha(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		if (ft_isalpha(str[i++]) == 1)
			return (0);
	return (1);
}
