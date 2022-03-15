/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:21:42 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/15 17:24:19 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	error_msg(int error)
{
	printf("Error\n");
	if (error == 2)
		printf("Invalid map info\n");
	else if (error == 3)
		printf("Invalid map\n");
	else if (error == 4)
		printf("Malloc Error\n");
	else if (error == 5)
		printf("Invalid argument\n");
}

void	free_all_2(t_cub *cub)
{
	if (cub->var)
	{
		free(cub->var->so);
		free(cub->var->no);
		free(cub->var->ea);
		free(cub->var->we);
		free(cub->var);
	}
	if (cub->tex)
	{
		if (cub->tex->no)
			free(cub->tex->no);
		if (cub->tex->so)
			free(cub->tex->so);
		if (cub->tex->ea)
			free(cub->tex->ea);
		if (cub->tex->we)
			free(cub->tex->we);
		free(cub->tex);
	}
}

int	free_all(t_cub *cub, int error)
{
	if (cub->p1)
		free(cub->p1);
	if (cub->img)
		free(cub->img);
	if (cub->map)
	{
		free_double_char(cub->map->map);
		free_double_char(cub->map->info);
		free(cub->map);
	}
	free_all_2(cub);
	if (error)
		error_msg(error);
	exit(1);
	return (1);
}

void	free_double_char(char **str)
{
	int	i;

	if (!str)
		return ;
	i = -1;
	while (str[++i])
		free(str[i]);
	free(str[i]);
	free(str);
}
