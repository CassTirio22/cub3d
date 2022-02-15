/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:32:54 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/15 18:06:36 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close(t_cub *cub)
{
	free_all(cub);
	exit (0);
	return (0);
}

// int	ft_up(t_cub *cub)
// {

// }

// int	ft_down(t_cub *cub)
// {
	
// }

// int	ft_left(t_cub *cub)
// {
	
// }

// int	ft_right(t_cub *cub)
// {
	
// }

int	ft_key(int key, t_cub *cub)
{
	if (key == KEY_ESC)
		ft_close(cub);
	// if (key == KEY_W)
	// 	ft_up(cub);
	// if (key == KEY_S)
	// 	ft_down(cub);
	// if (key == KEY_A)
	// 	ft_left(cub);
	// if (key == KEY_D)
	// 	ft_right(cub);
	return (0);
}
