/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:39:07 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/03 20:53:22 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	check_args(int argc, char **argv)
{
	int	size;

	if (argc != 2)
		return (1);
	size = ft_strlen(argv[1]);
	if (size < 5)
		return (1);
	if (ft_strncmp(argv[1] + size - 4, ".cub", 4))
		return (1);
	return (0);
}

int	main(int argc, char **argv)
{
	t_cub	cub;

	if (check_args(argc, argv) || init_var(&cub) || parse(argv, &cub))
		return (free_all(&cub, 5));
	draw_game(&cub);
	mlx_hook(cub.win_ptr, 3, 1L << 1, key_release, &cub);
	mlx_hook(cub.win_ptr, 2, 1L << 0, key_press, &cub);
	mlx_hook(cub.win_ptr, 17, 1L << 17, close_win, &cub);
	mlx_loop_hook(cub.mlx_ptr, make_moves, &cub);
	mlx_loop(cub.mlx_ptr);
	return (0);
}
