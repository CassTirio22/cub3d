/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:04:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/27 15:04:10 by ctirions         ###   ########.fr       */
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
	dx = cos((M_PI / 180) * struct_list->param->angle) * 5;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 5;
	while (++i < struct_list->param->weight)
	{
		j = -1;
		while (++j < struct_list->param->height)
			if (ft_is_wall(struct_list->param->x_p - dy + i - struct_list->param->weight / 2,\
				struct_list->param->y_p + dx + j - struct_list->param->height / 2, struct_list->map))
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
	dx = cos((M_PI / 180) * struct_list->param->angle) * 5;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 5;
	while (++i < struct_list->param->weight)
	{
		j = -1;
		while (++j < struct_list->param->height)
			if (ft_is_wall(struct_list->param->x_p + dy + i - struct_list->param->weight / 2,\
				struct_list->param->y_p - dx + j - struct_list->param->height / 2, struct_list->map))
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
	dx = cos((M_PI / 180) * struct_list->param->angle) * 5;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 5;
	while (++i < struct_list->param->weight)
	{
		j = -1;
		while (++j < struct_list->param->height)
			if (ft_is_wall(struct_list->param->x_p - dx + i - struct_list->param->weight / 2,\
				struct_list->param->y_p - dy + j - struct_list->param->height / 2, struct_list->map))
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
	dx = cos((M_PI / 180) * struct_list->param->angle) * 5;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 5;
	while (++i < struct_list->param->weight)
	{
		j = -1;
		while (++j < struct_list->param->height)
			if (ft_is_wall(struct_list->param->x_p + dx + i - struct_list->param->weight / 2,\
				struct_list->param->y_p + dy + j - struct_list->param->height / 2, struct_list->map))
				return ;
	}
	struct_list->param->x_p += dx;
	struct_list->param->y_p += dy;
}
