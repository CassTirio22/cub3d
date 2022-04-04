/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:43:21 by aliens            #+#    #+#             */
/*   Updated: 2022/04/04 11:57:22 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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

int	get_line_height(float i, t_cub *cub, double dist_wall)
{
	int		h;

	cub->var->perp_wall_dist = dist_wall * cos((i - FOV / 2) * (M_PI / 180));
	h = (int)(cub->var->resolution[1] / cub->var->perp_wall_dist);
	return (h);
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

void	draw_line_height(t_cub *cub, int color, float calc[3], int r_x)
{
	float	j;
	float	offset;
	float	line_height;
	t_img	*tex;

	tex = get_side(color, cub);
	line_height = get_line_height(calc[2], cub, cub->var->dist_wall);
	offset = (cub->var->resolution[1] - line_height) / 2;
	j = 0;
	while (j < offset && j < cub->var->resolution[1])
		draw_pixel(cub->img, r_x - calc[1], j++, cub->var->c);
	j = -1;
	if (offset < 0)
		j = -offset;
	while (++j < line_height && j + offset < cub->var->resolution[1])
	{
		get_pixel(tex, (calc[0] - (int)calc[0]) * (tex->img_h), \
		j * (tex->img_h / line_height), &color);
		draw_pixel(cub->img, r_x - calc[1], j + offset, color);
	}
	j--;
	while (++j + offset < cub->var->resolution[1])
		draw_pixel(cub->img, r_x - calc[1], j + offset, cub->var->f);
}

void	draw_game(t_cub *cub)
{
	float	calc_x;
	int		color;
	float	i;
	float	calc[3];

	i = -1;
	calc_x = 0;
	while (++i < cub->var->resolution[0])
	{
		calc[2] = i / (cub->var->resolution[0] / FOV);
		cub->p1->angle += calc[2] - FOV / 2;
		cub->var->dx = cos((cub->p1->angle) * (M_PI / 180));
		cub->var->dy = sin((cub->p1->angle) * (M_PI / 180));
		cub->var->dist_wall = dist_to_wall(cub, cub->p1, &color);
		cub->p1->angle -= calc[2] - FOV / 2;
		if (!cub->var->touch)
			calc[0] = cub->var->dist_wall * -cub->var->dy + cub->p1->pos[1];
		else
			calc[0] = cub->var->dist_wall * cub->var->dx + cub->p1->pos[0];
		calc[1] = i;
		draw_line_height(cub, color, calc, cub->var->resolution[0]);
	}
	draw_extern(cub);
	draw_map(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img->img, 0, 0);
}
