/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/22 13:47:54 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/22 13:47:56 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

#include "../libft/libft.h"
#include <fcntl.h>

typedef struct		s_rezult
{
	char 			*predecessor;
	char 			*name;
	struct s_rezult	*next;
}					t_rezult;

typedef struct		s_qeueu
{
	char 			*predecessor;
	char 			*name;
	struct s_qeueu	*next;
}					t_qeueu;

typedef struct		s_used
{
	char 			*predecessor;
	char 			*name;
	struct s_used	*next;
}					t_used;

typedef struct		s_nbr
{
	char			*name;
	struct s_nbr	*nextnbr;
}					t_nbr;

typedef struct 		s_room
{
    char			*name;
	int				x;
	int				y;
	int				flag;
	struct s_room	*nextroom;
	struct s_nbr	*headnbr;
}					t_room;

typedef struct		s_map
{
	unsigned long	ant;
	t_room			*allroom;
}					t_map;

typedef struct		s_check
{
	int 			count_st_sharp;
	int 			count_end_sharp;
	int 			count_st_path;
	int 			count_end_path;
	int				pipe;
	int 			room;
}					t_check;

void				start_first(t_map *head);
int					read_map(int fd, t_map *head);
void				free_all_map(t_map *map);
int					main_alg(t_map *head);
int					read_cycle(int fd, t_check *check, t_map *head);
void				init_check_map(t_check *check, t_map *head);
int					write_ant(char *line, t_map *head);
int					write_room(int fd, char **line, t_map *head, t_check *check);
void				write_pipe(char *line, t_map *head, t_check *check);
int					check_line(char *line, t_check *check, t_map *head);
int					check_after_read(t_check check);
void				free_split(char ***split, int i);
int 				check_if_alpha(char *str);
int 				check_same_room(char **split);
int 				check_space(char **split);
int					check_existence(char *str, t_map *head);
void				init_newroom(char *line, t_room **new_room, int flag);
int					check_new_room(t_room **new_room, t_room *head);
void 				null_rez_array(t_rezult ***rez, int num);
char				*search_flag(t_map *head, int flag);
void				alg_each_nbr(char *end, t_map *head, t_rezult **rez, int num);
int					len_rez(t_rezult *rez);
void				swap_rez(t_rezult **rez, int i);
int 				search_st_nbr(t_map *head);
void				del_cross_rez(t_rezult **rez);
int					count_rez(t_rezult **rez);
void				search_best_ways(t_rezult **rez, int ant, int **ants_on_way);
void				print_rezult(t_rezult **rez, int ant, int *ants_on_way);
void				free_main_rez(t_rezult **rez);
int					search_add_end(t_used *used, t_rezult **rez, char *end);
void				search_add_predecessor(t_used *used, t_rezult **rez);
t_nbr				*search_room(t_map *head, char *name);
void				count_antway(t_rezult **rez, int **onway, int *time);
void				free_used(t_used *used);
int					free_dublicat_rez(t_rezult **elem, t_rezult ***rez, int i);
int					add_rezult(t_rezult **rez, t_used *used, char *end);
void				add_front_used(t_used **used, t_qeueu *stack);
void				pop_first_stack(t_qeueu **stack);
int					count_notzero_way(int *ants_on_way, t_rezult **rez);

#endif
