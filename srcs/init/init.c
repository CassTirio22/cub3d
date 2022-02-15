/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:06:50 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/15 17:18:40 by ctirions         ###   ########.fr       */
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
	cub->map = (t_map *)malloc(sizeof(t_map));
	cub->var = (t_var *)malloc(sizeof(t_var));
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
		if (cub->var)
			free(cub->var);
		return (1);
	}
	cub->map->info[8] = NULL;
	return (0);
}

void	init_map_info(t_map *map, t_var *var)
{
	char	**tmp;
	int		i;

	i = -1;
	while (map->info[++i])
	{
		if (!ft_strncmp(map->info[i], "SO", 2))
			var->so = ft_substr(map->info[i], 3, ft_strlen(map->info[i]) - 3);
		if (!ft_strncmp(map->info[i], "NO", 2))
			var->no = ft_substr(map->info[i], 3, ft_strlen(map->info[i]) - 3);
		if (!ft_strncmp(map->info[i], "EA", 2))
			var->ea = ft_substr(map->info[i], 3, ft_strlen(map->info[i]) - 3);
		if (!ft_strncmp(map->info[i], "WE", 2))
			var->we = ft_substr(map->info[i], 3, ft_strlen(map->info[i]) - 3);
		if (!ft_strncmp(map->info[i], "R", 1))
		{
			tmp = ft_split(map->info[i], ' ');
			var->resolution[0] = ft_atoi(tmp[1]);
			var->resolution[1] = ft_atoi(tmp[2]);
			free_double_char(tmp);
		}
	}
	var->wall_size = var->resolution[0] / ft_strlen(map->map[0]);
	if (var->wall_size > var->resolution[1] / double_char_len(map->map))
		var->wall_size = var->resolution[1] / double_char_len(map->map);
	printf("size : %d\n", var->wall_size);
}

int	init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		return (1);
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, \
	cub->var->resolution[0], cub->var->resolution[1], "cub3d");
	cub->img->img = mlx_new_image(cub->mlx_ptr, \
	cub->var->resolution[0], cub->var->resolution[1]);
	cub->img->addr = mlx_get_data_addr(cub->img->img, \
	&cub->img->bits_per_pixel, &cub->img->line_length, &cub->img->endian);
	return (0);
}
