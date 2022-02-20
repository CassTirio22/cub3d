/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:26:14 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/20 15:57:37 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rot_left(t_cub *cub)
{
	cub->p1->angle += 10;
	cub->p1->angle %= 360;
	return (0);
}

int	rot_right(t_cub *cub)
{
	cub->p1->angle -= 10;
	cub->p1->angle %= 360;
	return (0);
}
