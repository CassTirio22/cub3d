/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/16 18:26:14 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/05 15:22:46 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	rot_left(t_cub *cub)
{
	cub->p1->angle += 3;
	cub->p1->angle %= 360;
	return (0);
}

int	rot_right(t_cub *cub)
{
	cub->p1->angle -= 3;
	cub->p1->angle %= 360;
	return (0);
}
