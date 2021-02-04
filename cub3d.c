/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/04 18:05:39 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

void	ft_set_param(t_cub3d *param)
{
	param->weight = 70;
	param->x_p = 960 - param->weight / 2;
	param->y_p = 540 - param->weight / 2;
}

void	ft_reset(t_cub3d param)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 1921)
	{
		j = -1;
		while (++j < 1081)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, i, j, 056230100);
	}
}

void	ft_put_player(t_cub3d param)
{
	int	i;
	int	j;

	i = -1;
	while (++i <= param.weight)
	{
		j = -1;
		while (++j <= param.weight)
			mlx_pixel_put(param.mlx_ptr, param.win_ptr, param.x_p + i, param.y_p + j, 01203230);
	}
}

void	ft_up(t_cub3d *param)
{
	int	i;
	int	j;

	i = -1;
	if (param->y_p >= 35)
		param->y_p -= 35;
	while (++i <= param->weight)
	{
		j = -1;
		while (++j <= param->weight / 2)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x_p + i, param->y_p + j + param->weight, 056230100);
	}
	ft_put_player(*param);
}

void	ft_down(t_cub3d *param)
{
	int	i;
	int	j;

	i = -1;
	if (param->y_p <= 1045)
		param->y_p += 35;
	while (++i <= param->weight)
	{
		j = -1;
		while (++j <= param->weight)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x_p + i, param->y_p + j - param->weight, 056230100);
	}
	ft_put_player(*param);
}

void	ft_left(t_cub3d *param)
{
	int	i;
	int	j;

	i = -1;
	if (param->x_p >= 35)
		param->x_p -= 35;
	while (++i <= param->weight / 2)
	{
		j = -1;
		while (++j <= param->weight)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x_p + i + param->weight, param->y_p + j, 056230100);
	}
	ft_put_player(*param);
}

void	ft_right(t_cub3d *param)
{
	int	i;
	int	j;

	i = -1;
	if (param->x_p <= 1905)
		param->x_p += 35;
	while (++i <= param->weight)
	{
		j = -1;
		while (++j <= param->weight)
			mlx_pixel_put(param->mlx_ptr, param->win_ptr, param->x_p + i - param->weight, param->y_p + j, 056230100);
	}
	ft_put_player(*param);
}

int		ft_key_hook(int key_code, t_cub3d *param)
{
	if (key_code == 13)
		ft_up(param);
	else if (key_code == 1)
		ft_down(param);
	else if (key_code == 0)
		ft_left(param);
	else if (key_code == 2)
		ft_right(param);
	return (0);
}

int	main(void)
{
	t_cub3d param;

	ft_set_param(&param);
	param.mlx_ptr = mlx_init();
	param.win_ptr = mlx_new_window(param.mlx_ptr, 1920, 1080, "cub3d");
	ft_reset(param);
	ft_put_player(param);
	mlx_key_hook(param.win_ptr, ft_key_hook, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
//		gcc -lmlx -framework OpenGL -framework AppKit cub3d.c
