/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:27:44 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 17:30:57 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

int	check_file(int ac, char **av)
{
	int	i;
	int	fd;

	if (ac != 2 || !av[1])
		return (1);
	i = string_length(av[1]);
	if (i < 4 || av[1][i - 1] != 't' || av[1][i - 2] != 'r' || av[1][i - 3] != '.')
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	close(fd);
	return (0);
}
