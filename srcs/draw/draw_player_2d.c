/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/06 12:12:10 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

double	dist_x_to_wall(t_cub *cub, t_player *p1)
{
	double	dx;
	double	dy;
	double	side_dist;
	double	delta_dist;
	double	final_len;

	dx = cos(p1->angle * (M_PI / 180));
	dy = -sin(p1->angle * (M_PI / 180));
	final_len = 0;
	if (dx < 0)
		side_dist = div_protect_in_dist_to_wall((p1->pos[0] - (int)p1->pos[0]), dx);
	else
		side_dist = div_protect_in_dist_to_wall((1 - (p1->pos[0] - (int)p1->pos[0])), dx);
	side_dist = fabs(side_dist) + 0.00000001;
	if (p1->pos[0] + side_dist * dx < 0 || p1->pos[0] + side_dist * dx > ft_strlen(cub->map->map[0]) || p1->pos[1] + side_dist * dy < 0 || p1->pos[1] + side_dist * dy > double_char_len(cub->map->map))
		return (ft_strlen(cub->map->map[0]));
	if (is_wall(p1->pos[0] + side_dist * dx, p1->pos[1] + side_dist * dy, cub))
		return (side_dist);
	delta_dist = fabs(div_protect_in_dist_to_wall(1, dx));
	while (!final_len)
	{
		side_dist += delta_dist;
		if (p1->pos[0] + side_dist * dx < 0 || p1->pos[0] + side_dist * dx > ft_strlen(cub->map->map[0]) || p1->pos[1] + side_dist * dy < 0 || p1->pos[1] + side_dist * dy > double_char_len(cub->map->map))
			return (ft_strlen(cub->map->map[0]));
		if (is_wall(p1->pos[0] + side_dist * dx, p1->pos[1] + side_dist * dy, cub))
			final_len = side_dist;
	}
	return (final_len);
}

double	dist_y_to_wall(t_cub *cub, t_player *p1)
{
	double	dx;
	double	dy;
	double	side_dist;
	double	delta_dist;
	double	final_len;

	dx = cos(p1->angle * (M_PI / 180));
	dy = -sin(p1->angle * (M_PI / 180));
	final_len = 0;
	if (dy < 0)
		side_dist = div_protect_in_dist_to_wall((p1->pos[1] - (int)p1->pos[1]), dy);
	else
		side_dist = div_protect_in_dist_to_wall((1 - (p1->pos[1] - (int)p1->pos[1])), dy);
	side_dist = fabs(side_dist) + 0.00000001;
	if (p1->pos[0] + side_dist * dx < 0 || p1->pos[0] + side_dist * dx > ft_strlen(cub->map->map[0]) || p1->pos[1] + side_dist * dy < 0 || p1->pos[1] + side_dist * dy > double_char_len(cub->map->map))
		return (double_char_len(cub->map->map));
	if (is_wall(p1->pos[0] + side_dist * dx, p1->pos[1] + side_dist * dy, cub))
		return (side_dist);
	delta_dist = fabs(div_protect_in_dist_to_wall(1, dy));
	while (!final_len)
	{
		side_dist += delta_dist;
		if (p1->pos[0] + side_dist * dx < 0 || p1->pos[0] + side_dist * dx > ft_strlen(cub->map->map[0]) || p1->pos[1] + side_dist * dy < 0 || p1->pos[1] + side_dist * dy > double_char_len(cub->map->map))
			return (double_char_len(cub->map->map));
		if (is_wall(p1->pos[0] + side_dist * dx, p1->pos[1] + side_dist * dy, cub))
			final_len = side_dist;
	}
	return (final_len);
}

void	draw_view(t_cub *cub, t_player *p1)
{
	double	dist_wall;
	double	dx;
	double	dy;
	int		i;
	int		j;
	int		player_view;
	int		color;

	player_view = cub->var->wall_size / 2;
	i = -31;
	while (++i < 31)
	{
		j = -1;
		dx = 0;
		dy = 0;
		p1->angle += i;
		dist_wall = dist_x_to_wall(cub, p1);
		color = 0xD20926;
		if (dist_wall > dist_y_to_wall(cub, p1))
		{
			color = 0xFFF033;
			dist_wall = dist_y_to_wall(cub, p1);
		}
		p1->angle -= i;
		while (++j < cub->var->wall_size * dist_wall && j < 5 * cub->var->wall_size)
		{
			dx += cos((p1->angle + i) * (M_PI / 180));
			dy += sin((p1->angle + i) * (M_PI / 180));
			if (color == 0xFFF033 && dy < 0)
				color = 0x0C4392;
			else if (color == 0xD20926 && dx < 0)
				color = 0x0BC103;
			draw_pixel(cub->img, cub->var->wall_size * 5 + player_view + dx, \
			cub->var->wall_size * 5 + player_view - dy, color);
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
