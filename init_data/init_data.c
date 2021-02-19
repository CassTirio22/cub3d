/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:10:50 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/19 17:51:21 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_r(t_map *map, char *line)
{
	int i;

	if (map->screen_size[0] != -1)
		map->error = 1;
	if (line[1] != ' ')
		map->error = 1;
	map->screen_size[0] = ft_atoi(line + 2);
	i = ft_count(map->screen_size[0]);
	if (line[i + 2] != ' ')
		map->error = 1;
	else if (ft_atoi(line + 2 + i))
		map->screen_size[1] = ft_atoi(line + 2 + i);
	i += ft_count(ft_atoi(line + 2 + i));
	if (line[3 + i])
		map->error = 1;
	if (map->error)
	{
		ft_putstr_fd("Error !\nError with screen size...\n", 2);
		exit(1);
	}
}

void	ft_get_map(t_map *map, char *line)
{
	(void)map;
	(void)line;
}

void	ft_get_data(t_map *map)
{
	char	*line;
	int		fd;

	if (!(fd = open(map->path_map, O_RDONLY)))
		return ;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			ft_get_r(map, line);
		else if (line[0] == 'N' && line[1] == 'O')
			ft_get_no(map, line);
		else if (line[0] == 'S' && line[1] == 'O')
			ft_get_so(map, line);
		else if (line[0] == 'W' && line[1] == 'E')
			ft_get_we(map, line);
		else if (line[0] == 'E' && line[1] == 'A')
			ft_get_ea(map, line);
		else if (line[0] == 'S')
			ft_get_s(map, line);
		else if (line[0] == 'F')
			ft_get_f(map, line);
		else if (line[0] == 'C')
			ft_get_c(map, line);
	}
}

void	ft_set_param(t_cub3d *param, char **argv)
{
	g_blue = 0x001E90FF;
	g_orange = 100100100;
	g_red = 150150150;
	g_brown = 0x00A52A2A;
	g_purple = 0x00800080;
	g_white = 0x00FFFFFF;
	g_green = 0x00008000;
	param->map.map = {{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
				 {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
				 {1, 1, 1, 0, 0, 0, 0, 0, 0, 1},
				 {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
				 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				 {1, 0, 0, 0, 1, 0, 0, 0, 0, 1},
				 {1, 0, 0, 0, 0, 1, 0, 0, 0, 1},
				 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				 {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
				 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
	param->map.screen_size[0] = -1;
	param->map.error = 0;
	param->map.color_floor = 0;
	param->map.color_ground = 0;
	param->map.path_north = NULL;
	param->map.path_south = NULL;
	param->map.path_west = NULL;
	param->map.path_east = NULL;
	param->map.path_sprite = NULL;
	param->map.path_map = argv[1];
	ft_get_data(&param->map);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr,\
		param->map.screen_size[0], param->map.screen_size[1], "cub3d");
	param->weight = 6;
	param->angle = 90;
	param->x_p = 480 - param->weight / 2;
	param->y_p = 270 - param->weight / 2;
}
