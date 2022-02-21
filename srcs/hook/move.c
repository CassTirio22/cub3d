/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:32:54 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/21 02:08:48 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	up(t_cub *cub, int b2o)
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
		up(cub, ++b2o);
	return (0);
}

int	down(t_cub *cub, int b2o)
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
		down(cub, ++b2o);
	return (0);
}

int	left(t_cub *cub, int b2o)
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
		left(cub, ++b2o);
	return (0);
}

int	right(t_cub *cub, int b2o)
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
		right(cub, ++b2o);
	return (0);
}

int	make_moves(t_cub *cub)
{
	if (cub->var->up == 1)
		up(cub, 0);
	if (cub->var->down == 1)
		down(cub, 0);
	if (cub->var->left == 1)
		left(cub, 0);
	if (cub->var->right == 1)
		right(cub, 0);
	if (cub->var->rot_left == 1)
		rot_left(cub);
	if (cub->var->rot_right == 1)
		rot_right(cub);
	draw_map(cub);
	return (0);
}
