/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_draw.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:08:13 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/16 15:27:02 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_put_line(t_param param, t_map map, t_data *img, int color)
{
	float	dx;
	float	dy;
	int		i;

	i = 0;
	dx = cos((M_PI / 180) * param.angle);
	dy = sin((M_PI / 180) * param.angle);
	while (++i < 1500 && !ft_is_wall(param.x_p - (i * dx),\
		param.y_p - (i * dy), map.map))
		put_pixel(img, param.x_p - (i * dx), param.y_p - (i * dy), color);
}

void	ft_put_view(t_struct_list *struct_list, int color)
{
	int	i;
	int	j;

	j = 30;
	i = -1;
	while (++i < j)
	{
		struct_list->param->angle++;
		ft_put_line(*struct_list->param, *struct_list->map, \
			struct_list->img, color);
	}
	struct_list->param->angle -= j;
	i = -1;
	while (++i < j)
	{
		struct_list->param->angle--;
		ft_put_line(*struct_list->param, *struct_list->map, \
			struct_list->img, color);
	}
	struct_list->param->angle += j;
}

void	ft_put_player(t_struct_list struct_list, int color)
{
	float	i;
	int		j;

	i = -1;
	while (++i <= struct_list.param->weight)
	{
		j = -1;
		while (++j <= struct_list.param->weight)
			put_pixel(struct_list.img, \
				struct_list.param->x_p + i - struct_list.param->weight / 2, \
				struct_list.param->y_p + j - struct_list.param->weight / 2, color);
	}
	if (color)
		color = 0x00FF69B4;
	ft_put_line(*struct_list.param, *struct_list.map, struct_list.img ,color);
	ft_put_view(&struct_list, color);
}

void	ft_square(int x, int y, int wall_or_not, t_data *img)
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
			put_pixel(img, x * 108 + i, y * 108 + j, 0x001E90FF);
	}
}

void	ft_draw_map(t_struct_list struct_list)
{
	int	i;
	int	j;
	int map_y;
	int	map_x;

	i = -1;
	map_x = 10;
	map_y = 10;
	while (++i < struct_list.map->weight)
	{
		j = -1;
		while (++j < struct_list.map->height)
			ft_square(i, j, struct_list.map->map[j][i], struct_list.img);
	}
	mlx_put_image_to_window(struct_list.param->mlx_ptr,\
		struct_list.param->win_ptr, struct_list.img->img, 0, 0);
}
