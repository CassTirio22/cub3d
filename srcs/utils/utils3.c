/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:33:08 by aliens            #+#    #+#             */
/*   Updated: 2022/04/01 18:18:14 by aliens           ###   ########.fr       */
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

int	spc_inf(char *info, int j[3], t_cub *cub)
{
	int	i;

	j[0] = 0;
	j[1] = 0;
	i = 0;
	info += 2;
	while (info[j[0]] && info[j[0]] == ' ')
		j[0]++;
	while (info[i + j[0]] && info[i + j[0]] != ' ')
		i++;
	while (info[i + j[0] + j[1]] && info[i + j[0] + j[1]] == ' ')
		j[1]++;
	if (info[i + j[0] + j[1]])
		free_all(cub, 2);
	j[2] = i;
	return (1);
}

void	info_check(int info[6], char **check, t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (info[i] > 1)
			free_all(cub, 11);
	i = -1;
	while (++i < 6)
	{
		if (!info[i])
		{
			printf("Error\n%s is missing\n", check[i]);
			free_all(cub, 1);
		}
	}
}
