/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:59:07 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/10/25 15:38:47 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2", 2);
		nb = 147483648;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + '0');
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	malloc_length(char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\n')
		i++;
	return (i);
}

char	*output(char *s)
{
	int		i;
	int		i2;
	int		size;
	char	*output;
	char	*temp;

	i = 0;
	size = malloc_length(s);
	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	while (s[i] != '\n')
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\0';
	return (output);
}

char	*remainder_s(char *s)
{
	int		i;
	int		i2;
	int		size;
	char	*output;
	char	*temp;

	i = 0;
	size = malloc_length(s);
	output = malloc(sizeof(char) * (size + 1));
	if (!output)
		return (NULL);
	while (s[i] != '\n')
	{
		output[i] = s[i];
		i++;
	}
	i++;
	output[i] = '\0';
	temp = malloc(sizeof(char) * (ft_strlen(s) - size + 1));
	i2 = 0;
	while (s[i])
	{
		temp[i2] = s[i];
		i++;
		i2++;
	}
	temp[i2] = '\0';
	return (temp);
}