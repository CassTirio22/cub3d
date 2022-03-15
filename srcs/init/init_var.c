/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:40:59 by aliens            #+#    #+#             */
/*   Updated: 2022/03/15 17:04:20 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_var_2(t_cub *cub)
{
	if (cub->tex)
	{
		cub->tex->no = (t_img *)malloc(sizeof(t_img));
		cub->tex->so = (t_img *)malloc(sizeof(t_img));
		cub->tex->ea = (t_img *)malloc(sizeof(t_img));
		cub->tex->we = (t_img *)malloc(sizeof(t_img));
	}
	if (cub->var)
	{
		cub->var->no = NULL;
		cub->var->so = NULL;
		cub->var->ea = NULL;
		cub->var->we = NULL;
	}
	if (cub->map)
	{
		cub->map->map_lst = NULL;
		cub->map->info = (char **)malloc(sizeof(char *) * 7);
	}
}

int	init_var(t_cub *cub)
{
	cub->p1 = NULL;
	cub->img = NULL;
	cub->map = NULL;
	cub->var = NULL;
	cub->tex = NULL;
	cub->p1 = (t_player *)malloc(sizeof(t_player));
	cub->img = (t_img *)malloc(sizeof(t_img));
	cub->tex = (t_tex *)malloc(sizeof(t_tex));
	cub->map = (t_map *)malloc(sizeof(t_map));
	cub->var = (t_var *)malloc(sizeof(t_var));
	init_var_2(cub);
	if (!cub->p1 || !cub->img || !cub->map || !cub->map->info || !cub->tex)
		return (free_all(cub, 4));
	cub->map->info[6] = NULL;
	return (0);
}
