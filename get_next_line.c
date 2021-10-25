/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gianlucapirro <gianlucapirro@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 15:59:04 by gianlucapir       #+#    #+#             */
/*   Updated: 2021/10/25 15:38:00 by gianlucapir      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	*s;
	char		buffer[100];
	char		*tmp;
	int 		ret;
	int 		i;

	i = 0;
	while ((ret = read(fd, buffer, BUFF_SIZE)))
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
	tmp = output(s);
	s = remainder_s(s);
	return (tmp);
}

int main()
{
	int	fd;

	fd = open("text", O_RDONLY);
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
	printf("%s\n", get_next_line(fd));
}