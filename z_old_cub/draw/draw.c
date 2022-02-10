/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:08:13 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/10 14:11:08 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ft_put_line(t_param param, t_map map, t_data *img, int color)
{
	double	side_x;
	double	side_y;
	double	dist_x;
	double	dist_y;
	double	dx;
	double	dy;
	double	size;
	int	map_x;
	int	map_y;
	int	step[2];
	int	hit;
	int	side;
	int	i;

	hit = 0;
	dx = cos((M_PI / 180) * param.angle);
	dy = sin((M_PI / 180) * param.angle);
	map_x = (int)param.x_p;
	map_y = (int)param.y_p;
	printf("%f | %f\n", dx, dy);
	if (dy < 0.00001 && dy > -0.00001)
		dist_x = 1;
	else if (dx < 0.00001 && dx > -0.00001)
		dist_x = 0;	
	else
		dist_x = fabs(1 / dx);
	if (dx < 0.00001 && dx > -0.00001)
		dist_y = 1;
	else if (dy < 0.00001 && dy > -0.00001)
		dist_y = 0;
	else
		dist_y = fabs(1 / dy);
	if (dx < 0)
	{
		step[0] = 1;
		side_x = (param.x_p - map_x) * dist_x;
	}
	else
	{
		step[0] = -1;
		side_x = (map_x + 1 - param.x_p) * dist_x;
	}
	if (dy < 0)
	{
		step[1] = 1;
		side_y = (param.y_p - map_y) * dist_y;
	}
	else
	{
		step[1] = -1;
		side_y = (map_y + 1 - param.y_p) * dist_y;
	}
	printf("dist_x = %f | dist_y = %f\n", dist_x, dist_y);
	printf("side_x = %f | side_y = %f\n", side_x, side_y);
	while (hit != 1)
	{
		if (side_x < side_y && (dx > 0.00001 || dx < -0.00001))
		{
			printf("coucou\n");
			side_x += dist_x;
			map_x += step[0];
			side = 0;
		}
		else
		{
			side_y += dist_y;
			map_y += step[1];
			side = 1;
		}
		hit = map.map[map_y][map_x + 1];
	}
	printf("----------------\n");
	if (!side)
		size = ((map_x - param.x_p + (1 - step[0]) / 2) / dx) * map.wall_size[0];
	else
		size = ((map_y - param.y_p + (1 - step[1]) / 2) / dy) * map.wall_size[1];
	i = -1;
	//printf("size = %f\n", fabs(size));
	while (++i < fabs(size))
		put_pixel(img, map.wall_size[0] * param.x_p - (i * dx), \
			map.wall_size[1] * param.y_p - (i * dy), color);
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

	i = 0;
	while (++i <= struct_list.map->wall_size[0] / 3)
	{
		j = 0;
		while (++j <= struct_list.map->wall_size[1] / 3 - 1)
			put_pixel(struct_list.img, \
				struct_list.map->wall_size[0] * (struct_list.param->x_p - 0.166666666666666666666) + i, \
				struct_list.map->wall_size[1] * (struct_list.param->y_p - 0.166666666666666666666) + j, color);
	}
	if (color)
		color = 0x00FF69B4;
	ft_put_line(*struct_list.param, *struct_list.map, struct_list.img ,color);
	//ft_put_view(&struct_list, color);
}

void	ft_square(int x, int y, int wall_or_not, t_struct_list struct_list)
{
	int	i;
	int	j;

	if (wall_or_not != 1)
		return ;
	i = 0;
	while (++i < struct_list.map->wall_size[0] - 1)
	{
		j = 0;
		while (++j < struct_list.map->wall_size[1] - 1)
			put_pixel(struct_list.img, x * struct_list.map->wall_size[0] + i, y * struct_list.map->wall_size[1] + j, 0x001E90FF);
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
	while (++i < struct_list.map->height)
	{
		j = 0;
		while (++j < struct_list.map->map[i][0])
			ft_square(j - 1, i, struct_list.map->map[i][j], struct_list);

	}
	mlx_put_image_to_window(struct_list.param->mlx_ptr,\
		struct_list.param->win_ptr, struct_list.img->img, 0, 0);
}
