/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:40:53 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/03 16:59:25 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	get_info_map(char **argv, t_cub *cub)
{
	char	*line;
	int		fd;
	int		index;

	line = NULL;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		free_all(cub, 6);
	index = 0;
	while (get_next_line(fd, &line))
		recup_info_map(line, &index, cub);
	get_line(line, cub, 1, index);
	cub->map->map = lst_to_double_char(cub->map->map_lst);
	if (!cub->map->map)
		free_all(cub, 4);
	close(fd);
	return (1);
}

int	verify_map_info(t_cub *cub)
{
	char	**check;
	int		info[7];
	int		i;
	int		j;

	check = init_check_info_map(info);
	if (!check)
		return (0);
	i = -1;
	while (cub->map->info[++i])
	{
		j = -1;
		while (++j < 7)
			if (!ft_strncmp(cub->map->info[i], check[j], ft_strlen(check[j])))
				info[j]++;
	}
	free(check);
	info_check(info, check, cub);
	if (!transform_map(cub->map, cub))
		return (0);
	return (1);
}

int	check_char_map(char **map, int *nb_player, int max_size, int inc[2])
{
	if (!inc[0] || inc[0] == max_size)
	{
		if (map[inc[0]][inc[1]] != '1' && map[inc[0]][inc[1]] != '2')
			return (1);
	}
	else if (map[inc[0]][inc[1]] == '0')
	{
		if (!arround_zero(map, inc[0], inc[1]))
			return (1);
	}
	else if (map[inc[0]][inc[1]] == 'N' || map[inc[0]][inc[1]] == 'S' \
	|| map[inc[0]][inc[1]] == 'W' || map[inc[0]][inc[1]] == 'E')
	{
		if (!arround_zero(map, inc[0], inc[1]))
			return (1);
		(*nb_player)++;
	}
	return (0);
}

int	closed_map(char **map, t_cub *cub)
{
	int	nb_player;
	int	max_size;
	int	inc[2];

	nb_player = 0;
	max_size = double_char_len(map) - 1;
	inc[0] = -1;
	while (map[++inc[0]])
	{
		inc[1] = -1;
		while (map[inc[0]][++inc[1]])
			if (check_char_map(map, &nb_player, max_size, inc))
				free_all(cub, 7);
	}
	if (!nb_player)
		free_all(cub, 8);
	else if (nb_player > 1)
		free_all(cub, 9);
	return (1);
}

int	get_line(char *line, t_cub *cub, int boolean, int index)
{
	t_list	*tmp;

	if (!boolean)
	{
		cub->map->info[index] = ft_strdup(line);
		if (!cub->map->info[index])
			free_all(cub, 4);
	}
	else
	{
		tmp = ft_lstnew((char *)line);
		if (!tmp)
			free_all(cub, 4);
		ft_lstadd_back(&cub->map->map_lst, tmp);
	}
	return (0);
}
