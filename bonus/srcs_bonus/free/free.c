/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:21:42 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/02 15:31:31 by ctirions         ###   ########.fr       */
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
		printf("Invalid color\n");
	else if (error == 11)
		printf("Multiple map infos declaration\n");
	else if (error == 12)
		printf("Invalid resolution\n");
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
		if (cub->map->map)
			free_double_char(cub->map->map);
		if (cub->map->info)
			free_double_char(cub->map->info);
		free(cub->map);
	}
	free_all_2(cub);
	if (error)
		error_msg(error);
	system("leaks cub3D_bonus");
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
