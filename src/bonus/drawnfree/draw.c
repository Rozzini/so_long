/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:40:55 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 06:49:09 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

void	draw_map(t_map *map, t_game *game, t_wme **wme)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	init_window(map, game);
	while (map->map[y] != NULL)
	{
		x = 0;
		while (map->map[y][x] != '\0')
		{
			pick_img(game, map->map[y][x], x, y);
			x++;
		}
		y++;
	}
	find_player(map);
	game->map = map;
	init_wme(game, wme);
}

void	pick_img(t_game *game, char c, int x, int y)
{
	if (c == '0')
		draw_img(game, PASS, x, y);
	if (c == '1')
		draw_img(game, WALL, x, y);
	if (c == 'C')
	{
		draw_img(game, PASS, x, y);
		draw_img(game, COIN, x, y);
	}
	if (c == 'E')
		draw_img(game, EXIT, x, y);
	if (c == 'P')
	{
		draw_img(game, PASS, x, y);
		draw_img(game, ME2, x, y);
	}
	if (c == 'W')
	{
		draw_img(game, PASS, x, y);
		draw_img(game, ENEMY, x, y);
	}	
}

void	draw_img(t_game *game, char *path, int x, int y)
{
	int	size;

	size = 64;
	x = x * size;
	y = y * size;
	game->img = mlx_xpm_file_to_image(game->mlx, path, &size, &size);
	mlx_put_image_to_window(game->mlx, game->mlx_win, game->img, x, y);
	mlx_destroy_image(game->mlx, game->img);
}
