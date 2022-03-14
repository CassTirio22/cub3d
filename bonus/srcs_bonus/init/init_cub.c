/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:06:50 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/10 18:50:30 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_map_fcr(t_map *map, t_var *var, int i)
{
	char	**tmp;

	tmp = NULL;
	if (!ft_strncmp(map->info[i], "R", 1))
	{
		tmp = ft_split(map->info[i], ' ');
		var->resolution[0] = ft_atoi(tmp[1]);
		var->resolution[1] = ft_atoi(tmp[2]);
		free_double_char(tmp);
	}
	if (!ft_strncmp(map->info[i], "F", 1))
	{
		tmp = ft_split(map->info[i] + 2, ',');
		var->f = do_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		free_double_char(tmp);
	}
	if (!ft_strncmp(map->info[i], "C", 1))
	{
		tmp = ft_split(map->info[i] + 2, ',');
		var->c = do_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		free_double_char(tmp);
	}
}

void	init_map_info(t_map *map, t_var *var)
{
	char	**tmp;
	int		i;

	i = -1;
	tmp = NULL;
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
		init_map_fcr(map, var, i);
	}
	var->wall_size = var->resolution[0] / 100;
	if (var->wall_size > var->resolution[1] / 100)
		var->wall_size = var->resolution[1] / 100;
}

int	init_player(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (cub->map->map[++i])
	{
		j = -1;
		while (cub->map->map[i][++j])
		{
			if (ft_isalpha(cub->map->map[i][j]))
			{
				cub->p1->pos[0] = j + 0.5;
				cub->p1->pos[1] = i + 0.5;
				if (cub->map->map[i][j] == 'E')
					cub->p1->angle = 0;
				if (cub->map->map[i][j] == 'N')
					cub->p1->angle = 90;
				if (cub->map->map[i][j] == 'W')
					cub->p1->angle = 180;
				if (cub->map->map[i][j] == 'S')
					cub->p1->angle = 270;
			}
		}
	}
	return (0);
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
	init_textures(cub->tex, cub);
	return (0);
}

char	**init_check_info_map(int info[7])
{
	int		i;
	char	**ret;

	i = -1;
	while (++i < 7)
		info[i] = 0;
	ret = (char **)malloc(sizeof(char *) * 7);
	if (!ret)
		return (NULL);
	ret[0] = "R ";
	ret[1] = "F ";
	ret[2] = "C ";
	ret[3] = "NO ";
	ret[4] = "SO ";
	ret[5] = "WE ";
	ret[6] = "EA ";
	return (ret);
}