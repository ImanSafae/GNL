/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: itaouil <itaouil@student.42nice.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/13 01:22:52 by itaouil           #+#    #+#             */
/*   Updated: 2021/10/16 22:51:04 by itaouil          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*buffer;
	char		*res;
	int			count;

	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	res = NULL;
	if (rest && *rest)
		res = ft_strjoin(res, rest);
	count = read(fd, buffer, BUFFER_SIZE);
	while ((ft_strchr(buffer, '\n') == -1 && ft_strchr(res, '\n') == -1) && count != 0)
	{
		res = ft_strjoin(res, buffer);
		count = read(fd, buffer, BUFFER_SIZE);
	}
	if (ft_strchr(res, '\n') != -1)
	{
		res = ft_strjoin(res, buffer);
		free(buffer);
		buffer = ft_strndup(res, ft_strchr(res, '\n'));
		rest = ft_strndup(res + (ft_strchr(res, '\n') + 1), ft_strlen(res) - ft_strchr(res, '\n'));
		free(res);
		return (buffer);
	}
	return (res);
}

// int	main()
// {
// 	int fd = open("./test", O_RDONLY);
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	printf("%s\n", get_next_line(fd));
// 	close(fd);
// }