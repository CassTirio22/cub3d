/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:43:21 by aliens            #+#    #+#             */
/*   Updated: 2022/03/07 17:32:49 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	reset(t_cub *cub)
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
	double	calc;

	if (!i)
		cub->var->perp_wall_dist = dist_wall;
	else
		cub->var->perp_wall_dist = dist_wall / cos(i * (M_PI / 180));
	h = (int)(cub->var->resolution[1] / cub->var->perp_wall_dist);
	if (h > cub->var->resolution[1])
		h = cub->var->resolution[1];
	k = -1;
	calc = (double)cub->var->resolution[0] / 60;
	i += 30;
	while (++k < calc)
	{
		j = -1;
		while (++j < h)
			draw_pixel(cub->img, -(i * calc + k), \
			-j + cub->var->resolution[1] / 2 + h / 2, color);
	}
}

void	draw_fc(t_cub *cub, t_var *var)
{
	int	i;
	int	j;

	i = -1;
	while (++i < var->resolution[0])
	{
		j = -1;
		while (++j < var->resolution[1])
		{
			if (j > var->resolution[1] / 2)
				draw_pixel(cub->img, i, j, var->f);
			else
				draw_pixel(cub->img, i, j, var->c);
		}
	}
}

void	draw_game(t_cub *cub)
{
	int	i;
	int	color;

	reset(cub);
	draw_fc(cub, cub->var);
	color = 0;
	i = -31;
	while (++i < 30)
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
