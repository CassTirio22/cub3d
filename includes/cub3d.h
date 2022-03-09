/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:37:45 by ctirions          #+#    #+#             */
/*   Updated: 2022/03/09 15:27:55 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include "../minilibx/mlx.h"
# include <math.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

# define KEY_ESC 53
# define KEY_W 13
# define KEY_S 1
# define KEY_A 0
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define SPEED 0.1
# define FOV 60
# define WEST_WALL 0x991a06
# define EAST_WALL 0xBF8D4F
# define SOUTH_WALL 0x433E7E
# define NORTH_WALL 0x552a85
# define CELLING 0x7cb5d9
# define FLOOR 0x9F7D5C

/*
**		-___STRUCT___-
*/

typedef struct s_player
{
	double	pos[2];
	double	angle;

}				t_player;

typedef struct s_var
{
	int		up;
	int		down;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
	int		resolution[2];
	int		f;
	int		c;
	int		wall_size;
	double	dx;
	double	dy;
	double	dist_wall;
	double	perp_wall_dist;
	double	line_height;
	char	*so;
	char	*no;
	char	*ea;
	char	*we;
	char	*s;
}				t_var;

typedef struct s_map
{
	char	**map;
	char	**info;
	t_list	*map_lst;
}				t_map;

typedef struct s_img
{
	char	*addr;
	void	*img;
	int		endian;
	int		line_length;
	int		bits_per_pixel;
	int		img_w;
	int		img_h;
}				t_img;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*p1;
	t_map		*map;
	t_img		*img;
	t_img		*textures_test;
	t_var		*var;
}				t_cub;

/*
**		-___INIT___-
*/

void	init_map_info(t_map *map, t_var *var);
void	init_textures(t_img *tex, t_cub *cub);
char	**init_check_info_map(int info[8]);
int		init_player(t_cub *cub);
int		init_mlx(t_cub *cub);
int		init_var(t_cub *cub);

/*
**		-___PARSING___-
*/

int		closed_map(char **map);
int		get_info_map(char **argv, t_cub *cub);
int		verify_map_info(t_cub *cub);
int		parse(char **argv, t_cub *cub);
int		get_line(char *line, t_cub *cub, int boolean, int index);
int		check_args(int argc, char **argv);
int		arround_zero(char **map, int i, int j);
int		transform_map(t_map *map);

/*
**		-___RAYCASTING___-
*/

double	dist_to_wall(t_cub *cub, t_player *p1, int *color);

/*
**		-___DRAW___-
*/
void	draw_line_height(int i, t_cub *cub, double dist_wall, int color);
void	draw_game(t_cub *cub);
void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_wall(double x, double y, t_cub *cub, int color);
void	draw_map(t_cub *cub);
void	draw_view(t_cub *cub, t_player *p1, t_var *var);
void	draw_player(t_cub *cub);

/*
**		-___HOOK___-
*/

int		make_moves(t_cub *cub);
int		key_press(int key, t_cub *cub);
int		key_release(int key, t_cub *cub);
int		close_win(t_cub *cub);
int		rot_left(t_cub *cub);
int		rot_right(t_cub *cub);

/*
**		-___FREE___-
*/

int		free_all(t_cub *cub);
int		init_protect(t_cub *cub);
void	free_double_char(char **str);

/*
**		-___UTILS___-
*/

double	div_protect(double a, double b);
void	print_lst(t_list *lst);
void	print_double_char(char **str);
void	get_pixel(t_img *image, int x, int y, int *color);
char	**lst_to_double_char(t_list *lst);
int		do_rgb(int r, int g, int b);
int		ft_is_white_space(char c);
int		ft_strlen_cub3d(char *str);
int		double_char_len(char **str);
int		is_wall(int x, int y, t_cub *cub);

#endif
