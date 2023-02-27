/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 14:49:20 by maujogue          #+#    #+#             */
/*   Updated: 2022/11/19 14:38:27 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	int_len(int n)
{
	int	i;

	i = 1;
	while (n / 10 != 0)
	{
		i++;
		n /= 10;
	}
	if (n < 0)
		i++;
	return (i);
}

static int	ft_pow(int n, int p)
{
	int	i;
	int	res;

	i = 1;
	res = n;
	if (p == 0)
		return (1);
	while (i++ < p)
		res *= n;
	return (res);
}

static char	*get_res(long n, int len, int i)
{
	char	*res;

	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	while (i < len)
	{
		res[i] = n / (ft_pow(10, len - i - 1)) + '0';
		n %= ft_pow(10, len - i - 1);
		i++;
	}
	res[i] = 0;
	return (res);
}

char	*ft_itoa(int nb)
{
	int		i;
	int		len;
	int		sign;
	char	*res;
	long	n;

	n = (long)nb;
	i = 0;
	sign = 0;
	len = int_len(n);
	if (n < 0)
	{
		sign = 1;
		i++;
		n *= -1;
	}
	res = get_res(n, len, i);
	if (!res)
		return (0);
	if (sign == 1)
		res[0] = '-';
	return (res);
}
