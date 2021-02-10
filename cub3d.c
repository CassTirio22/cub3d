/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/10 18:28:53 by ctirions         ###   ########.fr       */
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

void	ft_put_line(t_cub3d param, int color)
{
	float	dx;
	float	dy;
	int		i;

	i = 30;
	dx = cos((PI / 180) * param.angle);
	dy = sin((PI / 180) * param.angle);
	while (i--)
		mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p - (i * dx), param.y_p - (i * dy), color);
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
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p + i, param.y_p + j, color);
	}
	if (color)
		color = g_rose;
	ft_put_line(param, color);
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
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, x * 108 + i, y * 108 + j, g_wall_color);
	}
}

void	ft_draw_map(t_cub3d param)
{
	int	i;
	int	j;
	int mapX;
	int	mapY;
	int	map[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
				 1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
				 1, 1, 1, 0, 0, 0, 0, 0, 0, 1,
				 1, 0, 1, 0, 0, 0, 0, 0, 0, 1,
				 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
				 1, 0, 0, 0, 1, 0, 0, 0, 0, 1,
				 1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
				 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
				 1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
				 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

	i = -1;
	mapX = 10;
	mapY = 10;
	while (++i < mapX)
	{
		j =-1;
		while (++j < mapY)
			ft_square(i, j, map[j * mapX + i], param);
	}
}

void	ft_a(t_cub3d *param)
{
	float	dx;
	float	dy;

	ft_put_player(*param, 0);
	dx = cos((PI / 180) * param->angle) * 13;
	dy = sin((PI / 180) * param->angle) * 13;
	param->x_p -= dy;
	param->y_p += dx;
	ft_put_player(*param, g_orange);
}

void	ft_d(t_cub3d *param)
{
	float	dx;
	float	dy;

	ft_put_player(*param, 0);
	dx = cos((PI / 180) * param->angle) * 13;
	dy = sin((PI / 180) * param->angle) * 13;
	param->x_p += dy;
	param->y_p -= dx;
	ft_put_player(*param, g_orange);
}

void	ft_w(t_cub3d *param)
{
	float	dx;
	float	dy;

	ft_put_player(*param, 0);
	dx = cos((PI / 180) * param->angle) * 13;
	dy = sin((PI / 180) * param->angle) * 13;
	param->x_p -= dx;
	param->y_p -= dy;
	ft_put_player(*param, g_orange);
}

void	ft_s(t_cub3d *param)
{
	float	dx;
	float	dy;

	ft_put_player(*param, 0);
	dx = cos((PI / 180) * param->angle) * 13;
	dy = sin((PI / 180) * param->angle) * 13;
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

	ft_set_param(&param);
	img_ptr = mlx_xpm_file_to_image(param.mlx_ptr, "image.png", &width, &height);
	//mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img_ptr, param.x_p, param.y_p);
	ft_draw_map(param);
	ft_put_player(param, g_orange);
	mlx_key_hook(param.win_ptr, ft_key_hook, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}

//		gcc -lmlx -framework OpenGL -framework AppKit cub3d.c && ./a.out