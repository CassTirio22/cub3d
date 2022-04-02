/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:01:41 by aliens            #+#    #+#             */
/*   Updated: 2022/04/02 15:43:59 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	check_color(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = -1;
		while (tmp[i][++j])
			if (!ft_isdigit(tmp[i][j]) && tmp[i][j] != ' ')
				return (1);
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
			return (1);
	}
	return (0);
}

int	check_res(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 2)
	{
		j = -1;
		while (tmp[i][++j])
			if (!ft_isdigit(tmp[i][j]) && tmp[i][j] != '-' && tmp[i][j] != '+')
				return (1);
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 2000)
			return (1);
	}
	return (0);
}

void	info_check(int info[6], char **check, t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 6)
		if (info[i] > 1)
			free_all(cub, 11);
	i = -1;
	while (++i < 6)
	{
		if (info[i] != 1)
		{
			printf("Error\n%s is missing\n", check[i]);
			free_all(cub, 1);
		}
	}
}

void	init_map_r(t_map *map, t_var *var, int i, t_cub *cub)
{
	char	**tmp;

	tmp = NULL;
	if (!ft_strncmp(map->info[i], "R", 1))
	{
		tmp = ft_split(map->info[i] + 2, ' ');
		if (double_char_len(tmp) != 2 || check_res(tmp))
		{
			free_double_char(tmp);
			free_all(cub, 12);
		}
		var->resolution[0] = ft_atoi(tmp[0]);
		var->resolution[1] = ft_atoi(tmp[1]);
		free_double_char(tmp);
	}
}
