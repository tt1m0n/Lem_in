/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/29 23:55:24 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/29 15:50:29 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_lst		*search_and_append(t_lst **head, int fd)
{
	t_lst *tmp;
	t_lst *new;

	tmp = *head;
	if (tmp && tmp->fd == fd)
		return (tmp);
	while (tmp && tmp->next != NULL)
	{
		tmp = tmp->next;
		if (tmp->fd == fd)
			return (tmp);
	}
	new = (t_lst*)malloc(sizeof(t_lst));
	if (new == NULL)
		return (NULL);
	new->fd = fd;
	new->str = NULL;
	new->next = NULL;
	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	tmp->next = new;
	return (new);
}

int			check_str(char **line, char **str)
{
	int		st;
	int		i;
	char	*tmp;

	i = 0;
	st = i;
	while ((*str)[i] != '\0')
	{
		if ((*str)[i] == '\n')
		{
			tmp = *str;
			*line = ft_strsub(*str, st, i - st);
			*str = ft_strsub(*str, i - st + 1, ft_strlen(*str) - (i - st));
			free(tmp);
			tmp = NULL;
			return (1);
		}
		i++;
	}
	return (0);
}

int			readfile(int fd, t_lst *tmp, char **line)
{
	char	buf[BUFF_SIZE + 1];
	int		count;
	char	*del;

	while ((count = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[count] = '\0';
		if (tmp->str)
		{
			del = tmp->str;
			if (!(tmp->str = ft_strjoin(tmp->str, buf)))
				return (-1);
			free(del);
		}
		if (!(tmp->str))
			if (!(tmp->str = ft_strdup(buf)))
				return (-1);
		if (check_str(line, &(tmp->str)) == 1)
			return (1);
	}
	if (count == -1)
		return (-1);
	return (0);
}

int			ft_get_next_line(const int fd, char **line)
{
	static t_lst	*head = NULL;
	t_lst			*tmp;

	if (line == NULL)
		return (-1);
	tmp = search_and_append(&head, fd);
	if ((tmp->str && check_str(line, &(tmp->str)) == 1) ||
		(readfile(fd, tmp, line) == 1))
		return (1);
	if (readfile(fd, tmp, line) == -1)
		return (-1);
	if ((tmp->str) && ((tmp->str)[0] != '\0'))
	{
		*line = ft_strsub(tmp->str, 0, ft_strlen(tmp->str));
		free(tmp->str);
		tmp->str = NULL;
		return (1);
	}
	return (0);
}
