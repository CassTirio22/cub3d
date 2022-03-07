/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/07 13:47:47 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	line_height(int i, t_cub *cub, double dist_wall, int color)
{
	int		ret;
	int		j;
	int		k;
	int		calc;

	if (!i)
		cub->var->perp_wall_dist = dist_wall;
	else
		cub->var->perp_wall_dist = dist_wall / cos(i * (M_PI / 180));
	ret = (int)(cub->var->resolution[1] / cub->var->perp_wall_dist);
	if (ret > cub->var->resolution[1])
		ret = cub->var->resolution[1];
	k = -1;
	calc = cub->var->resolution[0] / 60;
	while (++k < calc)
	{
		j = -1;
		while (++j < ret)
			draw_pixel(cub->img, cub->var->resolution[0] / 2 - (i * calc + k), \
			-j + cub->var->resolution[1] / 2 + ret / 2, color);
	}
	return (ret);
}

void	draw_view(t_cub *cub, t_player *p1, t_var *var)
{
	int		i;
	int		j;
	int		player_view;
	int		color;

	player_view = var->wall_size / 2;
	i = -31;
	while (++i < 31)
	{
		j = -1;
		var->dx = cos((p1->angle + i) * (M_PI / 180));
		var->dy = sin((p1->angle + i) * (M_PI / 180));
		p1->angle += i;
		var->dist_wall = dist_to_wall(cub, p1, &color);
		p1->angle -= i;
		while (++j < var->wall_size * var->dist_wall && j < 5 * var->wall_size)
		{
			draw_pixel(cub->img, var->wall_size * 10 + player_view + var->dx, \
			var->wall_size * 10 + player_view - var->dy, color);
			var->dx += cos((p1->angle + i) * (M_PI / 180));
			var->dy += sin((p1->angle + i) * (M_PI / 180));
		}
		line_height(i, cub, var->dist_wall, color);
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
	draw_view(cub, cub->p1, cub->var);
	while (++i < player_size)
	{
		j = -1;
		while (++j < player_size)
			draw_pixel(cub->img, 10 * wall_size + i + player_size / 2, \
			10 * wall_size + j + player_size / 2, 0xEC57B8);
	}
}
