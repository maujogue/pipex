/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_functions_str.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 13:43:36 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/03 14:23:27 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	ft_putchar_count(char c, int *count)
{
	write(1, &c, 1);
	*count += 1;
}

void	ft_putstr_count(char *s, int *count)
{
	int	i;

	i = -1;
	if (s != NULL)
	{
		while (s[++i])
			ft_putchar_count(s[i], count);
	}
	else
		ft_putstr_count("(null)", count);
}
