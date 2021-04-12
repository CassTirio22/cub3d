/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/07 14:40:44 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_struct_list	struct_list;
	
	ft_argc_error(argc);
	ft_set_param(&struct_list, argv);
	ft_draw_map(struct_list.param);
	ft_put_player(struct_list.param, 0x00FFFFFF);
	mlx_hook(struct_list.param.win_ptr, 2, 1L<<0, ft_key_hook, &struct_list.param);
	mlx_hook(struct_list.param.win_ptr, 17, 1L<<17, ft_mlx_close, &struct_list.param);
	mlx_loop(struct_list.param.mlx_ptr);
	return (0);
}
