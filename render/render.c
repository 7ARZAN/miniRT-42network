/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:15:31 by elakhfif          #+#    #+#             */
/*   Updated: 2024/12/20 23:31:33 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

static void *init_mlx(t_vars *vars)
{
    vars->mlx = mlx_init(WIDTH, HEIGHT, "miniRT", false);
    if (!vars->mlx)
    {
        perror("Error: MLX initialization failed");
        exit(1);
    }
    return (vars->mlx);
}

static t_vec	get_ray_direction(t_scene *scene, int x, int y)
{
	double	aspect_ratio;
	double	fov_scale;
	double	nx;
	double	ny;
	t_vec	right;
	t_vec	up;
	t_vec	dir;

	aspect_ratio = (double)WIDTH / HEIGHT;
	fov_scale = tan(scene->camera.fov * M_PI / 360.0);
	nx = (2.0 * x / WIDTH - 1.0) * aspect_ratio * fov_scale;
	ny = (1.0 - 2.0 * y / HEIGHT) * fov_scale;
	right = normalize_vec(cross_product(scene->camera.direction, create_vec(0, 1, 0)));
	up = normalize_vec(cross_product(right, scene->camera.direction));
	dir = add_vec(multiply_vec(right, nx), multiply_vec(up, ny));
	dir = add_vec(dir, scene->camera.direction);
	return (normalize_vec(dir));
}

static void	render_pixel(t_scene *scene, t_img_data *img, int x, int y)
{
	t_ray	ray;
	t_vec	color;
	uint32_t	pixel;

	ray = create_ray(scene->camera.center, get_ray_direction(scene, x, y));
	color = ray_color(ray, scene);
	pixel = ((uint32_t)color.x << 24) | ((uint32_t)color.y << 16) | ((uint32_t)color.z << 8) | 0xFF;
	mlx_put_pixel(img->img, x, y, pixel);
}

void render_scene(t_scene *scene)
{
	t_vars		vars;
	t_img_data	img;
	int		x;
	int		y;

	init_mlx(&vars);
	img.img = mlx_new_image(vars.mlx, WIDTH, HEIGHT);
	if (!img.img)
	{
		perror("Error: Image creation failed");
		mlx_terminate(vars.mlx);
	        exit(1);
	}
	y = -1;
	while (++y < HEIGHT)
	{
	    x = -1;
	    while (++x < WIDTH)
		render_pixel(scene, &img, x, y);
	}
	mlx_image_to_window(vars.mlx, img.img, 0, 0);
	mlx_loop(vars.mlx);
	mlx_terminate(vars.mlx);
}
