/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:22:50 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/27 16:07:20 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int		ft_count(int nbr)
{
	int count;

	count = 0;
	while (nbr > 9)
	{
		count++;
		nbr /= 10;
	}
	return (++count);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		ft_is_wall(int x, int y, t_map *map)
{
	if (map->map[y / map->wall_size[1]][x / map->wall_size[0] + 1] == 1)
		return (1);
	return (0);
}

void	ft_argc_error(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error !\nYou didn't put any map...\n", 2);
		exit(1);
	}
	if (argc != 2)
	{
		ft_putstr_fd("Error !\nYou put too many arguments...\n", 2);
		exit(1);
	}
}
