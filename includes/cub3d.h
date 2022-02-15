/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 18:37:45 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/15 18:59:27 by ctirions         ###   ########.fr       */
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

/*
**		-___STRUCT___-
*/

typedef struct s_player
{
	int		pos[2];

}				t_player;

typedef	struct s_var
{
	int		resolution[2];
	int		wall_size;
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
}				t_img;

typedef struct s_cub
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_player	*p1;
	t_map		*map;
	t_img		*img;
	t_var		*var;
}				t_cub;

/*
**		-___INIT___-
*/

void	init_map_info(t_map *map, t_var *var);
int		init_player(t_cub *cub);
int		init_mlx(t_cub *cub);
int		init_var(t_cub *cub);

/*
**		-___PARSING___-
*/

int		verify_map_info(t_cub *cub);
int		parse(char **argv, t_cub *cub);
int		check_args(int argc, char **argv);

/*
**		-___DRAW___-
*/

void	draw_pixel(t_img *img, int x, int y, int color);
void	draw_wall(int x, int y, t_cub *cub, int color);
void	draw_map(t_cub *cub);

/*
**		-___HOOK___-
*/

int		ft_key(int key, t_cub *cub);
int		ft_close(t_cub *cub);

/*
**		-___FREE___-
*/

int		free_all(t_cub *cub);
void	free_double_char(char **str);

/*
**		-___UTILS___-
*/

char	**lst_to_double_char(t_list *lst);
void	print_lst(t_list *lst);
void	print_double_char(char **str);
int		ft_is_white_space(char c);
int		ft_strlen_cub3d(char *str);
int		double_char_len(char **str);

#endif