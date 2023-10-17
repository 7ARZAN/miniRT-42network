/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elakhfif <elakhfif@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 14:30:22 by elakhfif          #+#    #+#             */
/*   Updated: 2023/10/17 16:33:33 by elakhfif         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

//function to check if the map is valid or not :
//1- check if the map is surrounded by walls
//2- check if there is no spaces in the map
//3- check if there is no more than one player
//4- check if there is no more than one exit

static void	check_map(t_cub *cub)
{
	int i;
	int j;

	i = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			if (cub->map[i][j] == '0' || cub->map[i][j] == '2' ||
			cub->map[i][j] == 'N' || cub->map[i][j] == 'S' ||
			cub->map[i][j] == 'E' || cub->map[i][j] == 'W')
			{
				if (cub->map[i][j + 1] == ' ' || cub->map[i][j - 1] == ' ' ||
				cub->map[i + 1][j] == ' ' || cub->map[i - 1][j] == ' ')
					printf("ERROR: map is not surrounded by walls\n");
			}
			j++;
		}
		i++;
	}
}

static void	get_map(t_cub *cub, char *line)
{
	int i;
	int j;

	i = 0;
	j = 0;
	cub->map = (char **)malloc(sizeof(char *) * cub->map_height);
	while (i < cub->map_height)
	{
		cub->map[i] = (char *)malloc(sizeof(char) * cub->map_width);
		i++;
	}
	i = 0;
	while (i < cub->map_height)
	{
		j = 0;
		while (j < cub->map_width)
		{
			cub->map[i][j] = line[i * cub->map_width + j];
			j++;
		}
		i++;
	}
	check_map(cub);
}

static void	get_map_width_height(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1')
			cub->map_width++;
		i++;
	}
	cub->map_height = cub->map_size / cub->map_width;
	cub->map = (char **)malloc(sizeof(char *) * cub->map_height);
	i = 0;
	while (i < cub->map_height)
	{
		cub->map[i] = (char *)malloc(sizeof(char) * cub->map_width);
		i++;
	}
	i = 0;
	while (i < cub->map_size)
	{
		cub->map[i] = line;
		i++;
	}
	get_map(cub, line);
}

static void	get_map_from_file(t_cub *cub, char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == '2' ||
		line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			tmp = ft_strjoin(tmp, &line[i]);
			cub->map_size++;
		}
		i++;
	}
	get_map_width_height(cub, tmp);
}

void		read_map(t_cub *cub, char *line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] == '1' || line[i] == '0' || line[i] == '2' ||
		line[i] == 'N' || line[i] == 'S' || line[i] == 'E' || line[i] == 'W')
		{
			get_map_from_file(cub, line);
			break ;
		}
		i++;
	}
}
