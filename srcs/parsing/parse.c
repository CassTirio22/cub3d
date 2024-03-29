/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:45:07 by aliens            #+#    #+#             */
/*   Updated: 2022/04/01 17:09:18 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	parse(char **argv, t_cub *cub)
{
	if (!get_info_map(argv, cub) || !verify_map_info(cub))
		return (free_all(cub, 2));
	if (!closed_map(cub->map->map, cub))
		return (free_all(cub, 3));
	init_map_info(cub->map, cub->var, cub);
	init_player(cub);
	init_mlx(cub);
	return (0);
}
