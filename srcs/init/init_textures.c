/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/08 15:00:58 by aliens            #+#    #+#             */
/*   Updated: 2022/03/08 15:39:38 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void init_textures(t_img *tex, t_cub *cub)
{
    tex->img = mlx_xpm_file_to_image(cub->mlx_ptr, cub->var->no, &tex->img_w, \
    &tex->img_h);
    if (tex->img)
        tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel, \
        &tex->line_length, &tex->endian);
}
