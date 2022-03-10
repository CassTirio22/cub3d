/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:35:10 by aliens            #+#    #+#             */
/*   Updated: 2022/03/10 19:35:23 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall_around(double x, double y, t_cub *cub)
{
	double	i;
	double	j;
	double	dx;
	double	dy;

	i = -1;
	while (++i < 10)
	{
		j = -1;
		while (++j < 360)
		{
			dx = cos(j * (M_PI / 180)) / 100;
			dy = sin(j * (M_PI / 180)) / 100;
			if (is_wall((int)(x + dx * i), (int)(y + dy * i), cub))
				return (1);
		}
	}
	return (0);
}

int	is_wall(int x, int y, t_cub *cub)
{
	if (cub->map->map[y][x] == '1')
		return (1);
	return (0);
}

double	div_protect(double a, double b)
{
	int	rest;

	rest = 100 * (b - (int)b) + (int)b;
	if (!rest)
		return (a);
	return (a / b);
}
