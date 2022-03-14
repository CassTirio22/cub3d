/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:32:54 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/14 18:43:53 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	move(float dx, float dy, t_cub *cub, int recurse)
{
	int		add_x;
	int		add_y;
	float	calc_x;
	float	calc_y;

	add_x = 0;
	add_y = 0;
	calc_x = cub->p1->pos[0] + dx;
	calc_y = cub->p1->pos[1] + dy;
	if (!is_wall_around(calc_x, cub->p1->pos[1], cub))
		add_x = 1;
	if (!is_wall_around(cub->p1->pos[0], calc_y, cub))
		add_y = 1;
	if (is_wall_around(calc_x, calc_y, cub) && add_x && add_y)
		return ;
	if (add_x)
		cub->p1->pos[0] += dx;
	if (add_y)
		cub->p1->pos[1] += dy;
	if (recurse <= 8)
		move(dx, dy, cub, ++recurse);
}

int	make_moves(t_cub *cub)
{
	float	dx;
	float	dy;

	dx = cos(cub->p1->angle * M_PI / 180) * 1 / 128;
	dy = sin(cub->p1->angle * M_PI / 180) * 1 / 128;
	if (cub->var->run)
	{
		dx = cos(cub->p1->angle * M_PI / 180) * 1 / 64;
		dy = sin(cub->p1->angle * M_PI / 180) * 1 / 64;
	}
	if (cub->var->up == 1)
		move(dx, -dy, cub, 0);
	if (cub->var->down == 1)
		move(-dx, dy, cub, 0);
	if (cub->var->left == 1)
		move(-dy, -dx, cub, 0);
	if (cub->var->right == 1)
		move(dy, dx, cub, 0);
	if (cub->var->rot_left == 1)
		rot_left(cub);
	if (cub->var->rot_right == 1)
		rot_right(cub);
	rotate(cub);
	draw_game(cub);
	return (0);
}
