/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctirions <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 12:46:12 by ctirions          #+#    #+#             */
/*   Updated: 2020/12/20 13:44:45 by ctirions         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	const char	*src_bis;
	char		*dst_bis;

	dst_bis = (char *)dst;
	src_bis = (const char *)src;
	if (!dst_bis && !src_bis)
		return (0);
	while (n-- > 0)
		dst_bis[n] = src_bis[n];
	return ((void *)dst_bis);
}
