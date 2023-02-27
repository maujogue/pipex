/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <maujogue@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 09:33:43 by maujogue          #+#    #+#             */
/*   Updated: 2023/02/10 13:38:17 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_inset(const char *set, char c)
{
	while (*set)
	{
		if (c == *set++)
			return (1);
	}
	return (0);
}

static int	get_left(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (is_inset(set, str[i]) && str[i])
		i++;
	return (i);
}

static int	get_right(char const *s, char const *set)
{
	int	i;
	int	count;

	i = ft_strlen(s) - 1;
	count = 0;
	while (i >= 0 && is_inset(set, s[i]))
	{
		count++;
		i--;
	}
	return (count);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		start;
	int		end;

	if (!s1)
		return (NULL);
	start = get_left(s1, set);
	if (start == (int)ft_strlen(s1))
	{
		res = malloc(sizeof(char));
		if (!res)
			return (0);
		res[0] = '\0';
		return (res);
	}
	end = get_right(s1, set);
	res = ft_substr(s1, start, ft_strlen(s1) - start - end);
	if (!res)
		return (NULL);
	return (res);
}
