/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/01 17:30:00 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/04 12:03:10 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	recup_info_map(char *line, int *index, t_cub *cub)
{
	if (!line)
		free_all(cub, 4);
	if (*index < 6)
	{
		if (line[0])
			get_line(line, cub, 0, (*index)++);
		free(line);
	}
	else
		get_line(line, cub, 1, *index);
}

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
		while (tmp[i][j])
			if (!ft_isdigit(tmp[i][j++]))
				return (1);
		if (ft_atoi(tmp[i]) < 0 || ft_atoi(tmp[i]) > 255)
			return (1);
	}
	return (0);
}

void	draw_extern(t_cub *cub)
{
	int	i;
	int	j;

	i = -1;
	while (++i < cub->var->resolution[0])
	{
		j = -1;
		while (++j < cub->var->resolution[1])
			if (!j || !i || j == cub->var->resolution[1] \
			|| i == cub->var->resolution[0])
				draw_pixel(cub->img, i, j, 0);
	}
}
