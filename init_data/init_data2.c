/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:10:40 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/17 18:27:41 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

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
