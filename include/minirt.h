/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:04:55 by elakhfif          #+#    #+#             */
/*   Updated: 2024/12/20 23:27:49 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# define NOPARAM  "!params || !params[1] || !params[2] || !params[3]"

# include <stdio.h>
# include <stdlib.h>
# include <math.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>
# include <errno.h>
# include <limits.h>
# include <float.h>

# include "structs.h"

int	main(int ac, char **av);
int	check_file(int ac, char **av);
t_vec	get_color(char *str);
t_vec	get_vec(char *str);
void	parse_line(char *id, char **params, t_scene *scne);
void	parser(t_scene *scne, int fd);
t_light	*alloc_light(t_scene *scne);
void	ps_ambient(t_scene *scne, char **params);
void	ps_camera(t_scene *scne, char **params);
void	ps_light(t_scene *scne, char **params);
t_vec	sub_vec(t_vec v1, t_vec v2);
double	module_vec(t_vec v);
t_vec	div_vec(t_vec v, double d);
t_vec	make_vec(double x, double y, double z);
void	vctr_init(t_vec *v);
double	dot_vec(t_vec v1, t_vec v2);
t_vec	cross_vec(t_vec v1, t_vec v2);
t_vec	mult_vec(t_vec v, double t);
t_vec	add_vec(t_vec v1, t_vec v2);
t_collector	*new_node(void *addr);
t_collector	**append_addr(t_collector **g_root, void *addr);
void	free_memory(t_collector **g_root);
void	ft_malloc(t_collector **g_root, size_t size);
void	ft_collect(t_collector **g_root, t_collector *node);
t_scene	*alloc_scene(void);
t_objs	*alloc_obj(t_scene *scene);
char	*gnl(int fd);
char	**ohmysplit(char const *s, char c);
void	free_split(char **split);
int	ft_strlen(char *str);
double	take_min(double x, double y);
double	ft_atod(const char *str);
int	ft_atoi(const char *str);
void	ps_sphere(t_scene *scne, char **params);
void	ps_cylinder(t_scene *scne, char **params);
void	ps_plane(t_scene *scne, char **params);

#endif
