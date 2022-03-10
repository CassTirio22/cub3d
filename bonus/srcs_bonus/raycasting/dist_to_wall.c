/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dist_to_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 15:47:14 by aliens            #+#    #+#             */
/*   Updated: 2022/03/10 19:31:32 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	len_protect(double x, double y, t_cub *cub)
{
	if (x < 0 || x > ft_strlen(cub->map->map[0]) || \
	y < 0 || y > double_char_len(cub->map->map))
		return (0);
	return (1);
}

double	add_delta_dist(double delt[2], double s_dist, int b2o, t_cub *cub)
{
	double	delta_dist;
	double	final_len;

	final_len = 0;
	if (b2o)
		delta_dist = fabs(div_protect(1, delt[0]));
	else
		delta_dist = fabs(div_protect(1, delt[1]));
	while (!final_len)
	{
		s_dist += delta_dist;
		if (!len_protect(cub->p1->pos[0] + s_dist * delt[0], \
		cub->p1->pos[1] + s_dist * delt[1], cub))
		{
			if (b2o)
				return (ft_strlen(cub->map->map[0]));
			return (double_char_len(cub->map->map));
		}
		if (is_wall(cub->p1->pos[0] + s_dist * delt[0], \
		cub->p1->pos[1] + s_dist * delt[1], cub))
			final_len = s_dist;
	}
	return (final_len);
}

double	dist_x_to_wall(t_cub *cub, t_player *p1, double pos[2])
{
	double	delt[2];
	double	s_dist;

	delt[0] = cos(p1->angle * (M_PI / 180));
	delt[1] = -sin(p1->angle * (M_PI / 180));
	if (delt[0] < 0)
		s_dist = div_protect((pos[0] - (int)pos[0]), delt[0]);
	else
		s_dist = div_protect((1 - (pos[0] - (int)pos[0])), delt[0]);
	s_dist = fabs(s_dist) + 0.00000001;
	if (!len_protect(pos[0] + s_dist * delt[0], pos[1] + s_dist * delt[1], cub))
		return (ft_strlen(cub->map->map[0]));
	if (is_wall(pos[0] + s_dist * delt[0], pos[1] + s_dist * delt[1], cub))
		return (s_dist);
	return (add_delta_dist(delt, s_dist, 1, cub));
}

double	dist_y_to_wall(t_cub *cub, t_player *p1, double pos[2])
{
	double	delt[2];
	double	s_dist;

	delt[0] = cos(p1->angle * (M_PI / 180));
	delt[1] = -sin(p1->angle * (M_PI / 180));
	if (delt[1] < 0)
		s_dist = div_protect((pos[1] - (int)pos[1]), delt[1]);
	else
		s_dist = div_protect((1 - (pos[1] - (int)pos[1])), delt[1]);
	s_dist = fabs(s_dist) + 0.00000001;
	if (!len_protect(pos[0] + s_dist * delt[0], pos[1] + s_dist * delt[1], cub))
		return (double_char_len(cub->map->map));
	if (is_wall(pos[0] + s_dist * delt[0], pos[1] + s_dist * delt[1], cub))
		return (s_dist);
	return (add_delta_dist(delt, s_dist, 0, cub));
}

double	dist_to_wall(t_cub *cub, t_player *p1, int *color)
{
	double	dist_x;
	double	dist_y;
	double	dist;

	dist_x = dist_x_to_wall(cub, p1, p1->pos);
	dist_y = dist_y_to_wall(cub, p1, p1->pos);
	if (dist_x > dist_y)
	{
		cub->var->touch = 1;
		dist = -dist_y;
	}
	else
	{
		cub->var->touch = 0;
		dist = dist_x;
	}
	if (color)
		*color = get_color(cub, dist);
	return (fabs(dist));
}
