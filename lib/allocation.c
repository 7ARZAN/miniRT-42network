/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   allocation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:42:02 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 19:50:10 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	*malloc_safe(t_garbage **root, size_t size)
{
	void	*ptr;

	ptr = malloc(size);
	if (!ptr)
	{
		perror("Error: Memory allocation failed");
		exit(1);
	}
	append_addr(root, ptr);
	return (ptr);
}

t_scene	*alloc_scene(void)
{
	t_scene	*scene;

	scene = malloc_safe(NULL, sizeof(t_scene));
	init_vec(&scene->color);
	init_vec(&scene->camera.center);
	init_vec(&scene->camera.direction);
	scene->camera.fov = 0;
	scene->camera.count = 0;
	scene->lights = NULL;
	scene->ambient.count = 0;
	scene->objects = NULL;
	return (scene);
}

t_object	*alloc_object(t_scene *scene)
{
	t_object	*obj;

	obj = malloc_safe(NULL, sizeof(t_object));
	obj->type = SPHERE;
	init_vec(&obj->center);
	init_vec(&obj->direction);
	init_vec(&obj->params);
	init_vec(&obj->color);
	init_vec(&obj->normal);
	obj->next = scene->objects;
	scene->objects = obj;
	return (obj);
}

t_light	*alloc_light(t_scene *scene)
{
	t_light	*light;

	light = malloc_safe(NULL, sizeof(t_light));
	init_vec(&light->source);
	light->ratio = 0;
	init_vec(&light->color);
	light->next = scene->lights;
	scene->lights = light;
	return (light);
}
