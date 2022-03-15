/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:45:07 by aliens            #+#    #+#             */
/*   Updated: 2022/03/15 17:05:01 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse(char **argv, t_cub *cub)
{
	if (!get_info_map(argv, cub) || !verify_map_info(cub))
		return (free_all(cub, 2));
	if (!closed_map(cub->map->map))
		return (free_all(cub, 3));
	init_map_info(cub->map, cub->var, cub);
	init_player(cub);
	init_mlx(cub);
	return (0);
}
