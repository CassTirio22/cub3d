/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:14:04 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/12 20:49:38 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	transform_map_line(char **line, int max_len)
{
	char	*save_b;
	char	*save_a;
	int		i;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == ' ')
			(*line)[i] = '2';
		if ((*line)[i] == '\t')
		{
			save_a = ft_strdup(*line + i + 1);
			save_b = ft_substr(*line, 0, i);
			free(*line);
			save_b = ft_gnljoin(save_b, "2222");
			*line = ft_gnljoin(save_b, save_a);		/*---To protect---*/
			free(save_a);
			i = -1;
		}
	}
	while (++i <= max_len)
	{
		*line = ft_gnljoin(*line, "2");
		if (!*line)
			return (0);
	}
	return (1);
}

/*---ft_gnljoin to protect---*/

int	verify_map(t_map *map)
{
	int	max_len;
	int	i;

	i = -1;
	max_len = 0;
	while (map->map[++i])
		if ((int)ft_strlen(map->map[i]) > max_len)
			max_len = ft_strlen_cub3d(map->map[i]);
	i = -1;
	while (map->map[++i])
		if (!transform_map_line(&map->map[i], max_len))
			return (0);
	return (1);
}

char	**init_check_info_map(int info[8])
{
	int		i;
	char	**ret;

	i = -1;
	while (++i < 8)
		info[i] = 0;
	ret = (char **)malloc(sizeof(char *) * 8);
	if (!ret)
		return (NULL);
	ret[0] = "R ";
	ret[1] = "F ";
	ret[2] = "C ";
	ret[3] = "S ";
	ret[4] = "NO ";
	ret[5] = "SO ";
	ret[6] = "WE ";
	ret[7] = "EA ";
	return (ret);
}

int	verify_map_info(t_cub *cub)
{
	char	**check;
	int		info[8];
	int		i;
	int		j;

	check = init_check_info_map(info);
	if (!check)
		return (0);
	i = -1;
	while (cub->map->info[++i])
	{
		j = -1;
		while (++j < 8)
			if (!ft_strncmp(cub->map->info[i], check[j], ft_strlen(check[j])))
				info[j]++;
	}
	free(check);
	i = -1;
	while (++i < 8)
		if (info[i] != 1)
			return (0);
	if (!verify_map(cub->map))
		return (0);
	return (1);
}
