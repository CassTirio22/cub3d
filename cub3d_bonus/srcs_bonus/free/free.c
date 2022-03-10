/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:21:42 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/10 17:24:36 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

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
	if (cub->var)
	{
		free(cub->var->so);
		free(cub->var->no);
		free(cub->var->ea);
		free(cub->var->we);
		free(cub->var);
	}
	return (1);
}

int	init_protect(t_cub *cub)
{
	if (cub->p1)
		free(cub->p1);
	if (cub->img)
		free(cub->img);
	if (cub->map)
		free(cub->map);
	if (cub->map->info)
		free(cub->map->info);
	if (cub->var)
		free(cub->var);
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
