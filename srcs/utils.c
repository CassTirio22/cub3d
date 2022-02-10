/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <ctirions@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:22:50 by ctirions          #+#    #+#             */
/*   Updated: 2022/02/10 14:34:01 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int		ft_is_white_space(char c)
{
	if ((c >= 9 && c <= 13) || c == ' ')
		return (1);
	return (0);
}

int		count(int nbr)
{
	int count;

	count = 0;
	while (nbr > 9)
	{
		count++;
		nbr /= 10;
	}
	return (++count);
}

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	ft_argc_error(int argc)
{
	if (argc == 1)
	{
		ft_putstr_fd("Error !\nYou didn't put any map...\n", 2);
		exit(1);
	}
	if (argc != 2)
	{
		ft_putstr_fd("Error !\nYou put too many arguments...\n", 2);
		exit(1);
	}
}
