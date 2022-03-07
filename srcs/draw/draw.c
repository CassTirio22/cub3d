/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:43:21 by aliens            #+#    #+#             */
/*   Updated: 2022/03/07 15:12:36 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_all(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->var->resolution[0])
	{
		j = -1;
		while (++j < cub->var->resolution[1])
			draw_pixel(cub->img, i, j, 0x000000);
	}
}

void	draw_line_height(int i, t_cub *cub, double dist_wall, int color)
{
	int		h;
	int		j;
	int		k;
	int		calc;

	if (!i)
		cub->var->perp_wall_dist = dist_wall;
	else
		cub->var->perp_wall_dist = dist_wall / cos(i * (M_PI / 180));
	h = (int)(cub->var->resolution[1] / cub->var->perp_wall_dist);
	if (h > cub->var->resolution[1])
		h = cub->var->resolution[1];
	k = -1;
	calc = cub->var->resolution[0] / 60;
	while (++k < calc)
	{
		j = -1;
		while (++j < h)
			draw_pixel(cub->img, cub->var->resolution[0] / 2 - (i * calc + k), \
			-j + cub->var->resolution[1] / 2 + h / 2, color);
	}
}

void	draw_game(t_cub *cub)
{
	int	i;
	int	color;

	draw_all(cub);
	color = 0;
	i = -31;
	while (++i < 31)
	{
		cub->p1->angle += i;
		cub->var->dx = cos((cub->p1->angle) * (M_PI / 180));
		cub->var->dy = sin((cub->p1->angle) * (M_PI / 180));
		cub->var->dist_wall = dist_to_wall(cub, cub->p1, &color);
		cub->p1->angle -= i;
		draw_line_height(i, cub, cub->var->dist_wall, color);
	}
	draw_map(cub);
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
