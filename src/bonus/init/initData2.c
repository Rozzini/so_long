/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initData2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mraspors <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/24 03:47:06 by mraspors          #+#    #+#             */
/*   Updated: 2022/06/24 06:52:41 by mraspors         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../so_long_bonus.h"

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

int	count_wme(t_map *map)
{
	char	**s;
	int		i;
	int		j;

	s = map->map;
	i = 0;
	j = 0;
	while (s[i] != NULL)
	{
		j = 0;
		while (s[i][j] != '\0')
		{
			if (s[i][j] == 'W')
				map->wme++;
			j++;
		}
		i++;
	}
	return (map->wme);
}

void	pick_dir_for_wme(t_game *game, t_wme **wme)
{
	char	**s;
	int		x;

	s = game->map->map;
	x = 0;
	while (x < game->map->wme)
	{
		if (s[wme[x]->pos->y - 1][wme[x]->pos->x] == '0')
			wme[x]->dir = 1;
		else if (s[wme[x]->pos->y][wme[x]->pos->x - 1] == '0')
			wme[x]->dir = 2;
		else if (s[wme[x]->pos->y + 1][wme[x]->pos->x] == '0')
			wme[x]->dir = 3;
		else if (s[wme[x]->pos->y][wme[x]->pos->x + 1] == '0')
			wme[x]->dir = 4;
		x++;
	}
}
