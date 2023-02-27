/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 15:50:09 by maujogue          #+#    #+#             */
/*   Updated: 2022/11/16 17:05:58 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	lendst;
	unsigned int	lensrc;

	i = 0;
	if (dst == NULL && dstsize == 0)
		return (0);
	lendst = ft_strlen(dst);
	lensrc = ft_strlen(src);
	j = lendst;
	if (dstsize <= 0)
		return (lensrc);
	else if (lendst >= dstsize)
		return (dstsize + lensrc);
	else
	{
		while (src[i] && (j < dstsize - 1))
			dst[j++] = src[i++];
		dst[j] = '\0';
	}
	return (lendst + lensrc);
}
