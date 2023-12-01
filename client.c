/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   klient.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/22 14:01:52 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/24 17:05:47 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int	ft_atoi(const char *str)
{
	int	index;
	int	sign;
	int	value;

	index = 0;
	sign = 1;
	value = 0;
	while (str[index] == 32 || (str[index] >= 9 && str[index] <= 13))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -sign;
		index++;
	}	
	while (str[index] >= '0' && str[index] <= '9')
	{
		value = value * 10 + str[index] - '0';
		index++;
	}
	return (sign * value);
}

void	print_bits(unsigned char octet, int pid)
{
	int	i;

	i = 128;
	while (i > 0)
	{
		if (octet >= i)
		{
			octet = octet % i;
			i = i / 2;
			kill(pid, SIGUSR1);
		}
		else
		{
			i = i / 2;
			kill(pid, SIGUSR2);
		}
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	pid;
	int	i;

	if (argc == 3)
	{		
		i = 0;
		pid = ft_atoi(argv[1]);
		while (argv[2][i])
		{
			print_bits(argv[2][i], pid);
			i++;
		}
	}
	return (0);
}
