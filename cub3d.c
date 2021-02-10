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
	param->mouse_x = 0;
	param->mouse_y = 0;
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
	float	x;
	float	y;
	int		i;

	dx = cos((PI / 180) * param.angle) * 30;
	dy = sin((PI / 180) * param.angle) * 30;
	if (fabsf(dx) > fabsf(dy))
		i = fabsf(dx);
	else
		i = fabsf(dy);
	dx /= i;
	dy /= i;
	while (i--)
	{
		x += dx;
		y += dy;
		mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p - x, param.y_p - y, color);
	}
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
		color = 32123123;
	ft_put_line(param, color);
}

void	ft_square(int x, int y, int wall_or_not, t_cub3d param)
{
	int	color;
	int	i;
	int	j;

	i = -1;
	color = !wall_or_not ? 0 : 071230140;
	while (++i < 108)
	{
		j = -1;
		while (++j < 108)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, x * 108 + i, y * 108 + j, color);
	}
}

void	ft_draw_map(t_cub3d param)
{
	int	i;
	int	j;
	int mapX;
	int	mapY;
	int	mapS;
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
	mapS = mapY * mapX;
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
	ft_put_player(*param, 100100100);
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
	ft_put_player(*param, 100100100);
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
	ft_put_player(*param, 100100100);
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
	ft_put_player(*param, 100100100);
}

void	ft_rotate_left(t_cub3d *param)
{
	ft_put_player(*param, 0);
	param->angle -= 15;
	param->angle %= 360;
	ft_put_player(*param, 100100100);
}

void	ft_rotate_right(t_cub3d *param)
{
	ft_put_player(*param, 0);
	param->angle += 15;
	param->angle %= 360;
	ft_put_player(*param, 100100100);
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

int		ft_mouse_hook(int bouton, int x, int y, t_cub3d *param)
{
	printf("%d\n%d\n%d\n", bouton, x, y);
	return (0);
}

int	main(void)
{
	int		width;
	int		height;
	t_cub3d param;
	void	*img_ptr;

	ft_set_param(&param);
	img_ptr = mlx_new_image(param.mlx_ptr, 10, 10);
	img_ptr = mlx_xpm_file_to_image(param.mlx_ptr, "image.png", &width, &height);
	//mlx_put_image_to_window(param.mlx_ptr, param.win_ptr, img_ptr, param.x_p, param.y_p);
	ft_draw_map(param);
	ft_put_player(param, 100100100);
	mlx_key_hook(param.win_ptr, ft_key_hook, &param);
	mlx_mouse_hook(param.win_ptr, ft_mouse_hook, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}

//		gcc -lmlx -framework OpenGL -framework AppKit cub3d.c && ./a.out