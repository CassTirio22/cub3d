/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:21:42 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/14 17:25:22 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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

int	free_all(t_cub *cub)
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
