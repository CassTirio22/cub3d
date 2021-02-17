/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/17 18:24:54 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_cub3d param;
	t_map	map;

	ft_argc_error(argc);
	ft_set_param(&param, &map, argv);
	ft_draw_map(param);
	ft_put_player(param, g_white);
	mlx_hook(param.win_ptr, 2, 1L<<0, ft_key_hook, &param);
	mlx_hook(param.win_ptr, 17, 1L<<17, ft_mlx_close, &param);
	mlx_loop(param.mlx_ptr);
	return (0);
}
