/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/29 12:43:24 by ctirions          #+#    #+#             */
/*   Updated: 2020/11/29 12:43:53 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *new_list;

	if (!(new_list = malloc(sizeof(t_list))))
		return (0);
	new_list->content = content;
	new_list->next = 0;
	return (new_list);
}
