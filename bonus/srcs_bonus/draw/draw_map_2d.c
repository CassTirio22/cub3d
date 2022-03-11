/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map_2d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/19 18:04:09 by zminhas           #+#    #+#             */
/*   Updated: 2022/03/10 18:41:02 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	draw_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	draw_outlines(t_cub *cub)
{
	int	i;
	int	j;

	j = -1;
	while (++j < cub->var->wall_size)
	{
		i = -1;
		while (++i <= 20 * cub->var->wall_size)
			draw_pixel(cub->img, i, j, 0xCF722B);
		i = -1;
		while (++i <= 20 * cub->var->wall_size)
			draw_pixel(cub->img, j, i, 0xCF722B);
		i = -1;
		while (++i <= 20 * cub->var->wall_size)
			draw_pixel(cub->img, i, j + cub->var->wall_size * 20, 0xCF722B);
		i = -1;
		while (++i <= 20.99 * cub->var->wall_size)
			draw_pixel(cub->img, j + cub->var->wall_size * 20, i, 0xCF722B);
	}
}

void	draw_wall(double x, double y, t_cub *cub, int color)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->var->wall_size)
	{
		j = -1;
		while (++j < cub->var->wall_size)
			draw_pixel(cub->img, i + y * cub->var->wall_size, \
			j + x * cub->var->wall_size, color);
	}
}

void	draw_minimap(t_cub *cub, double pos[2], char **map, double i[2])
{
	if (pos[1] - 10 + i[1] < 0 || pos[0] - 10 + i[0] < 0 || \
	pos[0] - 10 + i[0] >= (int)ft_strlen(map[0]) || \
	pos[1] - 10 + i[1] >= double_char_len(map))
		draw_wall((int)pos[1] - pos[1] + i[1], \
		(int)pos[0] - pos[0] + i[0], cub, 0xD5D5D5);
	else if (map[(int)(pos[1] - 10 + i[1])][(int)(pos[0] - 10 + i[0])] == '1')
		draw_wall((int)pos[1] - pos[1] + i[1], \
		(int)pos[0] - pos[0] + i[0], cub, 0x787878);
	else if (map[(int)(pos[1] - 10 + i[1])][(int)(pos[0] - 10 + i[0])] == '0'\
	|| ft_isalpha(map[(int)(pos[1] - 10 + i[1])][(int)(pos[0] - 10 + i[0])]))
		draw_wall((int)pos[1] - pos[1] + i[1], \
		(int)pos[0] - pos[0] + i[0], cub, 0xFFFFFF);
	else if (map[(int)(pos[1] - 10 + i[1])][(int)(pos[0] - 10 + i[0])] == '2')
		draw_wall((int)pos[1] - pos[1] + i[1], \
		(int)pos[0] - pos[0] + i[0], cub, 0xD5D5D5);
	else if (map[(int)(pos[1] - 10 + i[1])][(int)(pos[0] - 10 + i[0])] == '3')
		draw_wall((int)pos[1] - pos[1] + i[1], \
		(int)pos[0] - pos[0] + i[0], cub, 0x593b2a);
	else if (map[(int)(pos[1] - 10 + i[1])][(int)(pos[0] - 10 + i[0])] == '4')
		draw_wall((int)pos[1] - pos[1] + i[1], \
		(int)pos[0] - pos[0] + i[0], cub, 0x593b2a);
}

void	draw_map(t_cub *cub)
{
	double	pos[2];
	double	inc[2];

	pos[0] = cub->p1->pos[0] - 0.5;
	pos[1] = cub->p1->pos[1] - 0.5;
	inc[0] = 0;
	while (++inc[0] <= 20)
	{
		inc[1] = 0;
		while (++inc[1] <= 20)
			draw_minimap(cub, pos, cub->map->map, inc);
	}
	draw_player(cub);
	draw_outlines(cub);
}
