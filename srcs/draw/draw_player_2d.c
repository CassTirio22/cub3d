/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_player_2d.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/20 20:26:51 by ctirions         ###   ########.fr       */
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
	i = -30;
	while (++i <= 30)
	{
		j = -1;
		dx = 0;
		dy = 0;
		while (++j < cub->var->wall_size)
		{
			dx += cos(((double)p1->angle + i) * (M_PI / 180));
			dy += sin(((double)p1->angle + i) * (M_PI / 180));
			draw_pixel(cub->img, cub->var->wall_size * 15 + player_view + dx, \
			cub->var->wall_size * 15 + player_view - dy, 0xFFEB3B);
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
			draw_pixel(cub->img, 15 * wall_size + i + player_size / 2, \
			15 * wall_size + j + player_size / 2, 0xEC57B8);
	}
	draw_view(cub, cub->p1);
}
