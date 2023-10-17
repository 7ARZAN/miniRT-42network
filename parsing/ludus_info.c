/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ludus_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 15:35:20 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 16:37:11 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void		get_player_info(t_info *info, int i, int j)
{
	if (info->map[i][j] == 'N')
	{
		info->player.dirx = -1;
		info->player.diry = 0;
		info->player.planex = 0;
		info->player.planey = 0.66;
	}
	else if (info->map[i][j] == 'S')
	{
		info->player.dirx = 1;
		info->player.diry = 0;
		info->player.planex = 0;
		info->player.planey = -0.66;
	}
	else if (info->map[i][j] == 'E')
	{
		info->player.dirx = 0;
		info->player.diry = 1;
		info->player.planex = 0.66;
		info->player.planey = 0;
	}
	else if (info->map[i][j] == 'W')
	{
		info->player.dirx = 0;
		info->player.diry = -1;
		info->player.planex = -0.66;
		info->player.planey = 0;
	}
}

static void		get_player_pos(t_info *info, int i, int j)
{
	info->player.posx = i + 0.5;
	info->player.posy = j + 0.5;
	get_player_info(info, i, j);
}

static void		get_map_info(t_info *info, int i, int j)
{
	if (info->map[i][j] == '1')
		info->map[i][j] = 'x';
	else if (info->map[i][j] == '2')
		info->map[i][j] = 's';
	else if (info->map[i][j] == '0')
		info->map[i][j] = 'o';
	else if (info->map[i][j] == 'N' || info->map[i][j] == 'S' ||
			info->map[i][j] == 'E' || info->map[i][j] == 'W')
		get_player_pos(info, i, j);
	else if (info->map[i][j] == ' ')
		info->map[i][j] = ' ';
}

static void		cb_map(t_info *info)
{
	int		i;
	int		j;

	i = 0;
	while (i < info->map_height)
	{
		j = 0;
		while (j < info->map_width)
		{
			get_map_info(info, i, j);
			j++;
		}
		i++;
	}
}

void			get_info(t_info *info)
{
	cb_map(info);
}
