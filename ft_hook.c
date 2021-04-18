/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:59:24 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/18 17:52:37 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_close(t_param *param)
{
	(void)param;
	exit(1);
	return (0);
}

void	calcul(t_struct_list *struct_list, t_param *param)
{
	int	x;

	x = -1;
	while (++x < struct_list->map->weight)
	{
		param->camera_x = 2 * x / struct_list->map->weight - 1;
		param->ray_dir_x = param->dir_x + param->plane_x * param->camera_x;
		param->ray_dir_y = param->dir_y + param->plane_y * param->camera_x;
		param->delta_dist_x = sqrt(1 + (param->ray_dir_y * \
			param->ray_dir_x) / (param->ray_dir_x * param->ray_dir_x));
		param->delta_dist_y = sqrt(1 + (param->ray_dir_x * \
			param->ray_dir_x) / (param->ray_dir_x * param->ray_dir_y));
		param->hit = 0;
		if (param->ray_dir_x < 0)
		{
			param->step_x = -1;
			param->side_dist_x = (param->x_p - (int)param->map_x) * param->delta_dist_x;
		}
		else
		{
			param->step_x = 1;
			param->side_dist_x = ((int)param->map_x + 1 - param->x_p) * param->delta_dist_x;
		}
		if (param->ray_dir_x < 0)
		{
			param->step_y = -1;
			param->side_dist_y = (param->y_p - (int)param->map_y) * param->delta_dist_y;
		}
		else
		{
			param->step_y = 1;
			param->side_dist_y = ((int)param->map_y + 1 - param->y_p) * param->delta_dist_y;
		}
		while (!param->hit)
		{
			if (param->side_dist_x < param->side_dist_y)
			{
				param->side_dist_x += param->delta_dist_x;
				param->map_x += param->step_x;
				param->side = 0;
			}
			else
			{
				param->side_dist_y += param->delta_dist_y;
				param->map_y -= param->step_y;
				param->side = 1;
			}
			if (struct_list->map->map[param->map_x][param->map_y] > 0)
				param->hit = 1;
		}
		if (!param->side)
			param->perp_wall_dist = (param->map_x - param->x_p + \
				(1 - param->step_x) / 2) / param->ray_dir_x;
		else
			param->perp_wall_dist = (param->map_y - param->y_p + \
				(1 - param->step_y) / 2) / param->ray_dir_y;
		param->line_height = (int)(struct_list->map->height / param->perp_wall_dist);
		param->draw_start = -param->line_height / 2 + struct_list->map->height / 2;
		param->draw_end = param->line_height / 2 + struct_list->map->height / 2;
		if (param->draw_start < 0)
			param->draw_start = 0;
		if (param->draw_end >= struct_list->map->height)
			param->draw_end = struct_list->map->height - 1;
	}
}

int	ft_key_hook(int key_code, t_struct_list *struct_list)
{
	//printf("%d\n", key_code);
	ft_put_player(*struct_list, 0);
	calcul(struct_list, struct_list->param);
	if (key_code == 13)
		ft_w(struct_list);
	else if (key_code == 1)
		ft_s(struct_list);
	else if (key_code == 0)
		ft_a(struct_list);
	else if (key_code == 2)
		ft_d(struct_list);
	else if (key_code == 123)
		ft_rotate_left(struct_list);
	else if (key_code == 124)
		ft_rotate_right(struct_list);
	else if (key_code == 53)
		ft_mlx_close(struct_list->param);
	ft_put_player(*struct_list, 0x00FFFFFF);
	mlx_put_image_to_window(struct_list->param->mlx_ptr,\
		struct_list->param->win_ptr, struct_list->img->img, 0, 0);
	return (0);
}
