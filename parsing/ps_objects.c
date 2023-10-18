/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_objects.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 03:55:47 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/18 04:03:43 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

void	ps_sphere(t_scene *scne, char **params)
{
	t_objs	*obj;

	if (NOPARAM || !params[4])
		perror("Error: Missing parameters for sphere");
	obj = alloc_obj(scne);
	obj->type = SPHERE;
	obj->cen = get_vec(params[1]);
	obj->p.x = ft_atod(params[2]);
	if (obj->p.x <= 0)
		perror("Error: Sphere diameter must be positive");
	obj->col = get_color(params[3]);
}

void	ps_cylinder(t_scene *scne, char **params)
{
	t_objs	*obj;

	if (NOPARAM || !params[4] || !params[5])
		perror("Error: Missing parameters for cylinder");
	obj = alloc_obj(scne);
	obj->type = CYLINDER;
	obj->cen = get_vec(params[1]);
	obj->dir = get_vec(params[2]);
	if (obj->dir.x > 1 || obj->dir.x < -1 || obj->dir.y > 1 || obj->dir.y < -1
		|| obj->dir.z > 1 || obj->dir.z < -1)
		perror("Error: Cylinder direction must be normalized");
	obj->p.x = ft_atod(params[3]);
	obj->p.y = ft_atod(params[4]);
	if (obj->p.x <= 0 || obj->p.y <= 0)
		perror("Error: Cylinder diameter and height must be positive");
	obj->col = get_color(params[5]);
}

void	ps_plane(t_scene *scne, char **params)
{
	t_objs	*obj;

	if (NOPARAM || !params[4])
		perror("Error: Missing parameters for plane");
	obj = alloc_obj(scne);
	obj->type = PLANE;
	obj->cen = get_vec(params[1]);
	obj->dir = get_vec(params[2]);
	if (obj->dir.x > 1 || obj->dir.x < -1 || obj->dir.y > 1 || obj->dir.y < -1
		|| obj->dir.z > 1 || obj->dir.z < -1)
		perror("Error: Plane direction must be normalized");
	obj->col = get_color(params[3]);
}
