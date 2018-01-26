/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_ss_long.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:54:01 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 18:54:04 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		use_ss_long(char *str, char **rez, va_list ap, char *p)
{
	if (p[0] == '1')
	{
		size_spec_j(str, rez, ap);
		return (1);
	}
	if (p[1] == '1')
	{
		size_spec_j(str, rez, ap);
		return (1);
	}
	if (p[2] == '1')
	{
		size_spec_ll(str, rez, ap);
		return (1);
	}
	return (0);
}
