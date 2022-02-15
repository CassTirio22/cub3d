/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:32:54 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/15 15:43:17 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close(t_cub *cub)
{
	free_all(cub);
	exit (0);
	return (0);
}

int	ft_key(int key, t_cub *cub)
{
	if (key == KEY_ESC)
		ft_close(cub);
	return (0);
}
