/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:57:36 by zminhas           #+#    #+#             */
/*   Updated: 2022/04/04 12:00:47 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	recup_info_map(char *line, int *index, t_cub *cub)
{
	if (!line)
		free_all(cub, 4);
	if (*index < 7)
	{
		if (line[0])
			get_line(line, cub, 0, (*index)++);
		free(line);
	}
	else
		get_line(line, cub, 1, *index);
}

void	draw_extern(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->var->resolution[0])
	{
		j = -1;
		while (++j < cub->var->resolution[1])
			if (!j || !i || j == cub->var->resolution[1] \
			|| i == cub->var->resolution[0])
				draw_pixel(cub->img, i, j, 0);
	}
}
