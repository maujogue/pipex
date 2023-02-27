/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 10:45:38 by maujogue          #+#    #+#             */
/*   Updated: 2022/11/21 09:39:16 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_word(char *str, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c)
			i++;
		if (str[i] != c && str[i])
		{
			count++;
			while (str[i] != c && str[i])
				i++;
		}
	}
	return (count);
}

static char	*get_next_word(int *index, char *str, char c)
{
	int		len;
	char	*res;
	int		i;

	i = 0;
	len = 0;
	while (str[*index] == c)
		(*index)++;
	while (str[*index + len] != c && str[*index + len])
		len++;
	res = malloc(len * sizeof(char) + 1);
	if (!res)
		return (NULL);
	while (i < len)
	{
		res[i] = str[*index];
		i++;
		*index = *index + 1;
	}
	res[i] = 0;
	return (res);
}

static void	free_str_array(char **array)
{
	int	i;

	if (!array)
		return ;
	i = -1;
	while (array[++i])
		free(array[i]);
	free(array);
}

char	**ft_split(const char *str, char c)
{
	char	**res;
	char	*s;
	int		nb_word;
	int		i;
	int		j;

	s = (char *)str;
	i = 0;
	j = 0;
	if (!s)
		return (0);
	nb_word = get_nb_word(s, c);
	res = ft_calloc(nb_word + 1, sizeof(char *));
	if (!res)
		return (NULL);
	while (i < nb_word)
	{
		res[i] = get_next_word(&j, s, c);
		if (!res[i++])
		{
			free_str_array(res);
			return (NULL);
		}
	}
	return (res[i] = 0, res);
}
