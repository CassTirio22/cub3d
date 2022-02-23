/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:04:09 by zminhas           #+#    #+#             */
/*   Updated: 2022/02/23 16:06:26 by ctirions         ###   ########.fr       */
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

void	draw_outlines(t_cub *cub)
{
	int	i;
	int	j;

	j = -1;
	while (++j < cub->var->wall_size)
	{
		i = -1;
		while (++i < 21 * cub->var->wall_size)
			draw_pixel(cub->img, i, j, 0xCF722B);
		i = -1;
		while (++i < 11 * cub->var->wall_size)
			draw_pixel(cub->img, j, i, 0xCF722B);
		i = -1;
		while (++i < 21 * cub->var->wall_size)
			draw_pixel(cub->img, i, j + cub->var->wall_size * 10, 0xCF722B);
		i = -1;
		while (++i < 11 * cub->var->wall_size)
			draw_pixel(cub->img, j + cub->var->wall_size * 20, i, 0xCF722B);
	}
}

void	draw_wall(double x, double y, t_cub *cub, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->var->wall_size - 1)
	{
		j = -1;
		while (++j < cub->var->wall_size - 1)
			draw_pixel(cub->img, i + y * cub->var->wall_size, \
			j + x * cub->var->wall_size, color);
	}
}

void	draw_map(t_cub *cub)
{
	double	pos[2];
	double	i;
	double	j;

	draw_all(cub);
	pos[0] = cub->p1->pos[0] - 0.5;
	pos[1] = cub->p1->pos[1] - 0.5;
	i = 0;
	while (++i < 21)
	{
		j = 0;
		while (++j < 11)
		{
			if (pos[1] - 5 + j < 0 || pos[0] - 10 + i < 0 || pos[0] - 10 + i >= (int)ft_strlen(cub->map->map[0]) || pos[1] - 5 + j >= double_char_len(cub->map->map))
				;
			else if (cub->map->map[(int)(pos[1] - 5 + j)][(int)(pos[0] - 10 + i)] == '1')
				draw_wall((int)pos[1] - pos[1] + j, (int)pos[0] - pos[0] + i, cub, 0x787878);
			else if (cub->map->map[(int)(pos[1] - 5 + j)][(int)(pos[0] - 10 + i)] == '0' || ft_isalpha(cub->map->map[(int)(pos[1] - 5 + j)][(int)(pos[0] - 10 + i)]))
				draw_wall((int)pos[1] - pos[1] + j, (int)pos[0] - pos[0] + i, cub, 0xFFFFFF);
			else if (cub->map->map[(int)(pos[1] - 5 + j)][(int)(pos[0] - 10 + i)] == '2')
				draw_wall((int)pos[1] - pos[1] + j, (int)pos[0] - pos[0] + i, cub, 0xD5D5D5);
		}
	}
	draw_player(cub);
	draw_outlines(cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img->img, 0, 0);
}
