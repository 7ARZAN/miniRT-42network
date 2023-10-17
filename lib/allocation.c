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

t_scene	*alloc_scene(void)
{
	t_scene	*scene;

	scene = ft_malloc(&g_root, sizeof(t_scene));
	if (!scene)
		return (NULL);
	scene->objs = NULL;
	scene->amb.count = 0;
	scene->cam.count = 0;
	scene->light = NULL;
	return (scene);
}

t_objs	*alloc_obj(t_scene *scene)
{
	t_objs	*new;

	g_root = NULL;
	new = ft_malloc(&g_root, sizeof(t_objs));
	if (!new)
		return (NULL);
	vctr_init(&(new->col));
	vctr_init(&(new->cen));
	vctr_init(&(new->dir));
	vctr_init(&(new->p));
	new->next = scene->objs;
	scene->objs = new;
	return (new);

