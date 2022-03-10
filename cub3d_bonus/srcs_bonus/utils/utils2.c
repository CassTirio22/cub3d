/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:59:30 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/10 17:21:02 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	get_color(t_cub *cub, double dist)
{
	double	tmp;
	double	dx;
	double	dy;

	dx = cos(cub->p1->angle * (M_PI / 180));
	dy = -sin(cub->p1->angle * (M_PI / 180));
	tmp = fabs(dist);
	if (cub->map->map[(int)(cub->p1->pos[1] + dy * tmp)][(int)(cub->p1->pos[0] + dx * tmp)] == '3')
		return (DOOR);
	if (dist < 0)
	{
		if (cub->var->dy < 0)
			return (SOUTH_WALL);
		return (NORTH_WALL);
	}
	if (cub->var->dx < 0)
		return (WEST_WALL);
	return (EAST_WALL);
}

t_img	*get_side(int color, t_cub *cub)
{
	if (color == WEST_WALL)
		return (cub->tex->we);
	if (color == EAST_WALL)
		return (cub->tex->ea);
	if (color == NORTH_WALL)
		return (cub->tex->no);
	if (color == DOOR)
		return (cub->tex->door);
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
	if (cub->map->map[y][x] == '1' || cub->map->map[y][x] == '3')
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
