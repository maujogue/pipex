/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 13:01:25 by maujogue          #+#    #+#             */
/*   Updated: 2022/11/14 14:54:57 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char			*s;
	char			*d;
	unsigned int	i;

	i = -1;
	s = (char *)src;
	d = (char *)dst;
	if (src != 0 || dst != 0)
	{
		if (d < s)
		{
			while (++i < n)
				d[i] = s[i];
		}
		else
		{
			while (n > 0)
			{
				d[n - 1] = s[n - 1];
				n--;
			}
		}
	}
	return (dst);
}
