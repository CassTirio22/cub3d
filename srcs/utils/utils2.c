/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:59:30 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/02 15:28:55 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall(int x, int y, t_cub *cub)
{
	if (cub->map->map[y][x] == '1')
		return (1);
	return (0);
}

int	ft_strlen_cub3d(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\t')
			i += 3;
	return (i);
}

double	div_protect_in_dist_to_wall(double a, double b)
{
	int	rest;

	rest = 100 * (b - (int)b) + (int)b;
	if (!rest)
		return (a);
	return (a / b);
}
