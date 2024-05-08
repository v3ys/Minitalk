/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veraslan <veraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 13:21:18 by veraslan          #+#    #+#             */
/*   Updated: 2024/05/08 16:58:44 by veraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(const char *str)
{
	char	*cstr;
	int		i;
	int		sign;
	int		number;

	i = 0;
	number = 0;
	sign = 1;
	cstr = (char *)str;
	while ((cstr[i] >= 9 && cstr[i] <= 13) || cstr[i] == ' ')
		i++;
	if (cstr[i] == '-' || cstr[i] == '+')
	{
		if (cstr[i] == '-')
			sign *= -1;
		i++;
	}
	while (cstr[i] >= '0' && cstr[i] <= '9')
	{
		number = ((number * 10) + cstr[i] - '0');
		i++;
	}
	return (sign * number);
}

void	bit_operator(int pid, char c)
{
	int	i;

	i = 0;
	while (i <= 6)
	{
		if ((c >> i) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		i++;
		usleep(50);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	i = 0;
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			bit_operator(pid, argv[2][i]);
			i++;
		}
		bit_operator(pid, '\n');
	}
	else
	{
		ft_printf("There must be exactly two arguments!\n");
		return (0);
	}
	return (0);
}
