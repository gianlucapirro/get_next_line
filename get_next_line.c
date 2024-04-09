/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   get_next_line.c                                    :+:    :+:            */
/*                                                     +:+                    */
/*   By: gianlucapirro <gianlucapirro@student.42      +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/22 15:59:04 by gianlucapir   #+#    #+#                 */
/*   Updated: 2021/11/08 11:33:43 by gpirro        ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line_2(int fd, char **s, int ret)
{
	char	*tmp;

	if (ft_strchr(*s, '\n'))
	{
		tmp = output(*s);
		if (!tmp)
			return (tmp);
		*s = remainder_s(*s);
		return (tmp);
	}
	else if (ret != 0)
		return (get_next_line(fd));
	tmp = *s;
	*s = 0;
	return (tmp);
}

char	*get_next_line_1(int fd, char **s, int ret, char *buffer)
{
	char	*tmp;

	if (*s == NULL && ret)
	{
		*s = ft_strdup(buffer);
		if (!*s)
			return (0);
	}
	else if (*s == NULL && ret == 0)
		return (0);
	else
	{
		tmp = ft_strjoin(*s, buffer);
		if (!tmp)
			return (0);
		free(*s);
		*s = tmp;
	}
	return (get_next_line_2(fd, &*s, ret));
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		buffer[BUFFER_SIZE + 1];
	int			ret;

	ret = read(fd, buffer, BUFFER_SIZE);
	if (ret < 0)
		return (0);
	buffer[ret] = '\0';
	return (get_next_line_1(fd, &s, ret, buffer));
}

char	*ft_strchr(const char *string, int c)
{
	while (*string && *string != (char)c)
		string++;
	if (*string == (char)c)
		return ((char *)string);
	return (0);
}
