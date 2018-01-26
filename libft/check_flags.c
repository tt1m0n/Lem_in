/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 19:51:20 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:32:54 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_minus_plus(char *str, char **rez)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[i] != '\0')
		if (str[i++] == '-')
			make_minus_flag(rez);
	i = 0;
	while (str[i] != '\0')
		if (str[i++] == '+' && (str[len] == 'd' ||
			str[len] == 'D' || str[len] == 'i'))
			make_plus_flag(rez);
}

static void	check_another_flag(char *str, char **rez)
{
	int		i;
	size_t	len;

	i = 0;
	len = ft_strlen(str) - 1;
	while (str[i] != '.' && !(ft_isalpha(str[i]))\
		&& (!(ft_isdigit(str[i])) || str[i] == '0'))
		if (str[i++] == '0' && str[len] != 'C')
			make_zero_flag(str, rez);
	i = 0;
	while (str[i] != '\0')
		if (str[i++] == ' ' && (str[ft_strlen(str) - 1] == 'd' ||
			str[len] == 'D' || str[len] == 'i'))
			make_space_flag(str, rez);
	i = 0;
	while (str[i] != '\0')
		if (str[i++] == '#' && (str[len] == 'o' || str[len] == 'O' ||
			str[len] == 'x' || str[len] == 'X'))
			make_sharp_flag(str, rez);
}

void		check_flags(char *str, char **rez)
{
	check_minus_plus(str, rez);
	check_another_flag(str, rez);
}
