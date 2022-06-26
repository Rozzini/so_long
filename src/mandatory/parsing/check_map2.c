/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:39:08 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 07:04:09 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

int	check_coins(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'C')
				map->coins++;
			j++;
		}
		i++;
	}
	if (map->coins == 0)
		return (1);
	else
		return (0);
}

int	check_exit(t_map *map)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'E')
				counter++;
			j++;
		}
		i++;
	}
	if (counter == 0)
		return (1);
	else
		return (0);
}

int	check_player(t_map *map)
{
	int	i;
	int	j;
	int	counter;

	counter = 0;
	i = 0;
	j = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0')
		{
			if (map->map[i][j] == 'P')
				counter++;
			j++;
		}
		i++;
	}
	if (counter != 1)
		return (1);
	else
		return (0);
}
