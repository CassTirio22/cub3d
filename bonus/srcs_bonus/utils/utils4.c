/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:01:41 by aliens            #+#    #+#             */
/*   Updated: 2022/04/04 13:13:31 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/cub3d.h"

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n < 0)
		len = 1;
	while (n / 10)
	{
		len++;
		n /= 10;
	}
	return (++len);
}

int	check_color(char **tmp)
{
	int	i;
	int	j;

	i = -1;
	while (++i < 3)
	{
		j = 0;
		while (tmp[i][j] && (tmp[i][j] == ' ' || tmp[i][j] == '\t'))
			j++;
		if (!tmp[i][j])
			return (1);
		while (tmp[i][j])
			if (!ft_isdigit(tmp[i][j++]))
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
			if (!ft_isdigit(tmp[i][j]))
				return (1);
		if (ft_atoi(tmp[i]) < 100 || ft_atoi(tmp[i]) > 1000)
			return (1);
	}
	return (0);
}

void	info_check_bonus(int info[7], t_cub *cub)
{
	int	i;

	i = -1;
	while (++i < 7)
		if (info[i] > 1)
			free_all(cub, 11);
}

void	init_map_r(t_map *map, t_var *var, int i, t_cub *cub)
{
	char	**tmp;

	tmp = NULL;
	if (!ft_strncmp(map->info[i], "R", 1))
	{
		tmp = ft_split(map->info[i] + 1, ' ');
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
