/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:40:33 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/07 17:09:24 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

//# include "libft.h"
//# include "get_next_line.h"
//# include "ft_printf.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>

# define PI 3.14159265359

typedef struct	s_cub3d
{
	int		x_p;
	int		y_p;
	int		weight;
	void	*mlx_ptr;
	void	*win_ptr;
	int		angle;
	int		mouse_x;
	int		mouse_y;
}				t_cub3d;

#endif