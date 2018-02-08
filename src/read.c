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

int		check_after_read(t_check check)
{
	if (check.pipe == 0 || check.room == 0 || check.count_st_sharp == 0 ||
		check.count_end_sharp == 0 || check.count_st_path == 0 ||
		check.count_end_path == 0)
		return (0);
	if (check.count_st_sharp > 1 || check.count_end_sharp > 1)
		return (0);
	return (1);
}

int		read_cycle(t_check *check, t_map *head, t_print **print_lines, int gnl)
{
	char	*line;

	gnl = ft_get_next_line(0, &line);
	while (gnl > 0)
	{
		if (check_line(line, check, head) == 1)
			if (write_room(&line, head, check, print_lines) == 0)
			{
				free(line);
				return (0);
			}
		if (check_line(line, check, head) == 2)
			if (write_pipe(line, head, check) == 0)
				break ;
		if (check_line(line, check, head) == 0)
			break ;
		if (check_line(line, check, head) != 4)
			add_line_toprint(print_lines, line);
		free(line);
		gnl = ft_get_next_line(0, &line);
	}
	if (gnl > 0)
		free(line);
	add_line_toprint(print_lines, "\n");
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

int		read_map(t_map *head, t_print **print_lines, int gnl)
{
	char	*line;
	t_check check;
	int		tmp;

	init_check_map(&check, head);
	tmp = ft_get_next_line(0, &line);
	if (tmp == 0 || tmp == -1)
		return (0);
	while (check_line(line, &check, head) == 3 ||
			check_line(line, &check, head) == 4)
	{
		if (check_line(line, &check, head) != 4)
			add_line_toprint(print_lines, line);
		free(line);
		ft_get_next_line(0, &line);
	}
	if (!(write_ant(line, head)))
		return (0);
	add_line_toprint(print_lines, line);
	free(line);
	if (read_cycle(&check, head, print_lines, gnl) == 0)
		return (0);
	if (check_after_read(check) == 0)
		return (0);
	return (1);
}
