/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zminhas <zminhas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:30:00 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/02 18:09:50 by zminhas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

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
		while (tmp[i][++j])
			if (!ft_isdigit(tmp[i][j]))
				return (1);
		// if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
		// 	return (1);
		// printf("|%d|-|%c|\n", (j - ft_intlen(ft_atoi(tmp[i]))), tmp[i][ft_intlen(ft_atoi(tmp[i])) + (j - ft_intlen(ft_atoi(tmp[i])))]);
		// if (tmp[i][ft_intlen(ft_atoi(tmp[i])) + (j - ft_intlen(ft_atoi(tmp[i])))])
		// 	return (1);
	}
	return (0);
}
