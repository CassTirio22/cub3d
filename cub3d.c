/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:38:56 by ctirions          #+#    #+#             */
/*   Updated: 2021/04/29 16:14:29 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(t_data *img, int x, int y, int color)
{
	char *dst;

	dst = img->addr + (y * img->line_length + x * (img->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	find_player(t_struct_list *struct_list, int i[2])
{
	if (struct_list->param->angle != -1)
		exit(1);
	if (struct_list->map->map[i[0]][i[1]] == 'N' - '0')
		struct_list->param->angle = 90;
	else if (struct_list->map->map[i[0]][i[1]] == 'S' - '0')
		struct_list->param->angle = 270;
	else if (struct_list->map->map[i[0]][i[1]] == 'W' - '0')
		struct_list->param->angle = 180;
	else if (struct_list->map->map[i[0]][i[1]] == 'E' - '0')
		struct_list->param->angle = 0;
	printf("%d|%d\n", i[0], i[1] - 1);
	struct_list->param->x_p = i[1] - 0.5;
	struct_list->param->y_p = i[0] + 0.5;
}

void	error_map(t_struct_list *struct_list)
{
	int	i[2];

	i[0] = -1;
	while (++i[0] < struct_list->map->height)
	{
		i[1] = 0;
		while (++i[1] < struct_list->map->map[i[0]][0])
		{
			if (struct_list->map->map[i[0]][i[1]] == 'N' - '0' ||\
				struct_list->map->map[i[0]][i[1]] == 'S' - '0' ||\
				struct_list->map->map[i[0]][i[1]] == 'W' - '0' ||\
				struct_list->map->map[i[0]][i[1]] == 'E' - '0')
				find_player(struct_list, i);
			else if (struct_list->map->map[i[0]][i[1]] != 0 &&\
				struct_list->map->map[i[0]][i[1]] != 1)
				exit(1);
		}
	}
}

int	main(int argc, char **argv)
{
	t_struct_list	struct_list;
	int	i[2];

	ft_argc_error(argc);
	ft_set_param(&struct_list, argv);
	i[0] = -1;
	while (++i[0] < struct_list.map->height)
	{
		printf("%d-", struct_list.map->map[i[0]][0]);
		i[1] = 0;
		while (++i[1] < struct_list.map->map[i[0]][0])
			printf("%c", struct_list.map->map[i[0]][i[1]] + '0');
		printf("\n");
	}
	error_map(&struct_list);
	ft_put_player(struct_list, 0x00FFFFFF);
	ft_draw_map(struct_list);
	mlx_hook(struct_list.param->win_ptr, 2, 1L<<0, ft_key_hook, &struct_list);
	mlx_hook(struct_list.param->win_ptr, 17, 1L<<17, ft_mlx_close, struct_list.param);
	mlx_loop(struct_list.param->mlx_ptr);
	return (0);
}
