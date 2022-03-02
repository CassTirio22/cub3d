/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/02 15:39:58 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	dist_to_wall(t_cub *cub, t_player *p1)
{
	double	dx;
	double	dy;
	double	side_dist[2];
	double	delta_dist[2];
	double	final_len;

	dx = cos(p1->angle * (M_PI / 180));
	dy = -sin(p1->angle * (M_PI / 180));
	final_len = 0;

	if (dx < 0)
		side_dist[0] = div_protect_in_dist_to_wall((p1->pos[0] - (int)p1->pos[0]), dx);
	else
		side_dist[0] = div_protect_in_dist_to_wall((1 - (p1->pos[0] - (int)p1->pos[0])), dx);
	if (dy < 0)
		side_dist[1] = div_protect_in_dist_to_wall((p1->pos[1] - (int)p1->pos[1]), dy);
	else
		side_dist[1] = div_protect_in_dist_to_wall((1 - (p1->pos[1] - (int)p1->pos[1])), dy);
	side_dist[0] = fabs(side_dist[0]) + 0.00000001;
	side_dist[1] = fabs(side_dist[1]) + 0.00000001;
	printf("side_x = %f || side_y = %f\n", side_dist[0], side_dist[1]);
	printf("dx = %f || dy = %f\n", dx, dy);
	if (is_wall(p1->pos[0] + side_dist[0] * dx, p1->pos[1] + side_dist[0] * dy, cub))
		final_len = side_dist[0];
	if (is_wall(p1->pos[0] + side_dist[1] * dx, p1->pos[1] + side_dist[1] * dy, cub))
		if (final_len > side_dist[1] || !final_len)
			final_len = side_dist[1];
	if (final_len)
	{
		printf("LADEDANS\n");
		return (final_len);
	}
	delta_dist[0] = fabs(div_protect_in_dist_to_wall(1, dx));
	delta_dist[1] = fabs(div_protect_in_dist_to_wall(1, dy));
	while (!final_len)
	{
		printf("1");
		side_dist[0] += delta_dist[0];
		side_dist[1] += delta_dist[1];
		printf("2");
		if (is_wall(p1->pos[0] + side_dist[0] * dx, p1->pos[1] + side_dist[0] * dy, cub))
			final_len = side_dist[0];
		printf("3");
		if (is_wall(p1->pos[0] + side_dist[1] * dx, p1->pos[1] + side_dist[1] * dy, cub))
		{
			printf("4");
			if (final_len > side_dist[1] || !final_len)
			{
				printf("5");
				final_len = side_dist[1];
			}

		}
		printf("6\n");
	}
	return (final_len);
}

void	draw_view(t_cub *cub, t_player *p1)
{
	double	dx;
	double	dy;
	double	j;
	double	dist_wall;
	int		i;
	int		player_view;

	player_view = cub->var->wall_size / 2;
	i = -1;
	while (++i < 1)
	{
		j = -1;
		dx = 0;
		dy = 0;
		dist_wall = dist_to_wall(cub, p1);
		printf("dist_wall = %f\n", dist_wall);
		while (++j < cub->var->wall_size * dist_wall && j < 6.5 * cub->var->wall_size)
		{
			dx += cos((p1->angle + i) * (M_PI / 180));
			dy += sin((p1->angle + i) * (M_PI / 180));
			draw_pixel(cub->img, cub->var->wall_size * 5 + player_view + dx, \
			cub->var->wall_size * 5 + player_view - dy, 0xD20926);
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
