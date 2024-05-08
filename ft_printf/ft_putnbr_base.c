/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veraslan <veraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/03 17:05:10 by veraslan          #+#    #+#             */
/*   Updated: 2024/02/05 16:18:54 by veraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_base(unsigned int nbr, char *base)
{
	int		len;
	long	number;

	number = nbr;
	len = 0;
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number < 16)
	{
		write(1, &base[number], 1);
		len++;
	}
	else if (number >= 16)
	{
		len += ft_putnbr_base(number / 16, base);
		len += ft_putnbr_base(number % 16, base);
	}
	return (len);
}
