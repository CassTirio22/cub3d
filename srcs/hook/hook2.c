/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:26:14 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/19 15:27:46 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close(t_cub *cub)
{
	free_all(cub);
	exit (0);
	return (0);
}

int	rot_left(t_cub *cub)
{
	cub->p1->angle += 10;
	cub->p1->angle %= 360;	
	return (0);
}

int	rot_right(t_cub *cub)
{
	cub->p1->angle -= 10;
	cub->p1->angle %= 360;	
	return (0);
}

int	ft_key(int key, t_cub *cub)
{
	//printf("key : %d\n", key);
	if (key == KEY_ESC)
		ft_close(cub);
	else if (key == KEY_W)
		ft_up(cub, 0);
	else if (key == KEY_S)
		ft_down(cub, 0);
	else if (key == KEY_A)
		ft_left(cub, 0);
	else if (key == KEY_D)
		ft_right(cub, 0);
	else if (key == KEY_LEFT)
		rot_left(cub);
	else if (key == KEY_RIGHT)
		rot_right(cub);
	draw_map(cub);
	return (0);
}

