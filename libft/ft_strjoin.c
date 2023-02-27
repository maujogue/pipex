/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 17:24:02 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/29 13:24:08 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char					*str1;
	char					*str2;
	char					*res;
	unsigned long int		i;

	str1 = (char *)s1;
	str2 = (char *)s2;
	i = -1;
	if (s1 != 0 && s2 != 0)
	{
		res = malloc(sizeof(char) * (ft_strlen(str1) + ft_strlen(str2) + 1));
		if (!res)
			return (NULL);
		while (++i < ft_strlen(str1))
			res[i] = str1[i];
		while (i < (ft_strlen(str1) + ft_strlen(str2)))
		{
			res[i] = str2[i - ft_strlen(str1)];
			i++;
		}
		res[i] = '\0';
		return (res);
	}
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char				*res;
	unsigned long int	i;
	size_t				len1;
	size_t				len2;

	if (s1 == NULL)
		return (s2);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	i = -1;
	if (s1 != 0 && s2 != 0)
	{
		res = malloc(sizeof(char) * (len1 + len2 + 1));
		if (!res)
			return (NULL);
		while (++i < len1)
			res[i] = s1[i];
		i--;
		while (++i < len1 + len2)
			res[i] = s2[i - len1];
		res[i] = '\0';
		free(s1);
		return (res);
	}
	return (NULL);
}
