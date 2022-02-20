/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:42:14 by aliens            #+#    #+#             */
/*   Updated: 2022/02/20 15:43:04 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_key(int key, t_cub *cub)
{
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

int	ft_close(t_cub *cub)
{
	free_all(cub);
	exit (0);
	return (0);
}
