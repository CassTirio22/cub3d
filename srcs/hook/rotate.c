/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:26:14 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/08 16:34:45 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rot_left(t_cub *cub)
{
	cub->p1->angle += 3;
	if (cub->p1->angle > 360)
		cub->p1->angle -= 360;
	return (0);
}

int	rot_right(t_cub *cub)
{
	cub->p1->angle -= 3;
	if (cub->p1->angle < 0)
		cub->p1->angle += 360;
	return (0);
}
