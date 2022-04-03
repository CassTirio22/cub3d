/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/03 16:57:36 by zminhas           #+#    #+#             */
/*   Updated: 2022/04/03 17:07:13 by zminhas          ###   ########.fr       */
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
