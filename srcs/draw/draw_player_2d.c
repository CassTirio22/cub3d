/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/23 20:03:47 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	forward_dir(t_cub *cub, t_player *p1)
{
	double	final_len;
	double	dx;
	double	dy;
	double	side_dist;

	final_len = 0;
	dx = cos(p1->angle * M_PI / 180);
	dy = sin(p1->angle * M_PI / 180);
	printf("%f | %f\n", dx, dy);
	side_dist = 0;
	if (dy == 1)
		side_dist = p1->pos[1] - (int)p1->pos[1];
	if (dx == -1)
		side_dist = p1->pos[0] - (int)p1->pos[0];
	if (dy == -1)
		side_dist = 1 - (p1->pos[1] - (int)p1->pos[1]);
	if (dx == 1)
		side_dist = 1 - (p1->pos[1] - (int)p1->pos[1]);
	if (is_wall(p1->pos[0] + (dx * side_dist) / cub->var->wall_size, p1->pos[1] - (dy * side_dist) / cub->var->wall_size, cub))
		final_len = side_dist;
	if (final_len)
		return (fabs(final_len));
	while (!final_len)
	{
		side_dist += 1;
		if (is_wall(p1->pos[0] + (dx * side_dist) / cub->var->wall_size, p1->pos[1] - (dy * side_dist) / cub->var->wall_size, cub))
			final_len = side_dist;
	}
	return (fabs(final_len));
}

double	dist_to_wall(t_cub *cub, t_player *p1)
{
	double	side_dist[2];
	double	delta_dist[2];
	double	final_len;
	double	dx;
	double	dy;

	dx = cos(p1->angle * M_PI / 180);
	dy = sin(p1->angle * M_PI / 180);
	final_len = 0;
	if (abs(p1->angle) == 90 || abs(p1->angle) == 180 || abs(p1->angle) == 270 || abs(p1->angle) == 0)
		return (forward_dir(cub, p1));
	if (dx <= 0)
		side_dist[0] = (p1->pos[0] - (int)p1->pos[0]) / dx;
	else
		side_dist[0] = (1 - (p1->pos[0] - (int)p1->pos[0])) / dx;
	if (dy <= 0)
		side_dist[1] = (p1->pos[1] - (int)p1->pos[1]) / dy;
	else
		side_dist[1] = (1 - (p1->pos[1] - (int)p1->pos[1])) / dy;
	//printf("side_dist : %f\n", side_dist[0]);
	delta_dist[0] = 1 / dx;
	delta_dist[1] = 1 / dy;
	if (is_wall(p1->pos[0] + (dx * side_dist[0]) / cub->var->wall_size, p1->pos[1] + (dy * side_dist[0]) / cub->var->wall_size, cub))
		final_len = side_dist[0];
	if (is_wall(p1->pos[0] - (dx * side_dist[1]) / cub->var->wall_size, p1->pos[1] - (dy * side_dist[1]) / cub->var->wall_size, cub))
		if (final_len > side_dist[1])
			final_len = side_dist[1];
	if (final_len)
		return (fabs(final_len));
	while (!final_len)
	{
		side_dist[0] += delta_dist[0];
		side_dist[1] += delta_dist[1];
		if (is_wall(p1->pos[0] + (dx * side_dist[0]) / cub->var->wall_size, p1->pos[1] + (dy * side_dist[0]) / cub->var->wall_size, cub))
			final_len = side_dist[0];
		if (is_wall(p1->pos[0] - (dx * side_dist[1]) / cub->var->wall_size, p1->pos[1] - (dy * side_dist[1]) / cub->var->wall_size, cub))
			if (final_len > side_dist[1])
				final_len = side_dist[1];
	}
	return (fabs(final_len));
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
		printf("%f\n", dist_wall);
		while (++j < dist_wall)
		{
			dx += cos((p1->angle + i) * (M_PI / 180));
			dy += sin((p1->angle + i) * (M_PI / 180));
			draw_pixel(cub->img, cub->var->wall_size * 10 + player_view + dx, \
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
			draw_pixel(cub->img, 10 * wall_size + i + player_size / 2, \
			5 * wall_size + j + player_size / 2, 0xEC57B8);
	}
	draw_view(cub, cub->p1);
}
