/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:40:53 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/10 20:28:54 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse(char **argv, t_cub *cub)
{
	char	*line;
	int		fd;
	int		i;
	int		j;

	j = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		return (free_all(cub));
	while (get_next_line(fd, &line))		/*---Make a fonction for get info---*/
	{
		i = 0;
		while (ft_is_white_space(line[i]))
			i++;
		if (ft_isdigit(line[i]))
		{
			close(fd);
			free(line);
			return (0);
		}
		if (line[0])
			cub->map->info[j++] = ft_strdup(line);		/*---To protect---*/
		free(line);
	}
	close(fd);
	return (0);
}

/*----get map-----*/

int	check_args(int argc, char **argv)
{
	int	size;

	if (argc != 2)
		return (1);
	size = ft_strlen(argv[1]);
	if (size < 5)
		return (1);
	if (ft_strncmp(argv[1] + size - 4, ".cub", 4))
		return (1);
	return (0);
}
