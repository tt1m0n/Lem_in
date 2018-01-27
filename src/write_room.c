/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_room.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 22:52:09 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 22:52:11 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		check_add_room(char *line, t_map *head, int flag)
{
	t_room *last;
	t_room *new_room;

	last = head->allroom;
	new_room = (t_room*)malloc(sizeof(t_room));
	init_newroom(line, &new_room, flag);
	if (check_new_room(&new_room, head->allroom) == 0)
		return (0);
	if (head->allroom == NULL)
	{
		head->allroom = new_room;
		return (1);
	}
	while (last->nextroom != NULL)
		last = last->nextroom;
	last->nextroom = new_room;
	return (1);
}

int		endline_if(int fd, char **line, t_check *check, t_map *head)
{
	ft_get_next_line(fd, line);
	if (check_line(*line, check, head) == 1)
		if (check_add_room(*line, head, 2) == 0)
			return (0);
	if (check_line(*line, check, head) == 0)
		return (0);
	return (1);
}

int		startline_if(int fd, char **line, t_check *check, t_map *head)
{
	ft_get_next_line(fd, line);
	if (check_line(*line, check, head) == 1)
		if (check_add_room(*line, head, 1) == 0)
			return (0);
	if (check_line(*line, check, head) == 0)
		return (0);
	return (1);
}

int		write_room(int fd, char **line, t_map *head, t_check *check)
{
	char	*tmp;

	tmp = *line;
	if (ft_strncmp(*line, "##start", 8) == 0)
	{
		ft_printf("%s\n", *line);
		free(tmp);
		if (startline_if(fd, line, check, head) == 0)
			return (0);
	}
	else if (ft_strncmp(*line, "##end", 6) == 0)
	{
		ft_printf("%s\n", *line);
		free(tmp);
		if (endline_if(fd, line, check, head) == 0)
			return (0);
	}
	else if (check_add_room(*line, head, 0) == 0)
		return (0);
	check->room++;
	return (1);
}
