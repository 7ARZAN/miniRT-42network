/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:31:15 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 21:09:03 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec	get_color(char *str)
{
	char	**params;
	t_vec	color;

	params = ohmysplit(str, ',');
	if (!params || !params[1] || !params[2] || params[3])
	{
		perror("Error: Wrong color format\n");
		exit(0);
	}
	color = (t_vec){ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2])};
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255
		|| color.z < 0 || color.z > 255)
	{
		perror("Error: Wrong color format\n");
		exit(0);
	}
	free_split(params);
	return (color);
}

t_vec	get_vec(char *str)
{
	char	**params;
	t_vec	vec;

	params = ohmysplit(str, ',');
	if (NOPARAM)
	{
		perror("Error: Wrong vector format\n");
		exit(0);
	}
	vec = (t_vec){ft_atod(params[0]), ft_atod(params[1]), ft_atod(params[2])};
	free_split(params);
	return (vec);
}

void	parse_line(char *id, char **params, t_scene *scne)
{
	if (id[0] == 'A' && id[1] == '\0')
		ps_ambient(scne, params);
	else if (id[0] == 'C' && id[1] == '\0')
		ps_camera(scne, params);
	else if (id[0] == 'L' && id[1] == '\0')
		ps_light(scne, params);
	else if (id[0] == 's' && id[1] == 'p' && id[2] == '\0')
		ps_sphere(scne, params);
	else if (id[0] == 'p' && id[1] == 'l' && id[2] == '\0')
		ps_plane(scne, params);
	else if (id[0] == 'c' && id[1] == 'y' && id[2] == '\0')
		ps_cylinder(scne, params);
	else
	{
		perror("Error: Wrong identifier\n");
		exit(0);
	}
}

void	parser(t_scene *scne, int fd)
{
	char	**params;

	while (1)
	{
		params = ohmysplit(gnl(fd), ' ');
		if (params == NULL)
			break ;
		if (*params)
			parse_line(*params, params, scne);
		free_split(params);
	}
	close(fd);
}
