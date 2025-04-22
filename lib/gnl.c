/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:56:53 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 18:02:15 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

char	*get_next_line(int fd)
{
	char	*line;
	char	buf[1024];
	int		i;
	int		bytes;

	line = malloc_safe(NULL, 1024);
	if (!line)
		return (NULL);
	i = 0;
	while ((bytes = read(fd, buf, 1)) > 0 && i < 1023)
	{
		if (buf[0] == '\n')
			break ;
		line[i++] = buf[0];
	}
	if (i == 0 && bytes <= 0)
	{
		free(line);
		return (NULL);
	}
	line[i] = '\0';
	return (line);
}
