/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initData.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:46:48 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 05:38:00 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long.h"

void	find_player(t_map *map)
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
			if (map->map[i][j] == 'P')
			{
				map->player->x = j;
				map->player->y = i;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	init_structs(t_map *map, t_game *game)
{
	map->player = malloc(sizeof(t_pos));
	map->coins = 0;
	game->steps = 0;
}

void	init_window(t_map *map, t_game *game)
{
	int	size;
	int	w;
	int	h;

	size = 64;
	w = map->w * size;
	h = map->h * size;
	game->mlx_win = mlx_new_window(game->mlx, w, h, "so_long");
}
