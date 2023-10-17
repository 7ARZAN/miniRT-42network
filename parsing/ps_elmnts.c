/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_elmnts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 18:12:19 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 21:06:39 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

t_light	*alloc_light(t_scene *scne)
{
	t_light	*new;

	new = (t_light *)malloc(sizeof(t_light));
	if (!new)
		perror("Error: malloc failed\n");
	new->next = scne->light;
	scne->light = new;
	return (new);
}

void	ps_ambient(t_scene *scne, char **params)
{
	if (NOPARAM)
		perror("Error: invalid ambient!");
	if (scne->amb.count != 0)
		perror("Error: too many ambient");
	scne->amb.count++;
	scne->amb.ratio = ft_atod(params[1]);
	if (scne->amb.ratio < 0 || scne->amb.ratio > 1)
		perror("enter ambient lighting ration in range [0.0 , 1.0]");
	scne->amb.col = get_color(params[2]);
}

void	ps_camera(t_scene *scne, char **params)
{
	if (NOPARAM)
		perror("Error: invalid camera!");
	if (scne->cam.count != 0)
		perror("Error: too many camera");
	scne->cam.count++;
	scne->cam.cen = get_vec(params[1]);
	scne->cam.dir = get_vec(params[2]);
	if (scne->cam.dir.x > 1 || scne->cam.dir.x < -1 || scne->cam.dir.y > 1
		|| scne->cam.dir.y < -1 || scne->cam.dir.z > 1 || scne->cam.dir.z < -1)
		perror("Error: camera direction must be normalized");
	scne->cam.fov = ft_atoi(params[3]);
	if (scne->cam.fov < 0 || scne->cam.fov > 180)
		perror("Error: camera fov must be in range [0 , 180]");
}

void	ps_light(t_scene *scne, char **params)
{
	t_light	*new;

	if (NOPARAM)
		perror("Error: invalid light!");
	new = alloc_light(scne);
	new->src = get_vec(params[1]);
	new->ratio = ft_atod(params[2]);
	if (new->ratio < 0 || new->ratio > 1)
		perror("Error: light ratio must be in range [0.0 , 1.0]");
	new->col = get_color(params[3]);
}
