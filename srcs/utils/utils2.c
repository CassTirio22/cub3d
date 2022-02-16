/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 19:59:30 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/16 19:39:44 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_wall(float x, float y, char **map)
{
	if (map[(int)y][(int)x] == '1')
		return (1);
	return (0);
}

int	ft_strlen_cub3d(char *str)
{
	int	i;

	if (!str)
		return (0);
	i = -1;
	while (str[++i])
		if (str[i] == '\t')
			i += 3;
	return (i);
}
