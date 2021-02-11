/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/11 15:06:18 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_reset(t_cub3d param)
{
	int	i;
	int	j;

	i =-1;
	while (++i < 1921)
	{
		j = -1;
		while (++j < 1081)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, i, j, 0);
	}
}

void	ft_set_param(t_cub3d *param)
{
	param->mlx_ptr = mlx_init();
	param->win_ptr = mlx_new_window(param->mlx_ptr, 1920, 1080, "cub3d");
	param->weight = 10;
	param->angle = 90;
	param->x_p = 480 - param->weight / 2;
	param->y_p = 270 - param->weight / 2;
}

int		ft_is_wall(int x, int y)
{
	if (g_map[y / 108][x / 108] == 1)
		return (1);
	return (0);
}

void	ft_put_line(t_cub3d param, int color)
{
	float	dx;
	float	dy;
	int		i;

	i = 0;
	dx = cos((M_PI / 180) * param.angle);
	dy = sin((M_PI / 180) * param.angle);
	while (++i < 1000 && !ft_is_wall(param.x_p - (i * dx), param.y_p - (i * dy)))
		mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p - (i * dx), param.y_p - (i * dy), color);
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
	while (++i <= param.weight / 2)
	{
		j = -1;
		while (++j <= param.weight / 2)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p + i - param.weight / 4, param.y_p + j - param.weight / 4, color);
	}
	if (color)
		color = g_green;
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
	while (++i < 106)
	{
		j = -1;
		while (++j < 106)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, x * 108 + i, y * 108 + j, g_wall_color);
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
	while (++i < param->weight / 2)
	{
		j = -1;
		while (++j < param->weight / 2)
			if (ft_is_wall(param->x_p - dy + i - 2 * dy / 13, param->y_p + dx + j + 2 * dx / 13))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p -= dy;
	param->y_p += dx;
	ft_put_player(*param, g_orange);
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
	while (++i < param->weight / 2)
	{
		j = -1;
		while (++j < param->weight / 2)
			if (ft_is_wall(param->x_p + dy + i + 2 * dy / 13, param->y_p - dx + j - 2 * dx / 13))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p += dy;
	param->y_p -= dx;
	ft_put_player(*param, g_orange);
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
	while (++i < param->weight / 2)
	{
		j = -1;
		while (++j < param->weight / 2)
			if (ft_is_wall(param->x_p - dx - 2 * dx / 13 + i, param->y_p - dy + j - 2 * dy / 13))
				return ;
	}
	ft_put_player(*param, 0);
	param->x_p -= dx;
	param->y_p -= dy;
	ft_put_player(*param, g_orange);
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
	while (++i < param->weight / 2)
	{
		j = -1;
		while (++j < param->weight / 2)
			if (ft_is_wall(param->x_p + dx + i + 2 * dx / 5, param->y_p + dy + j + 2 * dy / 5))
				return ;
	}
	ft_put_player(*param, 0);
	printf("dx : %f\ndy : %f\n", dx, dy);
	param->x_p += dx;
	param->y_p += dy;
	ft_put_player(*param, g_orange);
}

void	ft_rotate_left(t_cub3d *param)
{
	ft_put_player(*param, 0);
	param->angle -= 15;
	param->angle %= 360;
	ft_put_player(*param, g_orange);
}

void	ft_rotate_right(t_cub3d *param)
{
	ft_put_player(*param, 0);
	param->angle += 15;
	param->angle %= 360;
	ft_put_player(*param, g_orange);
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
		exit(1);
	return (0);
}

int	main(void)
{
	int		width;
	int		height;
	t_cub3d param;
	void	*img_ptr;

	width = 10;
	height = 10;

	ft_set_param(&param);
	img_ptr = mlx_xpm_file_to_image(param.mlx_ptr, "circle.XPM", &width, &height);
	//mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img_ptr, param.x_p, param.y_p);
	ft_draw_map(param);
	ft_put_player(param, g_orange);
	mlx_hook(param.win_ptr, 2, 1L<<0, ft_key_hook, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}

//		gcc -lmlx -framework OpenGL -framework AppKit cub3d.c && ./a.out