/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:42:14 by aliens            #+#    #+#             */
/*   Updated: 2022/02/21 02:07:37 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press(int key, t_cub *cub)
{
	if (key == KEY_ESC)
		close_win(cub);
	else if (key == KEY_W)
		cub->var->up = 1;
	else if (key == KEY_S)
		cub->var->down = 1;
	else if (key == KEY_A)
		cub->var->left = 1;
	else if (key == KEY_D)
		cub->var->right = 1;
	else if (key == KEY_LEFT)
		cub->var->rot_left = 1;
	else if (key == KEY_RIGHT)
		cub->var->rot_right = 1;
	return (0);
}

int	key_release(int key, t_cub *cub)
{
	if (key == KEY_ESC)
		close_win(cub);
	else if (key == KEY_W)
		cub->var->up = 0;
	else if (key == KEY_S)
		cub->var->down = 0;
	else if (key == KEY_A)
		cub->var->left = 0;
	else if (key == KEY_D)
		cub->var->right = 0;
	else if (key == KEY_LEFT)
		cub->var->rot_left = 0;
	else if (key == KEY_RIGHT)
		cub->var->rot_right = 0;
	return (0);
}

int	close_win(t_cub *cub)
{
	free_all(cub);
	exit (0);
	return (0);
}
