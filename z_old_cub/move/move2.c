/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:05:28 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/10 14:12:14 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
