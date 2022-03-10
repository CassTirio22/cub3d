/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:00:58 by aliens            #+#    #+#             */
/*   Updated: 2022/03/10 17:30:46 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

void	init_textures(t_tex *tex, t_cub *cub)
{
	tex->no->img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->var->no, &tex->no->img_w, \
	&tex->no->img_h);
	if (tex->no->img)
		tex->no->addr = mlx_get_data_addr(tex->no->img, &tex->no->bits_per_pixel, \
		&tex->no->line_length, &tex->no->endian);
	tex->so->img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->var->so, &tex->so->img_w, \
	&tex->so->img_h);
	if (tex->so->img)
		tex->so->addr = mlx_get_data_addr(tex->so->img, &tex->so->bits_per_pixel, \
		&tex->so->line_length, &tex->so->endian);
	tex->ea->img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->var->ea, &tex->ea->img_w, \
	&tex->ea->img_h);
	if (tex->ea->img)
		tex->ea->addr = mlx_get_data_addr(tex->ea->img, &tex->ea->bits_per_pixel, \
		&tex->ea->line_length, &tex->ea->endian);
	tex->we->img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->var->we, &tex->we->img_w, \
	&tex->we->img_h);
	if (tex->we->img)
		tex->we->addr = mlx_get_data_addr(tex->we->img, &tex->we->bits_per_pixel, \
		&tex->we->line_length, &tex->we->endian);
	tex->door->img = mlx_xpm_file_to_image(cub->mlx_ptr, "../textures/door.xpm", &tex->door->img_w, \
	&tex->door->img_h);
	if (tex->door->img)
		tex->door->addr = mlx_get_data_addr(tex->door->img, &tex->door->bits_per_pixel, \
		&tex->door->line_length, &tex->door->endian);
}
