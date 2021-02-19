
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:10:40 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/19 14:24:21 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_c(t_map *map, char *line)
{
	int	r;
	int	g;
	int	b;
	int	i;

	if (map->color_floor)
		map->error = 1;
	if (line[1] != ' ')
		map->error = 1;
	r = ft_atoi(line + 2);
	i = ft_count(r);
	if (line[2 + i] != ',')
		map->error = 1;
	g = ft_atoi(line + 3 + i);
	i += ft_count(g);
	if (line[3 + i] != ',')
		map->error = 1;
	b = ft_atoi(line + 4 + i);
	i += ft_count(b);
	if (line[4 + i])
		map->error = 1;
	if (map->error)
	{
		ft_putstr_fd("Error !\nError with floor color...\n", 2);
		exit(1);
	}
	map->color_floor = create_trgb(0, r, g, b);
}

void	ft_get_f(t_map *map, char *line)
{
	int	r;
	int	g;
	int	b;
	int	i;

	if (map->color_ground)
		map->error = 1;
	if (line[1] != ' ')
		map->error = 1;
	r = ft_atoi(line + 2);
	i = ft_count(r);
	if (line[2 + i] != ',')
		map->error = 1;
	g = ft_atoi(line + 3 + i);
	i += ft_count(g);
	if (line[3 + i] != ',')
		map->error = 1;
	b = ft_atoi(line + 4 + i);
	i += ft_count(b);
	if (line[4 + i])
		map->error = 1;
	if (map->error)
	{
		ft_putstr_fd("Error !\nError with ground color...\n", 2);
		exit(1);
	}
	map->color_ground = create_trgb(0, r, g, b);
}

void	ft_get_no(t_map *map, char *line)
{
	int i;

	if (map->path_north)
		map->error = 1;
	if (line[2] != ' ')
		map->error = 1;
	i = ft_strlen(line + 3);
	if (!(map->path_north = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		map->path_north[i] = line[3 + i];
	if (map->error)
	{
		ft_putstr_fd("Error !\nError with north path...\n", 2);
		exit(1);
	}
}

void	ft_get_so(t_map *map, char *line)
{
	int i;

	if (map->path_south)
		map->error = 1;
	if (line[2] != ' ')
		map->error = 1;
	i = ft_strlen(line + 3);
	if (!(map->path_south = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		map->path_south[i] = line[3 + i];
	if (map->error)
	{
		ft_putstr_fd("Error !\nError with south path...\n", 2);
		exit(1);
	}
}

void	ft_get_we(t_map *map, char *line)
{
	int i;

	if (map->path_west)
		map->error = 1;
	if (line[2] != ' ')
		map->error = 1;
	i = ft_strlen(line + 3);
	if (!(map->path_west = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		map->path_west[i] = line[3 + i];
	if (map->error)
	{
		ft_putstr_fd("Error !\nError with west path...\n", 2);
		exit(1);
	}
}

void	ft_get_ea(t_map *map, char *line)
{
	int i;

	if (map->path_east)
		map->error = 1;
	if (line[2] != ' ')
		map->error = 1;
	i = ft_strlen(line + 3);
	if (!(map->path_east = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		map->path_east[i] = line[3 + i];
	if (map->error)
	{
		ft_putstr_fd("Error !\nError with east path...\n", 2);
		exit(1);
	}
}

void	ft_get_s(t_map *map, char *line)
{
	int i;

	if (map->path_sprite)
		map->error = 1;
	if (line[1] != ' ')
		map->error = 1;
	i = ft_strlen(line + 2);
	if (!(map->path_sprite = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		map->path_sprite[i] = line[2 + i];
	if (map->error)
	{
		ft_putstr_fd("Error !\nError with sprite path...\n", 2);
		exit(1);
	}
}
