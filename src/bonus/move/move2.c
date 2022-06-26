/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 04:33:50 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 06:55:08 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

int	move_wme(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->map->wme)
	{
		if (game->wme[x]->dir == 1)
			put_wme(game, game->wme[x], 3);
		else if (game->wme[x]->dir == 2)
			put_wme(game, game->wme[x], 4);
		else if (game->wme[x]->dir == 3)
			put_wme(game, game->wme[x], 1);
		else if (game->wme[x]->dir == 4)
			put_wme(game, game->wme[x], 2);
		x++;
	}
	return (0);
}

void	put_wme(t_game *game, t_wme *wme, int change_dir)
{
	char	**s;

	s = game->map->map;
	s[wme->pos->y][wme->pos->x] = '0';
	draw_img(game, PASS, wme->pos->x, wme->pos->y);
	if (wme->dir == 1)
		wme->pos->y -= 1;
	else if (wme->dir == 2)
		wme->pos->x -= 1;
	else if (wme->dir == 3)
		wme->pos->y += 1;
	else if (wme->dir == 4)
		wme->pos->x += 1;
	if (s[wme->pos->y][wme->pos->x] == 'P')
		close_game(game);
	draw_img(game, ENEMY, wme->pos->x, wme->pos->y);
	wme->dir = change_dir;
	s[wme->pos->y][wme->pos->x] = 'W';
}

void	show_moves(t_game *game)
{
	char	*s;

	s = ft_strjoin("Moves: ", ft_itoa(game->steps));
	draw_img(game, WALL, 1, 0);
	draw_img(game, WALL, 0, 0);
	mlx_string_put(game->mlx, game->mlx_win, 20, 32, 0x01DC05, s);
}
