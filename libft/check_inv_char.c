/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_inv_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 20:02:21 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:31:55 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	check_inv_char(char *str, char p, int *n)
{
	int		len;
	char	*rez;

	*n = 0;
	if (!(rez = (char*)malloc(sizeof(char) * 2)))
		return (0);
	rez[0] = p;
	rez[1] = '\0';
	check_min_width(str, &rez);
	check_flags(str, &rez);
	len = ft_strlen(rez);
	write(1, rez, len);
	ft_strclr(rez, len);
	free(rez);
	return (len);
}
