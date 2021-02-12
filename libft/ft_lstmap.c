/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:43:16 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/12 12:53:29 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_all(t_list **lst)
{
	t_list	*tmp;

	while (*lst)
	{
		tmp = *lst;
		free(*lst);
		*lst = tmp->next;
	}
}

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*lst_2;
	t_list	*tmp;

	if (!f || !(lst_2 = ft_lstnew(0)))
		return (0);
	while (lst)
	{
		if (!(ft_lstlast(lst_2)->next = ft_lstnew(f(lst->content))))
		{
			if (del)
				ft_lstclear(&lst_2, del);
			else
				ft_free_all(&lst_2);
			return (0);
		}
		lst = lst->next;
	}
	tmp = lst_2->next;
	free(lst_2);
	return (tmp);
}
