/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 18:14:04 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/10 19:12:29 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	transform_map_line(char **line, int max_len)
{
	int		i;

	i = -1;
	while ((*line)[++i])
	{
		if ((*line)[i] == ' ')
			(*line)[i] = '2';
		else if ((*line)[i] == '1' || (*line)[i] == '0' || (*line)[i] == '3' || \
		(*line)[i] == 'N' || (*line)[i] == 'S' || (*line)[i] == 'W' || \
		(*line)[i] == 'E')
			;
		else
			return (0);
	}
	while (++i <= max_len)
	{
		*line = ft_gnljoin(*line, "2");
		if (!*line)
			return (0);
	}
	return (1);
}

int	transform_map(t_map *map)
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

int	arround_zero(char **map, int i, int j)
{
	if (!j)
		return (0);
	if (j == (int)ft_strlen(map[i]))
		return (0);
	if (map[i][j - 1] != '0' && map[i][j - 1] != '1' && map[i][j - 1] != '3' \
	&& map[i][j - 1] != 'N' && map[i][j - 1] != 'S' && map[i][j - 1] != 'W' && \
	map[i][j - 1] != 'E')
		return (0);
	if (map[i][j + 1] != '0' && map[i][j + 1] != '1' && map[i][j + 1] != '3' \
	&& map[i][j + 1] != 'N' && map[i][j + 1] != 'S' && map[i][j + 1] != 'W' && \
	map[i][j + 1] != 'E')
		return (0);
	if (map[i - 1][j] != '0' && map[i - 1][j] != '1' && map[i - 1][j] != '3' \
	&& map[i - 1][j] != 'N' && map[i - 1][j] != 'S' && map[i - 1][j] != 'W' && \
	map[i - 1][j] != 'E')
		return (0);
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1' && map[i + 1][j] != '3' \
	&& map[i + 1][j] != 'N' && map[i + 1][j] != 'S' && map[i + 1][j] != 'W' && \
	map[i + 1][j] != 'E')
		return (0);
	return (1);
}
