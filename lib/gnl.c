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

static char	*ft_strjoin(char *s, char c)
{
	char	*output;
	int		i;

	i = 2;
	if (s)
		while (*s && s++)
			i++;
	output = (char *)malloc(sizeof(char) * i);
	output[--i] = '\0';
	output[--i] = c;
	if (s)
	{
		while (i--)
			output[i] = s[i];
		free(s - 1);
	}
	return (output);
}

char	*gnl(int fd)
{
	char	c;
	static char	*str;

	str = NULL;
	if (str)
		free(str);
	str = NULL;
	while (read(fd, &c, 1) && (c != '\n' || !str))
	{
		if (c == '\n')
			continue ;
		str = ft_strjoin(str, c);
	}
	return (str);
}
