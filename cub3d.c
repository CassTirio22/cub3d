/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/07 18:28:23 by ctirions         ###   ########.fr       */
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
	param->angle = 0;
	param->x_p = 480 - param->weight / 2;
	param->y_p = 270 - param->weight / 2;
}

void	ft_put_player(t_cub3d param)
{
	float	dx;
	float	dy;
	float	i;
	int		j;

	/*i = -1;
	while (++i <= param.weight)
	{
		j = -1;
		while (++j <= param.weight)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p + i, param.y_p + j, 001203230);
	}
	*/
	ft_reset(param);
	i = -1;
	dx = cos((PI / 180) * (param.angle + 90)) * 30;
	dy = sin((PI / 180) * (param.angle + 90)) * 30;
	printf("dx : %f\ndy : %f\n%f\n",  dx, dy, param.y_p + dy * (0 - param.x_p) / dx);
	while (++i < dx)
		mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p + i, param.y_p + dy * (i - param.x_p) / dx, 241069123);
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

void	ft_up(t_cub3d *param)
{
	int	i;
	int	j;

	i = -1;
	if (param->y_p >= 27)
		param->y_p -= 27;
	while (++i <= param->weight)
	{
		j = -1;
		while (++j <= param->weight / 2)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x_p + i, param->y_p + j + param->weight, 0);
	}
	ft_put_player(*param);
}

void	ft_down(t_cub3d *param)
{
	int	i;
	int	j;

	i = -1;
	if (param->y_p <= 1053)
		param->y_p += 27;
	while (++i <= param->weight)
	{
		j = -1;
		while (++j <= param->weight / 2)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x_p + i, param->y_p + j - param->weight / 2, 0);
	}
	ft_put_player(*param);
}

void	ft_left(t_cub3d *param)
{
	int	i;
	int	j;

	i = -1;
	if (param->x_p >= 27)
		param->x_p -= 27;
	while (++i <= param->weight / 2)
	{
		j = -1;
		while (++j <= param->weight)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x_p + i + param->weight, param->y_p + j, 0);
	}
	ft_put_player(*param);
}

void	ft_right(t_cub3d *param)
{
	int	i;
	int	j;

	i = -1;
	if (param->x_p <= 1893)
		param->x_p += 27;
	while (++i <= param->weight / 2)
	{
		j = -1;
		while (++j <= param->weight)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x_p + i + param->weight / 2 - param->weight, param->y_p + j, 0);
	}
	ft_put_player(*param);
}

void	ft_rotate_left(t_cub3d *param)
{
	param->angle += 45;
	param->angle %= 360;
	ft_put_player(*param);
}

void	ft_rotate_right(t_cub3d *param)
{
	param->angle -= 45;
	param->angle %= 360;
	ft_put_player(*param);
}

int		ft_key_hook(int key_code, t_cub3d *param)
{
	printf("%d\n", key_code);
	if (key_code == 13)
	{
		if (!param->angle || param->angle == -360)
			ft_up(param);
		else if (param->angle == 90 || param->angle == -270)
			ft_left(param);
		else if (param->angle == 180 || param->angle == -180)
			ft_down(param);
		else if (param->angle == 270 || param->angle == -90)
			ft_right(param);
	}
	else if (key_code == 1)
	{
		if (!param->angle || param->angle == -360)
			ft_down(param);
		else if (param->angle == 90 || param->angle == -270)
			ft_right(param);
		else if (param->angle == 180 || param->angle == -180)
			ft_up(param);
		else if (param->angle == 270 || param->angle == -90)
			ft_left(param);
	}
	else if (!key_code)
	{
		if (!param->angle || param->angle == -360)
			ft_left(param);
		else if (param->angle == 90 || param->angle == -270)
			ft_down(param);
		else if (param->angle == 180 || param->angle == -180)
			ft_right(param);
		else if (param->angle == 270 || param->angle == -90)
			ft_up(param);
	}
	else if (key_code == 2)
	{
		if (!param->angle || param->angle == -360)
			ft_right(param);
		else if (param->angle == 90 || param->angle == -270)
			ft_up(param);
		else if (param->angle == 180 || param->angle == -180)
			ft_left(param);
		else if (param->angle == 270 || param->angle == -90)
			ft_down(param);
	}
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
	t_cub3d param;

	ft_set_param(&param);
	//ft_draw_map(param);
	ft_put_player(param);
	mlx_key_hook(param.win_ptr, ft_key_hook, &param);
	mlx_mouse_hook(param.win_ptr, ft_mouse_hook, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
//		gcc -lmlx -framework OpenGL -framework AppKit cub3d.c && ./a.out
