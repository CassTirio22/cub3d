/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:43:21 by aliens            #+#    #+#             */
/*   Updated: 2022/03/09 17:20:11 by aliens           ###   ########.fr       */
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

int	get_line_height(float i, t_cub *cub, double dist_wall)
{
	int		h;

	cub->var->perp_wall_dist = dist_wall * cos((i - FOV / 2) * (M_PI / 180));
	h = (int)(cub->var->resolution[1] / cub->var->perp_wall_dist);
	if (h > cub->var->resolution[1])
		h = cub->var->resolution[1];
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

void	draw_game(t_cub *cub)
{
	float	i;
	float	j;
	float	angle;
	float	offset;
	float	line_height;
	float	calc_x;
	int		color;

	i = -1;
	calc_x = 0;
	while (++i < cub->var->resolution[0])
	{
		angle = i / (cub->var->resolution[0] / FOV);
		cub->p1->angle += angle - FOV / 2;
		cub->var->dx = cos((cub->p1->angle) * (M_PI / 180));
		cub->var->dy = sin((cub->p1->angle) * (M_PI / 180));
		cub->var->dist_wall = dist_to_wall(cub, cub->p1, &color);
		//cub->var->dist_wall *= cos(angle * (M_PI / 180));
		cub->p1->angle -= angle - FOV / 2;
		line_height = get_line_height(angle, cub, cub->var->dist_wall);
		// printf("%d\n", line_height);
		offset = (cub->var->resolution[1] - line_height) / 2;
		if (color == EAST_WALL || color == WEST_WALL)
			calc_x = cub->var->dist_wall * cub->var->dy + cub->p1->pos[1];
		else
			calc_x = cub->var->dist_wall * cub->var->dx + cub->p1->pos[0];	
		//printf("%x\n", color);
		j = -1;
		while (++j < offset)
			draw_pixel(cub->img, -i, j, cub->var->c);
		while (++j < offset + line_height)
		{
			//printf("calc : %f\n",  (j - offset) * (cub->textures_test->img_h / line_height));
			get_pixel(cub->textures_test, (calc_x - (int)calc_x) * (cub->textures_test->img_h), (j - offset) * (cub->textures_test->img_h / line_height), &color);
			draw_pixel(cub->img, -i, j, color);
		}
		while (++j < cub->var->resolution[1])
			draw_pixel(cub->img, -i, j, cub->var->f);
	}
	draw_map(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img->img, 0, 0);
	//mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->textures_test->img, 0, 0);
}

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}
