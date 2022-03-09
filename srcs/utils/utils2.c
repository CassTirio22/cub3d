/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:59:30 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/09 16:26:28 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

t_img	*get_side(int color, t_cub *cub)
{
	if (color == WEST_WALL)
		return (cub->tex->we);
	if (color == EAST_WALL)
		return (cub->tex->ea);
	if (color == NORTH_WALL)
		return (cub->tex->no);
	return (cub->tex->so);
}

void	get_pixel(t_img *image, int x, int y, int *color)
{
	char	*dst;

	dst = image->addr + (y * image->line_length \
	+ x * (image->bits_per_pixel / 8));
	*color = *(unsigned int *)dst;
}

int	do_rgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

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

double	div_protect(double a, double b)
{
	int	rest;

	rest = 100 * (b - (int)b) + (int)b;
	if (!rest)
		return (a);
	return (a / b);
}
