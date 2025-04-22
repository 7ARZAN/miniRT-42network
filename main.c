/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:35:39 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 22:18:27 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/minirt.h"

int	main(int ac, char **av)
{
	t_scene		*scene;
	t_garbage	**root;
	int			fd;

	root = append_addr(NULL, NULL);
	if (check_file(ac, av))
	{
		perror("Error: Invalid file (e.g., scene.rt)");
		return (1);
	}
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		perror("Error: Cannot open file");
		return (1);
	}
	scene = alloc_scene();
	parse_scene(scene, fd);
	render_scene(scene);
	free_memory(root);
	return (0);
}
