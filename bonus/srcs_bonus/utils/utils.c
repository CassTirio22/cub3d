/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:40:06 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/10 17:24:51 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

void	print_double_char(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		ft_putstr_fd(str[i], 1);
		write(1, "\n", 1);
	}
}

void	print_lst(t_list *lst)
{
	t_list	*lst2;

	if (!lst)
		return ;
	lst2 = lst;
	while (lst2)
	{
		ft_putendl_fd(lst2->content, 1);
		lst2 = lst2->next;
	}
}

char	**lst_to_double_char(t_list *lst)
{
	char	**ret;
	t_list	*tmp;
	int		size;

	size = ft_lstsize(lst);
	ret = (char **)malloc(sizeof(char *) * (size + 1));
	if (!ret)
		return (NULL);
	size = 0;
	while (lst)
	{
		tmp = lst;
		ret[size++] = lst->content;
		lst = lst->next;
		free(tmp);
	}
	ret[size] = NULL;
	return (ret);
}

int	double_char_len(char **str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		i++;
	return (i);
}
