/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:37:52 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 07:04:04 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	check_top_bot_boundaries(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->w)
	{
		if (map->map[0][i] != '1')
			return (1);
		if (map->map[map->h - 1][i] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_side_boundaries(t_map *map)
{
	int	i;

	i = 0;
	while (map->map[i] != NULL)
	{
		if (map->map[i][0] != '1' || map->map[i][map->w - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_symbols(t_map *map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			c = map->map[i][j];
			if (c != '0' && c != '1' && c != 'C' && c != 'E' && c != 'P')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
