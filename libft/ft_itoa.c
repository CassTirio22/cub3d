/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/23 13:40:51 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/13 16:15:01 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			ft_itoa_count(int n)
{
	int				count;
	unsigned int	nb;

	count = 0;
	if (n < 0)
	{
		count++;
		nb = -n;
	}
	else
		nb = n;
	while (nb > 9)
	{
		count++;
		nb /= 10;
	}
	return (++count);
}

char				*ft_itoa(int n)
{
	int				count;
	char			*res;
	unsigned int	nb;

	count = (n) ? ft_itoa_count(n) : 1;
	if (!(res = (char *)ft_calloc(sizeof(char), count + 1)))
		return (0);
	if (!n)
	{
		res[0] = '0';
		return (res);
	}
	nb = (n < 0) ? -n : n;
	while (count)
	{
		res[count - 1] = nb % 10 + '0';
		if (!(count - 1) && !nb)
			res[count - 1] = '-';
		nb /= 10;
		count--;
	}
	return (res);
}
