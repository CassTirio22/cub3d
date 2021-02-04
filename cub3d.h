/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:40:33 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/04 15:05:20 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

//# include "libft.h"
//# include "get_next_line.h"
//# include "ft_printf.h"
# include <mlx.h>

typedef struct	s_cub3d
{
	int		x_p;
	int		y_p;
	int		weight;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_cub3d;

#endif