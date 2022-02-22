/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/22 18:18:04 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_view(t_cub *cub, t_player *p1)
{
	double	dx;
	double	dy;
	int		i;
	int		j;
	int		player_view;

	player_view = cub->var->wall_size / 2;
	i = -31;
	while (++i < 30)
	{
		j = -1;
		dx = 0;
		dy = 0;
		while (420)
		{
			if (++j < cub->var->wall_size * 5 && !is_wall(cub->p1->pos[0] + dx / cub->var->wall_size, cub->p1->pos[1] - dy / cub->var->wall_size, cub))
			{
				dx += cos(((double)p1->angle + i) * (M_PI / 180));
				dy += sin(((double)p1->angle + i) * (M_PI / 180));
				draw_pixel(cub->img, cub->var->wall_size * 5 + player_view + dx, \
				cub->var->wall_size * 5 + player_view - dy, 0xFFEB3B);

			}
			else if (!is_wall(cub->p1->pos[0] + dx / cub->var->wall_size, cub->p1->pos[1] - dy / cub->var->wall_size, cub))
			{
				dx += cos(((double)p1->angle + i) * (M_PI / 180));
				dy += sin(((double)p1->angle + i) * (M_PI / 180));
			}
			else
			{
				cub->var->dist_to_wall[i + 30] = sqrt(pow(dx / cub->var->wall_size, 2) + pow(dy / cub->var->wall_size, 2));
				printf("%f\n", cub->var->dist_to_wall[i + 30]);
				break ;
			}
		}
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
	while (++i < player_size)
	{
		j = -1;
		while (++j < player_size)
			draw_pixel(cub->img, 5 * wall_size + i + player_size / 2, \
			5 * wall_size + j + player_size / 2, 0xEC57B8);
	}
	draw_view(cub, cub->p1);
}
