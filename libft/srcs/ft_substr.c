/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aliens <aliens@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/20 11:49:18 by ctirions          #+#    #+#             */
/*   Updated: 2022/04/03 13:09:17 by aliens           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

char	*ft_substr(const char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*pt;

	if (!s)
		return (0);
	i = -1;
	if (ft_strlen(s) < start)
	{
		pt = (char *)ft_calloc(sizeof(char), 1);
		if (!pt)
			return (0);
		return (pt);
	}
	pt = (char *)ft_calloc(sizeof(char), len + 1);
	if (!pt)
		return (0);
	while (++i < len)
		pt[i] = s[start + i];
	return (pt);
}
