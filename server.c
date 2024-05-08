/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veraslan <veraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:21:15 by veraslan          #+#    #+#             */
/*   Updated: 2024/05/08 14:52:40 by veraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	write_the_bit(int signum)
{
	int static	b;
	int static	i;
	int			j;

	j = 1;
	if (signum == SIGUSR1)
	{
		j <<= i;
		b |= j;
	}
	i++;
	if (i == 7)
	{
		write(1, &b, 1);
		i = 0;
		b = 0;
	}
}

int	main(void)
{
	ft_printf("Pid : %d\n", getpid());
	signal(SIGUSR1, write_the_bit);
	signal(SIGUSR2, write_the_bit);
	while (1)
		pause();
}
