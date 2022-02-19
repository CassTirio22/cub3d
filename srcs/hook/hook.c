/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:32:54 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/19 18:03:13 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_up(t_cub *cub, int b2o)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * cub->p1->angle) * 1 / 64;
	dy = sin((M_PI / 180) * cub->p1->angle) * 1 / 64;
	if (is_wall((int)(cub->p1->pos[0] + dx - 0.125), \
	(int)(cub->p1->pos[1] - dy - 0.125), cub))
		return (0);
	if (is_wall((int)(cub->p1->pos[0] + dx + 0.125), \
	(int)(cub->p1->pos[1] - dy + 0.125), cub))
		return (0);
	if (is_wall((int)(cub->p1->pos[0] + dx - 0.125), \
	(int)(cub->p1->pos[1] - dy + 0.125), cub))
		return (0);
	if (is_wall((int)(cub->p1->pos[0] + dx + 0.125), \
	(int)(cub->p1->pos[1] - dy - 0.125), cub))
		return (0);
	cub->p1->pos[0] += dx;
	cub->p1->pos[1] -= dy;
	if (b2o <= 8)
		ft_up(cub, ++b2o);
	return (0);
}

int	ft_down(t_cub *cub, int b2o)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * cub->p1->angle) * 1 / 64;
	dy = sin((M_PI / 180) * cub->p1->angle) * 1 / 64;
	if (is_wall(cub->p1->pos[0] - dx - 0.125, \
	cub->p1->pos[1] + dy - 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] - dx + 0.125, \
	cub->p1->pos[1] + dy + 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] - dx - 0.125, \
	cub->p1->pos[1] + dy + 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] - dx + 0.125, \
	cub->p1->pos[1] + dy - 0.125, cub))
		return (0);
	cub->p1->pos[0] -= dx;
	cub->p1->pos[1] += dy;
	if (b2o <= 8)
		ft_down(cub, ++b2o);
	return (0);
}

int	ft_left(t_cub *cub, int b2o)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * cub->p1->angle) * 1 / 64;
	dy = sin((M_PI / 180) * cub->p1->angle) * 1 / 64;
	if (is_wall(cub->p1->pos[0] - dy - 0.125, \
	cub->p1->pos[1] - dx - 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] - dy + 0.125, \
	cub->p1->pos[1] - dx + 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] - dy - 0.125, \
	cub->p1->pos[1] - dx + 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] - dy + 0.125, \
	cub->p1->pos[1] - dx - 0.125, cub))
		return (0);
	cub->p1->pos[0] -= dy;
	cub->p1->pos[1] -= dx;
	if (b2o <= 8)
		ft_left(cub, ++b2o);
	return (0);
}

int	ft_right(t_cub *cub, int b2o)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * cub->p1->angle) * 1 / 64;
	dy = sin((M_PI / 180) * cub->p1->angle) * 1 / 64;
	if (is_wall(cub->p1->pos[0] + dy - 0.125, \
	cub->p1->pos[1] + dx - 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] + dy + 0.125, \
	cub->p1->pos[1] + dx + 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] + dy + 0.125, \
	cub->p1->pos[1] + dx - 0.125, cub))
		return (0);
	if (is_wall(cub->p1->pos[0] + dy - 0.125, \
	cub->p1->pos[1] + dx + 0.125, cub))
		return (0);
	cub->p1->pos[0] += dy;
	cub->p1->pos[1] += dx;
	if (b2o <= 8)
		ft_right(cub, ++b2o);
	return (0);
}
