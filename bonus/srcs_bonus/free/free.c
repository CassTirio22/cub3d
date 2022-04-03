/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:21:42 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/03 16:45:25 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	error_msg(int error)
{
	if (error == 1)
		return ;
	printf("Error\n");
	if (error == 2)
		printf("Invalid textures\n");
	else if (error == 3)
		printf("Invalid character in map\n");
	else if (error == 4)
		printf("Malloc Error\n");
	else if (error == 5)
		printf("Invalid argument\nUsage : ./cub3D <path_to_map.cub>\n");
	else if (error == 6)
		printf("Map does not exist\n");
	else if (error == 7)
		printf("Map is not closed\n");
	else if (error == 8)
		printf("No player on map\n");
	else if (error == 9)
		printf("Too much player on map\n");
	else if (error == 10)
		printf("Invalid color\nUsage : C or F <0~255>, <0~255>, <0~255>\n");
	else if (error == 11)
		printf("Multiple map infos declaration\n");
	else if (error == 12)
		printf("Invalid resolution\n");
}

void	free_cub_var(t_cub *cub)
{
	if (cub->var)
	{
		if (cub->var->so)
			free(cub->var->so);
		if (cub->var->no)
			free(cub->var->no);
		if (cub->var->ea)
			free(cub->var->ea);
		if (cub->var->we)
			free(cub->var->we);
		free(cub->var);
	}
}

void	free_cub_tex(t_cub *cub)
{
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
		if (cub->tex->door)
			free(cub->tex->door);
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
		if (cub->map->info)
			free_double_char(cub->map->info);
		if (cub->map->map)
			free_double_char(cub->map->map);
		free(cub->map);
	}
	free_cub_var(cub);
	free_cub_tex(cub);
	if (error)
		error_msg(error);
	exit(error);
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
