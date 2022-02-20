/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:04:09 by zminhas           #+#    #+#             */
/*   Updated: 2022/02/20 15:43:48 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_wall(int x, int y, t_cub *cub, int color)
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

void	draw_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	draw_all(cub);
	while (cub->map->map[++i])
	{
		j = -1;
		while (cub->map->map[i][++j])
		{
			if (cub->map->map[i][j] == '1')
				draw_wall(i, j, cub, 0x787878);
			if (cub->map->map[i][j] == '0' || ft_isalpha(cub->map->map[i][j]))
				draw_wall(i, j, cub, 0xFFFFFF);
			if (cub->map->map[i][j] == '2')
				draw_wall(i, j, cub, 0xD5D5D5);
		}
	}
	draw_player(cub->p1->pos[0], cub->p1->pos[1], cub);
	mlx_put_image_to_window(cub->mlx_ptr, cub->win_ptr, cub->img->img, 0, 0);
}
