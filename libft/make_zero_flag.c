/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_zero_flag.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:43:56 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 19:43:58 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	make_zero_flag(char *s, char **rez)
{
	int		i;
	char	*tmp;
	size_t	len;

	i = 0;
	tmp = *rez;
	len = ft_strlen(s) - 1;
	while (s[i] != '\0')
	{
		if ((s[i] == '.' || s[i] == '-') && s[len] != 'c' && s[len] != 's' &&
			s[len] != '%' && (check_char(s[len]) == 0) && s[len] != 'S')
			return ;
		i++;
	}
	if ((*rez)[0] == ' ')
	{
		*rez = ft_prnt_add_zero(*rez);
		free(tmp);
	}
}
