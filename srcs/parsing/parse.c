/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:40:53 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/12 16:55:33 by ctirions         ###   ########.fr       */
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
			{
				get_line(line, cub, 0, index);
				index++;
			}
		}
		else
			get_line(line, cub, 1, index);
	}
	get_line(line, cub, 1, index);
	cub->map->map = lst_to_double_char(cub->map->map_lst);
	close(fd);
	return (1);
}

int	parse(char **argv, t_cub *cub)
{
	if (!get_info_map(argv, cub))
		return (free_all(cub));
	return (0);
}
