/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/06 14:55:56 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_raycast(t_cub *cub, double dist_wall)
{
	int		line_h;
	int		angle;
	int		i;
	int		j;
	int		k;
	int		calc;
	double	perp_wall_dist;

	i = -FOV / 2;
	while (++i < FOV / 2)
	{
		angle = abs(i);
		if (!i)
			perp_wall_dist = dist_wall;
		else
			perp_wall_dist = dist_wall / cos(i * (M_PI / 180));
		line_h = (int)(cub->var->resolution[1] / perp_wall_dist);
		if (line_h > cub->var->resolution[1])
			line_h = cub->var->resolution[1];
		calc = cub->var->resolution[0] / FOV;
		k = -1;
		while (++k < calc)
		{
			j = -1;
			while (++j < line_h)
				draw_pixel(cub->img, cub->var->resolution[0] / 2 - (i * calc + k), -j + cub->var->resolution[1] / 2 + line_h / 2, 0x7D4BC1);
		}
	}
}

void	draw_view(t_cub *cub, t_player *p1)
{
	double	dx;
	double	dy;
	int		i;
	int		j;
	int		player_view;
	int		color;

	player_view = cub->var->wall_size / 2;
	draw_raycast(cub, cub->var->dist_wall);
	i = -31;
	while (++i < 31)
	{
		j = -1;
		dx = 0;
		dy = 0;
		p1->angle += i;
		cub->var->dist_wall = dist_x_to_wall(cub, p1);
		color = 0xD20926;
		if (cub->var->dist_wall > dist_y_to_wall(cub, p1))
		{
			color = 0xFFF033;
			cub->var->dist_wall = dist_y_to_wall(cub, p1);
		}
		while (++j < cub->var->wall_size * cub->var->dist_wall && j < 5 * cub->var->wall_size)
		{
			dx += cos((p1->angle) * (M_PI / 180));
			dy += sin((p1->angle) * (M_PI / 180));
			if (color == 0xFFF033 && dy < 0)
				color = 0x0C4392;
			else if (color == 0xD20926 && dx < 0)
				color = 0x0BC103;
			draw_pixel(cub->img, cub->var->wall_size * 5 + player_view + dx, \
			cub->var->wall_size * 5 + player_view - dy, color);
		}
		p1->angle -= i;
	}
}

void	draw_player(t_cub *cub)
{
	int	i;
	int	j;
	int	wall_size;
	int	player_size;

	wall_size = cub->var->wall_size;
	player_size = wall_size / 2;
	i = -1;
	draw_view(cub, cub->p1);
	while (++i < player_size)
	{
		j = -1;
		while (++j < player_size)
			draw_pixel(cub->img, 5 * wall_size + i + player_size / 2, \
			5 * wall_size + j + player_size / 2, 0xEC57B8);
	}
}
