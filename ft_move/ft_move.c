/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:04:17 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/30 15:11:32 by ctirions         ###   ########.fr       */
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
	dx = cos((M_PI / 180) * struct_list->param->angle) * 0.2;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 0.2;
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
	dx = cos((M_PI / 180) * struct_list->param->angle) * 0.2;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 0.2;
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
	dx = cos((M_PI / 180) * struct_list->param->angle) * 0.2;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 0.2;
	/*while (++i < struct_list->param->weight)
	{
		j = -1;
		while (++j < struct_list->param->height)
			if (ft_is_wall(struct_list->param->x_p - dx + i - struct_list->param->weight / 2,\
				struct_list->param->y_p - dy + j - struct_list->param->height / 2, struct_list->map))
				return ;
	}*/
	while (++i < 2)
	{
		j = -1;
		while (++j < 2)
		{
			if (ft_is_wall(struct_list->param->y_p + i / 3 - 1 / 6 - dy, \
			struct_list->param->x_p + j / 3 - 1 / 6 - dx, struct_list->map))
			{
			//	printf("%f|%f\n", struct_list->param->x_p + i / 3 - 1 / 6 - dx, struct_list->param->y_p + i / 3 - 1 / 6 - dy);
				return ;
			}
		}
	}
	struct_list->param->x_p -= dx;
	struct_list->param->y_p -= dy;
	printf("%f|%f\n", struct_list->param->x_p, struct_list->param->y_p);
}

void	ft_s(t_struct_list *struct_list)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * struct_list->param->angle) * 0.1;
	dy = sin((M_PI / 180) * struct_list->param->angle) * 0.1;
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
