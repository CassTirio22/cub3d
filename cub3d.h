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

int	g_rose = 32123123;
int	g_orange = 100100100;
int g_red = 150150150;
int	g_wall_color = 071230140;

# define PI 3.14159265359

typedef struct	s_cub3d
{
	int		x_p;
	int		y_p;
	int		weight;
	void	*mlx_ptr;
	void	*win_ptr;
	int		angle;
}				t_cub3d;

#endif