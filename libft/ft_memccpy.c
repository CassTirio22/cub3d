/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:56:29 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/01 18:33:50 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src_bis;
	unsigned char	*dst_bis;

	dst_bis = (unsigned char *)dst;
	src_bis = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		dst_bis[i] = src_bis[i];
		if (dst_bis[i] == (unsigned char)c)
			return ((void *)(dst + i + 1));
		i++;
	}
	return (0);
}
