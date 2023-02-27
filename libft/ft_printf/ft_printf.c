/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maujogue <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 13:59:53 by maujogue          #+#    #+#             */
/*   Updated: 2023/01/03 14:23:16 by maujogue         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

int	write_car(const char *str, int *count, int i)
{
	if (str[i] == '%' && str[i])
		;
	else
		ft_putchar_count(str[i], count);
	return (i);
}

static int	write_arg(const char *str, int i, va_list args, int *count)
{
	if (str[i] == '%' && str[i + 1])
	{
		if (str[i + 1] == 'c')
			ft_putchar_count(va_arg(args, int), count);
		else if (str[i + 1] == 's')
			ft_putstr_count((char *)va_arg(args, char *), count);
		else if (str[i + 1] == 'p')
			ft_putvoid_addrr(va_arg(args, unsigned long int), count);
		else if (str[i + 1] == 'd' || str[i + 1] == 'i')
			ft_putnbr_count(va_arg(args, int), count);
		else if (str[i + 1] == 'u')
			ft_putnbr_unsigned_fd(va_arg(args, int), 1, count);
		else if (str[i + 1] == 'x')
			ft_putnbr_hex_unsigned(va_arg(args, unsigned int),
				"0123456789abcdef", count);
		else if (str[i + 1] == 'X')
			ft_putnbr_hex_unsigned(va_arg(args, unsigned int),
				"0123456789ABCDEF", count);
		else
			ft_putchar_count(str[i + 1], count);
		return (i + 1);
	}
	else
		i = write_car(str, count, i);
	return (i);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		y;
	int		count;
	va_list	args;

	i = -1;
	count = 0;
	va_start(args, str);
	y = write(1, 0, 0);
	if (y < 0)
		return (-1);
	while (str[++i])
		i = write_arg(str, i, args, &count);
	va_end(args);
	return (count);
}
