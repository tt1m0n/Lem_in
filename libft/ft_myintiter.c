/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myintiter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:41:50 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/07 10:41:57 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_myintiter(int *tab, int length, void (*f)(int))
{
	int i;

	i = 0;
	if ((tab == NULL) || (f == NULL))
		return ;
	while (i < length)
	{
		f(tab[i]);
		i++;
	}
}
