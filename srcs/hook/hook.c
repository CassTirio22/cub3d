/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 15:32:54 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/16 16:42:15 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	ft_close(t_cub *cub)
{
	free_all(cub);
	exit (0);
	return (0);
}

int	ft_up(t_cub *cub)
{
	float calc_x;
	float calc_y;
	int		tmp;

	calc_x = cub->p1->pos[0] - 0.375;
	tmp = calc_x + 0.5;
	if (tmp > (int)calc_x)
		calc_x = tmp;
	calc_y = cub->p1->pos[1];
	tmp = calc_y + 0.5;
	if (tmp > (int)calc_y)
		calc_y = tmp;
	if (cub->map->map[(int)calc_x][(int)calc_y] == '1')
		return (0);
	cub->p1->pos[0] -= 0.25;
	return (0);
}

int	ft_down(t_cub *cub)
{
	float calc_x;
	float calc_y;
	int		tmp;

	calc_x = cub->p1->pos[0] + 0.375;
	tmp = calc_x + 0.5;
	if (tmp > (int)calc_x)
		calc_x = tmp;
	calc_y = cub->p1->pos[1];
	tmp = calc_y + 0.5;
	if (tmp > (int)calc_y)
		calc_y = tmp;
	if (cub->map->map[(int)calc_x][(int)calc_y] == '1')
		return (0);
	cub->p1->pos[0] += 0.25;
	return (0);
}

int	ft_left(t_cub *cub)
{
	float calc_x;
	float calc_y;
	int		tmp;

	calc_x = cub->p1->pos[0];
	tmp = calc_x + 0.5;
	if (tmp > (int)calc_x)
		calc_x = tmp;
	calc_y = cub->p1->pos[1] - 0.375;
	tmp = calc_y + 0.5;
	if (tmp > (int)calc_y)
		calc_y = tmp;
	if (cub->map->map[(int)calc_x][(int)calc_y] == '1')
		return (0);
	cub->p1->pos[1] -= 0.25;
	return (0);
}

int	ft_right(t_cub *cub)
{
	float calc_x;
	float calc_y;
	int		tmp;

	calc_x = cub->p1->pos[0];
	tmp = calc_x + 0.5;
	if (tmp > (int)calc_x)
		calc_x = tmp;
	calc_y = cub->p1->pos[1]+ 0.375;
	tmp = calc_y + 0.5;
	if (tmp > (int)calc_y)
		calc_y = tmp;
	if (cub->map->map[(int)calc_x][(int)calc_y] == '1')
		return (0);
	cub->p1->pos[1] += 0.25;
	return (0);	
}

int	ft_key(int key, t_cub *cub)
{
	//printf("key : %d\n", key);
	if (key == KEY_ESC)
		ft_close(cub);
	else if (key == KEY_W)
		ft_up(cub);
	else if (key == KEY_S)
		ft_down(cub);
	else if (key == KEY_A)
		ft_left(cub);
	else if (key == KEY_D)
		ft_right(cub);
	draw_map(cub);
	return (0);
}
