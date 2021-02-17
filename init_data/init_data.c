/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:10:50 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/17 18:27:14 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	ft_get_r(t_cub3d *param, char *line)
{
	int i;

	if (param->screen_size[0] != -1)
		param->error = 1;
	if (line[1] != ' ')
		param->error = 1;
	param->screen_size[0] = ft_atoi(line + 2);
	i = ft_count(param->screen_size[0]);
	if (line[i + 2] != ' ')
		param->error = 1;
	else if (ft_atoi(line + 2 + i))
		param->screen_size[1] = ft_atoi(line + 2 + i);
	i += ft_count(ft_atoi(line + 2 + i));
	if (line[3 + i])
		param->error = 1;
	if (param->error)
	{
		ft_putstr_fd("Error !\nError with screen size...\n", 2);
		exit(1);
	}
}

void	ft_get_map(t_cub3d *param, char *line)
{
	(void)param;
	(void)line;
}

void	ft_get_data(t_cub3d *param)
{
	char	*line;
	int		fd;

	if (!(fd = open(param->path_map, O_RDONLY)))
		return ;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R')
			ft_get_r(param, line);
		else if (line[0] == 'N' && line[1] == 'O')
			ft_get_no(param, line);
		else if (line[0] == 'S' && line[1] == 'O')
			ft_get_so(param, line);
		else if (line[0] == 'W' && line[1] == 'E')
			ft_get_we(param, line);
		else if (line[0] == 'E' && line[1] == 'A')
			ft_get_ea(param, line);
		else if (line[0] == 'S')
			ft_get_s(param, line);
		else if (line[0] == 'F')
			ft_get_f(param, line);
		else if (line[0] == 'C')
			ft_get_c(param, line);
	}
}

void	ft_set_param(t_cub3d *param, t_map *map, char **argv)
{
	map->screen_size[0] = -1;
	map->error = 0;
	map->color_floor = 0;
	map->color_ground = 0;
	map->path_north = NULL;
	map->path_south = NULL;
	map->path_west = NULL;
	map->path_east = NULL;
	map->path_sprite = NULL;
	map->path_map = argv[1];
	ft_get_data(param);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr,\
		map->screen_size[0], map->screen_size[1], "cub3d");
	param->weight = 6;
	param->angle = 90;
	param->x_p = 480 - param->weight / 2;
	param->y_p = 270 - param->weight / 2;
}
