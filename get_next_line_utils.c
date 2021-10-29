/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:59:07 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/10/28 16:05:12 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	int		size;
	char	*output;

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
	size = ft_strlen(s);
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
	while (i < size)
	{
		temp[i2] = s[i];
		i++;
		i2++;
	}
	temp[i2] = '\0';
	return (temp);
}
