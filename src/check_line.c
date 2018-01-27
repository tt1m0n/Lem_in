/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_line.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/27 22:34:09 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/27 22:34:11 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	free_split(char ***split, int i)
{
	while (i >= 0)
		free((*split)[i--]);
	free(*split);
}

int		check_room(char *line)
{
	char	**split;
	int		i;

	i = 0;
	split = ft_strsplit(line, ' ');
	while (split[i])
		i++;
	if (i != 3 || split[0][0] == 'L')
	{
		free_split(&split, i - 1);
		return (0);
	}
	if (check_if_alpha(split[1]) == 0 || check_if_alpha(split[2]) == 0)
	{
		free_split(&split, i - 1);
		return (0);
	}
	free_split(&split, i - 1);
	return (1);
}

int		check_pipe(char *line, t_map *head)
{
	char **split;

	if (line[0] == ' ' || line[0] == '-')
		return (0);
	split = ft_strsplit(line, '-');
	if (check_same_room(split) == 0 || check_space(split) == 0)
	{
		free(split[0]);
		free(split[1]);
		free(split);
		return (0);
	}
	if (check_existence(split[0], head) == 0 ||
		check_existence(split[1], head) == 0)
	{
		free(split[0]);
		free(split[1]);
		free(split);
		return (0);
	}
	free(split[0]);
	free(split[1]);
	free(split);
	return (1);
}

int		check_bad_line(char *line, t_map *head)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i++] == '-')
			count++;
	}
	if (count == 1)
	{
		if (check_pipe(line, head))
			return (2);
		return (0);
	}
	if (count > 1)
		return (0);
	return (check_room(line));
}

int		check_line(char *line, t_check *check, t_map *head)
{
	if (ft_strncmp(line, "##start", 8) == 0)
	{
		check->count_st_sharp++;
		return (1);
	}
	if (ft_strncmp(line, "##end", 6) == 0)
	{
		check->count_end_sharp++;
		return (1);
	}
	if ((line[0] == '#' && line[1] != '#') ||
		(line[0] == '#' && line[1] == '#' && line[2] == '#'))
		return (3);
	if (line[0] == '\0' || line[0] == ' ')
		return (0);
	return (check_bad_line(line, head));
}
