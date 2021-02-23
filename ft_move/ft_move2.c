/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:05:28 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/23 16:58:10 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_rotate_left(t_cub3d *param)
{
	ft_put_player(*param, 0);
	param->angle -= 5;
	param->angle %= 360;
	ft_put_player(*param, 0x00FFFFFF);
}

void	ft_rotate_right(t_cub3d *param)
{
	ft_put_player(*param, 0);
	param->angle += 5;
	param->angle %= 360;
	ft_put_player(*param, 0x00FFFFFF);
}
