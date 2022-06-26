/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initData1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:46:48 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 06:52:02 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

void	init_wme_pos(t_wme *wme, int x, int y)
{
	t_pos	*pos;

	pos = malloc(sizeof(t_pos));
	wme->pos = pos;
	wme->pos->x = x;
	wme->pos->y = y;
	wme->dir = 0;
}

void	init_wme(t_game *game, t_wme **wme)
{
	int	x;
	int	i;
	int	j;

	x = 0;
	i = 0;
	j = 0;
	while (game->map->map[i] != NULL && x < game->map->wme)
	{
		j = 0;
		while (game->map->map[i][j] != '\0')
		{
			if (game->map->map[i][j] == 'W')
			{
				wme[x] = malloc(sizeof(t_wme));
				init_wme_pos(wme[x], j, i);
				x++;
			}
			j++;
		}
		i++;
	}
	pick_dir_for_wme(game, wme);
	game->wme = wme;
}

void	init_structs(t_map *map, t_game *game)
{
	map->player = malloc(sizeof(t_pos));
	map->coins = 0;
	game->steps = 0;
	map->wme = 0;
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
