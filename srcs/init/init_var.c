/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:40:59 by aliens            #+#    #+#             */
/*   Updated: 2022/03/08 15:00:02 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	init_var(t_cub *cub)
{
	cub->p1 = NULL;
	cub->img = NULL;
	cub->map = NULL;
	cub->var = NULL;
	cub->p1 = (t_player *)malloc(sizeof(t_player));
	cub->img = (t_img *)malloc(sizeof(t_img));
	cub->tex = (t_tex *)malloc(sizeof(t_tex));
	cub->tex->no = (t_img *)malloc(sizeof(t_img));
	cub->tex->so = (t_img *)malloc(sizeof(t_img));
	cub->tex->ea = (t_img *)malloc(sizeof(t_img));
	cub->tex->we = (t_img *)malloc(sizeof(t_img));
	cub->map = (t_map *)malloc(sizeof(t_map));
	cub->var = (t_var *)malloc(sizeof(t_var));
	if (cub->map)
	{
		cub->map->map_lst = NULL;
		cub->map->info = (char **)malloc(sizeof(char *) * (8 + 1));
	}
	if (!cub->p1 || !cub->img || !cub->map || !cub->map->info || !cub->tex)
		return (init_protect(cub));
	cub->map->info[8] = NULL;
	return (0);
}
