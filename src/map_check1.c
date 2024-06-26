/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcardina <jcardina@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/07 16:21:57 by jcardina          #+#    #+#             */
/*   Updated: 2024/04/16 17:19:16 by jcardina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int  map_height(t_data *map)
{
	int height;

	height = 0;
	while (map->map[height])
		height++;
	return (height);
}

//sta roba é un cesso ma funziona, controlla che la mappa abbia i bordi chiusi
static int check_around(t_data *map, size_t i , size_t j)
{
		while (map->map[i][j] == ' ' || map->map[i][j] == '\t'
	|| map->map[i][j] == '\v' || map->map[i][j] == '\r'
	|| map->map[i][j] == '\f')
		j++;
	if (map->map[i][j] == '1')
		return (1);
	else if (map->map[i][j] != '1' && map->map[i][j] != '\n' && map->map[i][j] != '\0')
	{
		if (map->map[i][j + 1] != '0' && map->map[i][j + 1] != '1' && map->map[i][j + 1] != 'N' && map->map[i][j + 1] != 'S' && map->map[i][j + 1] != 'W' && map->map[i][j + 1] != 'E')
			return (0);
		else if (map->map[i][j - 1] != '0' && map->map[i][j - 1] != '1' && map->map[i][j - 1] != 'N' && map->map[i][j - 1] != 'S' && map->map[i][j - 1] != 'W' && map->map[i][j - 1] != 'E')
			return (0);
		else if (map->map[i + 1][j] != '0' && map->map[i + 1][j] != '1' && map->map[i + 1][j] != 'N' && map->map[i + 1][j] != 'S' && map->map[i + 1][j] != 'W' && map->map[i + 1][j] != 'E')
			return (0);
		else if (map->map[i - 1][j] != '0' && map->map[i - 1][j] != '1' && map->map[i - 1][j] != 'N' && map->map[i - 1][j] != 'S' && map->map[i - 1][j] != 'W' && map->map[i - 1][j] != 'E')
			return (0);
	}
	return (1);
}

int check_up_bottom(t_data *map, size_t i, size_t j)
{
	while (map->map[i][j])
	{
		if (map->map[i][j] != '1' && map->map[i][j] != ' ' && map->map[i][j] != 10)
			return (1);
		j++;
	}
	return (0);
}

int check_map(t_data *map)
{
	size_t i;
	size_t j;
	size_t height;
	i = 0;
	height = map_height(map) - 1;
	while (map->map[i])
	{
		j  = 0;
		if (i == 0 || i == height)
		{
			if (check_up_bottom(map, i, j))
				return (1);
		}
		else
		{
			while (j < ft_strlen(map->map[i]))
			{
			if (!check_around(map, i, j))
				return (1);
			j++;
			}
		}
	i++;
	}
	return (0);
}
