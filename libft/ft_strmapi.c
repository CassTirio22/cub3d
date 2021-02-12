/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:09:30 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/13 16:19:46 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*res;

	if (!s || !f)
		return (0);
	i = -1;
	if (!(res = (char *)ft_calloc(sizeof(char), ft_strlen(s) + 1)))
		return (0);
	while (++i < ft_strlen(s))
		res[i] = f(i, s[i]);
	return (res);
}
