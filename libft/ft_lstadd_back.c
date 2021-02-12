/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:42:15 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/03 15:49:08 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lst_2;

	if (!lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	lst_2 = ft_lstlast(*lst);
	lst_2->next = new;
}
