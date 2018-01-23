/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omakovsk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/05 18:24:45 by omakovsk          #+#    #+#             */
/*   Updated: 2018/01/20 21:59:24 by omakovsk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_free(t_list *del, t_list *head)
{
	while (del != NULL)
	{
		head = head->next;
		free(del);
		del = head;
	}
	head = NULL;
	return (NULL);
}

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *new;
	t_list *del;

	if ((lst == NULL) || (f == NULL))
		return (NULL);
	new = (t_list*)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new = f(lst);
	lst = lst->next;
	head = new;
	del = head;
	while (lst != NULL)
	{
		new->next = (t_list*)malloc(sizeof(t_list));
		if (new->next == NULL)
			return (ft_free(del, head));
		new->next = f(lst);
		lst = lst->next;
		new = new->next;
	}
	return (head);
}
