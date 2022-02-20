/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/20 15:44:12 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_view(t_cub *cub, t_player *p1)
{
	double	dx;
	double	dy;
	int		i;
	int		j;

	i = -30;
	while (++i <= 30)
	{
		j = -1;
		dx = 0;
		dy = 0;
		while (++j < cub->var->wall_size)
		{
			dx += cos(((double)p1->angle + i) * (M_PI / 180));
			dy += sin(((double)p1->angle + i) * (M_PI / 180));
			draw_pixel(cub->img, cub->var->wall_size * p1->pos[0] + dx, \
			cub->var->wall_size * p1->pos[1] - dy, 0xFFEB3B);
		}
	}
}

void	draw_player(double x, double y, t_cub *cub)
{
	int	i;
	int	j;
	int	wall_size;
	int	player_size;

	wall_size = cub->var->wall_size;
	player_size = wall_size / 4;
	i = -1;
	while (++i < player_size)
	{
		j = -1;
		while (++j < player_size)
			draw_pixel(cub->img, x * wall_size + i - player_size / 2, \
			y * wall_size + j - player_size / 2, 0xEC57B8);
	}
	draw_view(cub, cub->p1);
}
