/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:55:47 by elakhfif          #+#    #+#             */
/*   Updated: 2024/12/20 23:25:57 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	parse_sphere(t_scene *scene, char **params)
{
	t_object	*obj;

	if (!params || !params[1] || !params[2] || !params[3])
		perror("Error: Missing sphere parameters");
	obj = alloc_object(scene);
	obj->type = SPHERE;
	obj->center = get_vector(params[1]);
	obj->params.x = string_to_double(params[2]);
	if (obj->params.x <= 0)
		perror("Error: Sphere diameter must be positive");
	obj->color = get_color(params[3]);
}

void	parse_plane(t_scene *scene, char **params)
{
	t_object	*obj;

	if (!params || !params[1] || !params[2] || !params[3])
		perror("Error: Missing plane parameters");
	obj = alloc_object(scene);
	obj->type = PLANE;
	obj->center = get_vector(params[1]);
	obj->direction = normalize_vec(get_vector(params[2]));
	obj->color = get_color(params[3]);
}

void	parse_cylinder(t_scene *scene, char **params)
{
	t_object	*obj;

	if (!params || !params[1] || !params[2] || !params[3] || !params[4] || !params[5])
		perror("Error: Missing cylinder parameters");
	obj = alloc_object(scene);
	obj->type = CYLINDER;
	obj->center = get_vector(params[1]);
	obj->direction = normalize_vec(get_vector(params[2]));
	obj->params.x = string_to_double(params[3]);
	obj->params.y = string_to_double(params[4]);
	if (obj->params.x <= 0 || obj->params.y <= 0)
		perror("Error: Cylinder diameter and height must be positive");
	obj->color = get_color(params[5]);
}
