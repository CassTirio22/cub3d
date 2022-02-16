/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:32:54 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/16 19:44:46 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"


int	ft_up(t_cub *cub)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * cub->p1->angle) * 1 / 8;
	dy = sin((M_PI / 180) * cub->p1->angle) * 1 / 8;
	if (is_wall(cub->p1->pos[0] + dx, cub->p1->pos[1] - dy, cub->map->map))
		return (0);
	cub->p1->pos[0] += dx;
	cub->p1->pos[1] -= dy;
	return (0);
}

int	ft_down(t_cub *cub)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * cub->p1->angle) * 1 / 8;
	dy = sin((M_PI / 180) * cub->p1->angle) * 1 / 8;
	if (is_wall(cub->p1->pos[0] - dx, cub->p1->pos[1] + dy, cub->map->map))
		return (0);
	cub->p1->pos[0] -= dx;
	cub->p1->pos[1] += dy;
	return (0);
}

int	ft_left(t_cub *cub)
{
	float	dx;
	float	dy;

	dx = cos((M_PI / 180) * cub->p1->angle) * 1 / 8;
	dy = sin((M_PI / 180) * cub->p1->angle) * 1 / 8;
	if (is_wall(cub->p1->pos[0] - dy, cub->p1->pos[1] - dx, cub->map->map))
		return (0);
	cub->p1->pos[0] -= dy;
	cub->p1->pos[1] -= dx;
	return (0);
}

int	ft_right(t_cub *cub)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	dx = cos((M_PI / 180) * cub->p1->angle) * 1 / 8;
	dy = sin((M_PI / 180) * cub->p1->angle) * 1 / 8;
	i = -1;
	while (++i < cub->var->wall_size / 4)
	{
		j = -1;
		while (++j < cub->var->wall_size / 4)
		{
			if (is_wall(cub->p1->pos[0] + dy, cub->p1->pos[1] + dx, cub->map->map))
				return (0);
		}
	}
	cub->p1->pos[0] += dy;
	cub->p1->pos[1] += dx;
	return (0);	
}
