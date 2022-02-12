/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:06:50 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/12 16:59:29 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_var(t_cub *cub)
{
	cub->p1 = NULL;
	cub->img = NULL;
	cub->map = NULL;
	cub->p1 = (t_player *)malloc(sizeof(t_player));
	cub->img = (t_img *)malloc(sizeof(t_img));
	cub->map = (t_map *)malloc(sizeof(t_map));
	if (cub->map)
	{
		cub->map->map_lst = NULL;
		cub->map->info = (char **)malloc(sizeof(char *) * (8 + 1));
	}
	if (!cub->p1 || !cub->img || !cub->map || !cub->map->info)
	{
		if (cub->p1)
			free(cub->p1);
		if (cub->img)
			free(cub->img);
		if (cub->map)
			free(cub->map);
		if (cub->map->info)
			free(cub->map->info);
		return (1);
	}
	cub->map->info[8] = NULL;
	return (0);
}
