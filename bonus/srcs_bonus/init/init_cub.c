/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cub.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 19:06:50 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/04 12:43:39 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_map_fc(t_map *map, t_var *var, int i, t_cub *cub)
{
	char	**tmp;

	tmp = NULL;
	if (!ft_strncmp(map->info[i], "F", 1) || !ft_strncmp(map->info[i], "C", 1))
	{
		tmp = ft_split(map->info[i] + 1, ',');
		if (double_char_len(tmp) != 3 || check_color(tmp))
		{
			free_double_char(tmp);
			free_all(cub, 10);
		}
		if (!ft_strncmp(map->info[i], "F", 1))
			var->f = do_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		else
			var->c = do_rgb(ft_atoi(tmp[0]), ft_atoi(tmp[1]), ft_atoi(tmp[2]));
		free_double_char(tmp);
	}
}

void	init_map_info(t_map *map, t_var *var, t_cub *cub)
{
	char	**tmp;
	int		j[3];
	int		i;

	i = -1;
	tmp = NULL;
	while (map->info[++i])
	{
		if (!ft_strncmp(map->info[i], "SO", 2) && spc_inf(map->info[i], j, cub))
			var->so = ft_substr(map->info[i], 2 + j[0], j[2]);
		if (!ft_strncmp(map->info[i], "NO", 2) && spc_inf(map->info[i], j, cub))
			var->no = ft_substr(map->info[i], 2 + j[0], j[2]);
		if (!ft_strncmp(map->info[i], "EA", 2) && spc_inf(map->info[i], j, cub))
			var->ea = ft_substr(map->info[i], 2 + j[0], j[2]);
		if (!ft_strncmp(map->info[i], "WE", 2) && spc_inf(map->info[i], j, cub))
			var->we = ft_substr(map->info[i], 2 + j[0], j[2]);
		init_map_fc(map, var, i, cub);
		init_map_r(map, var, i, cub);
	}
	var->wall_size = var->resolution[0] / 100;
	if (var->wall_size > var->resolution[1] / 100)
		var->wall_size = var->resolution[1] / 100;
}

void	init_player(t_cub *cub)
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
}

void	init_mlx(t_cub *cub)
{
	cub->mlx_ptr = mlx_init();
	if (!cub->mlx_ptr)
		free_all(cub, 14);
	cub->win_ptr = mlx_new_window(cub->mlx_ptr, \
	cub->var->resolution[0], cub->var->resolution[1], "cub3D");
	cub->img->img = mlx_new_image(cub->mlx_ptr, \
	cub->var->resolution[0], cub->var->resolution[1]);
	cub->img->addr = mlx_get_data_addr(cub->img->img, \
	&cub->img->bits_per_pixel, &cub->img->line_length, &cub->img->endian);
	init_textures(cub->tex, cub);
}

char	**init_check_info_map_bonus(int info[7], t_cub *cub)
{
	int		i;
	char	**ret;

	i = -1;
	while (++i < 7)
		info[i] = 0;
	ret = (char **)malloc(sizeof(char *) * 7);
	if (!ret)
		free_all(cub, 4);
	ret[0] = "R";
	ret[1] = "F";
	ret[2] = "C";
	ret[3] = "NO";
	ret[4] = "SO";
	ret[5] = "WE";
	ret[6] = "EA";
	return (ret);
}
