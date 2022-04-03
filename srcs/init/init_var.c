/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:40:59 by aliens            #+#    #+#             */
/*   Updated: 2022/04/03 23:21:13 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	init_var_2(t_cub *cub)
{
	int	i;

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
		cub->map->map = NULL;
		cub->map->info = (char **)malloc(sizeof(char *) * 7);
		i = -1;
		while (++i < 7)
			cub->map->info[i] = NULL;
	}
}

void	init_var_3(t_cub *cub)
{
	if (cub->var)
	{
		cub->var->touch = 0;
		cub->var->up = 0;
		cub->var->down = 0;
		cub->var->left = 0;
		cub->var->right = 0;
		cub->var->rot_left = 0;
		cub->var->rot_right = 0;
		cub->var->run = 0;
		cub->var->f = 0;
		cub->var->c = 0;
	}
}

int	init_var(t_cub *cub)
{
	cub->p1 = NULL;
	cub->img = NULL;
	cub->map = NULL;
	cub->var = NULL;
	cub->tex = NULL;
	cub->mlx_ptr = NULL;
	cub->win_ptr = NULL;
	cub->p1 = (t_player *)malloc(sizeof(t_player));
	cub->img = (t_img *)malloc(sizeof(t_img));
	cub->tex = (t_tex *)malloc(sizeof(t_tex));
	cub->map = (t_map *)malloc(sizeof(t_map));
	cub->var = (t_var *)malloc(sizeof(t_var));
	init_var_2(cub);
	init_var_3(cub);
	if (!cub->p1 || !cub->img || !cub->map || !cub->map->info || !cub->tex || \
	!cub->var || !cub->tex->no || !cub->tex->so || !cub->tex->ea || \
	!cub->tex->we)
		return (free_all(cub, 4));
	return (0);
}
