/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 10:11:55 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/18 16:42:52 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line_res(char *holder)
{
	char	*res;
	int		i;

	i = 0;
	if (ft_strchr(holder, '\n') != NULL)
	{
		while (holder[i] != '\n')
			i++;
		res = malloc(sizeof(char) * (i + 2));
		if (!res)
			return (NULL);
		i = -1;
		while (holder[++i] != '\n')
			res[i] = holder[i];
		res[i] = '\n';
		res[++i] = '\0';
	}
	else
		res = ft_strdup(holder);
	return (res);
}

char	*get_overflow(char *holder)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (holder[i] && holder[i] != '\n')
		i++;
	if (holder[i] == 0)
		return (free(holder), NULL);
	s = (char *)malloc(sizeof(char) * (ft_strlen(holder) - i + 1));
	if (!s)
		return (free(holder), NULL);
	j = 0;
	while (holder[i])
		s[j++] = holder[++i];
	s[j] = '\0';
	free(holder);
	return (s);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	int			len;
	static char	*holder;
	char		*temp;
	char		*res;

	if (fd < 0 || fd > 1023 || BUFFER_SIZE <= 0)
		return (free (holder), holder = NULL, NULL);
	if (!holder)
		holder = ft_strdup("");
	while (ft_strchr(holder, '\n') == NULL)
	{
		len = read(fd, buffer, BUFFER_SIZE);
		if (len == -1 || (len == 0 && ft_strlen(holder) == 0))
			return (free (holder), holder = NULL, NULL);
		if (len == 0)
			break ;
		buffer[len] = '\0';
		temp = holder;
		holder = ft_strjoin_gnl(temp, buffer);
	}
	res = get_line_res(holder);
	temp = holder;
	holder = get_overflow(temp);
	return (res);
}
