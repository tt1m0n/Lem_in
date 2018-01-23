/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:23:38 by omakovsk          #+#    #+#             */
/*   Updated: 2017/11/06 12:52:27 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;
	t_list *other;

	if ((alst == NULL) || (del == NULL))
		return ;
	current = *alst;
	while (current != NULL)
	{
		other = current->next;
		del(current->content, current->content_size);
		free(current);
		current = other;
	}
	*alst = NULL;
}
