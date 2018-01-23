/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mypower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 11:02:25 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/07 11:02:28 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_mypower(int nb, int power)
{
	long long int a;

	a = nb;
	if (power < 0)
	{
		return (0);
	}
	else if (power == 0)
	{
		return (1);
	}
	while (power > 1)
	{
		a = a * nb;
		if (a > 2147483647 || a < -2147483648)
			return (0);
		power--;
	}
	return (a);
}
