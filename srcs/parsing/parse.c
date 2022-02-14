/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:40:53 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/14 17:19:40 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	get_line(char *line, t_cub *cub, int boolean, int index)
{
	if (!boolean)
	{
		cub->map->info[index] = ft_strdup(line);
		if (!cub->map->info[index])
		{
			free_double_char(cub->map->info);
			return (1);
		}	
	}
	else
		ft_lstadd_back(&cub->map->map_lst, ft_lstnew((char *)line));
	return (0);
}

int	get_info_map(char **argv, t_cub *cub)
{
	char	*line;
	int		fd;
	int		index;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (0);
	index = 0;
	while (get_next_line(fd, &line))
	{
		if (index < 8)
		{
			if (line[0])
				get_line(line, cub, 0, index++);
		}
		else
			get_line(line, cub, 1, index);
	}
	get_line(line, cub, 1, index);
	cub->map->map = lst_to_double_char(cub->map->map_lst);
	close(fd);
	return (1);
}

int	arround_zero(char **map, int i, int j)
{
	static int	nb_player;
	int			max_len;

	max_len = ft_strlen(map[i]);
	if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
		nb_player++;
	if (nb_player && nb_player != 1)
		return (0);
	if (!j)
		return (0);
	if (j == max_len)
		return (0);
	if (map[i][j - 1] != '0' && map[i][j - 1] != '1' && map[i][j - 1] != 'N' && map[i][j - 1] != 'S' && map[i][j - 1] != 'W' && map[i][j - 1] != 'E')
		return (0);
	if (map[i][j + 1] != '0' && map[i][j + 1] != '1' && map[i][j + 1] != 'N' && map[i][j + 1] != 'S' && map[i][j + 1] != 'W' && map[i][j + 1] != 'E')
		return (0);
	if (map[i - 1][j] != '0' && map[i - 1][j] != '1' && map[i - 1][j] != 'N' && map[i - 1][j] != 'S' && map[i - 1][j] != 'W' && map[i - 1][j] != 'E')
		return (0);
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1' && map[i + 1][j] != 'N' && map[i + 1][j] != 'S' && map[i + 1][j] != 'W' && map[i + 1][j] != 'E')
		return (0);
	return (1);
}

int	closed_map(char **map)
{
	int	max_size;
	int	i;
	int	j;

	max_size = double_char_len(map);
	i = -1;
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (!i || i == max_size)
			{
				if (map[i][j] != '1' && map[i][j] != '2')
					return (0);
			}
			else
				if (map[i][j] == '0' || map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
					if (!arround_zero(map, i, j))
						return (0);
		}
	}
	return (1);
}

int	parse(char **argv, t_cub *cub)
{
	if (!get_info_map(argv, cub) || !verify_map_info(cub))
		return (free_all(cub));
	if (!closed_map(cub->map->map))
		printf("OUVERT\n");
	else
		printf("FERME\n");
	return (0);
}
