/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 18:01:41 by aliens            #+#    #+#             */
/*   Updated: 2022/04/01 18:22:20 by aliens           ###   ########.fr       */
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
			if (ft_isalpha(tmp[i][j]))
				return (1);
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
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
