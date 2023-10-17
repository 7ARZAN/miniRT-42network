/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 22:15:31 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 23:08:05 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//rendering the scene need 5 steps :
//	@1: raytracing
//	@2: shading
//	@3: shadow
//	@4: reflection
//	@5: refraction
//soo we need to create a function for each step
//and then we will call them in the render function
