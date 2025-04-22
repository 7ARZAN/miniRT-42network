/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytracing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 21:28:15 by elakhfif          #+#    #+#             */
/*   Updated: 2024/12/20 23:31:26 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_vec	ray_color(t_ray ray, t_scene *scene)
{
	t_inter	closest_inter;
	t_object	*obj;
	t_inter	inter;

	init_vec(&closest_inter.color);
	closest_inter.t = INFINITY;
	obj = scene->objects;
	while (obj)
	{
		if (obj->type == SPHERE && intersect_sphere(ray, obj, &inter))
			if (inter.t < closest_inter.t)
				closest_inter = inter;
		if (obj->type == PLANE && intersect_plane(ray, obj, &inter))
			if (inter.t < closest_inter.t)
				closest_inter = inter;
		if (obj->type == CYLINDER && intersect_cylinder(ray, obj, &inter))
			if (inter.t < closest_inter.t)
				closest_inter = inter;
		obj = obj->next;
	}
	if (closest_inter.t == INFINITY)
		return (create_vec(0, 0, 0));
	return (compute_lighting(closest_inter, scene, ray));
}

int	intersect_sphere(t_ray ray, t_object *obj, t_inter *inter)
{
	t_vec	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;

	oc = subtract_vec(ray.origin, obj->center);
	a = dot_product(ray.direction, ray.direction);
	b = 2.0 * dot_product(oc, ray.direction);
	c = dot_product(oc, oc) - (obj->params.x * obj->params.x / 4.0);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	t = (-b - sqrtf(discriminant)) / (2.0 * a);
	if (t < EPSILON)
		t = (-b + sqrtf(discriminant)) / (2.0 * a);
	if (t < EPSILON)
		return (0);
	inter->t = t;
	inter->hit_point = add_vec(ray.origin, multiply_vec(ray.direction, t));
	inter->normal = normalize_vec(subtract_vec(inter->hit_point, obj->center));
	inter->color = obj->color;
	return (1);
}

int	intersect_plane(t_ray ray, t_object *obj, t_inter *inter)
{
	double	denom;
	double	t;

	denom = dot_product(obj->direction, ray.direction);
	if (fabs(denom) < EPSILON)
		return (0);
	t = dot_product(subtract_vec(obj->center, ray.origin), obj->direction) / denom;
	if (t < EPSILON)
		return (0);
	inter->t = t;
	inter->hit_point = add_vec(ray.origin, multiply_vec(ray.direction, t));
	inter->normal = obj->direction;
	if (dot_product(ray.direction, inter->normal) > 0)
		inter->normal = multiply_vec(inter->normal, -1);
	inter->color = obj->color;
	return (1);
}

int	intersect_cylinder(t_ray ray, t_object *obj, t_inter *inter)
{
	t_vec	oc;
	t_vec	proj_dir;
	t_vec	proj_oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t;
	double	height;

	oc = subtract_vec(ray.origin, obj->center);
	proj_dir = subtract_vec(ray.direction, multiply_vec(obj->direction, dot_product(ray.direction, obj->direction)));
	proj_oc = subtract_vec(oc, multiply_vec(obj->direction, dot_product(oc, obj->direction)));
	a = dot_product(proj_dir, proj_dir);
	b = 2.0 * dot_product(proj_dir, proj_oc);
	c = dot_product(proj_oc, proj_oc) - (obj->params.x * obj->params.x / 4.0);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (0);
	t = (-b - sqrtf(discriminant)) / (2.0 * a);
	if (t < EPSILON)
		t = (-b + sqrtf(discriminant)) / (2.0 * a);
	if (t < EPSILON)
		return (0);
	inter->hit_point = add_vec(ray.origin, multiply_vec(ray.direction, t));
	height = dot_product(subtract_vec(inter->hit_point, obj->center), obj->direction);
	if (fabs(height) > obj->params.y / 2.0)
		return (0);
	inter->t = t;
	inter->normal = normalize_vec(subtract_vec(subtract_vec(inter->hit_point, obj->center), multiply_vec(obj->direction, height)));
	inter->color = obj->color;
	return (1);
}
