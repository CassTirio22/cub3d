/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:06:50 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/10 20:26:10 by ctirions         ###   ########.fr       */
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
	cub->map->info = (char **)malloc(sizeof(char *) * (8 + 1));		/*---To protect---*/
	cub->map->info[8] = NULL;
	if (!cub->p1 || !cub->img || !cub->map)
	{
		if (cub->p1)
			free(cub->p1);
		if (cub->img)
			free(cub->img);
		if (cub->map)
			free(cub->map);
		return (1);
	}
	return (0);
}
