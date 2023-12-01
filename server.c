/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lohanyan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/21 20:32:50 by lohanyan          #+#    #+#             */
/*   Updated: 2022/09/24 17:24:16 by lohanyan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

int	astichan(int nb)
{
	int	i;
	int	count;

	i = 2;
	count = 1;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		count = count * 2;
		nb--;
	}
	return (count);
}

int	function(char *str)
{
	int	i;
	int	c;
	int	result;
	int	k;

	i = 0;
	c = 7;
	result = 0;
	while (str[i])
	{
		if (str[i] == '1')
		{
			k = astichan(c);
			result = result + k;
			c--;
		}
		else if (str[i] == '0')
			c--;
		i++;
	}
	return (result);
}

void	ft_putnbr(int nb)
{
	char	c;

	if (nb <= 9)
	{
		c = nb + 48;
		write(1, &c, 1);
		return ;
	}
	else
		ft_putnbr(nb / 10);
	ft_putnbr(nb % 10);
}

void	hex(int sig)
{
	static int		i;
	char			str[9];
	int				num;
	char			s;

	if (sig == SIGUSR1)
		str[i] = '1';
	else if (sig == SIGUSR2)
		str[i] = '0';
	i++;
	if (i == 8)
	{
		str[i] = '\0';
		num = function(str);
		s = (char)num;
		write(1, &s, 1);
		i = 0;
	}	
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_putnbr(pid);
	write(1, "\n", 1);
	signal(SIGUSR1, hex);
	signal(SIGUSR2, hex);
	while (1)
		pause();
}
