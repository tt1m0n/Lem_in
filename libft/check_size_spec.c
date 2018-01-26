/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_size_spec.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/26 18:58:49 by omakovsk          #+#    #+#             */
/*   Updated: 2017/12/26 22:42:46 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	check_size_spec(char *str, char **rez, va_list ap)
{
	char *p;

	p = ft_prnt_memalloc(6);
	if (ft_prnt_strstr(str, "j"))
		p[0] = '1';
	else if (ft_prnt_strstr(str, "z"))
		p[1] = '1';
	else if (ft_prnt_strstr(str, "ll"))
		p[2] = '1';
	else if (ft_prnt_strstr(str, "l"))
		p[3] = '1';
	else if (ft_prnt_strstr(str, "hh"))
		p[4] = '1';
	else if (ft_prnt_strstr(str, "h"))
		p[5] = '1';
	if (use_ss_long(str, rez, ap, p) == 0)
		use_ss_short(str, rez, ap, p);
	ft_strclr(p, 6);
	free(p);
}
