/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 04:33:41 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 07:08:51 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

int	move_error(t_game *game, int x, int y)
{
	char	**map;
	int		px;
	int		py;

	px = game->map->player->x + x;
	py = game->map->player->y + y;
	map = game->map->map;
	if (map[py][px] == 'W')
		close_game(game);
	if (map[py][px] == '1')
		return (1);
	if (map[py][px] == 'C')
	{
		game->map->coins--;
		map[py][px] = '0';
		return (0);
	}
	if (map[py][px] == 'E' && game->map->coins != 0)
		return (1);
	if (map[py][px] == 'E' && game->map->coins == 0)
		close_game(game);
	return (0);
}

int	try_move(int x, int y, t_game *game)
{
	char	**s;

	s = game->map->map;
	if (move_error(game, x, y) == 1)
		return (0);
	if (s[game->map->player->y][game->map->player->x] != 'W')
	{
		s[game->map->player->y][game->map->player->x] = '0';
		draw_img(game, PASS, game->map->player->x, game->map->player->y);
	}
	draw_img(game, PASS, game->map->player->x + x, game->map->player->y + y);
	if (game->steps % 2 == 0)
		draw_img(game, ME1, game->map->player->x + x, game->map->player->y + y);
	else
		draw_img(game, ME2, game->map->player->x + x, game->map->player->y + y);
	game->map->player->x += x;
	game->map->player->y += y;
	s[game->map->player->y][game->map->player->x] = 'P';
	game->steps++;
	show_moves(game);
	return (0);
}

int	move(int k, t_game *game)
{
	static int	call;

	if (k == 0 || k == 1 || k == 2 || k == 13)
	{
		call++;
		if (call % 3 == 0)
			move_wme(game);
	}
	if (k == 13)
		try_move(0, -1, game);
	if (k == 0)
		try_move(-1, 0, game);
	if (k == 1)
		try_move(0, 1, game);
	if (k == 2)
		try_move(1, 0, game);
	if (k == 53)
		close_game(game);
	return (0);
}
