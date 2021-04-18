/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:05:28 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/18 16:39:28 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_rotate_left(t_struct_list *struct_list)
{
	struct_list->param->angle -= 15;
	struct_list->param->angle %= 360;
}

void	ft_rotate_right(t_struct_list *struct_list)
{
	struct_list->param->angle += 15;
	struct_list->param->angle %= 360;
}
