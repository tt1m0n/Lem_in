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

#include <stdio.h>

#include "../libft/libft.h"
#include <fcntl.h>

typedef struct		t_nbr
{
	char			*name;
	struct t_nbr	*nextnbr;
}					s_nbr;

typedef struct 		t_room
{
    char			*name;
	int				x;
	int				y;
	int				flag;
	struct t_room	*nextroom;
	struct t_nbr	*headnbr;
}					s_room;

typedef struct		t_map
{
	unsigned long	ant;
	s_room			*allroom;
}					s_map;

typedef struct		t_check
{
	int 			count_st_sharp;
	int 			count_end_sharp;
	int 			count_st_path;
	int 			count_end_path;
	int				pipe;
	int 			room;
}					s_check;

#endif
