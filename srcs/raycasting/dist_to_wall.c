/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 14:39:25 by aliens            #+#    #+#             */
/*   Updated: 2022/03/06 14:39:46 by aliens           ###   ########.fr       */
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
