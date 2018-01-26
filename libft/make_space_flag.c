/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_space_flag.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:45:27 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 19:45:29 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_space_flag(char *str, char **rez)
{
	int		i;
	char	*tmp;
	size_t	len;

	i = 0;
	tmp = *rez;
	len = ft_strlen(*rez) - 1;
	while (str[i] != '\0')
		if ((str[i++] == '+') || (*rez)[0] == ' ')
			return ;
	i = 0;
	while ((*rez)[i] != '\0')
		if ((*rez)[i++] == '-')
			return ;
	if (ft_isdigit((*rez)[0]) && (*rez)[len] != ' ')
		*rez = ft_strjoin(" ", *rez);
	if (ft_isdigit((*rez)[0]) && ((*rez)[len] == ' ' || (*rez)[0] == '0'))
		*rez = ft_prnt_space_flag(*rez);
	free(tmp);
}
