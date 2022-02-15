/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:40:53 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/15 17:54:02 by ctirions         ###   ########.fr       */
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
	if (!j)
		return (0);
	if (j == (int)ft_strlen(map[i]))
		return (0);
	if (map[i][j - 1] != '0' && map[i][j - 1] != '1' && map[i][j - 1] != 'N' \
	&& map[i][j - 1] != 'S' && map[i][j - 1] != 'W' && map[i][j - 1] != 'E')
		return (0);
	if (map[i][j + 1] != '0' && map[i][j + 1] != '1' && map[i][j + 1] != 'N' \
	&& map[i][j + 1] != 'S' && map[i][j + 1] != 'W' && map[i][j + 1] != 'E')
		return (0);
	if (map[i - 1][j] != '0' && map[i - 1][j] != '1' && map[i - 1][j] != 'N' \
	&& map[i - 1][j] != 'S' && map[i - 1][j] != 'W' && map[i - 1][j] != 'E')
		return (0);
	if (map[i + 1][j] != '0' && map[i + 1][j] != '1' && map[i + 1][j] != 'N' \
	&& map[i + 1][j] != 'S' && map[i + 1][j] != 'W' && map[i + 1][j] != 'E')
		return (0);
	return (1);
}

int	closed_map(char **map)
{
	int	nb_player;
	int	max_size;
	int	i;
	int	j;

	nb_player = 0;
	max_size = double_char_len(map) - 1;
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
			else if (map[i][j] == '0')
			{
				if (!arround_zero(map, i, j))
					return (0);
			}
			else if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'W' || map[i][j] == 'E')
			{
				if (!arround_zero(map, i, j))
					return (0);
				nb_player++;
			}
		}
	}
	if (nb_player != 1)
		return (0);
	return (1);
}

int	parse(char **argv, t_cub *cub)
{
	if (!get_info_map(argv, cub) || !verify_map_info(cub))
		return (free_all(cub));
	if (!closed_map(cub->map->map))
		return (free_all(cub));
	init_map_info(cub->map, cub->var);
	init_mlx(cub);
	return (0);
}
