/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:35:39 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 18:41:06 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/minirt.h"

int	main(int ac, char **av)
{
	t_scene	*scne;
	int	fd;

	if (check_file(ac, av))
		perror("hey dummy enter a valid file ex: [meme.rt]");
	fd = open(av[1], O_RDONLY);
	scne = alloc_scene();
	if (!scne)
		perror("somehow you can't allocate memory");
	parser(scne, fd);
	//render(scne); -need to be implemented
	collect_data(&g_root, g_root);
	return (0);
}
