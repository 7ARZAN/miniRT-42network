/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_elmnts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:12:19 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 21:06:39 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parse_ambient(t_scene *scene, char **params)
{
	if (!params || !params[1] || !params[2])
		perror("Error: Invalid ambient parameters");
	if (scene->ambient.count != 0)
		perror("Error: Multiple ambient lights defined");
	scene->ambient.count++;
	scene->ambient.ratio = string_to_double(params[1]);
	if (scene->ambient.ratio < 0 || scene->ambient.ratio > 1)
		perror("Error: Ambient ratio must be in [0.0, 1.0]");
	scene->ambient.color = get_color(params[2]);
}

void	parse_camera(t_scene *scene, char **params)
{
	if (!params || !params[1] || !params[2] || !params[3])
		perror("Error: Invalid camera parameters");
	if (scene->camera.count != 0)
		perror("Error: Multiple cameras defined");
	scene->camera.count++;
	scene->camera.center = get_vector(params[1]);
	scene->camera.direction = normalize_vec(get_vector(params[2]));
	scene->camera.fov = string_to_int(params[3]);
	if (scene->camera.fov < 0 || scene->camera.fov > 180)
		perror("Error: Camera FOV must be in [0, 180]");
}

void	parse_light(t_scene *scene, char **params)
{
	t_light	*light;

	if (!params || !params[1] || !params[2] || !params[3])
		perror("Error: Invalid light parameters");
	light = alloc_light(scene);
	light->source = get_vector(params[1]);
	light->ratio = string_to_double(params[2]);
	if (light->ratio < 0 || light->ratio > 1)
		perror("Error: Light ratio must be in [0.0, 1.0]");
	light->color = get_color(params[3]);
}
