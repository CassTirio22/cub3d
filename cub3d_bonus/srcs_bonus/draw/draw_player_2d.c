/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/10 17:24:31 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_view(t_cub *cub, t_player *p1, t_var *var)
{
	int		i;
	int		j;
	int		player_view;
	int		color;

	player_view = var->wall_size / 2;
	color = 0;
	i = -31;
	while (++i < 31)
	{
		p1->angle += i;
		var->dx = cos((p1->angle) * (M_PI / 180));
		var->dy = sin((p1->angle) * (M_PI / 180));
		var->dist_wall = dist_to_wall(cub, p1, &color);
		j = -1;
		while (++j < var->wall_size * var->dist_wall && j < 5 * var->wall_size)
		{
			draw_pixel(cub->img, var->wall_size * 10 + player_view + var->dx, \
			var->wall_size * 10 + player_view - var->dy, color);
			var->dx += cos((p1->angle) * (M_PI / 180));
			var->dy += sin((p1->angle) * (M_PI / 180));
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
	draw_view(cub, cub->p1, cub->var);
	while (++i < player_size)
	{
		j = -1;
		while (++j < player_size)
			draw_pixel(cub->img, 10 * wall_size + i + player_size / 2, \
			10 * wall_size + j + player_size / 2, 0xEC57B8);
	}
}
