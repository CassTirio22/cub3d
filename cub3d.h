/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:40:33 by ctirions          #+#    #+#             */
/*   Updated: 2021/02/25 14:26:29 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

//# include "ft_printf.h"
# include "libft/libft.h"
# include "gnl/get_next_line.h"
# include <mlx.h>
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

/*
**	COLORS
*/

int	g_pink;
int	g_blue;
int	g_orange;
int	g_red;
int	g_green;
int	g_white;
int	g_purple;
int	g_brown;

/*
**	STRUCT
*/

typedef struct 	s_map
{
	char	*path_north;
	char	*path_south;
	char	*path_west;
	char	*path_east;
	char	*path_sprite;
	char	*path_map;
	int		color_floor;
	int		color_ground;
	int		screen_size[2];
	int		error;
	int		**map;
	int		height;
	int		weight;
	t_list	*the_map;
}				t_map;

typedef struct	s_cub3d
{
	t_map	map;
	float	x_p;
	float	y_p;
	int		weight;
	void	*mlx_ptr;
	void	*win_ptr;
	int		angle;
}				t_cub3d;

/*
**		UTILS
*/

int		ft_is_wall(int x, int y, int **map);
int		ft_is_white_space(char c);
int		ft_count(int nbr);
int		create_trgb(int t, int r, int g, int b);
void	ft_argc_error(int argc);

/*
**		DRAW
*/

float	ft_put_line(t_cub3d param, int color);
void	ft_put_view(t_cub3d *param, int color);
void	ft_put_player(t_cub3d param, int color);
void	ft_square(int x, int y, int wall_or_not, t_cub3d param);
void	ft_draw_map(t_cub3d param);

/*
**		MOVE
*/

void	ft_a(t_cub3d *param);
void	ft_d(t_cub3d *param);
void	ft_w(t_cub3d *param);
void	ft_s(t_cub3d *param);
void	ft_rotate_left(t_cub3d *param);
void	ft_rotate_right(t_cub3d *param);

/*
**		GET_DATA
*/

void	ft_get_r(t_map *map, char *line);
void	ft_get_data(t_map *map);
void	ft_set_param(t_cub3d *param, char **argv);
void	ft_get_c(t_map *map, char *line);
void	ft_get_f(t_map *map, char *line);
void	ft_get_no(t_map *map, char *line);
void	ft_get_so(t_map *map, char *line);
void	ft_get_we(t_map *map, char *line);
void	ft_get_ea(t_map *map, char *line);
void	ft_get_s(t_map *map, char *line);

/*
**		HOOKS
*/

int		ft_mlx_close(t_cub3d *param);
int		ft_key_hook(int key_code, t_cub3d *param);

#endif