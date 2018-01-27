/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 20:56:55 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 20:56:58 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int 	check_after_read(t_check check)
{
	if (check.pipe == 0 || check.room == 0 || check.count_st_sharp == 0 ||
		check.count_end_sharp == 0 || check.count_st_path == 0 ||
		check.count_end_path == 0)
		return (0);
	if (check.count_st_sharp > 1 || check.count_end_sharp > 1)
		return (0);
	return (1);
}

int		read_cycle(int fd, t_check *check, t_map *head)
{
	char *line;

	while (ft_get_next_line(fd, &line) > 0)
	{
		if (check_line(line, check, head) == 1)
			if (write_room(fd, &line, head, check) == 0)
			{	
				free(line);
				return (0);
			}
		if (check_line(line, check, head) == 2)
			write_pipe(line, head, check);
		if (check_line(line, check, head) == 0)
		{
			free(line);
			break;
		}
		ft_printf ("%s\n", line);
		free(line);
	}
	ft_printf("\n");
	return (1);
}

int		write_ant(char *line, t_map *head)
{
	int	i;

	i = 0;
	while (line[i])
		if (!(ft_isdigit(line[i++])))
			return (0);
	head->ant = ft_atoi(line);
	if (head->ant == 0 || head->ant > 1000000)
		return (0);
	return (1);
}

void	init_check_map(t_check *check, t_map *head)
{
	check->count_st_sharp = 0;
	check->count_end_sharp = 0;
	check->count_st_path = 0;
	check->count_end_path = 0;
	check->pipe = 0;
	check->room = 0;
	head->ant = 0;
	head->allroom = NULL;
}

int		read_map(int fd, t_map *head)
{
	char	*line;
	t_check check;

	init_check_map(&check, head);
	if (fd == -1)
		return (0);
	ft_get_next_line(fd, &line);
	if (!(write_ant(line, head)))
		return (0);
	ft_printf("%s\n", line);
	free(line);
	if (read_cycle(fd, &check, head) == 0)
		return (0);
	if (check_after_read(check) == 0)
		return (0);
	return (1);
}
