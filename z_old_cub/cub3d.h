/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:40:33 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/10 18:28:13 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_H
# define CUBE3D_H

# include "../libft/includes/libft.h"
# include "minilibx/mlx.h"
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
	int		wall_size[2];
	t_list	*the_map;
}				t_map;

typedef struct	s_param
{
	double	x_p;
	double	y_p;
	int		weight;
	int		height;
	int		angle;
	void	*mlx_ptr;
	void	*win_ptr;
}				t_param;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_struct_list
{
	t_data	*img;
	t_param *param;
	t_map	*map;
}				t_struct_list;

/*
**		UTILS
*/

int		ft_is_white_space(char c);
int		count(int nbr);
int		create_trgb(int t, int r, int g, int b);
void	ft_argc_error(int argc);

/*
**		DRAW
*/

void	put_pixel(t_data *img, int x, int y, int color);
void	ft_put_line(t_param param, t_map map, t_data *img, int color);
void	ft_put_view(t_struct_list *struct_list, int color);
void	ft_put_player(t_struct_list struct_list, int color);
void	ft_square(int x, int y, int wall_or_not, t_struct_list struct_list);
void	ft_draw_map(t_struct_list struct_list);

/*
**		MOVE
*/

void	ft_a(t_struct_list *struct_list);
void	ft_d(t_struct_list *struct_list);
void	ft_w(t_struct_list *struct_list);
void	ft_s(t_struct_list *struct_list);
void	ft_rotate_left(t_struct_list *struct_list);
void	ft_rotate_right(t_struct_list *struct_list);

/*
**		GET_DATA
*/

void	ft_get_r(t_map *map, char *line);
void	ft_get_data(t_map *map);
void	ft_set_param(t_struct_list *struct_list, char **argv);
void	get_c(t_map *map, char *line);
void	get_f(t_map *map, char *line);
void	get_no(t_map *map, char *line);
void	get_so(t_map *map, char *line);
void	get_we(t_map *map, char *line);
void	get_ea(t_map *map, char *line);
void	get_s(t_map *map, char *line);

/*
**		HOOKS
*/

int		ft_mlx_close(t_param *param);
int		ft_key_hook(int key_code, t_struct_list *struct_list);

#endif