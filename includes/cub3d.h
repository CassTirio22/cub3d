/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.s19.be>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:37:45 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/03 23:22:53 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/includes/libft.h"
# include <mlx.h>
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
# define KEY_E 14
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_SHIFT 257
# define SPEED 0.1
# define FOV 60
# define WEST_WALL 0x991a06
# define EAST_WALL 0xBF8D4F
# define SOUTH_WALL 0x433E7E
# define NORTH_WALL 0x552a85
# define CELLING 0x7cb5d9
# define FLOOR 0x9F7D5C
# define DOOR 3
# define R1 1000
# define R2 1000

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
	int		touch;
	int		up;
	int		down;
	int		left;
	int		right;
	int		rot_left;
	int		rot_right;
	int		run;
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

typedef struct s_tex
{
	t_img	*no;
	t_img	*so;
	t_img	*ea;
	t_img	*we;
	t_img	*door;
}				t_tex;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*p1;
	t_map		*map;
	t_img		*img;
	t_tex		*tex;
	t_var		*var;
}				t_cub;

/*
**		-___INIT___-
*/

void	init_map_info(t_map *map, t_var *var, t_cub *cub);
void	init_textures(t_tex *tex, t_cub *cub);
char	**init_check_info_map(int info[6], t_cub *cub);
char	**init_check_info_map_bonus(int info[7], t_cub *cub);
void	init_player(t_cub *cub);
void	init_mlx(t_cub *cub);
int		init_var(t_cub *cub);

/*
**		-___PARSING___-
*/

int		closed_map(char **map, t_cub *cub);
int		get_info_map(char **argv, t_cub *cub);
int		verify_map_info(t_cub *cub);
int		parse(char **argv, t_cub *cub);
int		get_line(char *line, t_cub *cub, int boolean, int index);
int		check_args(int argc, char **argv);
int		arround_zero(char **map, int i, int j);
int		transform_map(t_map *map, t_cub *cub);
void	recup_info_map(char *line, int *index, t_cub *cub);

/*
**		-___RAYCASTING___-
*/

double	dist_to_wall(t_cub *cub, t_player *p1, int *color);

/*
**		-___DRAW___-
*/

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

int		free_all(t_cub *cub, int error);
int		init_protect(t_cub *cub);
void	free_double_char(char **str);
void	error_msg_bonus(int error);

/*
**		-___UTILS___-
*/

t_img	*get_side(int color, t_cub *cub);
char	**lst_to_double_char(t_list *lst);
double	div_protect(double a, double b);
void	print_lst(t_list *lst);
void	print_double_char(char **str);
void	get_pixel(t_img *image, int x, int y, int *color);
int		get_color(t_cub *cub, double dist);
int		map_protect(char **map, int x, int y);
int		do_rgb(int r, int g, int b);
int		ft_is_white_space(char c);
int		ft_strlen_cub3d(char *str);
int		double_char_len(char **str);
int		is_wall(int x, int y, t_cub *cub);
int		is_wall_around(double x, double y, t_cub *cub);
int		spc_inf(char *info, int j[3], t_cub *cub);
void	info_check(int info[6], t_cub *cub);
void	info_check_bonus(int info[7], t_cub *cub);
int		check_color(char **tmp);
int		check_res(char **tmp);
void	init_map_r(t_map *map, t_var *var, int i, t_cub *cub);

#endif
