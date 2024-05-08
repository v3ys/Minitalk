/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veraslan <veraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 16:30:06 by veraslan          #+#    #+#             */
/*   Updated: 2024/02/12 15:25:39 by veraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_scan(char c, va_list list)
{
	if (c == 'c')
		return (ft_putchar(va_arg(list, int)));
	else if (c == 's')
		return (ft_putstr(va_arg(list, char *)));
	else if (c == 'd' || c == 'i')
		return (ft_putnbr(va_arg(list, int)));
	else if (c == 'u')
		return (ft_unsigned(va_arg(list, unsigned int)));
	else if (c == 'p')
	{
		ft_putstr("0x");
		return (ft_putpointer(va_arg(list, void *)) + 2);
	}
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(list, unsigned int),
				"0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(list, unsigned int),
				"0123456789ABCDEF"));
	else if (c == '%')
		return (ft_putchar('%'));
	else
		return (ft_putchar(c));
	return (0);
}

int	ft_printf(const char *sign, ...)
{
	va_list	list;
	int		i;
	int		len;

	va_start(list, sign);
	i = 0;
	len = 0;
	while (sign[i])
	{
		if (sign[i] == '%' && sign[i + 1] != '\0')
		{
			len += ft_scan(sign[i + 1], list);
			i++;
		}
		else
			len += write(1, &sign[i], 1);
		i++;
	}
	va_end(list);
	return (len);
}
