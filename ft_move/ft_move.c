/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:04:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/05/03 13:20:25 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_a(t_struct_list *struct_list)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * struct_list->param->angle) * 1 / 6;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 1 / 6;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
			if (struct_list->map->map[(int)(struct_list->param->y_p + dx + i / 3 - 1 / 6)]\
				[(int)(struct_list->param->x_p - dy + j / 3 - 1 / 6 + 1)] == 1)
				return ;
	}
	struct_list->param->x_p -= dy;
	struct_list->param->y_p += dx;
}

void	ft_d(t_struct_list *struct_list)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * struct_list->param->angle) * 1 / 6;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 1 / 6;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
			if (struct_list->map->map[(int)(struct_list->param->y_p - dx + i / 3 - 1 / 6)]\
				[(int)(struct_list->param->x_p + dy + j / 3 - 1 / 6 + 1)] == 1)
				return ;
	}
	struct_list->param->x_p += dy;
	struct_list->param->y_p -= dx;
}

void	ft_w(t_struct_list *struct_list)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * struct_list->param->angle) * 1 / 6;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 1 / 6;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
			if (struct_list->map->map[(int)(struct_list->param->y_p - 1 / 6 - dy)]\
			[(int)(struct_list->param->x_p + j / 3 - 1 / 6 - dx + 1)] == 1)
				return ;
	}
	struct_list->param->x_p -= dx;
	struct_list->param->y_p -= dy;
}

void	ft_s(t_struct_list *struct_list)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * struct_list->param->angle) * 1 / 6;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 1 / 6;
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
			if (struct_list->map->map[(int)(struct_list->param->y_p + dy + i / 3 - 1 / 6)]\
				[(int)(struct_list->param->x_p + dx + j / 3 - 1 / 6 + 1)] == 1)
				return ;
	}
	struct_list->param->x_p += dx;
	struct_list->param->y_p += dy;
}
