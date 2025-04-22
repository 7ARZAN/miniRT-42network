/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 17:31:15 by elakhfif          #+#    #+#             */
/*   Updated: 2024/12/20 23:31:44 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec	get_color(char *str)
{
	char	**params;
	t_vec	color;

	params = split_string(str, ',');
	if (!params || !params[0] || !params[1] || !params[2] || params[3])
	{
		free_split(params);
		perror("Error: Invalid color format");
		exit(1);
	}
	color = create_vec(string_to_double(params[0]), string_to_double(params[1]), string_to_double(params[2]));
	if (color.x < 0 || color.x > 255 || color.y < 0 || color.y > 255 || color.z < 0 || color.z > 255)
	{
		free_split(params);
		perror("Error: Color values must be in [0, 255]");
		exit(1);
	}
	free_split(params);
	return (color);
}

t_vec	get_vector(char *str)
{
	char	**params;
	t_vec	vector;

	params = split_string(str, ',');
	if (!params || !params[0] || !params[1] || !params[2] || params[3])
	{
		free_split(params);
		perror("Error: Invalid vector format");
		exit(1);
	}
	vector = create_vec(string_to_double(params[0]), string_to_double(params[1]), string_to_double(params[2]));
	free_split(params);
	return (vector);
}

static int	compare_strings(const char *s1, const char *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;

	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (*str1 && *str2 && *str1 == *str2 && --n)
	{
		str1++;
		str2++;
	}
	return (*str1 - *str2);
}

void	parse_line(char *id, char **params, t_scene *scene)
{
	if (id[0] == 'A' && id[1] == '\0')
		parse_ambient(scene, params);
	else if (id[0] == 'C' && id[1] == '\0')
		parse_camera(scene, params);
	else if (id[0] == 'L' && id[1] == '\0')
		parse_light(scene, params);
	else if (compare_strings(id, "sp", 2) == 0)
		parse_sphere(scene, params);
	else if (compare_strings(id, "pl", 2) == 0)
		parse_plane(scene, params);
	else if (compare_strings(id, "cy", 2) == 0)
		parse_cylinder(scene, params);
	else
	{
		perror("Error: Invalid identifier");
		exit(1);
	}
}

void	parse_scene(t_scene *scene, int fd)
{
	char	**params;
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		params = split_string(line, ' ');
		free(line);
		if (params && params[0])
			parse_line(params[0], params, scene);
		free_split(params);
	}
	close(fd);
}
