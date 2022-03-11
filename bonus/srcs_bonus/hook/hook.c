/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/20 15:42:14 by aliens            #+#    #+#             */
/*   Updated: 2022/03/10 17:24:38 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	open_close_door(t_cub *cub)
{
	double	dx;
	double	dy;

	dx = cos(cub->p1->angle * (M_PI / 180));
	dy = -sin(cub->p1->angle * (M_PI / 180));
	if (cub->map->map[(int)(cub->p1->pos[1] + dy)][(int)(cub->p1->pos[0] + dx)] == '3')
		cub->map->map[(int)(cub->p1->pos[1] + dy)][(int)(cub->p1->pos[0] + dx)] = '4';
	else if (cub->map->map[(int)(cub->p1->pos[1] + dy)][(int)(cub->p1->pos[0] + dx)] == '4')
		cub->map->map[(int)(cub->p1->pos[1] + dy)][(int)(cub->p1->pos[0] + dx)] = '3';
	
}

int	mouse_pos(int x, int y, t_cub *cub)
{
	cub->var->mouse_pos[0] = x;
	cub->var->mouse_pos[1] = y;
	return (0);
}

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
	else if (key == KEY_E)
		open_close_door(cub);
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
