/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:10:50 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/18 16:45:21 by ctirions         ###   ########.fr       */
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

void	ft_get_map(t_map *map)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	map->height = ft_lstsize(map->the_map);
	map->weight = 0;
	if (!(map->map = (int **)malloc(sizeof(int *) * map->height)))
		return ;
	k = -1;
	while (map->the_map)
	{
		k++;
		i = -1;
		j = ft_strlen(map->the_map->content);
		if (j > map->weight)
			map->weight = j;
		if (!(map->map[k] = (int *)ft_calloc(sizeof(int), j)))
			return ;
		str = map->the_map->content;
		while (++i < j)
				map->map[k][i] = (int)str[i] - '0';
		map->the_map = map->the_map->next;
	}
}

void	ft_get_data(t_map *map)
{
	char	*line;
	int		fd;
	int		i;

	if (!(fd = open(map->path_map, O_RDONLY)))
		return ;
	i = 0;
	while (get_next_line(fd, &line))
	{
		if (line[0] == 'R' && ++i)
			ft_get_r(map, line);
		else if (line[0] == 'N' && line[1] == 'O' && ++i)
			ft_get_no(map, line);
		else if (line[0] == 'S' && line[1] == 'O' && ++i)
			ft_get_so(map, line);
		else if (line[0] == 'W' && line[1] == 'E' && ++i)
			ft_get_we(map, line);
		else if (line[0] == 'E' && line[1] == 'A' && ++i)
			ft_get_ea(map, line);
		else if (line[0] == 'S' && ++i)
			ft_get_s(map, line);
		else if (line[0] == 'F' && ++i)
			ft_get_f(map, line);
		else if (line[0] == 'C' && ++i)
			ft_get_c(map, line);
		else if (i >= 8)
				ft_lstadd_back(&map->the_map, ft_lstnew(line));
	}
	ft_lstadd_back(&map->the_map, ft_lstnew(line));
	ft_get_map(map);
}

void	ft_set_param(t_struct_list *struct_list, char **argv)
{
	g_blue = 0x001E90FF;
	g_orange = 100100100;
	g_red = 150150150;
	g_brown = 0x00A52A2A;
	g_purple = 0x00800080;
	g_white = 0x00FFFFFF;
	g_green = 0x00008000;
	struct_list->map = malloc(sizeof(t_map));
	struct_list->param = malloc(sizeof(t_param));
	struct_list->img = malloc(sizeof(t_data));
	struct_list->map->screen_size[0] = -1;
	struct_list->map->error = 0;
	struct_list->map->color_floor = 0;
	struct_list->map->color_ground = 0;
	struct_list->map->path_north = NULL;
	struct_list->map->path_south = NULL;
	struct_list->map->path_west = NULL;
	struct_list->map->path_east = NULL;
	struct_list->map->path_sprite = NULL;
	struct_list->map->path_map = argv[1];
	struct_list->map->the_map = NULL;
	ft_get_data(struct_list->map);
	struct_list->param->mlx_ptr = mlx_init();
	struct_list->param->win_ptr = mlx_new_window(struct_list->param->mlx_ptr,\
		struct_list->map->screen_size[0],\
		struct_list->map->screen_size[1], "cub3d");
	struct_list->img->img = mlx_new_image(struct_list->param->mlx_ptr,\
		struct_list->map->screen_size[0], struct_list->map->screen_size[1]);
	struct_list->img->addr = mlx_get_data_addr(struct_list->img->img, \
		&struct_list->img->bits_per_pixel, &struct_list->img->line_length, \
		&struct_list->img->endian);
	struct_list->param->weight = 6;
	struct_list->param->angle = 90;
	struct_list->param->dir_x = -1;
	struct_list->param->dir_y = 0;
	struct_list->param->plane_x = 0;
	struct_list->param->plane_y = 0.66;
	struct_list->param->x_p = 480 - struct_list->param->weight / 2;
	struct_list->param->y_p = 270 - struct_list->param->weight / 2;
}
