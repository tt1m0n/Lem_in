/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_ss_short.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:54:55 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 18:54:58 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	use_ss_short(char *str, char **rez, va_list ap, char *p)
{
	if (p[3] == '1')
	{
		size_spec_l(str, rez, ap);
		return ;
	}
	if (p[5] == '1' && p[4] == '0')
	{
		size_spec_h(str, rez, ap);
		return ;
	}
	if (p[4] == '1')
	{
		size_spec_hh(str, rez, ap);
		return ;
	}
}
