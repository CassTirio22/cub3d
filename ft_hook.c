/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:59:24 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/17 18:01:06 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		ft_mlx_close(t_cub3d *param)
{
	(void)param;
	exit(1);
	return (0);
}

int		ft_key_hook(int key_code, t_cub3d *param)
{
	if (key_code == 13)
		ft_w(param);
	else if (key_code == 1)
		ft_s(param);
	else if (key_code == 0)
		ft_a(param);
	else if (key_code == 2)
		ft_d(param);
	else if (key_code == 123)
		ft_rotate_left(param);
	else if (key_code == 124)
		ft_rotate_right(param);
	else if (key_code == 53)
		ft_mlx_close(param);
	return (0);
}