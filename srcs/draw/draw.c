/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 16:53:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/15 18:58:54 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_player(int x, int y, t_cub *cub)
{
	int	i;
	int	j;
	int	wall_size;

	wall_size = cub->var->wall_size;
	i = -1;
	while (++i < wall_size / 4)
	{
		j = -1;
		while (++j < wall_size / 4)
			draw_pixel(cub->img, (y + 0.375) * wall_size + i, (x + 0.375) * wall_size + j, 0xEC57B8);
	}
}

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

void	draw_map(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	printf("size : %d\n", cub->var->wall_size);
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
