/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lemin.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/21 17:40:19 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/21 17:40:21 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || \
	c == '\v' || c == '\f' || c == '\r');
}

unsigned long			ft_atoi_ant(const char *str)
{
	size_t				i;
	unsigned long 		n;

	i = 0;
	n = 0;
	while (whitespace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while ((str[i] != '\0') && ft_isdigit(str[i]))
	{
		n = (n * 10) + (str[i] - '0');
		i++;
	}
	return (n);
}

// --------------------------- START CHECK -----------------------------

void	init_checkstruct(s_check *check)
{
	check->count_st_sharp = 0;
	check->count_end_sharp = 0;
	check->count_st_path = 0;
	check->count_end_path = 0;
	check->pipe = 0;
	check->room = 0;
}

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

int 	check_pipe(char *line)
{
	char **split;

	if (line[0] == ' ' || line[0] == '-')
		return (0);
	split = ft_strsplit(line, '-');
	if (check_same_room(split) == 0 || check_space(split) == 0)
		return (0);
	free(split[0]);
	free(split[1]);
	free(split);
	return (1);
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

void	free_split(char ***split, int i)
{
	while (i >= 0)
		free((*split)[i--]);
	free(*split);
}

int 	check_room(char *line)
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

int		check_bad_line(char *line)
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
		if (check_pipe(line))
			return (2);
		return (0);
	}
	if (count > 1)
		return (0);
	return(check_room(line));
}

int		check_line(char *line, s_check *check)
{
	if (strncmp(line, "##start", 8) == 0)
	{
		check->count_st_sharp++;
		return (1);
	}
	if (strncmp(line, "##end", 6) == 0) 
	{
		check->count_end_sharp++;
		return (1);
	}
	if ((line[0] == '#' && line[1] != '#' ) ||
	 (line[0] == '#' && line[1] == '#' && line[2] == '#'))
		return (3);
	if (line[0] == '\0' || line[0] == ' ')
		return (0);
	return (check_bad_line(line));
}

int 	check_after_read(s_check check)
{
	if (check.pipe == 0 || check.room == 0 || check.count_st_sharp == 0 ||
		check.count_end_sharp == 0 || check.count_st_path == 0 ||
		check.count_end_path == 0)
		return (0);
	if (check.count_st_sharp > 1 || check.count_end_sharp > 1)
		return (0);
	return (1);
}

// ----------------------------- END CHECK -------------------------

// ----------------------------- START WRITE ROOM --------------------------
void	map_init(s_map *head)
{
	head->ant = 0;
	head->allroom = NULL;
}

void	extract_name_room(char *line, s_room **new_room)
{
	char **split;

	split = ft_strsplit(line, ' ');
	(*new_room)->name = ft_strdup(split[0]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
}

void	extract_coord(char *line, s_room **new_room) 
{
	char **split;

	split = ft_strsplit(line, ' ');
	(*new_room)->x = ft_atoi(split[1]);
	(*new_room)->y = ft_atoi(split[2]);
	free(split[0]);
	free(split[1]);
	free(split[2]);
	free(split);
}

void	init_newroom(char *line, s_room **new_room, int flag)
{
	extract_name_room(line, new_room);
	extract_coord(line, new_room);
	(*new_room)->flag = flag;
	(*new_room)->nextroom = NULL;
	(*new_room)->headnbr = NULL;
}

int		check_new_room(s_room **new_room, s_room *head)
{
	s_room	*tmp;

	tmp = head;
	if (head == NULL)
		return (1);
	while (tmp != NULL)
	{
		if (ft_strcmp(tmp->name, (*new_room)->name) == 0 ||
			(tmp->x == (*new_room)->x && tmp->y == (*new_room)->y))
		{
			free((*new_room)->name);
			free((*new_room));
			return (0);
		}
		tmp = tmp->nextroom;
	}
	return (1);
}

int		check_add_room(char *line, s_map *head, int flag)
{
	s_room *last;
	s_room *new_room;

	last = head->allroom;
	new_room = (s_room*)malloc(sizeof(s_room));
	init_newroom(line, &new_room, flag);
	if (check_new_room(&new_room, head->allroom) == 0)
		return (0);
	//printf ("list == %s x == %d y == %d\n", new_room->name, new_room->x, new_room->y);
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

int		startline_if(int fd, char **line, s_check *check, s_map *head)
{
	ft_get_next_line(fd, line);
	if (check_line(*line, check) == 1)
		if (check_add_room(*line, head, 1) == 0)
			return (0);
	if (check_line(*line, check) == 0)
		return (0);
	return (1);
}

int		endline_if(int fd, char **line, s_check *check, s_map *head)
{
	ft_get_next_line(fd, line);
	if (check_line(*line, check) == 1)
		if (check_add_room(*line, head, 2) == 0)
			return (0);
	if (check_line(*line, check) == 0)
		return (0);
	return (1);
}

int		write_room(int fd, char **line, s_map *head, s_check *check)
{
	char	*tmp;

	tmp = *line;
	if (strncmp(*line, "##start", 8) == 0)
	{
		free(tmp);
		if (startline_if(fd, line, check, head) == 0)
			return (0);
	}
	else if (strncmp(*line, "##end", 6) == 0)
	{
		free(tmp);
		if (endline_if(fd, line, check, head) == 0)
			return (0);
	}
	else
		if (check_add_room(*line, head, 0) == 0)
			return (0);
	check->room++;
	return (1);
}

// ---------------------------- END WRITE ROOM ---------------------------------

// --------------------------- START WRITE PIPE --------------------------------

void	init_new_nbr(s_nbr *nbr, char *name)
{
	nbr->name = ft_strdup(name);
	nbr->nextnbr = NULL;
}

int		add_nbr(s_room *head, char *name, s_check *check)
{
	s_nbr	*tmp;
	s_nbr	*new_nbr;

	tmp = head->headnbr;
	if (head->flag == 1)
		check->count_st_path++;
	if (head->flag == 2)
		check->count_end_path++;
	new_nbr = (s_nbr*)malloc(sizeof(s_nbr));
	init_new_nbr(new_nbr, name);
	if (tmp == NULL)
	{
		head->headnbr = new_nbr;
		return (1);
	}
	while (tmp->nextnbr != NULL)
		tmp = tmp->nextnbr;
	if (ft_strcmp(tmp->name, new_nbr->name) == 0)
		return (0);
	tmp->nextnbr = new_nbr;
	return (1);
}

int 	check_add_nbr(char *room, char *nbr, s_map *head, s_check *check)
{
	s_room	*tmp;

	tmp = head->allroom;
	while (tmp != NULL)
	{
		if (ft_strcmp(room, tmp->name) == 0)
		{
			if (add_nbr(tmp, nbr, check) == 0)
				return (0);
			return (1);
		}
		tmp = tmp->nextroom;
	}
	return (0);
}

int		add_pipe(char **split, s_map *head, s_check *check)
{
	if (check_add_nbr(split[0], split[1], head, check) == 0 ||
		check_add_nbr(split[1], split[0], head, check) == 0)
		return (0);
	return (1);
}

void 	write_pipe(char *line, s_map *head, s_check *check)
{
	char **split;

	split = ft_strsplit(line, '-');
	if (add_pipe(split, head, check))
		check->pipe++;
	free(split[0]);
	free(split[1]);
	free(split);
}

// --------------------------- END WRITE PIPE -----------------------------------

int		write_ant(char *line, s_map *head)
{
	int	i;

	i = 0;
	while (line[i])
		if (!(ft_isdigit(line[i++])))
			return (0);
	head->ant = ft_atoi_ant(line);
	if (head->ant == 0)
		return (0);
	return (1);
}

void	free_nbr(s_nbr *headnbr)
{
	s_nbr	*tmpnbr;
	s_nbr	*prevnbr;

	prevnbr = headnbr;
	tmpnbr = headnbr;
	while (tmpnbr != NULL)
	{
		tmpnbr = tmpnbr->nextnbr;
		free(prevnbr->name);
		free(prevnbr);
		prevnbr = tmpnbr;
	}
}

void	free_all_map(s_map *map)
{
	s_room	*tmproom;
	s_room	*prevroom;

	prevroom = map->allroom;
	tmproom = map->allroom;
	while (tmproom != NULL)
	{
		tmproom = tmproom->nextroom;
		free_nbr(prevroom->headnbr);
		free(prevroom->name);
		prevroom = tmproom;
	}
}

//---------------------- START ALGHORITM -----------------------------------

char	*search_flag(s_map *head, int flag)
{
	s_room *tmp;

	tmp = head->allroom;
	while (tmp != NULL)
	{
		if (tmp->flag == flag)
			return (tmp->name);
		tmp = tmp->nextroom;
	}
	return (NULL);
}

void	stack_push(s_qeueu **stack, char *str, char *predecessor)
{
	s_qeueu *new;
	s_qeueu *tmp;

	tmp = *stack;
	if (!(new = (s_qeueu*)malloc(sizeof(s_qeueu))))
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

void		pop_first_stack(s_qeueu **stack)
{
	s_qeueu *del;

	del = (*stack);
	(*stack) = (*stack)->next;
	free(del->predecessor);
	del->predecessor = NULL;
	free(del->name);
	del->name = NULL;
	free(del);
	del = NULL;
}

void	add_front_used(s_used **used, s_qeueu *stack)
{
	s_used	*new;

	if (!(new = (s_used*)malloc(sizeof(s_used))))
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

void		search_add_predecessor(s_used *used, s_rezult **rez)
{
	s_rezult	*new;
	s_used	*tmpused;

	tmpused = used;
	if (!(new = (s_rezult*)malloc(sizeof(s_rezult))))
		return ;
	while(tmpused != NULL)
	{
		if (ft_strcmp(tmpused->name, (*rez)->predecessor) == 0)
		{
			new->name = ft_strdup(tmpused->name);
			new->predecessor = ft_strdup(tmpused->predecessor);
			new->next = (*rez);
			(*rez) = new;
			return ;
		}
		tmpused = tmpused->next;
	}
}

void 	null_rez_array(s_rezult ***rez, int num)
{
	int i;

	i = 0;
	while (i <= num)
	{
		(*rez)[i] = NULL;
		i++;
	}	
}

int 	search_st_nbr(s_map *head)
{
	int		i;
	s_nbr	*tmpnbr;

	i = 0;
	tmpnbr = head->allroom->headnbr;
	while (tmpnbr != NULL)
	{
		i++;
		tmpnbr = tmpnbr->nextnbr;
	}
	return (i);
}

int		check_stack_used(s_nbr *tmpnbr, s_qeueu *stack, s_used *used, s_map *head)
{
	s_nbr	*startnbr;

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

void	search_add_end(s_used *used, s_rezult **rez, char *end)
{
	s_rezult	*new;
	s_used		*tmpused;

	tmpused = used;
	if (!(new = (s_rezult*)malloc(sizeof(s_rezult))))
		return ;
	new->next = NULL;
	while(tmpused != NULL)
	{
		if (ft_strcmp(tmpused->name, end) == 0)
		{
			new->name = ft_strdup(end);
			new->predecessor = ft_strdup(tmpused->predecessor);
			(*rez) = new;
			return ;
		}
		tmpused = tmpused->next;
	}
}

s_nbr	*search_room(s_map *head, char *name)
{
	s_room	*tmp;

	tmp = head->allroom;
	while (tmp != NULL)
	{
		if (ft_strcmp(name, tmp->name) == 0)
			return (tmp->headnbr);
		tmp = tmp->nextroom;
	}
	return (NULL);
}

int		add_rezult(s_rezult **rez, s_used *used, char *end)
{
	s_rezult	*tmp;

	tmp = (*rez);
	if (tmp == NULL)
	{
		search_add_end(used, rez, end);
		if (ft_strcmp((*rez)->name, (*rez)->predecessor) == 0)
			return (0);
		return (1);
	}
	if (ft_strcmp((*rez)->name, (*rez)->predecessor) == 0)
		return (0);
	search_add_predecessor(used, rez);
	return (1);
}

void	free_used(s_used *used)
{
	s_used	*tmp;
	s_used	*prev;

	prev = used;
	tmp = used;
	while (tmp != NULL)
	{
		prev = tmp;
		tmp = tmp->next;
		free(prev->predecessor);
		prev->predecessor = NULL;
		free(prev->name);
		prev->name = NULL;
		free(prev);
		prev = NULL;
	}
}

int		start_alg(char *end, s_room *start, s_rezult **rez, s_map *head)
{
	s_qeueu *stack;
	s_nbr	*tmpnbr;
	s_used	*used;

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

void	alg_each_nbr(char *end, s_map *head, s_rezult **rez, int num)
{
	int		i;
	s_nbr	*tmp;
	s_room	*tmproom;

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

void	free_main_rez(s_rezult **rez)
{
	int i;
	s_rezult *tmp;
	s_rezult *prev;

	i = 0;
	while (rez[i] != NULL)
	{
		tmp = rez[i];
		while (tmp != NULL)
		{
			prev = tmp;
			tmp = tmp->next;
			free(prev->predecessor);
			prev->predecessor = NULL;
			free(prev->name);
			prev->name = NULL;
			free(prev);
			prev = NULL;
		}
		i++;
	}
}


void	print_draft(s_rezult **rez)
{
	int i;
	s_rezult *tmp;

	i = 0;
	while (rez[i] != NULL)
	{
		tmp = rez[i];
		while (tmp != NULL)
		{
			printf ("(%s) ->", tmp->name);
			tmp = tmp->next;
		}
		printf ("\n");
		i++;
	}
}

/*
void	print_rezult(s_rezult **rez, char *end, int ant)
{
	int i;
	int j;

	i = 1;
	j = 0;
	while (i < ant)
	{
		while (rez[j] != NULL)
		{
			printf ("L%d-%s ", i, rez[j]->name);
			rez = rez[j]->next;
		}
	}
}*/

int		len_rez(s_rezult *rez)
{
	int i;

	i = 0;
	while (rez != NULL)
	{
		rez = rez->next;
		i++;
	}
	return (i);
}

void	swap_rez(s_rezult **rez, int i)
{
	s_rezult	*tmp;

	tmp = rez[i];
	rez[i] = rez[i - 1];
	rez[i - 1] = tmp;
}

void	compare_rez(s_rezult **rez, int i)
{
	s_rezult *tmpnext;
	s_rezult *tmpprev;
	int 	j;

	tmpnext = rez[i];
	while (tmpnext->next != NULL)
	{
		j = 0;
		while (i - j - 1 >= 0)
		{
			tmpprev = rez[i - j - 1];
			while (tmpprev->next != NULL)
			{
				if (ft_strcmp(tmpnext->name, tmpprev->name) == 0)
				{
					free(tmpnext->name);
					free(tmpnext->predecessor);
					free(tmpnext);
					rez[i] = rez[i + 1];
					while (rez[i] != NULL)
					{
						rez[i] = rez[i + 1];
						i++;
					}
				}
				tmpprev = tmpprev->next;
			}
			j++;
		}	
		tmpnext = tmpnext->next;
	}
}

void	del_cross_rez(s_rezult **rez)
{
	int i;
	int j;

	i = 0;
	while (rez[i] != NULL)
	{
		if (i != 0)
			compare_rez(rez, i);
		i++;
	}
}

int 	main_alg(s_map *head)
{
	char	*end;
	s_rezult **rez;
	int		numnbr_start;
	int i;

	i = 0;
	numnbr_start = search_st_nbr(head);
	rez = (s_rezult**)malloc(sizeof(s_rezult*) * (numnbr_start * 2 + 1));
	null_rez_array(&rez, numnbr_start * 2 + 1);
	end = search_flag(head, 2);
	while (i < numnbr_start)
	{
		alg_each_nbr(end, head, &rez[i], i);
		if (i != 0)
			if (len_rez(rez[i]) < len_rez(rez[i - 1]))
				swap_rez(rez, i);
		i++;
	}
	del_cross_rez(rez);
	print_draft(rez);
//	print_rezult(rez, end, head->ant);
	free_main_rez(rez);
	free(rez);
	return (1);
}

// --------------------------------- END ALGHORITM ---------------------------------

int		read_cycle(int fd, s_check *check, s_map *head)
{
	char *line;

	while (ft_get_next_line(fd, &line) > 0)
	{
		if (check_line(line, check) == 1)
			if (write_room(fd, &line, head, check) == 0)
				return (0);
		if (check_line(line, check) == 2)
			write_pipe(line, head, check);
		if (check_line(line, check) == 0)
		{
			free(line);
			break;
		}
		free(line);
	}
	return (1);
}

int		read_map(int fd, s_map *head)
{
	char	*line;
	s_check check;

	init_checkstruct(&check);
	map_init(head);
	if (fd == -1)
		return (0);
	ft_get_next_line(fd, &line);
	if (!(write_ant(line, head)))
		return (0);
	free(line);
	if (read_cycle(fd, &check, head) == 0)
		return (0);
	if (check_after_read(check) == 0)
		return (0);
	return (1);
}

void	start_first(s_map *head)
{
	s_room	*tmp;
	s_room	*prev;

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

int		main (int argc, char **argv)
{
	int		fd;
	s_map	head;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (read_map(fd, &head) == 0)
		{
			ft_putstr("ERROR");
			free_all_map(&head);
			return (0);
		}
		start_first(&head);
		main_alg(&head);
		free_all_map(&head);
		close (fd);
	}
//	system("leaks lemin");
	return (0);
}