/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 17:59:24 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/30 15:09:59 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	ft_mlx_close(t_param *param)
{
	(void)param;
	exit(1);
	return (0);
}

int	ft_key_hook(int key_code, t_struct_list *struct_list)
{
	//printf("%d\n", key_code);
	ft_put_player(*struct_list, 0);
	if (key_code == 13)
		ft_w(struct_list);
	else if (key_code == 1)
		ft_s(struct_list);
	else if (key_code == 0)
		ft_a(struct_list);
	else if (key_code == 2)
		ft_d(struct_list);
	else if (key_code == 123)
		ft_rotate_left(struct_list);
	else if (key_code == 124)
		ft_rotate_right(struct_list);
	else if (key_code == 53)
		ft_mlx_close(struct_list->param);
	ft_put_player(*struct_list, 0x00FFFFFF);
	mlx_put_image_to_window(struct_list->param->mlx_ptr,\
		struct_list->param->win_ptr, struct_list->img->img, 0, 0);
	return (0);
}
