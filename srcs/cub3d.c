/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:39:07 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/15 17:51:15 by ctirions         ###   ########.fr       */
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
		return (1);
	draw_map(&cub);
	print_double_char(cub.map->map);
	printf("\nmap size = %d\n", double_char_len(cub.map->map));
	printf("line len = %zu\n", ft_strlen(cub.map->map[0]));
	mlx_hook(cub.win_ptr, 2, 1L << 0, ft_key, &cub);
	mlx_hook(cub.win_ptr, 17, 1L << 17, ft_close, &cub);
	mlx_loop(cub.mlx_ptr);
	return (0);
}
