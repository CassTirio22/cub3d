/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:08:13 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/19 14:41:31 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

float	ft_put_line(t_cub3d param, int color)
{
	float	dx;
	float	dy;
	int		i;

	i = 0;
	dx = cos((M_PI / 180) * param.angle);
	dy = sin((M_PI / 180) * param.angle);
	while (++i < 1000 && !ft_is_wall(param.x_p - (i * dx),\
		param.y_p - (i * dy)))
		mlx_pixel_put(param.mlx_ptr, param.win_ptr,\
			param.x_p - (i * dx), param.y_p - (i * dy), color);
	return (sqrt(i * (dx * dx) + (dy * dy) * i));
}

void	ft_put_view(t_cub3d *param, int color)
{
	int	i;
	int	j;

	j = 30;
	i = -1;
	while (++i < j)
	{
		param->angle++;
		ft_put_line(*param, color);
	}
	param->angle -= j;
	i = -1;
	while (++i < j)
	{
		param->angle--;
		ft_put_line(*param, color);
	}
	param->angle += j;
}

void	ft_put_player(t_cub3d param, int color)
{
	float	i;
	int		j;

	i = -1;
	while (++i <= param.weight)
	{
		j = -1;
		while (++j <= param.weight)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p + i - \
				param.weight / 2, param.y_p + j - param.weight / 2, color);
	}
	if (color)
		color = 0x00FF69B4;
	ft_put_line(param, color);
	ft_put_view(&param, color);
}

void	ft_square(int x, int y, int wall_or_not, t_cub3d param)
{
	int	i;
	int	j;

	if (!wall_or_not)
		return ;
	i = -1;
	while (++i < 108)
	{
		j = -1;
		while (++j < 108)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr,\
				x * 108 + i, y * 108 + j, 0x001E90FF);
	}
}

void	ft_draw_map(t_cub3d param)
{
	int	i;
	int	j;
	int map_y;
	int	map_x;

	i = -1;
	map_x = 10;
	map_y = 10;
	while (++i < map_x)
	{
		j = -1;
		while (++j < map_y)
			ft_square(i, j, g_map[j][i], param);
	}
}
