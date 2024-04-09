/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line_utils.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/22 15:59:07 by gianlucapir   #+#    #+#                 */
/*   Updated: 2021/11/08 11:11:36 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*output(char *s)
{
	int		i;
	int		size;
	char	*output;

	size = ft_strchr(s, '\n') - s;
	output = malloc(sizeof(char) * (size + 2));
	if (!output)
		return (NULL);
	i = 0;
	while (i < size)
	{
		output[i] = s[i];
		i++;
	}
	output[i] = '\n';
	output[i + 1] = '\0';
	return (output);
}

char	*remainder_s(char *s)
{
	char	*tmp;

	tmp = ft_strchr(s, '\n') + 1;
	if (*tmp)
	{
		tmp = ft_strdup(tmp);
		if (!tmp)
			return (0);
		free(s);
		return (tmp);
	}
	free(s);
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(const char *s1)
{
	char	*new;
	int		size;
	int		i;

	size = ft_strlen((char *)s1);
	new = malloc((size + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;

	if (s1 && s1)
	{
		new = (char *)malloc(sizeof(char) * (ft_strlen((char *) s1) + \
		ft_strlen((char *) s2) + 1));
		if (new == NULL)
			return (NULL);
		i = 0;
		while (s1[i])
		{
			new[i] = s1[i];
			i++;
		}
		i = 0;
		while (s2[i])
		{
			new[ft_strlen((char *) s1) + i] = s2[i];
			i++;
		}
		new[ft_strlen((char *) s1) + i] = '\0';
		return (new);
	}
	return (NULL);
}
