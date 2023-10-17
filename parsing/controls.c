/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   controls.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:34:56 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 16:35:45 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	rotate_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(-cub->rot_speed) -
		cub->dir_y * sin(-cub->rot_speed);
	cub->dir_y = old_dir_x * sin(-cub->rot_speed) +
		cub->dir_y * cos(-cub->rot_speed);
	old_plane_x = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(-cub->rot_speed) -
		cub->plane_y * sin(-cub->rot_speed);
	cub->plane_y = old_plane_x * sin(-cub->rot_speed) +
		cub->plane_y * cos(-cub->rot_speed);
}

static void	rotate_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->dir_x;
	cub->dir_x = cub->dir_x * cos(cub->rot_speed) -
		cub->dir_y * sin(cub->rot_speed);
	cub->dir_y = old_dir_x * sin(cub->rot_speed) +
		cub->dir_y * cos(cub->rot_speed);
	old_plane_x = cub->plane_x;
	cub->plane_x = cub->plane_x * cos(cub->rot_speed) -
		cub->plane_y * sin(cub->rot_speed);
	cub->plane_y = old_plane_x * sin(cub->rot_speed) +
		cub->plane_y * cos(cub->rot_speed);
}

static void	move_forward(t_cub *cub)
{
	if (cub->map[(int)(cub->pos_x + cub->dir_x * cub->move_speed)]
			[(int)(cub->pos_y)] == '0')
		cub->pos_x += cub->dir_x * cub->move_speed;
	if (cub->map[(int)(cub->pos_x)]
			[(int)(cub->pos_y + cub->dir_y * cub->move_speed)] == '0')
		cub->pos_y += cub->dir_y * cub->move_speed;
}

static void	move_backward(t_cub *cub)
{
	if (cub->map[(int)(cub->pos_x - cub->dir_x * cub->move_speed)]
			[(int)(cub->pos_y)] == '0')
		cub->pos_x -= cub->dir_x * cub->move_speed;
	if (cub->map[(int)(cub->pos_x)]
			[(int)(cub->pos_y - cub->dir_y * cub->move_speed)] == '0')
		cub->pos_y -= cub->dir_y * cub->move_speed;
}

int			key_press(int key, t_cub *cub)
{
	if (key == 53)
		exit(0);
	if (key == 13 || key == 126)
		move_forward(cub);
	if (key == 1 || key == 125)
		move_backward(cub);
	if (key == 2 || key == 124)
		rotate_right(cub);
	if (key == 0 || key == 123)
		rotate_left(cub);
	return (0);
}
