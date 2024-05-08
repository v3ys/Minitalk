/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: veraslan <veraslan@student.42istanbul.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 14:09:02 by veraslan          #+#    #+#             */
/*   Updated: 2024/05/08 15:00:56 by veraslan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include "ft_printf/ft_printf.h"

int		ft_atoi(const char *str);
void	bit_operator(int pid, char c);
void	write_the_bit(int signum);

#endif
