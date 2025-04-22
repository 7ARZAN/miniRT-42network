/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:05:47 by elakhfif          #+#    #+#             */
/*   Updated: 2024/12/20 23:26:13 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef STRUCTS_H
# define STRUCTS_H

typedef enum e_obj_type
{
	SPHERE,
	PLANE,
	SQUARE,
	TRIANGLE,
	CYLINDER
}	t_obj_type;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_img_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_vec
{
	double	x;
	double	y;
	double	z;
}	t_vec;

typedef struct s_ray
{
	t_vec	origin;
	t_vec	direction;
}	t_ray;

typedef struct s_inter
{
	double	t;
	t_vec	color;
	t_vec	hit_point;
	t_vec	normal;
}	t_inter;

typedef struct s_cam
{
	t_vec	center;
	t_vec	direction;
	double	fov;
	int		count;
}	t_camera;

typedef struct s_light
{
	t_vec			source;
	double			ratio;
	t_vec			color;
	struct s_light	*next;
}	t_light;

typedef struct s_amb
{
	t_vec	color;
	double	ratio;
	int		count;
}	t_ambient;

typedef struct s_objs
{
	t_obj_type		type;
	t_vec			center;
	t_vec			direction;
	t_vec			params;
	t_vec			color;
	t_vec			normal;
	struct s_objs	*next;
}	t_object;

typedef struct s_scene
{
	t_vec		color;
	t_camera	camera;
	t_light		*lights;
	t_ambient	ambient;
	t_object	*objects;
}	t_scene;

typedef struct s_garbage
{
	void				*address;
	struct s_garbage	*next;
}	t_garbage;

#endif
