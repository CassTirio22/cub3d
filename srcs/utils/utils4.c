/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:30:00 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/01 17:35:21 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color(char **tmp)
{
	int i;
	int j;

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
