/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:59:04 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/10/29 11:29:19 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s;
	char		buffer[BUFFER_SIZE + 1];
	char		*tmp;
	int 		ret;

	while ((ret = read(fd, buffer, 1)))
	{
		buffer[ret] = '\0';
		if (s == NULL)
			s = ft_strdup(buffer);
		else
		{
			tmp = ft_strjoin(s, buffer);
			free(s);
			s = tmp;
		}
		if (ft_strchr(s, '\n'))
			break ;		
	}
	if (ret)
	{
		tmp = output(s);
		s = remainder_s(s);
		return (tmp);
	}
	return (s);
}

int main()
{
	int	fd;

	fd = open("file1", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}