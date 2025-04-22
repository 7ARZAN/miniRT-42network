/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:04:55 by elakhfif          #+#    #+#             */
/*   Updated: 2025/04/22 10:00:00 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define NOPARAM "!params || !params[1] || !params[2] || !params[3]"
# define WIDTH 800
# define HEIGHT 600
# define EPSILON 1e-6

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <float.h>
# include <mlx.h>

# include "structs.h"

int		main(int ac, char **av);
int		check_file(int ac, char **av);
t_vec	get_color(char *str);
t_vec	get_vector(char *str);
void	parse_line(char *id, char **params, t_scene *scene);
void	parse_scene(t_scene *scene, int fd);
t_light	*alloc_light(t_scene *scene);
void	parse_ambient(t_scene *scene, char **params);
void	parse_camera(t_scene *scene, char **params);
void	parse_light(t_scene *scene, char **params);
void	parse_sphere(t_scene *scene, char **params);
void	parse_cylinder(t_scene *scene, char **params);
void	parse_plane(t_scene *scene, char **params);
t_vec	subtract_vec(t_vec v1, t_vec v2);
double	magnitude_vec(t_vec v);
t_vec	divide_vec(t_vec v, double d);
t_vec	create_vec(double x, double y, double z);
void	init_vec(t_vec *v);
double	dot_product(t_vec v1, t_vec v2);
t_vec	cross_product(t_vec v1, t_vec v2);
t_vec	multiply_vec(t_vec v, double t);
t_vec	add_vec(t_vec v1, t_vec v2);
t_garbage	*new_node(void *addr);
t_garbage	**append_addr(t_garbage **root, void *addr);
void	free_memory(t_garbage **root);
void	*malloc_safe(t_garbage **root, size_t size);
void	collect_node(t_garbage **root, t_garbage *node);
t_scene	*alloc_scene(void);
t_object	*alloc_object(t_scene *scene);
char	*get_next_line(int fd);
char	**split_string(char const *s, char c);
void	free_split(char **split);
int		string_length(char *str);
double	take_min(double x, double y);
double	string_to_double(const char *str);
int		string_to_int(const char *str);
void	render_scene(t_scene *scene);
t_vec	ray_color(t_ray ray, t_scene *scene);
int		intersect_sphere(t_ray ray, t_object *obj, t_inter *inter);
int		intersect_plane(t_ray ray, t_object *obj, t_inter *inter);
int		intersect_cylinder(t_ray ray, t_object *obj, t_inter *inter);
t_vec	compute_lighting(t_inter inter, t_scene *scene, t_ray ray);
t_vec	normalize_vec(t_vec v);
t_ray	create_ray(t_vec origin, t_vec direction);

#endif
