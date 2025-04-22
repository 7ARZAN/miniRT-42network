#include "../include/minirt.h"

t_vec	compute_lighting(t_inter inter, t_scene *scene, t_ray ray)
{
	(void) ray;
	t_vec	ambient;
	t_vec	diffuse;
	t_light	*light;
	t_vec	light_dir;
	double	light_dot;

	ambient = multiply_vec(scene->ambient.color, scene->ambient.ratio / 255.0);
	diffuse = create_vec(0, 0, 0);
	light = scene->lights;
	while (light)
	{
		light_dir = normalize_vec(subtract_vec(light->source, inter.hit_point));
		light_dot = dot_product(inter.normal, light_dir);
		if (light_dot > 0)
			diffuse = add_vec(diffuse, multiply_vec(multiply_vec(light->color, light->ratio * light_dot / 255.0), 1.0));
		light = light->next;
	}
	return (create_vec(
		fmin(255, (ambient.x + diffuse.x) * inter.color.x / 255.0),
		fmin(255, (ambient.y + diffuse.y) * inter.color.y / 255.0),
		fmin(255, (ambient.z + diffuse.z) * inter.color.z / 255.0)));
}

t_vec	normalize_vec(t_vec v)
{
	double	mag;

	mag = magnitude_vec(v);
	if (mag < EPSILON)
		return (create_vec(0, 0, 0));
	return (divide_vec(v, mag));
}

t_ray	create_ray(t_vec origin, t_vec direction)
{
	t_ray	ray;

	ray.origin = origin;
	ray.direction = normalize_vec(direction);
	return (ray);
}
