/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:04:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/07 15:09:29 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_a(t_cub3d *param)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * param->angle) * 5;
	dy = sin((M_PI / 180) * param->angle) * 5;
	while (++i < param->weight)
	{
		j = -1;
		while (++j < param->weight)
			if (ft_is_wall(param->x_p - dy + i - param->weight / 2,\
				param->y_p + dx + j - param->weight / 2, param->map.map))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p -= dy;
	param->y_p += dx;
	ft_put_player(*param, 0x00FFFFFF);
}

void	ft_d(t_cub3d *param)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * param->angle) * 5;
	dy = sin((M_PI / 180) * param->angle) * 5;
	while (++i < param->weight)
	{
		j = -1;
		while (++j < param->weight)
			if (ft_is_wall(param->x_p + dy + i - param->weight / 2,\
				param->y_p - dx + j - param->weight / 2, param->map.map))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p += dy;
	param->y_p -= dx;
	ft_put_player(*param, 0x00FFFFFF);
}

void	ft_w(t_cub3d *param)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * param->angle) * 5;
	dy = sin((M_PI / 180) * param->angle) * 5;
	while (++i < param->weight)
	{
		j = -1;
		while (++j < param->weight)
			if (ft_is_wall(param->x_p - dx + i - param->weight / 2,\
				param->y_p - dy + j - param->weight / 2, param->map.map))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p -= dx;
	param->y_p -= dy;
	ft_put_player(*param, 0x00FFFFFF);
}

void	ft_s(t_struct_list *struct_list)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * struct_list->param.angle) * 5;
	dy = sin((M_PI / 180) * struct_list->param.angle) * 5;
	while (++i < struct_list->param.weight)
	{
		j = -1;
		while (++j < struct_list->param.weight)
			if (ft_is_wall(struct_list->param.x_p + dx + i - struct_list->param.weight / 2,\
				struct_list->param.y_p + dy + j - struct_list->param.weight / 2, struct_list->map.map))
				return ;
	}
	ft_put_player(struct_list->param, 0);
	param->x_p += dx;
	param->y_p += dy;
	ft_put_player(struct_list->param, 0x00FFFFFF);
}
