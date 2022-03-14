/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:45:07 by aliens            #+#    #+#             */
/*   Updated: 2022/03/10 17:24:49 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	parse(char **argv, t_cub *cub)
{
	if (!get_info_map(argv, cub) || !verify_map_info(cub))
		return (free_all(cub));
	if (!closed_map(cub->map->map))
		return (free_all(cub));
	init_map_info(cub->map, cub->var);
	init_player(cub);
	init_mlx(cub);
	return (0);
}