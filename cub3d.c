/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/18 17:26:32 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	t_struct_list	struct_list;

	ft_argc_error(argc);
	ft_set_param(&struct_list, argv);
	ft_put_player(struct_list, 0x00FFFFFF);
	ft_draw_map(struct_list);
	mlx_hook(struct_list.param->win_ptr, 2, 1L<<0, ft_key_hook, &struct_list);
	mlx_hook(struct_list.param->win_ptr, 17, 1L<<17, ft_mlx_close, struct_list.param);
	mlx_loop(struct_list.param->mlx_ptr);
	return (0);
}
