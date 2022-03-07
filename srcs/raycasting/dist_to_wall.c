/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:47:14 by aliens            #+#    #+#             */
/*   Updated: 2022/03/07 15:28:30 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	len_protect(double x, double y, t_cub *cub)
{
	if (x < 0 || x > ft_strlen(cub->map->map[0]) || \
	y < 0 || y > double_char_len(cub->map->map))
		return (0);
	return (1);
}

double	dist_x_to_wall(t_cub *cub, t_player *p1, double pos[2])
{
	double	dx;
	double	dy;
	double	s_dist;
	double	delta_dist;
	double	final_len;

	dx = cos(p1->angle * (M_PI / 180));
	dy = -sin(p1->angle * (M_PI / 180));
	final_len = 0;
	if (dx < 0)
		s_dist = div_protect((pos[0] - (int)pos[0]), dx);
	else
		s_dist = div_protect((1 - (pos[0] - (int)pos[0])), dx);
	s_dist = fabs(s_dist) + 0.00000001;
	if (!len_protect(pos[0] + s_dist * dx, pos[1] + s_dist * dy, cub))
		return (ft_strlen(cub->map->map[0]));
	if (is_wall(pos[0] + s_dist * dx, pos[1] + s_dist * dy, cub))
		return (s_dist);
	delta_dist = fabs(div_protect(1, dx));
	while (!final_len)
	{
		s_dist += delta_dist;
		if (!len_protect(pos[0] + s_dist * dx, pos[1] + s_dist * dy, cub))
			return (ft_strlen(cub->map->map[0]));
		if (is_wall(pos[0] + s_dist * dx, pos[1] + s_dist * dy, cub))
			final_len = s_dist;
	}
	return (final_len);
}

double	dist_y_to_wall(t_cub *cub, t_player *p1, double pos[2])
{
	double	dx;
	double	dy;
	double	s_dist;
	double	delta_dist;
	double	final_len;

	dx = cos(p1->angle * (M_PI / 180));
	dy = -sin(p1->angle * (M_PI / 180));
	final_len = 0;
	if (dy < 0)
		s_dist = div_protect((pos[1] - (int)pos[1]), dy);
	else
		s_dist = div_protect((1 - (pos[1] - (int)pos[1])), dy);
	s_dist = fabs(s_dist) + 0.00000001;
	if (!len_protect(pos[0] + s_dist * dx, pos[1] + s_dist * dy, cub))
		return (double_char_len(cub->map->map));
	if (is_wall(pos[0] + s_dist * dx, pos[1] + s_dist * dy, cub))
		return (s_dist);
	delta_dist = fabs(div_protect(1, dy));
	while (!final_len)
	{
		s_dist += delta_dist;
		if (!len_protect(pos[0] + s_dist * dx, pos[1] + s_dist * dy, cub))
			return (double_char_len(cub->map->map));
		if (is_wall(pos[0] + s_dist * dx, pos[1] + s_dist * dy, cub))
			final_len = s_dist;
	}
	return (final_len);
}

double	dist_to_wall(t_cub *cub, t_player *p1, int *color)
{
	double	dist_x;
	double	dist_y;

	dist_x = dist_x_to_wall(cub, p1, p1->pos);
	dist_y = dist_y_to_wall(cub, p1, p1->pos);
	if (dist_x > dist_y)
	{
		if (color)
			*color = 0xFFF033;
		if (color && cub->var->dy < 0)
			*color = 0x0C4392;
		return (dist_y);
	}
	if (color)
		*color = 0xD20926;
	if (color && cub->var->dx < 0)
		*color = 0x0BC103;
	return (dist_x);
}
