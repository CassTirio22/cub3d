/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/17 15:39:54 by ctirions         ###   ########.fr       */
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
	return(t << 24 | r << 16 | g << 8 | b);
}

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

void	ft_get_c(t_cub3d *param, char *line)
{
	int	r;
	int	g;
	int	b;
	int	i;

	if (param->color_floor)
		param->error = 1;
	if (line[1] != ' ')
		param->error = 1;
	r = ft_atoi(line + 2);
	i = ft_count(r);
	if (line[2 + i] != ',')
		param->error = 1;
	g = ft_atoi(line + 3 + i);
	i += ft_count(g);
	if (line[3 + i] != ',')
		param->error = 1;
	b = ft_atoi(line + 4 + i);
	i += ft_count(b);
	if (line[4 + i])
		param->error = 1;
	if (param->error)
	{
		ft_putstr_fd("Error !\nError with floor color...\n", 2);
		exit(1);
	}
	param->color_floor = create_trgb(0, r, g, b);
}

void	ft_get_f(t_cub3d *param, char *line)
{
	int	r;
	int	g;
	int	b;
	int	i;

	if (param->color_ground)
		param->error = 1;
	if (line[1] != ' ')
		param->error = 1;
	r = ft_atoi(line + 2);
	i = ft_count(r);
	if (line[2 + i] != ',')
		param->error = 1;
	g = ft_atoi(line + 3 + i);
	i += ft_count(g);
	if (line[3 + i] != ',')
		param->error = 1;
	b = ft_atoi(line + 4 + i);
	i += ft_count(b);
	if (line[4 + i])
		param->error = 1;
	if (param->error)
	{
		ft_putstr_fd("Error !\nError with ground color...\n", 2);
		exit(1);
	}
	param->color_ground = create_trgb(0, r, g, b);
}

void	ft_get_no(t_cub3d *param, char *line)
{
	int i;

	if (param->path_north)
		param->error = 1;
	if (line[2] != ' ')
		param->error = 1;
	i = ft_strlen(line + 3);
	if (!(param->path_north = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		param->path_north[i] = line[3 + i];
	if (param->error)
	{
		ft_putstr_fd("Error !\nError with north path...\n", 2);
		exit(1);
	}
}

void	ft_get_so(t_cub3d *param, char *line)
{
	int i;

	if (param->path_south)
		param->error = 1;
	if (line[2] != ' ')
		param->error = 1;
	i = ft_strlen(line + 3);
	if (!(param->path_south = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		param->path_south[i] = line[3 + i];
	if (param->error)
	{
		ft_putstr_fd("Error !\nError with south path...\n", 2);
		exit(1);
	}
}

void	ft_get_we(t_cub3d *param, char *line)
{
	int i;

	if (param->path_west)
		param->error = 1;
	if (line[2] != ' ')
		param->error = 1;
	i = ft_strlen(line + 3);
	if (!(param->path_west = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		param->path_west[i] = line[3 + i];
	if (param->error)
	{
		ft_putstr_fd("Error !\nError with west path...\n", 2);
		exit(1);
	}
}

void	ft_get_ea(t_cub3d *param, char *line)
{
	int i;

	if (param->path_east)
		param->error = 1;
	if (line[2] != ' ')
		param->error = 1;
	i = ft_strlen(line + 3);
	if (!(param->path_east = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		param->path_east[i] = line[3 + i];
	if (param->error)
	{
		ft_putstr_fd("Error !\nError with east path...\n", 2);
		exit(1);
	}
}

void	ft_get_s(t_cub3d *param, char *line)
{
	int i;

	if (param->path_sprite)
		param->error = 1;
	if (line[1] != ' ')
		param->error = 1;
	i = ft_strlen(line + 2);
	if (!(param->path_sprite = (char *)ft_calloc(sizeof(char), i + 1)))
		return ;
	while (i--)
		param->path_sprite[i] = line[2 + i];

	if (param->error)
	{
		ft_putstr_fd("Error !\nError with sprite path...\n", 2);
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
	int 	fd;
	int		i;

	i = 0;
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
		if (i == 7)
			ft_get_map(param, line);
	}
}

void	ft_set_param(t_cub3d *param, char **argv)
{
	param->screen_size[0] = -1;
	param->error = 0;
	param->color_floor = 0;
	param->color_ground = 0;
	param->path_north = NULL;
	param->path_south = NULL;
	param->path_west = NULL;
	param->path_east = NULL;
	param->path_sprite = NULL;
	param->path_map = argv[1];
	ft_get_data(param);
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, param->screen_size[0], param->screen_size[1], "cub3d");
	param->weight = 6;
	param->angle = 90;
	param->x_p = 480 - param->weight / 2;
	param->y_p = 270 - param->weight / 2;
}

int		ft_is_wall(int x, int y)
{
	if (g_map[y / 108][x / 108])
		return (1);
	return (0);
}

float	ft_put_line(t_cub3d param, int color)
{
	float	dx;
	float	dy;
	int		i;

	i = 0;
	dx = cos((M_PI / 180) * param.angle);
	dy = sin((M_PI / 180) * param.angle);
	while (++i < 1000 && !ft_is_wall(param.x_p - (i * dx), param.y_p - (i * dy)))
		mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p - (i * dx), param.y_p - (i * dy), color);
	return (sqrt(i * (dx * dx) + (dy * dy) * i));
}

void	ft_put_view(t_cub3d *param, int color)
{
	int	i;
	int	j;

	j = 30;
	i = -1;
	while (++i < j)
	{
		param->angle++;
		ft_put_line(*param, color);
	}
	param->angle -= j;
	i = -1;
	while (++i < j)
	{
		param->angle--;
		ft_put_line(*param, color);

	}
	param->angle += j;
}

void	ft_put_player(t_cub3d param, int color)
{
	float	i;
	int		j;

	i = -1;
	while (++i <= param.weight)
	{
		j = -1;
		while (++j <= param.weight)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p + i - param.weight / 2, param.y_p + j - param.weight / 2, color);
	}
	if (color)
		color = param.color_floor;
	ft_put_line(param, color);
	ft_put_view(&param, color);
}

void	ft_square(int x, int y, int wall_or_not, t_cub3d param)
{
	int	i;
	int	j;

	if (!wall_or_not)
		return ;
	i = -1;
	while (++i < 108)
	{
		j = -1;
		while (++j < 108)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, x * 108 + i, y * 108 + j, param.color_ground);
	}
}

void	ft_draw_map(t_cub3d param)
{
	int	i;
	int	j;
	int mapX;
	int	mapY;

	i = -1;
	mapX = 10;
	mapY = 10;
	while (++i < mapX)
	{
		j =-1;
		while (++j < mapY)
			ft_square(i, j, g_map[j][i], param);
	}
}

void	ft_a(t_cub3d *param)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * param->angle) * 5;
	dy = sin((M_PI / 180) * param->angle) * 5;
	while (++i < param->weight)
	{
		j = -1;
		while (++j < param->weight)
			if (ft_is_wall(param->x_p - dy + i - param->weight / 2, param->y_p + dx + j - param->weight / 2))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p -= dy;
	param->y_p += dx;
	ft_put_player(*param, g_white);
}

void	ft_d(t_cub3d *param)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * param->angle) * 5;
	dy = sin((M_PI / 180) * param->angle) * 5;
	while (++i < param->weight)
	{
		j = -1;
		while (++j < param->weight)
			if (ft_is_wall(param->x_p + dy + i - param->weight / 2, param->y_p - dx + j - param->weight / 2))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p += dy;
	param->y_p -= dx;
	ft_put_player(*param, g_white);
}

void	ft_w(t_cub3d *param)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * param->angle) * 5;
	dy = sin((M_PI / 180) * param->angle) * 5;
	while (++i < param->weight)
	{
		j = -1;
		while (++j < param->weight)
			if (ft_is_wall(param->x_p - dx + i - param->weight / 2, param->y_p - dy + j - param->weight / 2))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p -= dx;
	param->y_p -= dy;
	ft_put_player(*param, g_white);
}

void	ft_s(t_cub3d *param)
{
	float	dx;
	float	dy;
	int		i;
	int		j;

	i = -1;
	dx = cos((M_PI / 180) * param->angle) * 5;
	dy = sin((M_PI / 180) * param->angle) * 5;
	while (++i < param->weight)
	{
		j = -1;
		while (++j < param->weight)
			if (ft_is_wall(param->x_p + dx + i - param->weight / 2, param->y_p + dy + j - param->weight / 2))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p += dx;
	param->y_p += dy;
	ft_put_player(*param, g_white);
}

void	ft_rotate_left(t_cub3d *param)
{
	ft_put_player(*param, 0);
	param->angle -= 5;
	param->angle %= 360;
	ft_put_player(*param, g_white);
}

void	ft_rotate_right(t_cub3d *param)
{
	ft_put_player(*param, 0);
	param->angle += 5;
	param->angle %= 360;
	ft_put_player(*param, g_white);
}

int		ft_mlx_close(t_cub3d *param)
{
	(void)param;
	exit(1);
	return (0);
}

int		ft_key_hook(int key_code, t_cub3d *param)
{
	if (key_code == 13)
		ft_w(param);
	else if (key_code == 1)
		ft_s(param);
	else if (key_code == 0)
		ft_a(param);
	else if (key_code == 2)
		ft_d(param);
	else if (key_code == 123)
		ft_rotate_left(param);
	else if (key_code == 124)
		ft_rotate_right(param);
	else if (key_code == 53)
		ft_mlx_close(param);
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

int	main(int argc, char **argv)
{
	t_cub3d param;

	ft_argc_error(argc);
	ft_set_param(&param, argv);
	ft_draw_map(param);
	ft_put_player(param, g_white);
	mlx_hook(param.win_ptr, 2, 1L<<0, ft_key_hook, &param);
	mlx_hook(param.win_ptr, 17, 1L<<17, ft_mlx_close, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
