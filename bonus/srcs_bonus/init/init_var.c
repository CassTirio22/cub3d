/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/07 14:40:59 by aliens            #+#    #+#             */
/*   Updated: 2022/04/03 23:25:08 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_cub_tex(t_cub *cub)
{
	if (cub->tex)
	{
		cub->tex->no = (t_img *)malloc(sizeof(t_img));
		cub->tex->so = (t_img *)malloc(sizeof(t_img));
		cub->tex->ea = (t_img *)malloc(sizeof(t_img));
		cub->tex->we = (t_img *)malloc(sizeof(t_img));
		cub->tex->door = (t_img *)malloc(sizeof(t_img));
	}
}

void	init_cub_var(t_cub *cub)
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
		cub->var->no = NULL;
		cub->var->so = NULL;
		cub->var->ea = NULL;
		cub->var->we = NULL;
		cub->var->run = 0;
	}
}

void	init_cub_map(t_cub *cub)
{
	int	i;

	if (cub->map)
	{
		cub->map->map_lst = NULL;
		cub->map->map = NULL;
		cub->map->info = (char **)malloc(sizeof(char *) * 8);
		i = -1;
		while (++i < 8)
			cub->map->info[i] = NULL;
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
	init_cub_tex(cub);
	init_cub_var(cub);
	init_cub_map(cub);
	if (!cub->p1 || !cub->img || !cub->map || !cub->map->info || !cub->tex || \
	!cub->var || !cub->tex->no || !cub->tex->so || !cub->tex->ea || \
	!cub->tex->we || !cub->tex->door)
		return (free_all(cub, 4));
	return (0);
}
